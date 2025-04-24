// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Ohlc : public Trace {
 public:
    Ohlc()
    : Trace() {
        json["type"] = "ohlc";
    }

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    static std::string to_string(Visible e);

    enum class Xcalendar {
        CHINESE,
        COPTIC,
        DISCWORLD,
        ETHIOPIAN,
        GREGORIAN,
        HEBREW,
        ISLAMIC,
        JALALI,
        JULIAN,
        MAYAN,
        NANAKSHAHI,
        NEPALI,
        PERSIAN,
        TAIWAN,
        THAI,
        UMMALQURA,
    };
    static std::string to_string(Xcalendar e);

    enum class Xperiodalignment {
        START,
        MIDDLE,
        END,
    };
    static std::string to_string(Xperiodalignment e);

    class Decreasing;
    class Hoverlabel;
    class Increasing;
    class Legendgrouptitle;
    class Line;
    class Stream;

    // Sets the close values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& close(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `close`.
    Ohlc& closesrc(std::string f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Ohlc& customdatasrc(std::string f);

    Ohlc& decreasing(class Decreasing f);

    // Sets the high values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& high(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `high`.
    Ohlc& highsrc(std::string f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Ohlc& hoverinfo(std::string f);
    Ohlc& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Ohlc& hoverinfosrc(std::string f);

    Ohlc& hoverlabel(class Hoverlabel f);

    // Same as `text`.
    Ohlc& hovertext(std::string f);
    Ohlc& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Ohlc& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Ohlc& idssrc(std::string f);

    Ohlc& increasing(class Increasing f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Ohlc& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Ohlc& legendgroup(std::string f);

    Ohlc& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Ohlc& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Ohlc& legendwidth(double f);

    Ohlc& line(class Line f);

    // Sets the low values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& low(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `low`.
    Ohlc& lowsrc(std::string f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Ohlc& meta(T f);
    template <typename T>
    Ohlc& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Ohlc& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Ohlc& name(std::string f);

    // Sets the opacity of the trace.
    Ohlc& opacity(double f);

    // Sets the open values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& open(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `open`.
    Ohlc& opensrc(std::string f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Ohlc& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Ohlc& showlegend(bool f);

    Ohlc& stream(class Stream f);

    // Sets hover text elements associated with each sample point. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to this trace's sample points.
    Ohlc& text(std::string f);
    Ohlc& text(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Ohlc& textsrc(std::string f);

    // Sets the width of the open/close tick marks relative to the *x* minimal interval.
    Ohlc& tickwidth(double f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Ohlc& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Ohlc& uirevision(T f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Ohlc& visible(enum Visible f);

    // Sets the x coordinates. If absent, linear coordinate will be generated.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Ohlc& x(std::vector<T> f);

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Ohlc& xaxis(std::string f);

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Ohlc& xcalendar(enum Xcalendar f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Ohlc& xhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Ohlc& xperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Ohlc& xperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Ohlc& xperiodalignment(enum Xperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Ohlc& xsrc(std::string f);

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Ohlc& yaxis(std::string f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Ohlc& yhoverformat(std::string f);

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Ohlc& zorder(int f);
};

class Ohlc::Decreasing {
 public:

    class Line;

    Ohlc::Decreasing& line(class Line f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Decreasing::Line {
 public:

    // Sets the line color.
    Ohlc::Decreasing::Line& color(std::string f);
    Ohlc::Decreasing::Line& color(double f);

    // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
    // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
    Ohlc::Decreasing::Line& dash(std::string f);

    // Sets the line width (in px).
    Ohlc::Decreasing::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Hoverlabel {
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
    Ohlc::Hoverlabel& align(enum Align f);
    Ohlc::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Ohlc::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Ohlc::Hoverlabel& bgcolor(std::string f);
    Ohlc::Hoverlabel& bgcolor(double f);
    Ohlc::Hoverlabel& bgcolor(std::vector<std::string> f);
    Ohlc::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Ohlc::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Ohlc::Hoverlabel& bordercolor(std::string f);
    Ohlc::Hoverlabel& bordercolor(double f);
    Ohlc::Hoverlabel& bordercolor(std::vector<std::string> f);
    Ohlc::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Ohlc::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Ohlc::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Ohlc::Hoverlabel& namelength(int f);
    Ohlc::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Ohlc::Hoverlabel& namelengthsrc(std::string f);

    // Show hover information (open, close, high, low) in separate labels.
    Ohlc::Hoverlabel& split(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used in hover labels.
class Ohlc::Hoverlabel::Font {
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

    Ohlc::Hoverlabel::Font& color(std::string f);
    Ohlc::Hoverlabel::Font& color(double f);
    Ohlc::Hoverlabel::Font& color(std::vector<std::string> f);
    Ohlc::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Ohlc::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Ohlc::Hoverlabel::Font& family(std::string f);
    Ohlc::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Ohlc::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Ohlc::Hoverlabel::Font& lineposition(std::string f);
    Ohlc::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Ohlc::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Ohlc::Hoverlabel::Font& shadow(std::string f);
    Ohlc::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Ohlc::Hoverlabel::Font& shadowsrc(std::string f);

    Ohlc::Hoverlabel::Font& size(double f);
    Ohlc::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Ohlc::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Ohlc::Hoverlabel::Font& style(enum Style f);
    Ohlc::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Ohlc::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Ohlc::Hoverlabel::Font& textcase(enum Textcase f);
    Ohlc::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Ohlc::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Ohlc::Hoverlabel::Font& variant(enum Variant f);
    Ohlc::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Ohlc::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Ohlc::Hoverlabel::Font& weight(int f);
    Ohlc::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Ohlc::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Increasing {
 public:

    class Line;

    Ohlc::Increasing& line(class Line f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Increasing::Line {
 public:

    // Sets the line color.
    Ohlc::Increasing::Line& color(std::string f);
    Ohlc::Increasing::Line& color(double f);

    // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
    // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
    Ohlc::Increasing::Line& dash(std::string f);

    // Sets the line width (in px).
    Ohlc::Increasing::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Ohlc::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Ohlc::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Ohlc::Legendgrouptitle::Font {
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

    Ohlc::Legendgrouptitle::Font& color(std::string f);
    Ohlc::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Ohlc::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Ohlc::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Ohlc::Legendgrouptitle::Font& shadow(std::string f);

    Ohlc::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Ohlc::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Ohlc::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Ohlc::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Ohlc::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Line {
 public:

    // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
    // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*). Note that this style setting can also be set
    // per direction via `increasing.line.dash` and `decreasing.line.dash`.
    Ohlc::Line& dash(std::string f);

    // [object Object] Note that this style setting can also be set per direction via `increasing.line.width` and
    // `decreasing.line.width`.
    Ohlc::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Ohlc::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Ohlc::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Ohlc::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/ohlc_impl.hpp"
