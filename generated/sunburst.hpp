// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Sunburst : public Trace {
 public:
    Sunburst()
    : Trace() {
        json["type"] = "sunburst";
    }

    enum class Branchvalues {
        REMAINDER,
        TOTAL,
    };
    static std::string to_string(Branchvalues e);

    enum class Insidetextorientation {
        HORIZONTAL,
        RADIAL,
        TANGENTIAL,
        AUTO,
    };
    static std::string to_string(Insidetextorientation e);

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    static std::string to_string(Visible e);

    class Domain;
    class Hoverlabel;
    // Sets the font used for `textinfo` lying inside the sector.
    class Insidetextfont;
    class Leaf;
    class Legendgrouptitle;
    class Marker;
    // Sets the font used for `textinfo` lying outside the sector. This option refers to the root of the hierarchy
    // presented at the center of a sunburst graph. Please note that if a hierarchy has multiple root nodes, this option
    // won't have any effect and `insidetextfont` would be used.
    class Outsidetextfont;
    class Root;
    class Stream;
    // Sets the font used for `textinfo`.
    class Textfont;

    // Determines how the items in `values` are summed. When set to *total*, items in `values` are taken to be value of
    // all its descendants. When set to *remainder*, items in `values` corresponding to the root and the branches
    // sectors are taken to be the extra part not part of the sum of the values at their leaves.
    // - Default: remainder
    Sunburst& branchvalues(enum Branchvalues f);

    // Determines default for `values` when it is not provided, by inferring a 1 for each of the *leaves* and/or
    // *branches*, otherwise 0.
    // - Default: leaves
    // - Flags: ['branches', 'leaves']
    Sunburst& count(std::string f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Sunburst& customdatasrc(std::string f);

    Sunburst& domain(class Domain f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: label+text+value+name
    // - Flags: ['label', 'text', 'value', 'name', 'current path', 'percent root', 'percent entry', 'percent parent']
    // - Extras ['all', 'none', 'skip']
    Sunburst& hoverinfo(std::string f);
    Sunburst& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Sunburst& hoverinfosrc(std::string f);

    Sunburst& hoverlabel(class Hoverlabel f);

    // Template string used for rendering the information that appear on hover box. Note that this will override
    // `hoverinfo`. Variables are inserted using %{variable}, for example "y: %{y}" as well as %{xother}, {%_xother},
    // {%_xother_}, {%xother_}. When showing info for several points, *xother* will be added to those with different x
    // positions from the first point. An underscore before or after *(x|y)other* will add a space on that side, only
    // when this field is shown. Numbers are formatted using d3-format's syntax %{variable:d3-format}, for example
    // "Price: %{y:$.2f}". https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax.
    // Dates are formatted using d3-time-format's syntax %{variable|d3-time-format}, for example "Day:
    // %{2019-01-01|%A}". https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date
    // formatting syntax. The variables available in `hovertemplate` are the ones emitted as event data described at
    // this link https://plotly.com/javascript/plotlyjs-events/#event-data. Additionally, every attributes that can be
    // specified per-point (the ones that are `arrayOk: true`) are available. Finally, the template string has access to
    // variables `currentPath`, `root`, `entry`, `percentRoot`, `percentEntry` and `percentParent`. Anything contained
    // in tag `<extra>` is displayed in the secondary box, for example "<extra>{fullData.name}</extra>". To hide the
    // secondary box completely, use an empty tag `<extra></extra>`.
    Sunburst& hovertemplate(std::string f);
    Sunburst& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Sunburst& hovertemplatesrc(std::string f);

    // Sets hover text elements associated with each sector. If a single string, the same string appears for all data
    // points. If an array of string, the items are mapped in order of this trace's sectors. To be seen, trace
    // `hoverinfo` must contain a *text* flag.
    Sunburst& hovertext(std::string f);
    Sunburst& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Sunburst& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Sunburst& idssrc(std::string f);

    // Sets the font used for `textinfo` lying inside the sector.
    Sunburst& insidetextfont(class Insidetextfont f);

    // Controls the orientation of the text inside chart sectors. When set to *auto*, text may be oriented in any
    // direction in order to be as big as possible in the middle of a sector. The *horizontal* option orients text to be
    // parallel with the bottom of the chart, and may make text smaller in order to achieve that goal. The *radial*
    // option orients text along the radius of the sector. The *tangential* option orients text perpendicular to the
    // radius of the sector.
    // - Default: auto
    Sunburst& insidetextorientation(enum Insidetextorientation f);

    // Sets the labels of each of the sectors.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& labels(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `labels`.
    Sunburst& labelssrc(std::string f);

    Sunburst& leaf(class Leaf f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Sunburst& legend(std::string f);

    Sunburst& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Sunburst& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Sunburst& legendwidth(double f);

    // Sets the level from which this trace hierarchy is rendered. Set `level` to `''` to start from the root node in
    // the hierarchy. Must be an "id" if `ids` is filled in, otherwise plotly attempts to find a matching item in
    // `labels`.
    template <typename T>
    Sunburst& level(T f);

    Sunburst& marker(class Marker f);

    // Sets the number of rendered sectors from any given `level`. Set `maxdepth` to *-1* to render all the levels in
    // the hierarchy.
    Sunburst& maxdepth(int f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Sunburst& meta(T f);
    template <typename T>
    Sunburst& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Sunburst& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Sunburst& name(std::string f);

    // Sets the opacity of the trace.
    Sunburst& opacity(double f);

    // Sets the font used for `textinfo` lying outside the sector. This option refers to the root of the hierarchy
    // presented at the center of a sunburst graph. Please note that if a hierarchy has multiple root nodes, this option
    // won't have any effect and `insidetextfont` would be used.
    Sunburst& outsidetextfont(class Outsidetextfont f);

    // Sets the parent sectors for each of the sectors. Empty string items '' are understood to reference the root node
    // in the hierarchy. If `ids` is filled, `parents` items are understood to be "ids" themselves. When `ids` is not
    // set, plotly attempts to find matching items in `labels`, but beware they must be unique.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& parents(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `parents`.
    Sunburst& parentssrc(std::string f);

    Sunburst& root(class Root f);

    // Rotates the whole diagram counterclockwise by some angle. By default the first slice starts at 3 o'clock.
    Sunburst& rotation(double f);

    // Determines whether or not the sectors are reordered from largest to smallest.
    Sunburst& sort(bool f);

    Sunburst& stream(class Stream f);

    // Sets text elements associated with each sector. If trace `textinfo` contains a *text* flag, these elements will
    // be seen on the chart. If trace `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will
    // be seen in the hover labels.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& text(std::vector<T> f);

    // Sets the font used for `textinfo`.
    Sunburst& textfont(class Textfont f);

    // Determines which trace information appear on the graph.
    // - Flags: ['label', 'text', 'value', 'current path', 'percent root', 'percent entry', 'percent parent']
    // - Extras ['none']
    Sunburst& textinfo(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Sunburst& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available. Finally, the
    // template string has access to variables `currentPath`, `root`, `entry`, `percentRoot`, `percentEntry`,
    // `percentParent`, `label` and `value`.
    Sunburst& texttemplate(std::string f);
    Sunburst& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Sunburst& texttemplatesrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Sunburst& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Sunburst& uirevision(T f);

    // Sets the values associated with each of the sectors. Use with `branchvalues` to determine how the values are
    // summed.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst& values(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `values`.
    Sunburst& valuessrc(std::string f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Sunburst& visible(enum Visible f);
};

class Sunburst::Domain {
 public:

    // If there is a layout grid, use the domain for this column in the grid for this sunburst trace .
    Sunburst::Domain& column(int f);

    // If there is a layout grid, use the domain for this row in the grid for this sunburst trace .
    Sunburst::Domain& row(int f);

    // Sets the horizontal domain of this sunburst trace (in plot fraction).
    Sunburst::Domain& x(std::vector<std::string> f);

    // Sets the vertical domain of this sunburst trace (in plot fraction).
    Sunburst::Domain& y(std::vector<std::string> f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Hoverlabel {
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
    Sunburst::Hoverlabel& align(enum Align f);
    Sunburst::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Sunburst::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Sunburst::Hoverlabel& bgcolor(std::string f);
    Sunburst::Hoverlabel& bgcolor(double f);
    Sunburst::Hoverlabel& bgcolor(std::vector<std::string> f);
    Sunburst::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Sunburst::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Sunburst::Hoverlabel& bordercolor(std::string f);
    Sunburst::Hoverlabel& bordercolor(double f);
    Sunburst::Hoverlabel& bordercolor(std::vector<std::string> f);
    Sunburst::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Sunburst::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Sunburst::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Sunburst::Hoverlabel& namelength(int f);
    Sunburst::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Sunburst::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used in hover labels.
class Sunburst::Hoverlabel::Font {
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

    Sunburst::Hoverlabel::Font& color(std::string f);
    Sunburst::Hoverlabel::Font& color(double f);
    Sunburst::Hoverlabel::Font& color(std::vector<std::string> f);
    Sunburst::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Sunburst::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Hoverlabel::Font& family(std::string f);
    Sunburst::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Sunburst::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Hoverlabel::Font& lineposition(std::string f);
    Sunburst::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Sunburst::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Hoverlabel::Font& shadow(std::string f);
    Sunburst::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Sunburst::Hoverlabel::Font& shadowsrc(std::string f);

    Sunburst::Hoverlabel::Font& size(double f);
    Sunburst::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Sunburst::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Hoverlabel::Font& style(enum Style f);
    Sunburst::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Sunburst::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Hoverlabel::Font& textcase(enum Textcase f);
    Sunburst::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Sunburst::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Hoverlabel::Font& variant(enum Variant f);
    Sunburst::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Sunburst::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Hoverlabel::Font& weight(int f);
    Sunburst::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Sunburst::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `textinfo` lying inside the sector.
class Sunburst::Insidetextfont {
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

    Sunburst::Insidetextfont& color(std::string f);
    Sunburst::Insidetextfont& color(double f);
    Sunburst::Insidetextfont& color(std::vector<std::string> f);
    Sunburst::Insidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Sunburst::Insidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Insidetextfont& family(std::string f);
    Sunburst::Insidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Sunburst::Insidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Insidetextfont& lineposition(std::string f);
    Sunburst::Insidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Sunburst::Insidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Insidetextfont& shadow(std::string f);
    Sunburst::Insidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Sunburst::Insidetextfont& shadowsrc(std::string f);

    Sunburst::Insidetextfont& size(double f);
    Sunburst::Insidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Sunburst::Insidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Insidetextfont& style(enum Style f);
    Sunburst::Insidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Sunburst::Insidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Insidetextfont& textcase(enum Textcase f);
    Sunburst::Insidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Sunburst::Insidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Insidetextfont& variant(enum Variant f);
    Sunburst::Insidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Sunburst::Insidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Insidetextfont& weight(int f);
    Sunburst::Insidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Sunburst::Insidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Leaf {
 public:

    // Sets the opacity of the leaves. With colorscale it is defaulted to 1; otherwise it is defaulted to 0.7
    Sunburst::Leaf& opacity(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Sunburst::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Sunburst::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Sunburst::Legendgrouptitle::Font {
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

    Sunburst::Legendgrouptitle::Font& color(std::string f);
    Sunburst::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Legendgrouptitle::Font& shadow(std::string f);

    Sunburst::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker {
 public:

    class Colorbar;
    class Line;
    // Sets the pattern within the marker.
    class Pattern;

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.colorscale`. Has an effect only if colors is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Sunburst::Marker& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here colors) or the bounds
    // set in `marker.cmin` and `marker.cmax` Has an effect only if colors is set to a numerical array. Defaults to
    // `false` when `marker.cmin` and `marker.cmax` are set by the user.
    Sunburst::Marker& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if colors is set to a numerical array. Value should
    // have the same units as colors and if set, `marker.cmin` must be set as well.
    Sunburst::Marker& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to this
    // point. Has an effect only if colors is set to a numerical array. Value should have the same units as colors. Has
    // no effect when `marker.cauto` is `false`.
    Sunburst::Marker& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if colors is set to a numerical array. Value should
    // have the same units as colors and if set, `marker.cmax` must be set as well.
    Sunburst::Marker& cmin(double f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Sunburst::Marker& coloraxis(std::string f);

    Sunburst::Marker& colorbar(class Colorbar f);

    // Sets the color of each sector of this trace. If not specified, the default trace color set is used to pick the
    // sector colors.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst::Marker& colors(std::vector<T> f);

    // Sets the colorscale. Has an effect only if colors is set to a numerical array. The colorscale must be an array
    // containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At minimum, a
    // mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'], [1,
    // 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `marker.cmin` and `marker.cmax`.
    // Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Sunburst::Marker& colorscale(std::string f);
    Sunburst::Marker& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `colors`.
    Sunburst::Marker& colorssrc(std::string f);

    Sunburst::Marker& line(class Line f);

    // Sets the pattern within the marker.
    Sunburst::Marker& pattern(class Pattern f);

    // Reverses the color mapping if true. Has an effect only if colors is set to a numerical array. If true,
    // `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the first
    // color.
    Sunburst::Marker& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if colors is set to a
    // numerical array.
    Sunburst::Marker& showscale(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker::Colorbar {
 public:

    enum class Exponentformat {
        NONE,
        E,
        POWER,
        SI,
        B,
    };
    static std::string to_string(Exponentformat e);

    enum class Lenmode {
        FRACTION,
        PIXELS,
    };
    static std::string to_string(Lenmode e);

    enum class Orientation {
        H,
        V,
    };
    static std::string to_string(Orientation e);

    enum class Showexponent {
        ALL,
        FIRST,
        LAST,
        NONE,
    };
    static std::string to_string(Showexponent e);

    enum class Showtickprefix {
        ALL,
        FIRST,
        LAST,
        NONE,
    };
    static std::string to_string(Showtickprefix e);

    enum class Showticksuffix {
        ALL,
        FIRST,
        LAST,
        NONE,
    };
    static std::string to_string(Showticksuffix e);

    enum class Thicknessmode {
        FRACTION,
        PIXELS,
    };
    static std::string to_string(Thicknessmode e);

    enum class Ticklabeloverflow {
        ALLOW,
        HIDE_PAST_DIV,
        HIDE_PAST_DOMAIN,
    };
    static std::string to_string(Ticklabeloverflow e);

    enum class Ticklabelposition {
        OUTSIDE,
        INSIDE,
        OUTSIDE_TOP,
        INSIDE_TOP,
        OUTSIDE_LEFT,
        INSIDE_LEFT,
        OUTSIDE_RIGHT,
        INSIDE_RIGHT,
        OUTSIDE_BOTTOM,
        INSIDE_BOTTOM,
    };
    static std::string to_string(Ticklabelposition e);

    enum class Tickmode {
        AUTO,
        LINEAR,
        ARRAY,
    };
    static std::string to_string(Tickmode e);

    enum class Ticks {
        OUTSIDE,
        INSIDE,
        EMPTY,
    };
    static std::string to_string(Ticks e);

    enum class Xanchor {
        LEFT,
        CENTER,
        RIGHT,
    };
    static std::string to_string(Xanchor e);

    enum class Xref {
        CONTAINER,
        PAPER,
    };
    static std::string to_string(Xref e);

    enum class Yanchor {
        TOP,
        MIDDLE,
        BOTTOM,
    };
    static std::string to_string(Yanchor e);

    enum class Yref {
        CONTAINER,
        PAPER,
    };
    static std::string to_string(Yref e);

    // Sets the color bar's tick label font
    class Tickfont;
    class Tickformatstops;
    class Title;

    // Sets the color of padded area.
    Sunburst::Marker::Colorbar& bgcolor(std::string f);
    Sunburst::Marker::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Sunburst::Marker::Colorbar& bordercolor(std::string f);
    Sunburst::Marker::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Sunburst::Marker::Colorbar& borderwidth(double f);

    // Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings
    // available to *log* and *date* axes. If the axis `type` is *log*, then ticks are set every 10^(n*dtick) where n is
    // the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1,
    // 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or
    // 0.69897000433. *log* has several special values; *L<f>*, where `f` is a positive number, gives ticks linearly
    // spaced in value (but not position). For example `tick0` = 0.1, `dtick` = *L0.5* will put ticks at 0.1,
    // 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use *D1* (all digits) or *D2* (only 2 and 5).
    // `tick0` is ignored for *D1* and *D2*. If the axis `type` is *date*, then you must convert the time to
    // milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. *date* also
    // has special values *M<n>* gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks
    // on the 15th of every third month, set `tick0` to *2000-01-15* and `dtick` to *M3*. To set ticks every 4 years,
    // set `dtick` to *M48*
    template <typename T>
    Sunburst::Marker::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Sunburst::Marker::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Sunburst::Marker::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Sunburst::Marker::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Sunburst::Marker::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Sunburst::Marker::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Sunburst::Marker::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Sunburst::Marker::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Sunburst::Marker::Colorbar& outlinecolor(std::string f);
    Sunburst::Marker::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Sunburst::Marker::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Sunburst::Marker::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Sunburst::Marker::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Sunburst::Marker::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Sunburst::Marker::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Sunburst::Marker::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Sunburst::Marker::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Sunburst::Marker::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Sunburst::Marker::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Sunburst::Marker::Colorbar& tickangle(double f);

    // Sets the tick color.
    Sunburst::Marker::Colorbar& tickcolor(std::string f);
    Sunburst::Marker::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Sunburst::Marker::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Sunburst::Marker::Colorbar& tickformat(std::string f);

    Sunburst::Marker::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Sunburst::Marker::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Sunburst::Marker::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Sunburst::Marker::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Sunburst::Marker::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Sunburst::Marker::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Sunburst::Marker::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Sunburst::Marker::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Sunburst::Marker::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst::Marker::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Sunburst::Marker::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Sunburst::Marker::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Sunburst::Marker::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Sunburst::Marker::Colorbar& tickwidth(double f);

    Sunburst::Marker::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Sunburst::Marker::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Sunburst::Marker::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Sunburst::Marker::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Sunburst::Marker::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Sunburst::Marker::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Sunburst::Marker::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Sunburst::Marker::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Sunburst::Marker::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the color bar's tick label font
class Sunburst::Marker::Colorbar::Tickfont {
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

    Sunburst::Marker::Colorbar::Tickfont& color(std::string f);
    Sunburst::Marker::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Marker::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Marker::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Marker::Colorbar::Tickfont& shadow(std::string f);

    Sunburst::Marker::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Marker::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Marker::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Marker::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Marker::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Sunburst::Marker::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Sunburst::Marker::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker::Colorbar::Title {
 public:

    enum class Side {
        RIGHT,
        TOP,
        BOTTOM,
    };
    static std::string to_string(Side e);

    // Sets this color bar's title font.
    class Font;

    // Sets this color bar's title font.
    Sunburst::Marker::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Sunburst::Marker::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Sunburst::Marker::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this color bar's title font.
class Sunburst::Marker::Colorbar::Title::Font {
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

    Sunburst::Marker::Colorbar::Title::Font& color(std::string f);
    Sunburst::Marker::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Marker::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Marker::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Marker::Colorbar::Title::Font& shadow(std::string f);

    Sunburst::Marker::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Marker::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Marker::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Marker::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Marker::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Marker::Line {
 public:

    // Sets the color of the line enclosing each sector. Defaults to the `paper_bgcolor` value.
    Sunburst::Marker::Line& color(std::string f);
    Sunburst::Marker::Line& color(double f);
    Sunburst::Marker::Line& color(std::vector<std::string> f);
    Sunburst::Marker::Line& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Sunburst::Marker::Line& colorsrc(std::string f);

    // Sets the width (in px) of the line enclosing each sector.
    Sunburst::Marker::Line& width(double f);
    Sunburst::Marker::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Sunburst::Marker::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the pattern within the marker.
class Sunburst::Marker::Pattern {
 public:

    enum class Fillmode {
        REPLACE,
        OVERLAY,
    };
    static std::string to_string(Fillmode e);

    enum class Shape {
        EMPTY,
        SLASH,
        DOUBLEBACKSLASH,
        X,
        HYPHEN,
        OR,
        PLUS,
        DOT,
    };
    static std::string to_string(Shape e);

    // When there is no colorscale sets the color of background pattern fill. Defaults to a `marker.color` background
    // when `fillmode` is *overlay*. Otherwise, defaults to a transparent background.
    Sunburst::Marker::Pattern& bgcolor(std::string f);
    Sunburst::Marker::Pattern& bgcolor(double f);
    Sunburst::Marker::Pattern& bgcolor(std::vector<std::string> f);
    Sunburst::Marker::Pattern& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Sunburst::Marker::Pattern& bgcolorsrc(std::string f);

    // When there is no colorscale sets the color of foreground pattern fill. Defaults to a `marker.color` background
    // when `fillmode` is *replace*. Otherwise, defaults to dark grey or white to increase contrast with the `bgcolor`.
    Sunburst::Marker::Pattern& fgcolor(std::string f);
    Sunburst::Marker::Pattern& fgcolor(double f);
    Sunburst::Marker::Pattern& fgcolor(std::vector<std::string> f);
    Sunburst::Marker::Pattern& fgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `fgcolor`.
    Sunburst::Marker::Pattern& fgcolorsrc(std::string f);

    // Sets the opacity of the foreground pattern fill. Defaults to a 0.5 when `fillmode` is *overlay*. Otherwise,
    // defaults to 1.
    Sunburst::Marker::Pattern& fgopacity(double f);

    // Determines whether `marker.color` should be used as a default to `bgcolor` or a `fgcolor`.
    // - Default: replace
    Sunburst::Marker::Pattern& fillmode(enum Fillmode f);

    // Sets the shape of the pattern fill. By default, no pattern is used for filling the area.
    // - Default:
    Sunburst::Marker::Pattern& shape(enum Shape f);
    Sunburst::Marker::Pattern& shape(const std::vector<enum Shape>& f);

    // Sets the source reference on Chart Studio Cloud for `shape`.
    Sunburst::Marker::Pattern& shapesrc(std::string f);

    // Sets the size of unit squares of the pattern fill in pixels, which corresponds to the interval of repetition of
    // the pattern.
    Sunburst::Marker::Pattern& size(double f);
    Sunburst::Marker::Pattern& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Sunburst::Marker::Pattern& sizesrc(std::string f);

    // Sets the solidity of the pattern fill. Solidity is roughly the fraction of the area filled by the pattern.
    // Solidity of 0 shows only the background color without pattern and solidty of 1 shows only the foreground color
    // without pattern.
    Sunburst::Marker::Pattern& solidity(double f);
    Sunburst::Marker::Pattern& solidity(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `solidity`.
    Sunburst::Marker::Pattern& soliditysrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `textinfo` lying outside the sector. This option refers to the root of the hierarchy presented
// at the center of a sunburst graph. Please note that if a hierarchy has multiple root nodes, this option won't have
// any effect and `insidetextfont` would be used.
class Sunburst::Outsidetextfont {
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

    Sunburst::Outsidetextfont& color(std::string f);
    Sunburst::Outsidetextfont& color(double f);
    Sunburst::Outsidetextfont& color(std::vector<std::string> f);
    Sunburst::Outsidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Sunburst::Outsidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Outsidetextfont& family(std::string f);
    Sunburst::Outsidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Sunburst::Outsidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Outsidetextfont& lineposition(std::string f);
    Sunburst::Outsidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Sunburst::Outsidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Outsidetextfont& shadow(std::string f);
    Sunburst::Outsidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Sunburst::Outsidetextfont& shadowsrc(std::string f);

    Sunburst::Outsidetextfont& size(double f);
    Sunburst::Outsidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Sunburst::Outsidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Outsidetextfont& style(enum Style f);
    Sunburst::Outsidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Sunburst::Outsidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Outsidetextfont& textcase(enum Textcase f);
    Sunburst::Outsidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Sunburst::Outsidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Outsidetextfont& variant(enum Variant f);
    Sunburst::Outsidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Sunburst::Outsidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Outsidetextfont& weight(int f);
    Sunburst::Outsidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Sunburst::Outsidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Root {
 public:

    // sets the color of the root node for a sunburst/treemap/icicle trace. this has no effect when a colorscale is used
    // to set the markers.
    Sunburst::Root& color(std::string f);
    Sunburst::Root& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Sunburst::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Sunburst::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Sunburst::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `textinfo`.
class Sunburst::Textfont {
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

    Sunburst::Textfont& color(std::string f);
    Sunburst::Textfont& color(double f);
    Sunburst::Textfont& color(std::vector<std::string> f);
    Sunburst::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Sunburst::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Sunburst::Textfont& family(std::string f);
    Sunburst::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Sunburst::Textfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Sunburst::Textfont& lineposition(std::string f);
    Sunburst::Textfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Sunburst::Textfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Sunburst::Textfont& shadow(std::string f);
    Sunburst::Textfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Sunburst::Textfont& shadowsrc(std::string f);

    Sunburst::Textfont& size(double f);
    Sunburst::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Sunburst::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Sunburst::Textfont& style(enum Style f);
    Sunburst::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Sunburst::Textfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Sunburst::Textfont& textcase(enum Textcase f);
    Sunburst::Textfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Sunburst::Textfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Sunburst::Textfont& variant(enum Variant f);
    Sunburst::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Sunburst::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Sunburst::Textfont& weight(int f);
    Sunburst::Textfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Sunburst::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/sunburst_impl.hpp"
