// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <json.hpp>

namespace plotlypp {

class Waterfall : public Trace {
 public:
    Waterfall()
    : Trace() {
        json["type"] = "waterfall";
    }

    enum class Constraintext {
        INSIDE,
        OUTSIDE,
        BOTH,
        NONE,
    };
    static std::string to_string(Constraintext e);

    enum class Insidetextanchor {
        END,
        MIDDLE,
        START,
    };
    static std::string to_string(Insidetextanchor e);

    enum class Orientation {
        V,
        H,
    };
    static std::string to_string(Orientation e);

    enum class Textposition {
        INSIDE,
        OUTSIDE,
        AUTO,
        NONE,
    };
    static std::string to_string(Textposition e);

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    static std::string to_string(Visible e);

    enum class Xperiodalignment {
        START,
        MIDDLE,
        END,
    };
    static std::string to_string(Xperiodalignment e);

    enum class Yperiodalignment {
        START,
        MIDDLE,
        END,
    };
    static std::string to_string(Yperiodalignment e);

    class Connector;
    class Decreasing;
    class Hoverlabel;
    class Increasing;
    // Sets the font used for `text` lying inside the bar.
    class Insidetextfont;
    class Legendgrouptitle;
    // Sets the font used for `text` lying outside the bar.
    class Outsidetextfont;
    class Stream;
    // Sets the font used for `text`.
    class Textfont;
    class Totals;

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Waterfall& alignmentgroup(std::string f);

    // Sets where the bar base is drawn (in position axis units).
    Waterfall& base(double f);

    // Determines whether the text nodes are clipped about the subplot axes. To show the text nodes above axis lines and
    // tick labels, make sure to set `xaxis.layer` and `yaxis.layer` to *below traces*.
    Waterfall& cliponaxis(bool f);

    Waterfall& connector(class Connector f);

    // Constrain the size of text inside or outside a bar to be no larger than the bar itself.
    // - Default: both
    Waterfall& constraintext(enum Constraintext f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Waterfall& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Waterfall& customdatasrc(std::string f);

    Waterfall& decreasing(class Decreasing f);

    // Sets the x coordinate step. See `x0` for more info.
    Waterfall& dx(double f);

    // Sets the y coordinate step. See `y0` for more info.
    Waterfall& dy(double f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['name', 'x', 'y', 'text', 'initial', 'delta', 'final']
    // - Extras ['all', 'none', 'skip']
    Waterfall& hoverinfo(std::string f);
    Waterfall& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Waterfall& hoverinfosrc(std::string f);

    Waterfall& hoverlabel(class Hoverlabel f);

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
    // variables `initial`, `delta` and `final`. Anything contained in tag `<extra>` is displayed in the secondary box,
    // for example "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an empty tag
    // `<extra></extra>`.
    Waterfall& hovertemplate(std::string f);
    Waterfall& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Waterfall& hovertemplatesrc(std::string f);

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Waterfall& hovertext(std::string f);
    Waterfall& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Waterfall& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Waterfall& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Waterfall& idssrc(std::string f);

    Waterfall& increasing(class Increasing f);

    // Determines if texts are kept at center or start/end points in `textposition` *inside* mode.
    // - Default: end
    Waterfall& insidetextanchor(enum Insidetextanchor f);

    // Sets the font used for `text` lying inside the bar.
    Waterfall& insidetextfont(class Insidetextfont f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Waterfall& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Waterfall& legendgroup(std::string f);

    Waterfall& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Waterfall& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Waterfall& legendwidth(double f);

    // An array containing types of values. By default the values are considered as 'relative'. However; it is possible
    // to use 'total' to compute the sums. Also 'absolute' could be applied to reset the computed total or to declare an
    // initial value where needed.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Waterfall& measure(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `measure`.
    Waterfall& measuresrc(std::string f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Waterfall& meta(T f);
    template <typename T>
    Waterfall& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Waterfall& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Waterfall& name(std::string f);

    // Shifts the position where the bar is drawn (in position axis units). In *group* barmode, traces that set *offset*
    // will be excluded and drawn in *overlay* mode instead.
    Waterfall& offset(double f);
    Waterfall& offset(std::vector<double> f);

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Waterfall& offsetgroup(std::string f);

    // Sets the source reference on Chart Studio Cloud for `offset`.
    Waterfall& offsetsrc(std::string f);

    // Sets the opacity of the trace.
    Waterfall& opacity(double f);

    // Sets the orientation of the bars. With *v* (*h*), the value of the each bar spans along the vertical
    // (horizontal).
    Waterfall& orientation(enum Orientation f);

    // Sets the font used for `text` lying outside the bar.
    Waterfall& outsidetextfont(class Outsidetextfont f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Waterfall& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Waterfall& showlegend(bool f);

    Waterfall& stream(class Stream f);

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Waterfall& text(std::string f);
    Waterfall& text(std::vector<std::string> f);

    // Sets the angle of the tick labels with respect to the bar. For example, a `tickangle` of -90 draws the tick
    // labels vertically. With *auto* the texts may automatically be rotated to fit with the maximum size in bars.
    Waterfall& textangle(double f);

    // Sets the font used for `text`.
    Waterfall& textfont(class Textfont f);

    // Determines which trace information appear on the graph. In the case of having multiple waterfalls, totals are
    // computed separately (per trace).
    // - Flags: ['label', 'text', 'initial', 'delta', 'final']
    // - Extras ['none']
    Waterfall& textinfo(std::string f);

    // Specifies the location of the `text`. *inside* positions `text` inside, next to the bar end (rotated and scaled
    // if needed). *outside* positions `text` outside, next to the bar end (scaled if needed), unless there is another
    // bar stacked on this one, then the text gets pushed inside. *auto* tries to position `text` inside the bar, but if
    // the bar is too small and no bar is stacked on this one the text is moved outside. If *none*, no text appears.
    // - Default: auto
    Waterfall& textposition(enum Textposition f);
    Waterfall& textposition(const std::vector<enum Textposition>& f);

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Waterfall& textpositionsrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Waterfall& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available. Finally, the
    // template string has access to variables `initial`, `delta`, `final` and `label`.
    Waterfall& texttemplate(std::string f);
    Waterfall& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Waterfall& texttemplatesrc(std::string f);

    Waterfall& totals(class Totals f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Waterfall& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Waterfall& uirevision(T f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Waterfall& visible(enum Visible f);

    // Sets the bar width (in position axis units).
    Waterfall& width(double f);
    Waterfall& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Waterfall& widthsrc(std::string f);

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Waterfall& x(std::vector<T> f);

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Waterfall& x0(T f);

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Waterfall& xaxis(std::string f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Waterfall& xhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Waterfall& xperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Waterfall& xperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Waterfall& xperiodalignment(enum Xperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Waterfall& xsrc(std::string f);

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Waterfall& y(std::vector<T> f);

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Waterfall& y0(T f);

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Waterfall& yaxis(std::string f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Waterfall& yhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Waterfall& yperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Waterfall& yperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Waterfall& yperiodalignment(enum Yperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `y`.
    Waterfall& ysrc(std::string f);

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Waterfall& zorder(int f);
};

class Waterfall::Connector {
 public:

    enum class Mode {
        SPANNING,
        BETWEEN,
    };
    static std::string to_string(Mode e);

    class Line;

    Waterfall::Connector& line(class Line f);

    // Sets the shape of connector lines.
    // - Default: between
    Waterfall::Connector& mode(enum Mode f);

    // Determines if connector lines are drawn.
    Waterfall::Connector& visible(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Connector::Line {
 public:

    // Sets the line color.
    Waterfall::Connector::Line& color(std::string f);
    Waterfall::Connector::Line& color(double f);

    // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
    // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
    Waterfall::Connector::Line& dash(std::string f);

    // Sets the line width (in px).
    Waterfall::Connector::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Decreasing {
 public:

    class Marker;

    Waterfall::Decreasing& marker(class Marker f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Decreasing::Marker {
 public:

    class Line;

    // Sets the marker color of all decreasing values.
    Waterfall::Decreasing::Marker& color(std::string f);
    Waterfall::Decreasing::Marker& color(double f);

    Waterfall::Decreasing::Marker& line(class Line f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Decreasing::Marker::Line {
 public:

    // Sets the line color of all decreasing values.
    Waterfall::Decreasing::Marker::Line& color(std::string f);
    Waterfall::Decreasing::Marker::Line& color(double f);

    // Sets the line width of all decreasing values.
    Waterfall::Decreasing::Marker::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Hoverlabel {
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
    Waterfall::Hoverlabel& align(enum Align f);
    Waterfall::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Waterfall::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Waterfall::Hoverlabel& bgcolor(std::string f);
    Waterfall::Hoverlabel& bgcolor(double f);
    Waterfall::Hoverlabel& bgcolor(std::vector<std::string> f);
    Waterfall::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Waterfall::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Waterfall::Hoverlabel& bordercolor(std::string f);
    Waterfall::Hoverlabel& bordercolor(double f);
    Waterfall::Hoverlabel& bordercolor(std::vector<std::string> f);
    Waterfall::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Waterfall::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Waterfall::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Waterfall::Hoverlabel& namelength(int f);
    Waterfall::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Waterfall::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used in hover labels.
class Waterfall::Hoverlabel::Font {
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

    Waterfall::Hoverlabel::Font& color(std::string f);
    Waterfall::Hoverlabel::Font& color(double f);
    Waterfall::Hoverlabel::Font& color(std::vector<std::string> f);
    Waterfall::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Waterfall::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Waterfall::Hoverlabel::Font& family(std::string f);
    Waterfall::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Waterfall::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Waterfall::Hoverlabel::Font& lineposition(std::string f);
    Waterfall::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Waterfall::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Waterfall::Hoverlabel::Font& shadow(std::string f);
    Waterfall::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Waterfall::Hoverlabel::Font& shadowsrc(std::string f);

    Waterfall::Hoverlabel::Font& size(double f);
    Waterfall::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Waterfall::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Waterfall::Hoverlabel::Font& style(enum Style f);
    Waterfall::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Waterfall::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Waterfall::Hoverlabel::Font& textcase(enum Textcase f);
    Waterfall::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Waterfall::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Waterfall::Hoverlabel::Font& variant(enum Variant f);
    Waterfall::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Waterfall::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Waterfall::Hoverlabel::Font& weight(int f);
    Waterfall::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Waterfall::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Increasing {
 public:

    class Marker;

    Waterfall::Increasing& marker(class Marker f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Increasing::Marker {
 public:

    class Line;

    // Sets the marker color of all increasing values.
    Waterfall::Increasing::Marker& color(std::string f);
    Waterfall::Increasing::Marker& color(double f);

    Waterfall::Increasing::Marker& line(class Line f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Increasing::Marker::Line {
 public:

    // Sets the line color of all increasing values.
    Waterfall::Increasing::Marker::Line& color(std::string f);
    Waterfall::Increasing::Marker::Line& color(double f);

    // Sets the line width of all increasing values.
    Waterfall::Increasing::Marker::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used for `text` lying inside the bar.
class Waterfall::Insidetextfont {
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

    Waterfall::Insidetextfont& color(std::string f);
    Waterfall::Insidetextfont& color(double f);
    Waterfall::Insidetextfont& color(std::vector<std::string> f);
    Waterfall::Insidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Waterfall::Insidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Waterfall::Insidetextfont& family(std::string f);
    Waterfall::Insidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Waterfall::Insidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Waterfall::Insidetextfont& lineposition(std::string f);
    Waterfall::Insidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Waterfall::Insidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Waterfall::Insidetextfont& shadow(std::string f);
    Waterfall::Insidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Waterfall::Insidetextfont& shadowsrc(std::string f);

    Waterfall::Insidetextfont& size(double f);
    Waterfall::Insidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Waterfall::Insidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Waterfall::Insidetextfont& style(enum Style f);
    Waterfall::Insidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Waterfall::Insidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Waterfall::Insidetextfont& textcase(enum Textcase f);
    Waterfall::Insidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Waterfall::Insidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Waterfall::Insidetextfont& variant(enum Variant f);
    Waterfall::Insidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Waterfall::Insidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Waterfall::Insidetextfont& weight(int f);
    Waterfall::Insidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Waterfall::Insidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Waterfall::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Waterfall::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this legend group's title font.
class Waterfall::Legendgrouptitle::Font {
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

    Waterfall::Legendgrouptitle::Font& color(std::string f);
    Waterfall::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Waterfall::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Waterfall::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Waterfall::Legendgrouptitle::Font& shadow(std::string f);

    Waterfall::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Waterfall::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Waterfall::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Waterfall::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Waterfall::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used for `text` lying outside the bar.
class Waterfall::Outsidetextfont {
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

    Waterfall::Outsidetextfont& color(std::string f);
    Waterfall::Outsidetextfont& color(double f);
    Waterfall::Outsidetextfont& color(std::vector<std::string> f);
    Waterfall::Outsidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Waterfall::Outsidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Waterfall::Outsidetextfont& family(std::string f);
    Waterfall::Outsidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Waterfall::Outsidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Waterfall::Outsidetextfont& lineposition(std::string f);
    Waterfall::Outsidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Waterfall::Outsidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Waterfall::Outsidetextfont& shadow(std::string f);
    Waterfall::Outsidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Waterfall::Outsidetextfont& shadowsrc(std::string f);

    Waterfall::Outsidetextfont& size(double f);
    Waterfall::Outsidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Waterfall::Outsidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Waterfall::Outsidetextfont& style(enum Style f);
    Waterfall::Outsidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Waterfall::Outsidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Waterfall::Outsidetextfont& textcase(enum Textcase f);
    Waterfall::Outsidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Waterfall::Outsidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Waterfall::Outsidetextfont& variant(enum Variant f);
    Waterfall::Outsidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Waterfall::Outsidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Waterfall::Outsidetextfont& weight(int f);
    Waterfall::Outsidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Waterfall::Outsidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Waterfall::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Waterfall::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used for `text`.
class Waterfall::Textfont {
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

    Waterfall::Textfont& color(std::string f);
    Waterfall::Textfont& color(double f);
    Waterfall::Textfont& color(std::vector<std::string> f);
    Waterfall::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Waterfall::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Waterfall::Textfont& family(std::string f);
    Waterfall::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Waterfall::Textfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Waterfall::Textfont& lineposition(std::string f);
    Waterfall::Textfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Waterfall::Textfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Waterfall::Textfont& shadow(std::string f);
    Waterfall::Textfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Waterfall::Textfont& shadowsrc(std::string f);

    Waterfall::Textfont& size(double f);
    Waterfall::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Waterfall::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Waterfall::Textfont& style(enum Style f);
    Waterfall::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Waterfall::Textfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Waterfall::Textfont& textcase(enum Textcase f);
    Waterfall::Textfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Waterfall::Textfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Waterfall::Textfont& variant(enum Variant f);
    Waterfall::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Waterfall::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Waterfall::Textfont& weight(int f);
    Waterfall::Textfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Waterfall::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Totals {
 public:

    class Marker;

    Waterfall::Totals& marker(class Marker f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Totals::Marker {
 public:

    class Line;

    // Sets the marker color of all intermediate sums and total values.
    Waterfall::Totals::Marker& color(std::string f);
    Waterfall::Totals::Marker& color(double f);

    Waterfall::Totals::Marker& line(class Line f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Waterfall::Totals::Marker::Line {
 public:

    // Sets the line color of all intermediate sums and total values.
    Waterfall::Totals::Marker::Line& color(std::string f);
    Waterfall::Totals::Marker::Line& color(double f);

    // Sets the line width of all intermediate sums and total values.
    Waterfall::Totals::Marker::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp

#include "impl/waterfall_impl.hpp"
