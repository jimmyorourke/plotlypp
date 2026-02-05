#!/usr/bin/env python3

# Copyright (c) 2025-2026 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

# Formatting: `ruff format --line-length=120`

import os
import json
from pathlib import Path
import subprocess
import sys
from typing import Dict, Any, List, Optional, Tuple, Generator
import dataclasses

VALTYPE_MAP = {
    "number": ["double"],
    "boolean": ["bool"],
    "angle": ["double"],
    "integer": ["int"],
    "subplotid": ["std::string"],
    "string": ["std::string"],
    "any": ["T"],  # can usually be dbl?
    "data_array": ["std::vector<T>"],  # with constraint
    # Prefer overloads to templates in order to support initializer lists. Same is true of std::variant.
    "info_array": [
        "std::vector<double>",
        "std::vector<std::string>",
        "std::vector<std::vector<std::string>>",
        "std::vector<std::vector<double>>",
    ],
    "enumerated": ["ENUM"],
    # Colors can be strings or numbers. The template for proper handling of std::string, const char*,
    # or double gets complicated, as does a vector of std::variant, so just use overloads instead.
    "color": ["std::string", "double"],
    "flaglist": ["std::string"],  # basically enum
    # "A Plotly colorscale either picked by a name: (any of Greys, YlGnBu, Greens, YlOrRd, Bluered, RdBu, Reds, Blues, Picnic, Rainbow, Portland, Jet, Hot, Blackbody, Earth, Electric, Viridis, Cividis ) or customized as an {array} of 2-element {arrays} where the first element is the normalized color level value (starting at *0* and ending at *1*), and the second item is a valid color string.",
    "colorscale": [
        "std::string",
        "std::vector<std::pair<double, std::string>>",
    ],  # also need to json, basically enum --- could be smarter
    # Not really, but it's useful to add here
    "object": ["OBJECT"],
    "colorlist": ["std::vector<std::string>", "std::vector<double>"],
}


class IndentBlock:
    """Context manager for managing indentation in Writer."""

    def __init__(self, writer: "Writer") -> None:
        self.writer = writer

    def __enter__(self) -> None:
        self.writer.indent_level += 1

    def __exit__(self, exc_type: Any, exc_val: Any, exc_tb: Any) -> None:
        self.writer.indent_level -= 1


class Writer:
    """Helper class for writing indented text to a file or stdout."""

    INDENT_SIZE = 4

    def __init__(self, output_file: Optional[Path] = None) -> None:
        self.indent_level: int = 0
        self._output_file: Optional[Path] = output_file
        self._output_file_handle = open(self._output_file, "w") if self._output_file is not None else sys.stdout

    def write(self, line: str) -> None:
        """Outputs input text with a newline at current indent level."""
        indent = " " * self.INDENT_SIZE * self.indent_level
        print(f"{indent}{line}", file=self._output_file_handle)

    def close(self) -> None:
        """Closes the file handle if it's not stdout."""
        if self._output_file is not None and self._output_file_handle is not sys.stdout:
            self._output_file_handle.close()


def emit_json_member(writer: Writer) -> None:
    writer.write("// Advanced users may modify the JSON representation directly, at their own peril!")
    writer.write("Json json{};")


def _get_json_literal(val: Any) -> str:
    """Converts a Python value to its C++/JSON literal representation."""
    if isinstance(val, bool):
        return "true" if val else "false"
    elif isinstance(val, str):
        # Use json.dumps() to produce a valid JSON string representation
        # (e.g., '"string"'), which also works as a correctly escaped
        # C++ string literal for assignment.
        return json.dumps(val)
    elif isinstance(val, (int, float)):
        return str(val)
    else:
        raise TypeError(f"Unsupported enum value type: {type(val)} for {val}")


def emit_array_field_setter_decl(class_object: "Object", field: "Field", output_val_type: str, writer: Writer) -> None:
    if output_val_type == "T":
        writer.write("template <typename T>")
    writer.write(f"{class_object.name.title()}& {field.name}(const std::vector<{output_val_type}>& f);")


def emit_array_field_setter(class_object: "Object", field: "Field", output_val_type: str, writer: Writer) -> None:
    if output_val_type == "T":
        writer.write("template <typename T>")
    writer.write(
        f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(const std::vector<{output_val_type}>& f) {{"
    )
    with IndentBlock(writer):
        if field.object_definition:
            writer.write("std::vector<Json> jsonified(f.size());")
            writer.write("std::transform(f.begin(), f.end(), jsonified.begin(), [](auto& e){ return e.json; });")
            writer.write(f'json["{field.name}"] = std::move(jsonified);')
        else:
            writer.write(f'json["{field.name}"] = f;')
        writer.write("return *this;")
    writer.write("}")


def emit_lambda_setter_decl(
    class_object: "Object", field: "Field", output_val_types: List[str], writer: Writer
) -> None:
    enable_if_cond = " || ".join([f"std::is_invocable_v<Callable, {t}&>" for t in output_val_types])

    if "T" in output_val_types:
        writer.write(f"template <typename T, typename Callable, typename=std::enable_if_t<{enable_if_cond}>>")
    elif field.json_val_type == "data_array":
        writer.write(
            f"template <typename T, typename Callable, typename=std::enable_if_t<is_data_array_element_v<T> && ({enable_if_cond})>>"
        )
    else:
        writer.write(f"template <typename Callable, typename=std::enable_if_t<{enable_if_cond}>>")
    writer.write(f"{class_object.name.title()}& {field.name}(Callable&& c);")
    if field.is_subplot_object:
        # Add an index-first overload. Putting the index last we could default it and not need an overload but that
        # makes it less readable and less consistent with plotly.js.
        if "T" in output_val_types:
            writer.write(f"template <typename T, typename Callable, typename=std::enable_if_t<{enable_if_cond}>>")
        elif field.json_val_type == "data_array":
            writer.write(
                f"template <typename T, typename Callable, typename=std::enable_if_t<is_data_array_element_v<T> && ({enable_if_cond})>>"
            )
        else:
            writer.write(f"template <typename Callable, typename=std::enable_if_t<{enable_if_cond}>>")
        writer.write(f"{class_object.name.title()}& {field.name}(int index, Callable&& c);")


def emit_field_setter_decl(class_object: "Object", field: "Field", output_val_type: str, writer: Writer) -> None:
    def write_template_signature():
        if output_val_type == "T":
            writer.write("template <typename T>")

    vec_type = "std::vector" in output_val_type

    if field.json_val_type == "data_array":
        writer.write("template <typename Range, typename = std::enable_if_t<is_data_array_v<Range>>>")
        writer.write(f"{class_object.name.title()}& {field.name}(Range&& f);")
    else:
        write_template_signature()
        if vec_type:
            # nlohmann json can't uses a const ref to_json for container types
            writer.write(f"{class_object.name.title()}& {field.name}(const {output_val_type}& f);")
        else:
            writer.write(f"{class_object.name.title()}& {field.name}({output_val_type} f);")

    if field.is_subplot_object:
        # Add an index-first overload. Putting the index last we could default it and not need an overload but that
        # makes it less readable and less consistent with plotly.js.
        if field.json_val_type == "data_array":
            writer.write("template <typename Range, typename = std::enable_if_t<is_data_array_v<Range>>>")
            writer.write(f"{class_object.name.title()}& {field.name}(int index, Range&& f);")
        else:
            write_template_signature()
            if vec_type:
                writer.write(f"{class_object.name.title()}& {field.name}(int index, const {output_val_type}& f);")
            else:
                writer.write(f"{class_object.name.title()}& {field.name}(int index, {output_val_type} f);")


def emit_field_setter(class_object: "Object", field: "Field", output_val_type: str, writer: Writer) -> None:
    def write_template_signature():
        if output_val_type == "T":
            writer.write("template <typename T>")

    vec_type = "std::vector" in output_val_type

    if field.json_val_type == "data_array":
        writer.write("template <typename Range, typename>")
        writer.write(f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(Range&& f) {{")
    else:
        write_template_signature()
        if vec_type:
            writer.write(
                f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(const {output_val_type}& f) {{"
            )
        else:
            writer.write(
                f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}({output_val_type} f) {{"
            )
    with IndentBlock(writer):
        if field.object_definition:
            writer.write(f'json["{field.name}"] = std::move(f.json);')
        else:
            writer.write(f'json["{field.name}"] = ' + ("f" if vec_type else "std::move(f)") + ";")
        writer.write("return *this;")
    writer.write("}")

    if field.is_subplot_object:
        # Add an index-first overload. Putting the index last we could default it and not need an overload but that
        # makes it less readable and less consistent with plotly.js.
        if field.json_val_type == "data_array":
            writer.write("template <typename Range, typename>")
            writer.write(
                f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(int index, Range&& f) {{"
            )
        else:
            write_template_signature()
            if vec_type:
                writer.write(
                    f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(int index, const {output_val_type}& f) {{"
                )
            else:
                writer.write(
                    f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(int index, {output_val_type} f) {{"
                )
        with IndentBlock(writer):
            # Hmm
            writer.write(f'const auto key = std::string("{field.name}") + (index > 1 ? std::to_string(index) : "");')
            if field.object_definition:
                writer.write(f"json[key] = std::move(f.json);")
            else:
                writer.write(f"json[key] = " + ("f" if vec_type else "std::move(f)") + ";")
            writer.write("return *this;")
        writer.write("}")


def emit_lambda_setter(class_object: "Object", field: "Field", output_val_types: List[str], writer: Writer) -> None:
    if "T" in output_val_types or field.json_val_type == "data_array":
        writer.write("template <typename T, typename Callable, typename>")
    else:
        writer.write("template <typename Callable, typename>")
    writer.write(f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(Callable&& c) {{")
    with IndentBlock(writer):
        writer.write(f"{output_val_types[0]} f{{}};")
        writer.write("std::forward<Callable>(c)(f);")
        writer.write(f"return {field.name}(std::move(f));")
    writer.write("}")
    if field.is_subplot_object:
        if "T" in output_val_types or field.json_val_type == "data_array":
            writer.write("template <typename T, typename Callable, typename>")
        else:
            writer.write("template <typename Callable, typename>")
        writer.write(
            f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(int index, Callable&& c) {{"
        )
        with IndentBlock(writer):
            writer.write(f"{output_val_types[0]} f{{}};")
            writer.write("std::forward<Callable>(c)(f);")
            writer.write(f"return {field.name}(index, std::move(f));")
        writer.write("}")


def emit_enum_field_setter_decl(class_object: "Object", field: "Field", writer: Writer) -> None:
    # To help compiler ambiguity, add enum keyword.
    writer.write(f"{class_object.name.title()}& {field.name}(enum {field.name.title()} f);")


def emit_enum_field_setter(class_object: "Object", field: "Field", writer: Writer) -> None:
    # To help compiler ambiguity, add enum keyword.
    writer.write(
        f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(enum {field.name.title()} f) {{"
    )
    with IndentBlock(writer):
        # For enums, we cannot rely on a simple to_string() function because
        # enumerated values in the Plotly schema can be strings, booleans, or numbers
        # (e.g., `false`, 'all', 0). Therefore, we generate a switch statement
        # to serialize each enum member to the correct JSON type.
        writer.write("switch(f) {")
        with IndentBlock(writer):
            for safe_val, json_val in field.enum_definition.safe_to_json_vals.items():
                val_repr = _get_json_literal(json_val)
                writer.write(f'case {field.name.title()}::{safe_val}: json["{field.name}"] = {val_repr}; break;')
        writer.write("}")
        writer.write("return *this;")
    writer.write("}")


def emit_enum_array_field_setter_decl(class_object: "Object", field: "Field", writer: Writer) -> None:
    writer.write(f"{class_object.name.title()}& {field.name}(const std::vector<enum {field.name.title()}>& f);")


def emit_enum_array_field_setter(class_object: "Object", field: "Field", writer: Writer) -> None:
    writer.write(
        f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(const std::vector<enum {field.name.title()}>& f) {{"
    )
    with IndentBlock(writer):
        writer.write("Json arr = Json::array();")
        writer.write("for(const auto& e : f) {")
        with IndentBlock(writer):
            # For enums, we cannot rely on a simple to_string() function because
            # enumerated values in the Plotly schema can be strings, booleans, or numbers
            # (e.g., `false`, 'all', 0). Therefore, we generate a switch statement
            # to serialize each enum member to the correct JSON type.
            writer.write("switch(e) {")
            with IndentBlock(writer):
                for safe_val, json_val in field.enum_definition.safe_to_json_vals.items():
                    val_repr = _get_json_literal(json_val)
                    writer.write(f"case {field.name.title()}::{safe_val}: arr.push_back({val_repr}); break;")
            writer.write("}")
        writer.write("}")
        writer.write(f'json["{field.name}"] = std::move(arr);')
        writer.write("return *this;")
    writer.write("}")


def emit_enum_definition(enum: "StringEnum", writer: Writer) -> None:
    writer.write("")
    writer.write(f"enum class {enum.name.title()} {{")
    with IndentBlock(writer):
        for safe_val in enum.safe_to_json_vals:
            writer.write(f"{safe_val},")
    writer.write("};")


def emit_enum_to_string_decl(enum: "StringEnum", writer: Writer) -> None:
    # No-op: As enums can represent different types (bool, str, int),
    # serialization is now handled in setters via switch statements,
    # and a single to_string() function is no longer generated for enums.
    pass


def emit_enum_to_string(class_object: "Object", enum: "StringEnum", writer: Writer) -> None:
    # No-op: As enums can represent different types (bool, str, int),
    # serialization is now handled in setters via switch statements,
    # and a single to_string() function is no longer generated for enums.
    pass


def emit_flaglist_definition(fl: "FlagList", writer: Writer) -> None:
    writer.write("")
    writer.write(f"enum class {fl.name.title()} {{")
    with IndentBlock(writer):
        for safe_val in fl.safe_flags:
            writer.write(f"{safe_val},")
    writer.write("};")
    if fl.safe_extras:
        writer.write(f"enum class {fl.name.title()}Extra {{")
        with IndentBlock(writer):
            for safe_val in fl.safe_extras:
                writer.write(f"{safe_val},")
        writer.write("};")


def emit_flaglist_to_string_decls(fl: "FlagList", writer: Writer) -> None:
    writer.write(f"static std::string to_string({fl.name.title()} e);")
    if fl.safe_extras:
        writer.write(f"static std::string to_string({fl.name.title()}Extra e);")


def emit_flaglist_setter_decls(class_object: "Object", field: "Field", writer: Writer) -> None:
    writer.write(f"{class_object.name.title()}& {field.name}(std::initializer_list<{field.name.title()}> flags);")
    if field.flaglist and field.flaglist.safe_extras:
        writer.write(f"{class_object.name.title()}& {field.name}({field.name.title()}Extra extra);")


def emit_flaglist_to_string_impls(class_object: "Object", fl: "FlagList", writer: Writer) -> None:
    # Unlike enums, flaglist values ('flags' and 'extras') are always
    # serialized as strings in Plotly, so a to_string method is appropriate.
    writer.write(f"inline std::string {class_object.name.title()}::to_string({fl.name.title()} e) {{")
    with IndentBlock(writer):
        writer.write("switch(e) {")
        with IndentBlock(writer):
            for s, j in fl.safe_flags.items():
                writer.write(f'case {fl.name.title()}::{s}: return "{j}";')
        writer.write("}")
        writer.write('throw std::invalid_argument{"Unknown flag value for ' + fl.name + '."};')
    writer.write("}")
    if fl.safe_extras:
        writer.write(f"inline std::string {class_object.name.title()}::to_string({fl.name.title()}Extra e) {{")
        with IndentBlock(writer):
            writer.write("switch(e) {")
            with IndentBlock(writer):
                for s, j in fl.safe_extras.items():
                    writer.write(f'case {fl.name.title()}Extra::{s}: return "{j}";')
            writer.write("}")
            writer.write('throw std::invalid_argument{"Unknown extra value for ' + fl.name + '."};')
        writer.write("}")


def emit_flaglist_setter_impls(class_object: "Object", field: "Field", writer: Writer) -> None:
    writer.write(
        f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}(std::initializer_list<{field.name.title()}> flags) {{"
    )
    with IndentBlock(writer):
        writer.write(f'json["{field.name}"] = detail::joinFlaglist(flags, [](auto f){{ return to_string(f); }});')
        writer.write("return *this;")
    writer.write("}")
    if field.flaglist and field.flaglist.safe_extras:
        writer.write(
            f"inline {class_object.name.title()}& {class_object.name.title()}::{field.name}({field.name.title()}Extra extra) {{"
        )
        with IndentBlock(writer):
            writer.write(f'json["{field.name}"] = to_string(extra);')
            writer.write("return *this;")
        writer.write("}")


def emit_class_public_members(class_object: "Object", writer: Writer) -> None:
    for field in class_object.fields:
        if field.enum_definition:
            emit_enum_to_string(class_object, field.enum_definition, writer)
        if field.flaglist:
            emit_flaglist_to_string_impls(class_object, field.flaglist, writer)

    writer.write("")

    for field in class_object.fields:
        if field.enum_definition:
            emit_enum_field_setter(class_object, field, writer)
            if field.array_ok:
                emit_enum_array_field_setter(class_object, field, writer)
        elif field.flaglist:
            emit_flaglist_setter_impls(class_object, field, writer)
        else:
            if field.object_definition:
                object_type = field.object_type_name if field.object_type_name else field.name
                output_val_types = [f"{object_type.title()}"]
            else:
                output_val_types = VALTYPE_MAP[field.json_val_type]
            if not (field.object_definition and field.array_ok):
                for output_val_type_overload in output_val_types:
                    emit_field_setter(class_object, field, output_val_type_overload, writer)
                if field.object_definition:
                    # Lambda setter is only generated for non-array objects.
                    emit_lambda_setter(class_object, field, output_val_types, writer)
            if field.array_ok:
                for output_val_type_overload in output_val_types:
                    emit_array_field_setter(class_object, field, output_val_type_overload, writer)

        writer.write("")


def emit_class_public_members_decl(class_object: "Object", writer: Writer) -> None:
    for field in class_object.fields:
        if field.enum_definition:
            emit_enum_definition(field.enum_definition, writer)
            emit_enum_to_string_decl(field.enum_definition, writer)
        if field.flaglist:
            emit_flaglist_definition(field.flaglist, writer)
            emit_flaglist_to_string_decls(field.flaglist, writer)

    writer.write("")
    for field in class_object.fields:
        if field.object_definition:
            emit_forward_object_decl(field.object_definition, writer)

    writer.write("")
    for field in class_object.fields:
        if field.description:
            lines = field.description.split("\n")
            # Dumb hack for clang-format not respecting existing newlines in comments.
            writer.write(f"// {lines[0]}")
            for line in lines[1:]:
                writer.write(f"// - {line}")
        if field.enum_definition:
            emit_enum_field_setter_decl(class_object, field, writer)
            if field.array_ok:
                emit_enum_array_field_setter_decl(class_object, field, writer)
        elif field.flaglist:
            emit_flaglist_setter_decls(class_object, field, writer)
        else:
            if field.object_definition:
                field_type = field.object_type_name if field.object_type_name else field.name
                output_val_types = [f"{field_type.title()}"]
            else:
                output_val_types = VALTYPE_MAP[field.json_val_type]
            if not (field.object_definition and field.array_ok):
                for output_val_type_overload in output_val_types:
                    emit_field_setter_decl(class_object, field, output_val_type_overload, writer)
                if field.object_definition:
                    emit_lambda_setter_decl(class_object, field, output_val_types, writer)
            if field.array_ok:
                for output_val_type_overload in output_val_types:
                    emit_array_field_setter_decl(class_object, field, output_val_type_overload, writer)

        writer.write("")


def emit_forward_object_decl(class_object: "Object", writer: Writer) -> None:
    if class_object.description:
        writer.write(f"// {class_object.description}")
    writer.write(f"class {class_object.name.split('::')[-1].title()};")


def emit_default_constructor(class_object: "Object", writer: Writer) -> None:
    writer.write(f"{class_object.name.split('::')[-1].title()}() = default;")


def emit_json_constructor(class_object: "Object", writer: Writer) -> None:
    # Converting constructor
    writer.write(f"{class_object.name.split('::')[-1].title()}(std::string jsonStr)")
    # https://json.nlohmann.me/home/faq/#brace-initialization-yields-arrays
    writer.write(": json(parse(std::move(jsonStr))) {}")


def emit_object_decl(class_object: "Object", writer: Writer) -> None:
    if class_object.description:
        writer.write(f"// {class_object.description}")
    writer.write(f"class {class_object.name.title()} {{")
    writer.write("public:")
    with IndentBlock(writer):
        emit_default_constructor(class_object, writer)
        emit_json_constructor(class_object, writer)
        emit_class_public_members_decl(class_object, writer)
        emit_json_member(writer)
    writer.write("};")
    writer.write("")


def unnest_objects(parent: "Object", unnested_objects: List["Object"]) -> None:
    for field in parent.fields:
        if field.object_definition:
            obj = field.object_definition
            obj.name = f"{parent.name}::{obj.name.capitalize()}"
            unnested_objects.append(obj)
            unnest_objects(obj, unnested_objects)


def emit_preamble(writer: Writer) -> None:
    writer.write("// Copyright (c) 2025-2026 Jimmy O'Rourke")
    writer.write("// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.")
    writer.write("// Official repository: https://github.com/jimmyorourke/plotlypp")
    writer.write("")
    writer.write("// Autogenerated by plotlypp/generator, from official Plotly sources.")
    writer.write("// See https://plotly.com/graphing-libraries.")
    writer.write("// Do not edit, changes may be overwritten!")
    writer.write("")
    writer.write("#pragma once")
    writer.write("")


def emit_trace(trace: "Object", out_dir: Path, impl_subdir: Path) -> None:
    """Emits C++ header and implementation files for a given trace."""
    out_file = out_dir / f"{trace.name}.hpp"
    writer = Writer(out_file)

    emit_preamble(writer)

    writer.write("#include <initializer_list>")
    writer.write("#include <string>")
    writer.write("#include <utility>")
    writer.write("#include <vector>")
    writer.write("#include <type_traits>")
    writer.write("")
    writer.write("#include <plotlypp/json.hpp>")
    writer.write("#include <plotlypp/trace.hpp>")
    writer.write("#include <plotlypp/traits.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    # Special case the outermost trace object to handle the 'type' field
    writer.write(f"class {trace.name.title()} : public Trace {{")
    writer.write("public:")
    with IndentBlock(writer):
        writer.write(f"{trace.name.title()}() : Trace() {{")
        with IndentBlock(writer):
            writer.write(f'json["type"] = "{trace.name}";')
        writer.write("}")
        # Converting constructor
        writer.write(f"{trace.name.split('::')[-1].title()}(std::string jsonStr)")
        writer.write(": Trace(std::move(jsonStr)) {}")
        emit_class_public_members_decl(trace, writer)
    writer.write("};")
    writer.write("")

    unnested_objects = []
    unnest_objects(trace, unnested_objects)
    for obj in unnested_objects:
        emit_object_decl(obj, writer)

    writer.write("} // namespace plotlypp")
    writer.write("")
    writer.write(f'#include "{impl_subdir}/{trace.name}_impl.hpp"')
    writer.write("")
    writer.close()

    writer = Writer(out_dir / impl_subdir / f"{trace.name}_impl.hpp")
    emit_preamble(writer)
    writer.write("#include <plotlypp/detail/flaglist_helpers.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    emit_class_public_members(trace, writer)
    for obj in unnested_objects:
        emit_class_public_members(obj, writer)
    writer.write("} // namespace plotlypp")
    writer.write("")
    writer.close()


@dataclasses.dataclass
class Object:
    """Represents a Plotly object node in the schema."""

    name: str = ""
    description: str = ""
    fields: List["Field"] = dataclasses.field(default_factory=list)


@dataclasses.dataclass
class Field:
    """Represents a field within a Plotly object."""

    name: str  # name vs JSON name for CamelCase classes?
    description: str = ""
    json_val_type: Optional[str] = None
    array_ok: bool = False
    enum_definition: Optional["StringEnum"] = None
    flaglist: Optional["FlagList"] = None
    object_definition: Optional["Object"] = None
    is_subplot_object: bool = False
    object_type_name: Optional[str] = None


@dataclasses.dataclass
class FlagList:
    """Represents a flaglist type with combinable flags and standalone extras."""

    name: str = ""
    safe_flags: Dict[str, str] = dataclasses.field(default_factory=dict)
    safe_extras: Dict[str, str] = dataclasses.field(default_factory=dict)


@dataclasses.dataclass
class StringEnum:
    """Represents an enumerated type with string values in JSON."""

    name: str = ""
    safe_to_json_vals: Dict[str, str] = dataclasses.field(default_factory=dict)


# Translate enum symbol strings to valid name identifiers
JSON_SYMBOL_NAME_MAP = {
    "": "Empty",
    "=": "Eq",
    ">": "Gt",
    "-": "Hyphen",
    "<": "Lt",
    "|": "Or",
    "/": "Slash",
    "\\": "Doublebackslash",  # Warning! Needs special escaping.
    "^": "Cape",
    "(": "Lpar",
    ")": "Rpar",
    "[": "Lbracket",
    "]": "Rbracket",
    "+": "Plus",
    "?": "Question",
    "$": "Dollar",
    ".": "Dot",
}


def safe_field_name(name: str) -> str:
    """Filter reserved keywords"""
    if name == "template":
        return "plotly_template"
    return name


def looks_like_regex(name: str) -> bool:
    """Checks if a string looks like it contains regex characters.
    This is a heuristic used to skip enum generation for plotly values that
    are regexes, like '/^x([2-9]|[1-9][0-9]+)?$/'"""
    regex_chars = {"^", "(", ")", "[", "]", "*", "$", "+"}
    for c in name:
        if c in regex_chars:
            return True
    return False


def _clean_enum_value(val: Any) -> Tuple[str, Any]:
    """Cleans a schema enum value (e.g. 'foo', '-', false, 1) to be a valid C++
    identifier, returning the safe identifier and the original value for serialization."""
    json_val = val
    safe_val = str(val)

    # Some are invalid symbols
    if safe_val in JSON_SYMBOL_NAME_MAP:
        safe_val = JSON_SYMBOL_NAME_MAP[safe_val]

    # To avoid keyword conflicts, and for style, use upper case. Avoid uppercase due to macro conflicts.
    safe_val = safe_val.title()
    # Some names have spaces! Remove spaces, since we should be in Pascale case style now.
    safe_val = safe_val.replace(" ", "")
    # Some have hypens which are invalid. Note this has to be done after symbol mapping!
    safe_val = safe_val.replace("-", "")
    # Some are empty strings (crazy!).
    if safe_val == "":
        safe_val = "Empty"

    # Some are numbers which invalid enum identifiers. Enumerators can't start with a digit.
    if safe_val[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
        safe_val = "Num_" + safe_val
    return safe_val, json_val


def _parse_enumerated_attribute(f: "Field", node: Dict[str, Any]) -> None:
    """Parses an enumerated attribute, creating an enum if necessary."""
    # Some "enums" have regex enumerators. These can't be statically defined so treat them as strings.
    for val in node["values"]:
        if looks_like_regex(str(val)):
            # print("set as string")
            f.json_val_type = "string"
            return

    # Also create an enum which will be associated with the parent trace.
    e = StringEnum()
    e.name = f.name
    e.description = f.description

    if "dflt" in node:
        f.description += f"\nDefault: {node['dflt']}"

    for val in node["values"]:
        # Some enums contain "True" of "False" which get mistakenly parse to Python bools.
        safe_val, json_val = _clean_enum_value(val)
        # The map also handles the uniqueness requirement.
        e.safe_to_json_vals[safe_val] = json_val

    f.enum_definition = e


def _parse_flaglist_attribute(f: "Field", node: Dict[str, Any]) -> None:
    """Parses a flaglist attribute, creating a FlagList object."""
    fl = FlagList(name=f.name)
    for flag_val in node.get("flags", []):
        safe_val, json_val = _clean_enum_value(flag_val)
        fl.safe_flags[safe_val] = json_val
    for extra_val in node.get("extras", []):
        safe_val, json_val = _clean_enum_value(extra_val)
        fl.safe_extras[safe_val] = json_val
    f.flaglist = fl


def parse_attributes(parent: "Object", attributes_node: Dict[str, Any]) -> None:
    """Parses attributes from a schema node into Fields, Enums, or nested Objects."""
    for name, node in attributes_node.items():
        if name == "_deprecated":
            continue

        # TODO: check contour impliedEdits autocontour
        if not (isinstance(node, dict) and ("role" in node or "valType" in node)):
            continue

        # Every node is a field that can be set.
        f = Field(safe_field_name(name))

        # objects don't have description. Some random valType nodes also don't
        if "description" in node:
            f.description = node["description"]

        if node.get("_isSubplotObj", False):
            # print(name)
            f.is_subplot_object = True

        if "role" in node and node["role"] == "object":
            #  Nested structure.
            obj = Object()
            f.object_definition = obj
            if "arrayOk" in node and node["arrayOk"] == True:
                f.array_ok = True

            obj.name = f.name
            obj.description = f.description

            # For some reason, "arrayOk" is not set on arrays of objects.
            is_array_of_objects = "items" in node and node["items"] and len(node["items"]) > 0
            if is_array_of_objects:
                f.array_ok = True
                item_name = list(node["items"].keys())[0]
                item_node = node["items"][item_name]
                obj.name = item_name
                f.object_type_name = item_name
                parse_attributes(obj, item_node)
            else:
                parse_attributes(obj, node)

        elif "valType" in node:
            f.json_val_type = node["valType"]
            # f.val_type = valtype_map[f.json_val_type]

            if "arrayOk" in node and node["arrayOk"] == True:
                f.array_ok = True

            if f.json_val_type == "enumerated":
                _parse_enumerated_attribute(f, node)
            elif f.json_val_type == "flaglist":
                _parse_flaglist_attribute(f, node)
                if "dflt" in node:
                    f.description += f"\nDefault: {node['dflt']}"
                f.description += f"\nFlags: {node['flags']}"
                if "extras" in node:
                    f.description += f"\nExtras {node['extras']}"

        parent.fields.append(f)


def parse_type(trace: "Object", type_node: str) -> None:
    # Just the name again
    assert trace.name == type_node


def parse_meta(trace: "Object", meta_node: Dict[str, Any]) -> None:
    for name, node in meta_node.items():
        if name == "description":
            trace.description = node
        elif name == "hr_name" or name == "hrName":
            pass
        else:
            print(f"Skipping unknown meta field {name}. Does parser needs updating?")


def create_trace(name: str, trace_node: Dict[str, Any]) -> None:
    """Creates and emits a trace object from a schema node."""
    print("Parsing trace", name)

    trace = Object()
    trace.name = name  # TODO: convert case

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
            print(f"Skipping unknown attribute field {node_name}. Does parser needs updating?")

    # emit_trace(trace)
    # print_obj_structure(trace)
    top_level_src_dir = Path(__file__).parent.parent / "include" / "plotlypp"
    traces_dir = top_level_src_dir / "traces"
    impl_subdir = Path("impl")
    os.makedirs(traces_dir / impl_subdir, exist_ok=True)
    emit_trace(trace, traces_dir, impl_subdir)
    # We did our best with formatting, but let's auto format to catch long comments, etc.
    subprocess.run(["clang-format", "--style=file", "-i", str(traces_dir / f"{trace.name}.hpp")], check=True)


def create_traces(schema: Dict[str, Any]) -> None:
    for name, trace_node in schema["traces"].items():
        create_trace(name, trace_node)


def package_js() -> None:
    """Reads plotly.min.js and embeds it in a C++ header as a raw string."""
    with open(Path(__file__).parent / "plotly.min.js") as f:
        plotly_js = f.read()

    writer = Writer(Path(__file__).parent.parent / "include" / "plotlypp" / "plotly_min_js.hpp")
    emit_preamble(writer)
    writer.write("#include <plotlypp/warnings.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    writer.write("PLOTLYPP_DISABLE_WARNING_PUSH")
    writer.write("PLOTLYPP_DISABLE_WARNING_OVERLENGTH_STRINGS")
    writer.write("")
    writer.write("// Note: constexpr string_view excessively bloats compile times due to length counts.")
    writer.write(
        "// Note: Plotly JS is chunked into multiple raw string literals to support MSVC limits, and 0x1a characters are escaped to avoid MSVC trating them as EOF."
    )
    writer.write("inline constexpr const char* const plotlyJS = ")
    chunk_size = 4096  # Under MSVC limit of 65535

    def find_safe_delimiter(chunk: str) -> str:
        i = 0
        while True:
            delim = "d" + str(i)
            if f'){delim}"' not in chunk:
                return delim
            i + 1

    # Split by 0x1A byte
    segments = plotly_js.split("\x1a")

    for i, segment in enumerate(segments):
        if segment:
            for j in range(0, len(segment), chunk_size):
                chunk = segment[j : j + chunk_size]
                delimiter = find_safe_delimiter(chunk)
                writer.write(f'R"{delimiter}({chunk}){delimiter}"')
        # Add the escaped byte between segments
        if i < len(segments) - 1:
            writer.write('"\\x1a"')
    writer.write(";")
    writer.write("")
    writer.write("PLOTLYPP_DISABLE_WARNING_POP")
    writer.write("")
    writer.write("} // namespace plotlypp")
    writer.close()


def emit_layout(layout: "Object", out_dir: Path, impl_subdir: Path) -> None:
    """Emits C++ header and implementation files for the layout object."""
    out_file = out_dir / f"{layout.name}.hpp"
    writer = Writer(out_file)

    emit_preamble(writer)

    writer.write("#include <initializer_list>")
    writer.write("#include <string>")
    writer.write("#include <type_traits>")
    writer.write("#include <utility>")
    writer.write("#include <vector>")
    writer.write("")
    writer.write("#include <plotlypp/json.hpp>")
    writer.write("#include <plotlypp/traits.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")

    emit_object_decl(layout, writer)

    unnested_objects = []
    unnest_objects(layout, unnested_objects)
    for obj in unnested_objects:
        emit_object_decl(obj, writer)

    writer.write("} // namespace plotlypp")
    writer.write("")
    writer.write(f'#include "{impl_subdir}/{layout.name}_impl.hpp"')
    writer.write("")
    writer.close()

    writer = Writer(out_dir / impl_subdir / f"{layout.name}_impl.hpp")
    emit_preamble(writer)
    writer.write("#include <plotlypp/detail/flaglist_helpers.hpp>")
    writer.write("")
    writer.write("namespace plotlypp {")
    writer.write("")
    emit_class_public_members(layout, writer)
    for obj in unnested_objects:
        emit_class_public_members(obj, writer)
    writer.write("} // namespace plotlypp")
    writer.write("")
    writer.close()


def collect_layout_attributes(schema: Dict[str, Any]) -> Dict[str, Any]:
    """Merges layoutAttributes from schema.layout and schema.traces."""
    attributes = schema["layout"]["layoutAttributes"].copy()
    for trace in schema["traces"].values():
        if "layoutAttributes" in trace:
            attributes.update(trace["layoutAttributes"])
    return attributes


def create_layout(layout_attributes_node: Dict[str, Any]) -> None:
    """Creates and emits the layout object from a schema node."""
    layout = Object()
    layout.name = "layout"
    print("Parsing layout")

    parse_attributes(layout, layout_attributes_node)

    top_level_src_dir = Path(__file__).parent.parent / "include" / "plotlypp"
    layout_dir = top_level_src_dir / "layout"
    impl_subdir = Path("impl")
    os.makedirs(layout_dir / impl_subdir, exist_ok=True)

    emit_layout(layout, layout_dir, impl_subdir)
    # We did our best with formatting, but let's auto format to catch long comments, etc.
    subprocess.run(["clang-format", "--style=file", "-i", str(layout_dir / f"{layout.name}.hpp")], check=True)


def main() -> None:
    """Main function to parse schema and generate C++ files."""
    schema = {}
    with open(Path(__file__).parent / "schema.json") as f:
        schema = json.load(f)

    # Consider handling versions?

    create_traces(schema)
    layout_attributes = collect_layout_attributes(schema)
    create_layout(layout_attributes)

    package_js()


if __name__ == "__main__":
    main()
