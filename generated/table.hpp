// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <json.hpp>

namespace plotlypp {

class Table : public Trace {
 public:
    Table()
    : Trace() {
        json["type"] = "table";
    }

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    static std::string to_string(Visible e);

    class Cells;
    class Domain;
    class Header;
    class Hoverlabel;
    class Legendgrouptitle;
    class Stream;

    Table& cells(class Cells f);

    // Specifies the rendered order of the data columns; for example, a value `2` at position `0` means that column
    // index `0` in the data will be rendered as the third column, as columns have an index base of zero.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table& columnorder(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `columnorder`.
    Table& columnordersrc(std::string f);

    // The width of columns expressed as a ratio. Columns fill the available width in proportion of their specified
    // column widths.
    Table& columnwidth(double f);
    Table& columnwidth(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `columnwidth`.
    Table& columnwidthsrc(std::string f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Table& customdatasrc(std::string f);

    Table& domain(class Domain f);

    Table& header(class Header f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Table& hoverinfo(std::string f);
    Table& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Table& hoverinfosrc(std::string f);

    Table& hoverlabel(class Hoverlabel f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Table& idssrc(std::string f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Table& legend(std::string f);

    Table& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Table& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Table& legendwidth(double f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Table& meta(T f);
    template <typename T>
    Table& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Table& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Table& name(std::string f);

    Table& stream(class Stream f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Table& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Table& uirevision(T f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Table& visible(enum Visible f);
};

class Table::Cells {
 public:

    enum class Align {
        LEFT,
        CENTER,
        RIGHT,
    };
    static std::string to_string(Align e);

    class Fill;
    class Font;
    class Line;

    // Sets the horizontal alignment of the `text` within the box. Has an effect only if `text` spans two or more lines
    // (i.e. `text` contains one or more <br> HTML tags) or if an explicit width is set to override the text width.
    // - Default: center
    Table::Cells& align(enum Align f);
    Table::Cells& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Table::Cells& alignsrc(std::string f);

    Table::Cells& fill(class Fill f);

    Table::Cells& font(class Font f);

    // Sets the cell value formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table::Cells& format(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `format`.
    Table::Cells& formatsrc(std::string f);

    // The height of cells.
    Table::Cells& height(double f);

    Table::Cells& line(class Line f);

    // Prefix for cell values.
    Table::Cells& prefix(std::string f);
    Table::Cells& prefix(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `prefix`.
    Table::Cells& prefixsrc(std::string f);

    // Suffix for cell values.
    Table::Cells& suffix(std::string f);
    Table::Cells& suffix(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `suffix`.
    Table::Cells& suffixsrc(std::string f);

    // Cell values. `values[m][n]` represents the value of the `n`th point in column `m`, therefore the `values[m]`
    // vector length for all columns must be the same (longer vectors will be truncated). Each value must be a finite
    // number or a string.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table::Cells& values(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `values`.
    Table::Cells& valuessrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Cells::Fill {
 public:

    // Sets the cell fill color. It accepts either a specific color or an array of colors or a 2D array of colors.
    Table::Cells::Fill& color(std::string f);
    Table::Cells::Fill& color(double f);
    Table::Cells::Fill& color(std::vector<std::string> f);
    Table::Cells::Fill& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Cells::Fill& colorsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Cells::Font {
 public:

    enum class Style {
        NORMAL,
        ITALIC,
    };
    static std::string to_string(Style e);

    enum class Textcase {
        NORMAL,
        WORD_CAPS,
        UPPER,
        LOWER,
    };
    static std::string to_string(Textcase e);

    enum class Variant {
        NORMAL,
        SMALL_CAPS,
        ALL_SMALL_CAPS,
        ALL_PETITE_CAPS,
        PETITE_CAPS,
        UNICASE,
    };
    static std::string to_string(Variant e);

    Table::Cells::Font& color(std::string f);
    Table::Cells::Font& color(double f);
    Table::Cells::Font& color(std::vector<std::string> f);
    Table::Cells::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Cells::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Table::Cells::Font& family(std::string f);
    Table::Cells::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Table::Cells::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Table::Cells::Font& lineposition(std::string f);
    Table::Cells::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Table::Cells::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Table::Cells::Font& shadow(std::string f);
    Table::Cells::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Table::Cells::Font& shadowsrc(std::string f);

    Table::Cells::Font& size(double f);
    Table::Cells::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Table::Cells::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Table::Cells::Font& style(enum Style f);
    Table::Cells::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Table::Cells::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Table::Cells::Font& textcase(enum Textcase f);
    Table::Cells::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Table::Cells::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Table::Cells::Font& variant(enum Variant f);
    Table::Cells::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Table::Cells::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Table::Cells::Font& weight(int f);
    Table::Cells::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Table::Cells::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Cells::Line {
 public:

    Table::Cells::Line& color(std::string f);
    Table::Cells::Line& color(double f);
    Table::Cells::Line& color(std::vector<std::string> f);
    Table::Cells::Line& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Cells::Line& colorsrc(std::string f);

    Table::Cells::Line& width(double f);
    Table::Cells::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Table::Cells::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Domain {
 public:

    // If there is a layout grid, use the domain for this column in the grid for this table trace .
    Table::Domain& column(int f);

    // If there is a layout grid, use the domain for this row in the grid for this table trace .
    Table::Domain& row(int f);

    // Sets the horizontal domain of this table trace (in plot fraction).
    Table::Domain& x(std::vector<std::string> f);

    // Sets the vertical domain of this table trace (in plot fraction).
    Table::Domain& y(std::vector<std::string> f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Header {
 public:

    enum class Align {
        LEFT,
        CENTER,
        RIGHT,
    };
    static std::string to_string(Align e);

    class Fill;
    class Font;
    class Line;

    // Sets the horizontal alignment of the `text` within the box. Has an effect only if `text` spans two or more lines
    // (i.e. `text` contains one or more <br> HTML tags) or if an explicit width is set to override the text width.
    // - Default: center
    Table::Header& align(enum Align f);
    Table::Header& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Table::Header& alignsrc(std::string f);

    Table::Header& fill(class Fill f);

    Table::Header& font(class Font f);

    // Sets the cell value formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table::Header& format(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `format`.
    Table::Header& formatsrc(std::string f);

    // The height of cells.
    Table::Header& height(double f);

    Table::Header& line(class Line f);

    // Prefix for cell values.
    Table::Header& prefix(std::string f);
    Table::Header& prefix(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `prefix`.
    Table::Header& prefixsrc(std::string f);

    // Suffix for cell values.
    Table::Header& suffix(std::string f);
    Table::Header& suffix(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `suffix`.
    Table::Header& suffixsrc(std::string f);

    // Header cell values. `values[m][n]` represents the value of the `n`th point in column `m`, therefore the
    // `values[m]` vector length for all columns must be the same (longer vectors will be truncated). Each value must be
    // a finite number or a string.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Table::Header& values(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `values`.
    Table::Header& valuessrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Header::Fill {
 public:

    // Sets the cell fill color. It accepts either a specific color or an array of colors or a 2D array of colors.
    Table::Header::Fill& color(std::string f);
    Table::Header::Fill& color(double f);
    Table::Header::Fill& color(std::vector<std::string> f);
    Table::Header::Fill& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Header::Fill& colorsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Header::Font {
 public:

    enum class Style {
        NORMAL,
        ITALIC,
    };
    static std::string to_string(Style e);

    enum class Textcase {
        NORMAL,
        WORD_CAPS,
        UPPER,
        LOWER,
    };
    static std::string to_string(Textcase e);

    enum class Variant {
        NORMAL,
        SMALL_CAPS,
        ALL_SMALL_CAPS,
        ALL_PETITE_CAPS,
        PETITE_CAPS,
        UNICASE,
    };
    static std::string to_string(Variant e);

    Table::Header::Font& color(std::string f);
    Table::Header::Font& color(double f);
    Table::Header::Font& color(std::vector<std::string> f);
    Table::Header::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Header::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Table::Header::Font& family(std::string f);
    Table::Header::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Table::Header::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Table::Header::Font& lineposition(std::string f);
    Table::Header::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Table::Header::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Table::Header::Font& shadow(std::string f);
    Table::Header::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Table::Header::Font& shadowsrc(std::string f);

    Table::Header::Font& size(double f);
    Table::Header::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Table::Header::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Table::Header::Font& style(enum Style f);
    Table::Header::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Table::Header::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Table::Header::Font& textcase(enum Textcase f);
    Table::Header::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Table::Header::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Table::Header::Font& variant(enum Variant f);
    Table::Header::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Table::Header::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Table::Header::Font& weight(int f);
    Table::Header::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Table::Header::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Header::Line {
 public:

    Table::Header::Line& color(std::string f);
    Table::Header::Line& color(double f);
    Table::Header::Line& color(std::vector<std::string> f);
    Table::Header::Line& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Header::Line& colorsrc(std::string f);

    Table::Header::Line& width(double f);
    Table::Header::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Table::Header::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Hoverlabel {
 public:

    enum class Align {
        LEFT,
        RIGHT,
        AUTO,
    };
    static std::string to_string(Align e);

    // Sets the font used in hover labels.
    class Font;

    // Sets the horizontal alignment of the text content within hover label box. Has an effect only if the hover label
    // text spans more two or more lines
    // - Default: auto
    Table::Hoverlabel& align(enum Align f);
    Table::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Table::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Table::Hoverlabel& bgcolor(std::string f);
    Table::Hoverlabel& bgcolor(double f);
    Table::Hoverlabel& bgcolor(std::vector<std::string> f);
    Table::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Table::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Table::Hoverlabel& bordercolor(std::string f);
    Table::Hoverlabel& bordercolor(double f);
    Table::Hoverlabel& bordercolor(std::vector<std::string> f);
    Table::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Table::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Table::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Table::Hoverlabel& namelength(int f);
    Table::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Table::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used in hover labels.
class Table::Hoverlabel::Font {
 public:

    enum class Style {
        NORMAL,
        ITALIC,
    };
    static std::string to_string(Style e);

    enum class Textcase {
        NORMAL,
        WORD_CAPS,
        UPPER,
        LOWER,
    };
    static std::string to_string(Textcase e);

    enum class Variant {
        NORMAL,
        SMALL_CAPS,
        ALL_SMALL_CAPS,
        ALL_PETITE_CAPS,
        PETITE_CAPS,
        UNICASE,
    };
    static std::string to_string(Variant e);

    Table::Hoverlabel::Font& color(std::string f);
    Table::Hoverlabel::Font& color(double f);
    Table::Hoverlabel::Font& color(std::vector<std::string> f);
    Table::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Table::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Table::Hoverlabel::Font& family(std::string f);
    Table::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Table::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Table::Hoverlabel::Font& lineposition(std::string f);
    Table::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Table::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Table::Hoverlabel::Font& shadow(std::string f);
    Table::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Table::Hoverlabel::Font& shadowsrc(std::string f);

    Table::Hoverlabel::Font& size(double f);
    Table::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Table::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Table::Hoverlabel::Font& style(enum Style f);
    Table::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Table::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Table::Hoverlabel::Font& textcase(enum Textcase f);
    Table::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Table::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Table::Hoverlabel::Font& variant(enum Variant f);
    Table::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Table::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Table::Hoverlabel::Font& weight(int f);
    Table::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Table::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Table::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Table::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this legend group's title font.
class Table::Legendgrouptitle::Font {
 public:

    enum class Style {
        NORMAL,
        ITALIC,
    };
    static std::string to_string(Style e);

    enum class Textcase {
        NORMAL,
        WORD_CAPS,
        UPPER,
        LOWER,
    };
    static std::string to_string(Textcase e);

    enum class Variant {
        NORMAL,
        SMALL_CAPS,
        ALL_SMALL_CAPS,
        ALL_PETITE_CAPS,
        PETITE_CAPS,
        UNICASE,
    };
    static std::string to_string(Variant e);

    Table::Legendgrouptitle::Font& color(std::string f);
    Table::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Table::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Table::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Table::Legendgrouptitle::Font& shadow(std::string f);

    Table::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Table::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Table::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Table::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Table::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Table::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Table::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Table::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp

#include "impl/table_impl.hpp"
