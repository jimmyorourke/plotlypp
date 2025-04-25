#!/usr/bin/env python3

import os
import json
from pathlib import Path
import subprocess


def get_all_valtypes(d):
    for key, value in d.items():
        if key == 'valType':
            yield value
        if isinstance(value, dict):
            yield from get_all_valtypes(value)
    #{'number', 'color', 'flaglist', 'info_array', 'boolean', 'angle', 'integer', 'data_array', 'any', 'colorscale', 'subplotid', 'string', 'colorlist', 'enumerated'}

# /*
#     import plotly.graph_objects as go
#     import numpy as np

#     N = 1000
#     t = np.linspace(0, 10, 100)
#     y = np.sin(t)

#     fig = go.Figure(data=go.Scatter(x=t, y=y, mode='markers'))

#     fig.show()
# */

    # fig := &grob.Fig{
    #     Data: []types.Trace{
    #         &grob.Scatter{
    #             X:    types.DataArray(t),
    #             Y:    types.DataArray(y),
    #             Mode: grob.ScatterModeMarkers,
    #         },
    #     },
    # }
    # offline.ToHtml(fig, "scatter.html")
    # data = JSON.parse('{"data":[{"type":"scatter","mode":"markers","x":


#auto fig = Figure(Scatter().x(std::move(t)).y(std::move(y)).mode("markers"));


#Plotly.newPlot(                        "054d4733-9bc6-4455-bd62-e734b2551e79",                        [{"mode":"markers","name":"Markers","x":[1,2,3,4,5],"y":[2,4,1,3,5],"type":"scatter"}]

# Colors can be strings or numbers. The template for proper handling of std::string, const char*,
                    # or double gets complicated, as does a vector of std::variant, so just use overloads instead.
valtype_map = {
    'number': ['double'],
    'boolean': ['bool'],
    'angle': ['double'],
    'integer': ['int'],
    'subplotid': ['std::string'],
    'string': ['std::string'],
    'any': ['T'], # can usualle be dbl?
    'data_array': ['std::vector<T>'], # with constraint
    'info_array': ['std::vector<std::string>'],#'std::vector<T>',
    'enumerated': ['ENUM'], # also need to json
    'color': ["std::string", "double"], # also need to json
    'flaglist': ['std::string'], # also need to json, basically enum
    'colorscale': ['std::string', 'std::vector<std::pair<double, std::string>>'], # also need to json, basically enum --- could be smarter
    # Not really, but it's useful to add here
    "object": ['OBJECT']
}

class IndentBlock:
    def __init__(self, writer):
        self.writer = writer

    def __enter__(self):
        self.writer.indent_level += 1

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.writer.indent_level -= 1


class Writer:
    INDENT_SIZE = 4
    def __init__(self, output_file=None):
        self.indent_level = 0
        self._output_file = output_file
        self._output_file_handle = open(self._output_file, "w") if self._output_file is not None else sys.stdout
        # TODO: handle closing file

    def write(self, line):
        """Outputs input text with a newline at current indent level"""
        indent = " " * self.INDENT_SIZE * self.indent_level
        print(f"{indent}{line}", file=self._output_file_handle)


def emit_json_member(writer):
    with IndentBlock(writer):
        writer.write("// Advanced users may modify the JSON representation directly, at their own peril!")
        writer.write("Json json{};")

def emit_array_field_setter_decl(class_object, field, output_val_type, writer):
    if output_val_type == 'T':
        writer.write(f"template <typename T>")
    writer.write(f"{class_object.name.title()}& {field.name}(std::vector<{output_val_type}> f);")

def emit_array_field_setter(class_object, field, output_val_type, writer):
    if output_val_type == 'T':
        writer.write(f"template <typename T>")
    writer.write(f"{class_object.name.title()}& {class_object.name.title()}::{field.name}(std::vector<{output_val_type}> f) {{")
    with IndentBlock(writer):
        if field.is_object:
            writer.write(f"std::vector<json> jsonified(f.size());")
            writer.write(f"std::transform(f.begin(), f.end(), jsonified.begin(), [](auto& e){{return std::move(e.j);}});")
            writer.write(f"json[\"{field.name}\"] = std::move(jsonified);")
        else:
            writer.write(f"json[\"{field.name}\"] = std::move(f);")
        writer.write("return *this;")
    writer.write("}")

def emit_field_setter_decl(class_object, field, output_val_type, writer):
    if output_val_type == 'T':
        writer.write(f"template <typename T>")
    elif field.json_val_type == 'data_array':
        writer.write(f"template <typename T, typename=std::enable_if_t<is_data_array_element_v<T>>>")
    writer.write(f"{class_object.name.title()}& {field.name}({output_val_type} f);")

def emit_field_setter(class_object, field, output_val_type, writer):
    if output_val_type == 'T':
        writer.write(f"template <typename T>")
    elif field.json_val_type == 'data_array':
        writer.write(f"template <typename T, typename>")
    writer.write(f"{class_object.name.title()}& {class_object.name.title()}::{field.name}({output_val_type} f) {{")
    with IndentBlock(writer):
        if field.is_object:
            writer.write(f"json[\"{field.name}\"] = std::move(f.json);")
        else:
            writer.write(f"json[\"{field.name}\"] = std::move(f);")
        writer.write("return *this;")
    writer.write("}")

def emit_enum_field_setter_decl(class_object, field, writer):
    # To help compiler ambiguity, add enum keyword.
    writer.write(f"{class_object.name.title()}& {field.name}(enum {field.name.title()} f);")

def emit_enum_field_setter(class_object, field, writer):
    # To help compiler ambiguity, add enum keyword.
    writer.write(f"{class_object.name.title()}& {class_object.name.title()}::{field.name}(enum {field.name.title()} f) {{")
    with IndentBlock(writer):
        writer.write(f"json[\"{field.name}\"] = to_string(f);")
        writer.write("return *this;")
    writer.write("}")

def emit_enum_array_field_setter_decl(class_object, field, writer):
    writer.write(f"{class_object.name.title()}& {field.name}(const std::vector<enum {field.name.title()}>& f);")

def emit_enum_array_field_setter(class_object, field, writer):
    writer.write(f"{class_object.name.title()}& {class_object.name.title()}::{field.name}(const std::vector<enum {field.name.title()}>& f) {{")
    with IndentBlock(writer):
        writer.write(f"std::vector<std::string> stringified(f.size());")
        writer.write(f"std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){{return to_string(e);}});")
        writer.write(f"json[\"{field.name}\"] = std::move(stringified);")
        writer.write("return *this;")
    writer.write("}")

def emit_enum_definition(enum, writer):
    writer.write("")
    writer.write(f"enum class {enum.name.title()} {{")
    with IndentBlock(writer):
        for safe_val in enum.safe_to_json_vals:
            writer.write(f"{safe_val},")
    writer.write("};")

def emit_enum_to_string_decl(enum, writer):
    writer.write(f"static std::string to_string({enum.name.title()} e);")

def emit_enum_to_string(class_object, enum, writer):
    writer.write(f"std::string {class_object.name.title()}::to_string({enum.name.title()} e) {{")
    with IndentBlock(writer):
        writer.write("switch(e) {")
        with IndentBlock(writer):
            for safe_val, json_val in enum.safe_to_json_vals.items():
                writer.write(f'case {enum.name.title()}::{safe_val}: return "{json_val}";')
        writer.write("}")
    writer.write("}")

def emit_class_public_members(class_object, writer):
    for e in class_object.enums:
        emit_enum_to_string(class_object, e, writer)

    writer.write("")

    for field in class_object.fields:
        if field.is_enum:
            emit_enum_field_setter(class_object, field, writer)
            if field.array_ok:
                emit_enum_array_field_setter(class_object, field, writer)
        else:
            if field.is_object:
                # Quirky
                output_val_types = [f"class {field.name.title()}"]
            else:
                output_val_types = valtype_map[field.json_val_type]
            for output_val_type_overload in output_val_types:
                emit_field_setter(class_object, field, output_val_type_overload, writer)
            if field.array_ok:
                for output_val_type_overload in output_val_types:
                    emit_array_field_setter(class_object, field, output_val_type_overload, writer)

        writer.write("")

def emit_class_public_members_decl(class_object, writer):
    with IndentBlock(writer):
        for e in class_object.enums:
            emit_enum_definition(e, writer)
            emit_enum_to_string_decl(e, writer)

        writer.write("")
        for obj in class_object.objects:
            emit_forward_object_decl(obj, writer)

        writer.write("")
        for field in class_object.fields:
            if field.description:
                lines = field.description.split("\n")
                # Dumb hack for clang-format not respecting existing newlines in comments.
                writer.write(f"// {lines[0]}")
                for line in lines[1:]:
                    writer.write(f"// - {line}")
            if field.is_enum:
                emit_enum_field_setter_decl(class_object, field, writer)
                if field.array_ok:
                    emit_enum_array_field_setter_decl(class_object, field, writer)
            else:
                if field.is_object:
                    # Quirky
                    output_val_types = [f"class {field.name.title()}"]
                else:
                    output_val_types = valtype_map[field.json_val_type]
                for output_val_type_overload in output_val_types:
                    emit_field_setter_decl(class_object, field, output_val_type_overload, writer)
                if field.array_ok:
                    for output_val_type_overload in output_val_types:
                        emit_array_field_setter_decl(class_object, field, output_val_type_overload, writer)

            writer.write("")

def emit_forward_object_decl(class_object, writer):
    if class_object.description:
        writer.write(f"// {class_object.description}")
    writer.write(f"class {class_object.name.split("::")[-1].title()};")

def emit_object_decl(class_object, writer):
    if class_object.description:
        writer.write(f"// {class_object.description}")
    writer.write(f"class {class_object.name.title()} {{")
    writer.write("public:")
    emit_class_public_members_decl(class_object, writer)
    emit_json_member(writer)
    writer.write("};")
    writer.write("")

def unnest_objects(parent, unnested_objects):
    for obj in parent.objects:
        obj.name = f"{parent.name}::{obj.name.capitalize()}"
        unnested_objects.append(obj)
        unnest_objects(obj, unnested_objects)


def emit_trace(trace, out_dir, impl_subdir):
    out_file = out_dir/f"{trace.name}.hpp"
    writer = Writer(out_file)

    writer.write("// TODO: includes, copyright, etc")
    writer.write("#pragma once")
    writer.write("")
    writer.write("#include <string>")
    writer.write("#include <vector>")
    writer.write("#include <type_traits>")
    writer.write("")
    writer.write("#include <plotlypp/trace.hpp>")
    writer.write("#include <plotlypp/traits.hpp>")
    writer.write("")
    writer.write("#include <plotlypp/json.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    # Special case the outermost trace object to handle the 'type' field
    writer.write(f"class {trace.name.title()} : public Trace {{")
    writer.write("public:")
    with IndentBlock(writer):
        writer.write(f"{trace.name.title()}() : Trace() {{")
        with IndentBlock(writer):
            writer.write(f"json[\"type\"] = \"{trace.name}\";")
        writer.write("}")
    emit_class_public_members_decl(trace, writer)
    writer.write("};")
    writer.write("")

    unnested_objects = []
    unnest_objects(trace, unnested_objects)
    for obj in unnested_objects:
        emit_object_decl(obj, writer)

    writer.write("} // namespace plotlypp")
    writer.write("")
    writer.write(f"#include \"{impl_subdir}/{trace.name}_impl.hpp\"")
    writer.write("")

    writer = Writer(out_dir / impl_subdir / f"{trace.name}_impl.hpp")
    writer.write("// TODO: includes, copyright, etc")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    emit_class_public_members(trace, writer)
    for obj in unnested_objects:
        emit_class_public_members(obj, writer)
    writer.write("} // namespace plotlypp")
    writer.write("")


class Object:
    def __init__(self):
        self.name = ""
        self.description = ""
        self.fields = []

        self.enums = []
        self.flaglists = []
        self.objects = []

class Field:
    def __init__(self):
        self.name = "" # name vs JSON name for CamelCase classes?
        self.description = ""
        #self.val_type = None
        self.json_val_type = None
        self.array_ok = False
        self.is_enum = False
        self.is_object = False

class StringEnum:
    def __init__(self):
        self.name = ""
        self.safe_to_json_vals = {}

# Translate enum symbol strings to valid name identifiers
json_symbol_name_map = {
    "": "Empty",
    "=": "Eq",
    ">": "Gt",
    "-": "Hyphen",
    "<": "Lt",
    "|": "Or",
    "/": "Slash",
    "\\": "Doublebackslash", # Warning! Needs special escaping.
    "^": "Cape",
    "(": "Lpar",
    ")": "Rpar",
    "[": "Lbracket",
    "]": "Rbracket",
    "+": "Plus",
    "?": "Question",
    "$": "Dollar",
    ".": "Dot"
}

json_name_escape_map = {
    "\\" : "\\\\"
}

def output(text: str, indent_level):
        """Outputs input text with a newline at current indent level"""
        indent = " " * 4 * indent_level
        print(f"{indent}{text}")

def print_obj_structure(obj, indent=0):
    output(f"{obj.name}", indent)
    indent+=1
    output("::enums::", indent)
    for e in obj.enums:
        output(f"{e.name}", indent)
    output("::objects::", indent)
    for o in obj.objects:
        print_obj_structure(o, indent+1)
    output("::fields::", indent)
    for f in obj.fields:
        output(f"{f.name}", indent)



def parse_attributes(parent, attributes_node):
    for name, node in attributes_node.items():
        if name == "_deprecated":
            continue
        #print(name, node)
        # TODO: check contour impliedEdits autocontour
        if not (isinstance(node, dict) and ("role" in node or "valType" in node)):
            continue

        # Every node is a field that can be set.
        f = Field()
        f.name = name
        #print(name)
        # objects don't have description. Some random valType nodes also don't
        if "description" in node:
            f.description = node["description"]

        if "role" in node and node["role"] == "object":
            #  Nested structure.
            f.is_object = True
            if "arrayOk" in node and node["arrayOk"] == True:
                f.array_ok = True
            # Quirky but works.
            #f.val_type = f.name
            obj = Object()
            obj.name = f.name
            obj.description = f.description
            parse_attributes(obj, node)
            parent.objects.append(obj)

            # TODO: Items!
            if "items" in node:
                parse_attributes(obj, node["items"])



        elif "valType" in node:
            f.json_val_type = node["valType"]
            #f.val_type = valtype_map[f.json_val_type]

            if "arrayOk" in node and node["arrayOk"] == True:
                f.array_ok = True

            if f.json_val_type == "enumerated":
                f.is_enum = True
                # Also create an enum which will be associated with the parent trace.
                e = StringEnum()
                e.name = f.name
                e.description = f.description

                if "dflt" in node:
                    f.description += f"\nDefault: {node["dflt"]}"

                for val in node['values']:
                    # Some enums contain "True" of "False" which get mistakenly parse to Python bools.
                    json_val = str(val)
                    safe_val = str(val)
                    if json_val in json_name_escape_map:
                        json_val = json_name_escape_map[json_val]

                    # Some are invalid symbols
                    if safe_val in json_symbol_name_map:
                        safe_val = json_symbol_name_map[safe_val]

                    # Some names have spaces!
                    safe_val = safe_val.replace(" ", "_")
                    # Some have hypens which are invalid. Note this has to be done after symbol mapping!
                    safe_val = safe_val.replace("-", "_")

                    # Some are numbers which invalid enum identifiers. Enumerators can't start with a digit.
                    if safe_val[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
                        safe_val = "NUM_" + safe_val
                    # To avoid keyword conflicts, and for style, use upper case.
                    safe_val = safe_val.upper()
                    # The map also handles the uniqueness requirement.
                    e.safe_to_json_vals[safe_val] = json_val

                parent.enums.append(e)

            if f.json_val_type == "flaglist":
                if "dflt" in node:
                    f.description += f"\nDefault: {node["dflt"]}"
                f.description += f"\nFlags: {node["flags"]}"
                if "extras" in node:
                    f.description += f"\nExtras {node["extras"]}"

        parent.fields.append(f)


def parse_type(trace, type_node):
    # Just the name again
    assert(trace.name == type_node)

def parse_meta(trace, meta_node):
    for name, node in meta_node.items():
        if name == "description":
            trace.description = node
        elif name == "hr_name" or name == "hrName":
            pass
        else:
            print(f"Skipping unknown meta field {name}. Does parser needs updating?")


def create_trace(name, trace_node):
    trace = Object()
    trace.name = name # TODO: convert case
    print("Parsing trace", name)

    for node_name, node in trace_node.items():
        if node_name == "meta":
            parse_meta(trace, node)
        elif node_name == "type":
            parse_type(trace, node)
        elif node_name == "attributes":
            parse_attributes(trace, node)
        elif node_name in ["animatable", "categories", "layoutAttributes"]:
            pass
        else:
            print(f"Skipping unknown attribute field {attribute}. Does parser needs updating?")

    #emit_trace(trace)
    #print_obj_structure(trace)
    top_level_src_dir = Path(__file__).parent.parent / "include" / "plotlypp"
    traces_dir = top_level_src_dir / "traces"
    impl_subdir = Path("impl")
    os.makedirs(traces_dir / impl_subdir, exist_ok=True)
    emit_trace(trace, traces_dir, impl_subdir)
    # We did our best with formatting, but let's auto format to catch long comments, etc.
    subprocess.run(["clang-format", "--style=file", "-i", str(traces_dir/f"{trace.name}.hpp")])



def create_traces(schema):
    for name, trace_node in schema['traces'].items():
        #if name != "scatter":
        #    continue
        create_trace(name, trace_node)
        #break




def main():
    schema = {}
    with open(Path(__file__).parent / 'schema.json') as f:
        schema = json.load(f)


    # handle versions?

    # create plotly
    # functions for adding traces to a figure

    # create traces

    # CreateLayout

    # CreateConfig(graphObjectsOuput)

    #CreateAnimation(graphObjectsOuput)

    #CreateFrames(graphObjectsOuput)







    #print("--")
    #print("traces")
    # for k in data['traces']:
    #     print("\t", k)
    #print("traces/scatter")
    create_traces(schema)
    #for name, trace in data['traces'].items():
    #    if name == "scatter":
        #     #print(json.dumps(trace, indent=4))
    #         process_trace(name, trace)
        #process_trace(name, trace)

    #valtypes = set()
    # for v in get_all_valtypes(data['traces']):
    #     valtypes.add(v)
    # print(valtypes)

    # for k in data:

# traces/scatter
#      animatable
#      attributes --
#      categories
#      layoutAttributes
#      meta. --
#      type --

# animation
# config. --
# defs
# frames
# layout --
# traces --
# transforms


# skip
# var MetaKeys = []MetaKey{
#     "_isSubplotObj",
#     "_isLinkedToArray",
#     "_arrayAttrRegexps",
#     "_deprecated",
#     "description",
#     "role",
#     "editType",
#     "impliedEdits",
# }

    #     print(k)

    # print("--")
    # print("traces")
    # for k in data['traces']:
    #     print("\t", k)

    # print("--")
    # print("layout")
    # for k in data['layout']:
    #     print("\t", k)
    #     for j in  data['layout'][k]:
    #         print("\t\t", j)



# layout
#      layoutAttributes
#          _deprecated
#          activeselection
#          activeshape
#          annotations
#          autosize
#          autotypenumbers
#          calendar
#          clickmode
#          coloraxis
#          colorscale
#          colorway
#          computed
#          datarevision
#          dragmode
#          editrevision
#          editType
#          font
#          geo
#          grid
#          height
#          hidesources
#          hoverdistance
#          hoverlabel
#          hovermode
#          images
#          legend
#          mapbox
#          margin
#          meta
#          metasrc
#          minreducedheight
#          minreducedwidth
#          modebar
#          newselection
#          newshape
#          paper_bgcolor
#          plot_bgcolor
#          polar
#          scene
#          selectdirection
#          selectionrevision
#          selections
#          separators
#          shapes
#          showlegend
#          sliders
#          smith
#          spikedistance
#          template
#          ternary
#          title
#          transition
#          uirevision
#          uniformtext
#          updatemenus
#          width
#          xaxis
#          yaxis


if __name__ == '__main__':
    main()
