#!/usr/bin/env python3

import json

def get_all_valtypes(d):
    for key, value in d.items():
        if key == 'valType':
            yield value
        if isinstance(value, dict):
            yield from get_all_valtypes(value)
    #{'number', 'color', 'flaglist', 'info_array', 'boolean', 'angle', 'integer', 'data_array', 'any', 'colorscale', 'subplotid', 'string', 'colorlist', 'enumerated'}

valtype_map = {
    'number': 'double',
    'boolean': 'bool',
    'angle': 'double',
    'integer': 'int',
    'subplotid': 'std::string',
    'string': 'std::string',
    'any': 'T', # can usualle be dbl?
    'data_array': 'std::vector<double>',
    'info_array': 'std::vector<std::string>',#'std::vector<T>',
    'enumerated': 'ENUM', # also need to json
    'color': 'std::string', # also need to json
    'flaglist': 'TODO', # also need to json, basically enum
    'colorscale': 'std::string', # also need to json, basically enum --- could be smarter
}

# if plotly_type == "data_array":
#     pytype = "numpy.ndarray"
# elif plotly_type == "info_array":
#     pytype = "list"
# elif plotly_type == "colorlist":
#     pytype = "list"
# elif plotly_type in ("string", "color", "colorscale", "subplotid"):
#     pytype = "str"
# elif plotly_type in ("enumerated", "flaglist", "any"):
#     pytype = "Any"
# elif plotly_type in ("number", "angle"):
#     pytype = "int|float"
# elif plotly_type == "integer":
#     pytype = "int"
# elif plotly_type == "boolean":
#     pytype = "bool"


def emit_trace(trace):
    print(f"// {trace.description}")
    print(f"class {trace.name} {{")

    for e in trace.enums:
        # hack for name not set on trace yet
        print(f"    enum class {e.name} {{")
        for val in e.vals:
            val_str = str(val) # Some have True, False, others, which gets confused as bools
            if val_str: # why are there empty strings?
                print(f"        {str(val).replace(" ", "_")},")
        print("    };")
        print(f"    std::string to_string({e.name} e) {{")
        print("        switch(e) {")
        for val in e.vals:
            val_str = str(val)
            if val_str: # why are there empty strings?
                print(f'            case {e.name}::{val_str.replace(" ", "_")}: return "{val}";')
        print("        }")
        print("    }")

    for field in trace.fields:
        if field.valType == 'ENUM':
            # TODO: is it allowed to have enum and function with same name?
            print(f"    {trace.name}& {field.name}({field.name} f) {{")
            print(f"        j[\"{field.name}\"] = to_string(f);")
            print("        return *this;")
            print("    }")
        else:
            # print("\n")
            # print(f"    // {field.description}")
            if field.valType == 'T':
                print(f"    template <typename T>")
            print(f"    {trace.name}& {field.name}({field.valType} f) {{")

            print(f"        j[\"{field.name}\"] = std::move(f);")
            print("        return *this;")
            print("    }")



    print("    nlohmann::json j{};")
    print("};")

class Trace:
    def __init__(self):
        self.name = ""
        self.description = ""
        self.fields = []

        self.subtypes = []

        self.enums = []

        # objects
        # enums
        # flagtypes

class Field:
    def __init__(self):
        self.name = ""
        self.description = ""
        self.valType = None

class StringEnum:
    def __init__(self):
        self.name = ""
        self.vals = []


def do_meta(meta, trace):
    print("process meta")
    for key, value in meta.items():
        if key == "description":
            trace.description = value
        # wtf
        elif key != "hr_name" and key != "hrName":
            print(f"Skipping unknown meta attribute {key}. Parser needs updating!")

def do_type(type, trace):
    # just the name again
   trace.name = type


def do_attributes(attributes, trace):
    print("process attributes")
    for key, value in attributes.items():
        #print(key)
        if not isinstance(value, dict):
            # type is just the trace name again
            if key != "type" and key != "editType":
                print(f"Skipping unknown attribute {key}. Parser needs updating!")
        else:
            if key == "_deprecated":
                continue
            # valType for leaf objects, role for sub fields
            if "valType" in value:
                f = Field()
                f.name = key
                f.description = value["description"]

                valtype = value['valType']
                if valtype == 'enumerated':
                    f.valType = valtype_map[valtype]
                    e = StringEnum()
                    e.name = f.name
                    e.vals = value['values']
                    trace.enums.append(e)
                else:
                    f.valType = valtype_map[valtype]
                trace.fields.append(f)

            elif "role" in value:
                pass
            else:
                print("No role or valtype! Parse needs updating!")


            # if "valType" not in value:
            #     print("no valType", key)
            # elif "role" not in value:
            #     print("no role", key)
            # else:
            #     print("no role or valType", key)
            #print(key)
            #print(key, value["valType"])
        #attribute = value



def process_trace(name, data):
    print("process_trace", name)

    trace = Trace()
    for attribute, value in data.items():
        if attribute == "meta":
            do_meta(value, trace)
        elif attribute == "type":
            do_type(value, trace)
        # naming is hard
        elif attribute == "attributes":
            do_attributes(value, trace)
        elif attribute == "animatable" or attribute == "categories" or attribute == "layoutAttributes":
            pass
            #print("Skipping known attribute", attribute)
        else:
            print(f"Skipping unknown attribute {attribute}. Parser needs updating!")

    emit_trace(trace)

def main():
    data = {}
    with open('/Users/jimmyorourke/schema/schema.json') as f:
        data = json.load(f)

    print("--")
    print("traces")
    # for k in data['traces']:
    #     print("\t", k)
    print("traces/scatter")
    for name, trace in data['traces'].items():
        if name == "scatter":
        #     #print(json.dumps(trace, indent=4))
             process_trace(name, trace)
        #process_trace(name, trace)

    valtypes = set()
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


# process attributes
# alignmentgroup
# cliponaxis
# connectgaps
# customdata
# customdatasrc
# dx
# dy
# error_x
# error_y
# fill
# fillcolor
# fillpattern
# groupnorm
# hoverinfo
# hoverinfosrc
# hoverlabel
# hoveron
# hovertemplate
# hovertemplatesrc
# hovertext
# hovertextsrc
# ids
# idssrc
# legend
# legendgroup
# legendgrouptitle
# legendrank
# legendwidth
# line
# marker
# meta
# metasrc
# mode
# name
# offsetgroup
# opacity
# orientation
# selected
# selectedpoints
# showlegend
# stackgaps
# stackgroup
# stream
# text
# textfont
# textposition
# textpositionsrc
# textsrc
# texttemplate
# texttemplatesrc
# transforms
# type
# uid
# uirevision
# unselected
# visible
# x
# x0
# xaxis
# xcalendar
# xhoverformat
# xperiod
# xperiod0
# xperiodalignment
# xsrc
# y
# y0
# yaxis
# ycalendar
# yhoverformat
# yperiod
# yperiod0
# yperiodalignment
# ysrc


if __name__ == '__main__':
    main()
