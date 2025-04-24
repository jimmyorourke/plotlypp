// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Indicator : public Trace {
 public:
    Indicator()
    : Trace() {
        json["type"] = "indicator";
    }

    enum class Align {
        LEFT,
        CENTER,
        RIGHT,
    };
    static std::string to_string(Align e);

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    static std::string to_string(Visible e);

    class Delta;
    class Domain;
    // The gauge of the Indicator plot.
    class Gauge;
    class Legendgrouptitle;
    class Number;
    class Stream;
    class Title;

    // Sets the horizontal alignment of the `text` within the box. Note that this attribute has no effect if an angular
    // gauge is displayed: in this case, it is always centered
    Indicator& align(enum Align f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Indicator& customdatasrc(std::string f);

    Indicator& delta(class Delta f);

    Indicator& domain(class Domain f);

    // The gauge of the Indicator plot.
    Indicator& gauge(class Gauge f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Indicator& idssrc(std::string f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Indicator& legend(std::string f);

    Indicator& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Indicator& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Indicator& legendwidth(double f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Indicator& meta(T f);
    template <typename T>
    Indicator& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Indicator& metasrc(std::string f);

    // Determines how the value is displayed on the graph. `number` displays the value numerically in text. `delta`
    // displays the difference to a reference value in text. Finally, `gauge` displays the value graphically on an axis.
    // - Default: number
    // - Flags: ['number', 'delta', 'gauge']
    Indicator& mode(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Indicator& name(std::string f);

    Indicator& number(class Number f);

    Indicator& stream(class Stream f);

    Indicator& title(class Title f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Indicator& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Indicator& uirevision(T f);

    // Sets the number to be displayed.
    Indicator& value(double f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Indicator& visible(enum Visible f);
};

class Indicator::Delta {
 public:

    enum class Position {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT,
    };
    static std::string to_string(Position e);

    class Decreasing;
    // Set the font used to display the delta
    class Font;
    class Increasing;

    Indicator::Delta& decreasing(class Decreasing f);

    // Set the font used to display the delta
    Indicator::Delta& font(class Font f);

    Indicator::Delta& increasing(class Increasing f);

    // Sets the position of delta with respect to the number.
    // - Default: bottom
    Indicator::Delta& position(enum Position f);

    // Sets a prefix appearing before the delta.
    Indicator::Delta& prefix(std::string f);

    // Sets the reference value to compute the delta. By default, it is set to the current value.
    Indicator::Delta& reference(double f);

    // Show relative change
    Indicator::Delta& relative(bool f);

    // Sets a suffix appearing next to the delta.
    Indicator::Delta& suffix(std::string f);

    // Sets the value formatting rule using d3 formatting mini-languages which are very similar to those in Python. For
    // numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
    Indicator::Delta& valueformat(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Delta::Decreasing {
 public:

    // Sets the color for increasing value.
    Indicator::Delta::Decreasing& color(std::string f);
    Indicator::Delta::Decreasing& color(double f);

    // Sets the symbol to display for increasing value
    Indicator::Delta::Decreasing& symbol(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Set the font used to display the delta
class Indicator::Delta::Font {
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

    Indicator::Delta::Font& color(std::string f);
    Indicator::Delta::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Indicator::Delta::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Indicator::Delta::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Indicator::Delta::Font& shadow(std::string f);

    Indicator::Delta::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Indicator::Delta::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Indicator::Delta::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Indicator::Delta::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Indicator::Delta::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Delta::Increasing {
 public:

    // Sets the color for increasing value.
    Indicator::Delta::Increasing& color(std::string f);
    Indicator::Delta::Increasing& color(double f);

    // Sets the symbol to display for increasing value
    Indicator::Delta::Increasing& symbol(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Domain {
 public:

    // If there is a layout grid, use the domain for this column in the grid for this indicator trace .
    Indicator::Domain& column(int f);

    // If there is a layout grid, use the domain for this row in the grid for this indicator trace .
    Indicator::Domain& row(int f);

    // Sets the horizontal domain of this indicator trace (in plot fraction).
    Indicator::Domain& x(std::vector<std::string> f);

    // Sets the vertical domain of this indicator trace (in plot fraction).
    Indicator::Domain& y(std::vector<std::string> f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// The gauge of the Indicator plot.
class Indicator::Gauge {
 public:

    enum class Shape {
        ANGULAR,
        BULLET,
    };
    static std::string to_string(Shape e);

    class Axis;
    // Set the appearance of the gauge's value
    class Bar;
    class Steps;
    class Threshold;

    Indicator::Gauge& axis(class Axis f);

    // Set the appearance of the gauge's value
    Indicator::Gauge& bar(class Bar f);

    // Sets the gauge background color.
    Indicator::Gauge& bgcolor(std::string f);
    Indicator::Gauge& bgcolor(double f);

    // Sets the color of the border enclosing the gauge.
    Indicator::Gauge& bordercolor(std::string f);
    Indicator::Gauge& bordercolor(double f);

    // Sets the width (in px) of the border enclosing the gauge.
    Indicator::Gauge& borderwidth(double f);

    // Set the shape of the gauge
    // - Default: angular
    Indicator::Gauge& shape(enum Shape f);

    Indicator::Gauge& steps(class Steps f);

    Indicator::Gauge& threshold(class Threshold f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Axis {
 public:

    enum class Exponentformat {
        NONE,
        E,
        POWER,
        SI,
        B,
    };
    static std::string to_string(Exponentformat e);

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

    // Sets the color bar's tick label font
    class Tickfont;
    class Tickformatstops;

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
    Indicator::Gauge::Axis& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Indicator::Gauge::Axis& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Indicator::Gauge::Axis& labelalias(T f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Indicator::Gauge::Axis& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Indicator::Gauge::Axis& nticks(int f);

    // Sets the range of this axis.
    Indicator::Gauge::Axis& range(std::vector<std::string> f);

    // If "true", even 4-digit integers are separated
    Indicator::Gauge::Axis& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Indicator::Gauge::Axis& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Indicator::Gauge::Axis& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Indicator::Gauge::Axis& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Indicator::Gauge::Axis& showticksuffix(enum Showticksuffix f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Indicator::Gauge::Axis& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Indicator::Gauge::Axis& tickangle(double f);

    // Sets the tick color.
    Indicator::Gauge::Axis& tickcolor(std::string f);
    Indicator::Gauge::Axis& tickcolor(double f);

    // Sets the color bar's tick label font
    Indicator::Gauge::Axis& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Indicator::Gauge::Axis& tickformat(std::string f);

    Indicator::Gauge::Axis& tickformatstops(class Tickformatstops f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Indicator::Gauge::Axis& ticklabelstep(int f);

    // Sets the tick length (in px).
    Indicator::Gauge::Axis& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Indicator::Gauge::Axis& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Indicator::Gauge::Axis& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default: outside
    Indicator::Gauge::Axis& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Indicator::Gauge::Axis& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator::Gauge::Axis& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Indicator::Gauge::Axis& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator::Gauge::Axis& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Indicator::Gauge::Axis& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Indicator::Gauge::Axis& tickwidth(double f);

    // A single toggle to hide the axis while preserving interaction like dragging. Default is true when a cheater plot
    // is present on the axis, otherwise false
    Indicator::Gauge::Axis& visible(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the color bar's tick label font
class Indicator::Gauge::Axis::Tickfont {
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

    Indicator::Gauge::Axis::Tickfont& color(std::string f);
    Indicator::Gauge::Axis::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Indicator::Gauge::Axis::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Indicator::Gauge::Axis::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Indicator::Gauge::Axis::Tickfont& shadow(std::string f);

    Indicator::Gauge::Axis::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Indicator::Gauge::Axis::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Indicator::Gauge::Axis::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Indicator::Gauge::Axis::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Indicator::Gauge::Axis::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Axis::Tickformatstops {
 public:

    class Tickformatstop;

    Indicator::Gauge::Axis::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Axis::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Set the appearance of the gauge's value
class Indicator::Gauge::Bar {
 public:

    class Line;

    // Sets the background color of the arc.
    Indicator::Gauge::Bar& color(std::string f);
    Indicator::Gauge::Bar& color(double f);

    Indicator::Gauge::Bar& line(class Line f);

    // Sets the thickness of the bar as a fraction of the total thickness of the gauge.
    Indicator::Gauge::Bar& thickness(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Bar::Line {
 public:

    // Sets the color of the line enclosing each sector.
    Indicator::Gauge::Bar::Line& color(std::string f);
    Indicator::Gauge::Bar::Line& color(double f);

    // Sets the width (in px) of the line enclosing each sector.
    Indicator::Gauge::Bar::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Steps {
 public:

    class Step;

    Indicator::Gauge::Steps& step(class Step f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Steps::Step {
 public:

    class Line;

    // Sets the background color of the arc.
    Indicator::Gauge::Steps::Step& color(std::string f);
    Indicator::Gauge::Steps::Step& color(double f);

    Indicator::Gauge::Steps::Step& line(class Line f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Indicator::Gauge::Steps::Step& name(std::string f);

    // Sets the range of this axis.
    Indicator::Gauge::Steps::Step& range(std::vector<std::string> f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Indicator::Gauge::Steps::Step& templateitemname(std::string f);

    // Sets the thickness of the bar as a fraction of the total thickness of the gauge.
    Indicator::Gauge::Steps::Step& thickness(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Steps::Step::Line {
 public:

    // Sets the color of the line enclosing each sector.
    Indicator::Gauge::Steps::Step::Line& color(std::string f);
    Indicator::Gauge::Steps::Step::Line& color(double f);

    // Sets the width (in px) of the line enclosing each sector.
    Indicator::Gauge::Steps::Step::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Threshold {
 public:

    class Line;

    Indicator::Gauge::Threshold& line(class Line f);

    // Sets the thickness of the threshold line as a fraction of the thickness of the gauge.
    Indicator::Gauge::Threshold& thickness(double f);

    // Sets a treshold value drawn as a line.
    Indicator::Gauge::Threshold& value(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Gauge::Threshold::Line {
 public:

    // Sets the color of the threshold line.
    Indicator::Gauge::Threshold::Line& color(std::string f);
    Indicator::Gauge::Threshold::Line& color(double f);

    // Sets the width (in px) of the threshold line.
    Indicator::Gauge::Threshold::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Indicator::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Indicator::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Indicator::Legendgrouptitle::Font {
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

    Indicator::Legendgrouptitle::Font& color(std::string f);
    Indicator::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Indicator::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Indicator::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Indicator::Legendgrouptitle::Font& shadow(std::string f);

    Indicator::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Indicator::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Indicator::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Indicator::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Indicator::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Number {
 public:

    // Set the font used to display main number
    class Font;

    // Set the font used to display main number
    Indicator::Number& font(class Font f);

    // Sets a prefix appearing before the number.
    Indicator::Number& prefix(std::string f);

    // Sets a suffix appearing next to the number.
    Indicator::Number& suffix(std::string f);

    // Sets the value formatting rule using d3 formatting mini-languages which are very similar to those in Python. For
    // numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
    Indicator::Number& valueformat(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Set the font used to display main number
class Indicator::Number::Font {
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

    Indicator::Number::Font& color(std::string f);
    Indicator::Number::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Indicator::Number::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Indicator::Number::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Indicator::Number::Font& shadow(std::string f);

    Indicator::Number::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Indicator::Number::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Indicator::Number::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Indicator::Number::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Indicator::Number::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Indicator::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Indicator::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Indicator::Title {
 public:

    enum class Align {
        LEFT,
        CENTER,
        RIGHT,
    };
    static std::string to_string(Align e);

    // Set the font used to display the title
    class Font;

    // Sets the horizontal alignment of the title. It defaults to `center` except for bullet charts for which it
    // defaults to right.
    Indicator::Title& align(enum Align f);

    // Set the font used to display the title
    Indicator::Title& font(class Font f);

    // Sets the title of this indicator.
    Indicator::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Set the font used to display the title
class Indicator::Title::Font {
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

    Indicator::Title::Font& color(std::string f);
    Indicator::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Indicator::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Indicator::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Indicator::Title::Font& shadow(std::string f);

    Indicator::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Indicator::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Indicator::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Indicator::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Indicator::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/indicator_impl.hpp"
