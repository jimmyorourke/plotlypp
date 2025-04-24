// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Bar : public Trace {
 public:
    Bar()
    : Trace() {
        json["type"] = "bar";
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

    enum class Ycalendar {
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
    static std::string to_string(Ycalendar e);

    enum class Yperiodalignment {
        START,
        MIDDLE,
        END,
    };
    static std::string to_string(Yperiodalignment e);

    class Error_X;
    class Error_Y;
    class Hoverlabel;
    // Sets the font used for `text` lying inside the bar.
    class Insidetextfont;
    class Legendgrouptitle;
    class Marker;
    // Sets the font used for `text` lying outside the bar.
    class Outsidetextfont;
    class Selected;
    class Stream;
    // Sets the font used for `text`.
    class Textfont;
    class Unselected;

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Bar& alignmentgroup(std::string f);

    // Sets where the bar base is drawn (in position axis units). In *stack* or *relative* barmode, traces that set
    // *base* will be excluded and drawn in *overlay* mode instead.
    template <typename T>
    Bar& base(T f);
    template <typename T>
    Bar& base(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `base`.
    Bar& basesrc(std::string f);

    // Determines whether the text nodes are clipped about the subplot axes. To show the text nodes above axis lines and
    // tick labels, make sure to set `xaxis.layer` and `yaxis.layer` to *below traces*.
    Bar& cliponaxis(bool f);

    // Constrain the size of text inside or outside a bar to be no larger than the bar itself.
    // - Default: both
    Bar& constraintext(enum Constraintext f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Bar& customdatasrc(std::string f);

    // Sets the x coordinate step. See `x0` for more info.
    Bar& dx(double f);

    // Sets the y coordinate step. See `y0` for more info.
    Bar& dy(double f);

    Bar& error_x(class Error_X f);

    Bar& error_y(class Error_Y f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Bar& hoverinfo(std::string f);
    Bar& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Bar& hoverinfosrc(std::string f);

    Bar& hoverlabel(class Hoverlabel f);

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
    // variables `value` and `label`. Anything contained in tag `<extra>` is displayed in the secondary box, for example
    // "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an empty tag `<extra></extra>`.
    Bar& hovertemplate(std::string f);
    Bar& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Bar& hovertemplatesrc(std::string f);

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Bar& hovertext(std::string f);
    Bar& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Bar& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Bar& idssrc(std::string f);

    // Determines if texts are kept at center or start/end points in `textposition` *inside* mode.
    // - Default: end
    Bar& insidetextanchor(enum Insidetextanchor f);

    // Sets the font used for `text` lying inside the bar.
    Bar& insidetextfont(class Insidetextfont f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Bar& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Bar& legendgroup(std::string f);

    Bar& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Bar& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Bar& legendwidth(double f);

    Bar& marker(class Marker f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Bar& meta(T f);
    template <typename T>
    Bar& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Bar& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Bar& name(std::string f);

    // Shifts the position where the bar is drawn (in position axis units). In *group* barmode, traces that set *offset*
    // will be excluded and drawn in *overlay* mode instead.
    Bar& offset(double f);
    Bar& offset(std::vector<double> f);

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Bar& offsetgroup(std::string f);

    // Sets the source reference on Chart Studio Cloud for `offset`.
    Bar& offsetsrc(std::string f);

    // Sets the opacity of the trace.
    Bar& opacity(double f);

    // Sets the orientation of the bars. With *v* (*h*), the value of the each bar spans along the vertical
    // (horizontal).
    Bar& orientation(enum Orientation f);

    // Sets the font used for `text` lying outside the bar.
    Bar& outsidetextfont(class Outsidetextfont f);

    Bar& selected(class Selected f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Bar& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Bar& showlegend(bool f);

    Bar& stream(class Stream f);

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Bar& text(std::string f);
    Bar& text(std::vector<std::string> f);

    // Sets the angle of the tick labels with respect to the bar. For example, a `tickangle` of -90 draws the tick
    // labels vertically. With *auto* the texts may automatically be rotated to fit with the maximum size in bars.
    Bar& textangle(double f);

    // Sets the font used for `text`.
    Bar& textfont(class Textfont f);

    // Specifies the location of the `text`. *inside* positions `text` inside, next to the bar end (rotated and scaled
    // if needed). *outside* positions `text` outside, next to the bar end (scaled if needed), unless there is another
    // bar stacked on this one, then the text gets pushed inside. *auto* tries to position `text` inside the bar, but if
    // the bar is too small and no bar is stacked on this one the text is moved outside. If *none*, no text appears.
    // - Default: auto
    Bar& textposition(enum Textposition f);
    Bar& textposition(const std::vector<enum Textposition>& f);

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Bar& textpositionsrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Bar& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available. Finally, the
    // template string has access to variables `value` and `label`.
    Bar& texttemplate(std::string f);
    Bar& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Bar& texttemplatesrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Bar& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Bar& uirevision(T f);

    Bar& unselected(class Unselected f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Bar& visible(enum Visible f);

    // Sets the bar width (in position axis units).
    Bar& width(double f);
    Bar& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Bar& widthsrc(std::string f);

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& x(std::vector<T> f);

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Bar& x0(T f);

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Bar& xaxis(std::string f);

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Bar& xcalendar(enum Xcalendar f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Bar& xhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Bar& xperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Bar& xperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Bar& xperiodalignment(enum Xperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Bar& xsrc(std::string f);

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& y(std::vector<T> f);

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Bar& y0(T f);

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Bar& yaxis(std::string f);

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Bar& ycalendar(enum Ycalendar f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Bar& yhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Bar& yperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Bar& yperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Bar& yperiodalignment(enum Yperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `y`.
    Bar& ysrc(std::string f);

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Bar& zorder(int f);
};

class Bar::Error_X {
 public:

    enum class Type {
        PERCENT,
        CONSTANT,
        SQRT,
        DATA,
    };
    static std::string to_string(Type e);

    // Sets the data corresponding the length of each error bar. Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Error_X& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Error_X& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Bar::Error_X& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Bar::Error_X& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Bar::Error_X& color(std::string f);
    Bar::Error_X& color(double f);

    Bar::Error_X& copy_ystyle(bool f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Bar::Error_X& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Bar::Error_X& thickness(double f);

    Bar::Error_X& traceref(int f);

    Bar::Error_X& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Bar::Error_X& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Bar::Error_X& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Bar::Error_X& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Bar::Error_X& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Bar::Error_X& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Error_Y {
 public:

    enum class Type {
        PERCENT,
        CONSTANT,
        SQRT,
        DATA,
    };
    static std::string to_string(Type e);

    // Sets the data corresponding the length of each error bar. Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Error_Y& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Error_Y& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Bar::Error_Y& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Bar::Error_Y& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Bar::Error_Y& color(std::string f);
    Bar::Error_Y& color(double f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Bar::Error_Y& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Bar::Error_Y& thickness(double f);

    Bar::Error_Y& traceref(int f);

    Bar::Error_Y& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Bar::Error_Y& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Bar::Error_Y& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Bar::Error_Y& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Bar::Error_Y& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Bar::Error_Y& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Hoverlabel {
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
    Bar::Hoverlabel& align(enum Align f);
    Bar::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Bar::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Bar::Hoverlabel& bgcolor(std::string f);
    Bar::Hoverlabel& bgcolor(double f);
    Bar::Hoverlabel& bgcolor(std::vector<std::string> f);
    Bar::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Bar::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Bar::Hoverlabel& bordercolor(std::string f);
    Bar::Hoverlabel& bordercolor(double f);
    Bar::Hoverlabel& bordercolor(std::vector<std::string> f);
    Bar::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Bar::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Bar::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Bar::Hoverlabel& namelength(int f);
    Bar::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Bar::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used in hover labels.
class Bar::Hoverlabel::Font {
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

    Bar::Hoverlabel::Font& color(std::string f);
    Bar::Hoverlabel::Font& color(double f);
    Bar::Hoverlabel::Font& color(std::vector<std::string> f);
    Bar::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Hoverlabel::Font& family(std::string f);
    Bar::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Bar::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Hoverlabel::Font& lineposition(std::string f);
    Bar::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Bar::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Hoverlabel::Font& shadow(std::string f);
    Bar::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Bar::Hoverlabel::Font& shadowsrc(std::string f);

    Bar::Hoverlabel::Font& size(double f);
    Bar::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Bar::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Hoverlabel::Font& style(enum Style f);
    Bar::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Bar::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Hoverlabel::Font& textcase(enum Textcase f);
    Bar::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Bar::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Hoverlabel::Font& variant(enum Variant f);
    Bar::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Bar::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Bar::Hoverlabel::Font& weight(int f);
    Bar::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Bar::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `text` lying inside the bar.
class Bar::Insidetextfont {
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

    Bar::Insidetextfont& color(std::string f);
    Bar::Insidetextfont& color(double f);
    Bar::Insidetextfont& color(std::vector<std::string> f);
    Bar::Insidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Insidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Insidetextfont& family(std::string f);
    Bar::Insidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Bar::Insidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Insidetextfont& lineposition(std::string f);
    Bar::Insidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Bar::Insidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Insidetextfont& shadow(std::string f);
    Bar::Insidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Bar::Insidetextfont& shadowsrc(std::string f);

    Bar::Insidetextfont& size(double f);
    Bar::Insidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Bar::Insidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Insidetextfont& style(enum Style f);
    Bar::Insidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Bar::Insidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Insidetextfont& textcase(enum Textcase f);
    Bar::Insidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Bar::Insidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Insidetextfont& variant(enum Variant f);
    Bar::Insidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Bar::Insidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Bar::Insidetextfont& weight(int f);
    Bar::Insidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Bar::Insidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Bar::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Bar::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Bar::Legendgrouptitle::Font {
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

    Bar::Legendgrouptitle::Font& color(std::string f);
    Bar::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Legendgrouptitle::Font& shadow(std::string f);

    Bar::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Bar::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker {
 public:

    class Colorbar;
    class Line;
    // Sets the pattern within the marker.
    class Pattern;

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.colorscale`. Has an effect only if in `marker.color` is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Bar::Marker& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in `marker.color`) or
    // the bounds set in `marker.cmin` and `marker.cmax` Has an effect only if in `marker.color` is set to a numerical
    // array. Defaults to `false` when `marker.cmin` and `marker.cmax` are set by the user.
    Bar::Marker& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmin` must be set as well.
    Bar::Marker& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to this
    // point. Has an effect only if in `marker.color` is set to a numerical array. Value should have the same units as
    // in `marker.color`. Has no effect when `marker.cauto` is `false`.
    Bar::Marker& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmax` must be set as well.
    Bar::Marker& cmin(double f);

    // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if set.
    Bar::Marker& color(std::string f);
    Bar::Marker& color(double f);
    Bar::Marker& color(std::vector<std::string> f);
    Bar::Marker& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Bar::Marker& coloraxis(std::string f);

    Bar::Marker& colorbar(class Colorbar f);

    // Sets the colorscale. Has an effect only if in `marker.color` is set to a numerical array. The colorscale must be
    // an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At
    // minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'],
    // [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `marker.cmin` and
    // `marker.cmax`. Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Bar::Marker& colorscale(std::string f);
    Bar::Marker& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Marker& colorsrc(std::string f);

    // Sets the rounding of corners. May be an integer number of pixels, or a percentage of bar width (as a string
    // ending in %). Defaults to `layout.barcornerradius`. In stack or relative barmode, the first trace to set
    // cornerradius is used for the whole stack.
    template <typename T>
    Bar::Marker& cornerradius(T f);

    Bar::Marker& line(class Line f);

    // Sets the opacity of the bars.
    Bar::Marker& opacity(double f);
    Bar::Marker& opacity(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `opacity`.
    Bar::Marker& opacitysrc(std::string f);

    // Sets the pattern within the marker.
    Bar::Marker& pattern(class Pattern f);

    // Reverses the color mapping if true. Has an effect only if in `marker.color` is set to a numerical array. If true,
    // `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the first
    // color.
    Bar::Marker& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `marker.color` is set
    // to a numerical array.
    Bar::Marker& showscale(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker::Colorbar {
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
    Bar::Marker::Colorbar& bgcolor(std::string f);
    Bar::Marker::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Bar::Marker::Colorbar& bordercolor(std::string f);
    Bar::Marker::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Bar::Marker::Colorbar& borderwidth(double f);

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
    Bar::Marker::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Bar::Marker::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Bar::Marker::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Bar::Marker::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Bar::Marker::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Bar::Marker::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Bar::Marker::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Bar::Marker::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Bar::Marker::Colorbar& outlinecolor(std::string f);
    Bar::Marker::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Bar::Marker::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Bar::Marker::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Bar::Marker::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Bar::Marker::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Bar::Marker::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Bar::Marker::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Bar::Marker::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Bar::Marker::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Bar::Marker::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Bar::Marker::Colorbar& tickangle(double f);

    // Sets the tick color.
    Bar::Marker::Colorbar& tickcolor(std::string f);
    Bar::Marker::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Bar::Marker::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Bar::Marker::Colorbar& tickformat(std::string f);

    Bar::Marker::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Bar::Marker::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Bar::Marker::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Bar::Marker::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Bar::Marker::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Bar::Marker::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Bar::Marker::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Bar::Marker::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Bar::Marker::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Marker::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Bar::Marker::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar::Marker::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Bar::Marker::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Bar::Marker::Colorbar& tickwidth(double f);

    Bar::Marker::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Bar::Marker::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Bar::Marker::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Bar::Marker::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Bar::Marker::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Bar::Marker::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Bar::Marker::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Bar::Marker::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Bar::Marker::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the color bar's tick label font
class Bar::Marker::Colorbar::Tickfont {
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

    Bar::Marker::Colorbar::Tickfont& color(std::string f);
    Bar::Marker::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Marker::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Marker::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Marker::Colorbar::Tickfont& shadow(std::string f);

    Bar::Marker::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Marker::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Marker::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Marker::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Bar::Marker::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Bar::Marker::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Bar::Marker::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Bar::Marker::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Bar::Marker::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Bar::Marker::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Bar::Marker::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker::Colorbar::Title {
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
    Bar::Marker::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Bar::Marker::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Bar::Marker::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this color bar's title font.
class Bar::Marker::Colorbar::Title::Font {
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

    Bar::Marker::Colorbar::Title::Font& color(std::string f);
    Bar::Marker::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Marker::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Marker::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Marker::Colorbar::Title::Font& shadow(std::string f);

    Bar::Marker::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Marker::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Marker::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Marker::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Bar::Marker::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Marker::Line {
 public:

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.line.colorscale`. Has an effect only if in `marker.line.color` is set to a numerical array. In case
    // `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen according to whether
    // numbers in the `color` array are all positive, all negative or mixed.
    Bar::Marker::Line& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in
    // `marker.line.color`) or the bounds set in `marker.line.cmin` and `marker.line.cmax` Has an effect only if in
    // `marker.line.color` is set to a numerical array. Defaults to `false` when `marker.line.cmin` and
    // `marker.line.cmax` are set by the user.
    Bar::Marker::Line& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmin` must be set as
    // well.
    Bar::Marker::Line& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.line.cmin` and/or `marker.line.cmax` to be equidistant
    // to this point. Has an effect only if in `marker.line.color` is set to a numerical array. Value should have the
    // same units as in `marker.line.color`. Has no effect when `marker.line.cauto` is `false`.
    Bar::Marker::Line& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmax` must be set as
    // well.
    Bar::Marker::Line& cmin(double f);

    // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
    // `marker.line.cmax` if set.
    Bar::Marker::Line& color(std::string f);
    Bar::Marker::Line& color(double f);
    Bar::Marker::Line& color(std::vector<std::string> f);
    Bar::Marker::Line& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Bar::Marker::Line& coloraxis(std::string f);

    // Sets the colorscale. Has an effect only if in `marker.line.color` is set to a numerical array. The colorscale
    // must be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color
    // string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0,
    // 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use
    // `marker.line.cmin` and `marker.line.cmax`. Alternatively, `colorscale` may be a palette name string of the
    // following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Bar::Marker::Line& colorscale(std::string f);
    Bar::Marker::Line& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Marker::Line& colorsrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.line.color` is set to a numerical array. If
    // true, `marker.line.cmin` will correspond to the last color in the array and `marker.line.cmax` will correspond to
    // the first color.
    Bar::Marker::Line& reversescale(bool f);

    // Sets the width (in px) of the lines bounding the marker points.
    Bar::Marker::Line& width(double f);
    Bar::Marker::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Bar::Marker::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the pattern within the marker.
class Bar::Marker::Pattern {
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
    Bar::Marker::Pattern& bgcolor(std::string f);
    Bar::Marker::Pattern& bgcolor(double f);
    Bar::Marker::Pattern& bgcolor(std::vector<std::string> f);
    Bar::Marker::Pattern& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Bar::Marker::Pattern& bgcolorsrc(std::string f);

    // When there is no colorscale sets the color of foreground pattern fill. Defaults to a `marker.color` background
    // when `fillmode` is *replace*. Otherwise, defaults to dark grey or white to increase contrast with the `bgcolor`.
    Bar::Marker::Pattern& fgcolor(std::string f);
    Bar::Marker::Pattern& fgcolor(double f);
    Bar::Marker::Pattern& fgcolor(std::vector<std::string> f);
    Bar::Marker::Pattern& fgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `fgcolor`.
    Bar::Marker::Pattern& fgcolorsrc(std::string f);

    // Sets the opacity of the foreground pattern fill. Defaults to a 0.5 when `fillmode` is *overlay*. Otherwise,
    // defaults to 1.
    Bar::Marker::Pattern& fgopacity(double f);

    // Determines whether `marker.color` should be used as a default to `bgcolor` or a `fgcolor`.
    // - Default: replace
    Bar::Marker::Pattern& fillmode(enum Fillmode f);

    // Sets the shape of the pattern fill. By default, no pattern is used for filling the area.
    // - Default:
    Bar::Marker::Pattern& shape(enum Shape f);
    Bar::Marker::Pattern& shape(const std::vector<enum Shape>& f);

    // Sets the source reference on Chart Studio Cloud for `shape`.
    Bar::Marker::Pattern& shapesrc(std::string f);

    // Sets the size of unit squares of the pattern fill in pixels, which corresponds to the interval of repetition of
    // the pattern.
    Bar::Marker::Pattern& size(double f);
    Bar::Marker::Pattern& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Bar::Marker::Pattern& sizesrc(std::string f);

    // Sets the solidity of the pattern fill. Solidity is roughly the fraction of the area filled by the pattern.
    // Solidity of 0 shows only the background color without pattern and solidty of 1 shows only the foreground color
    // without pattern.
    Bar::Marker::Pattern& solidity(double f);
    Bar::Marker::Pattern& solidity(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `solidity`.
    Bar::Marker::Pattern& soliditysrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `text` lying outside the bar.
class Bar::Outsidetextfont {
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

    Bar::Outsidetextfont& color(std::string f);
    Bar::Outsidetextfont& color(double f);
    Bar::Outsidetextfont& color(std::vector<std::string> f);
    Bar::Outsidetextfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Outsidetextfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Outsidetextfont& family(std::string f);
    Bar::Outsidetextfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Bar::Outsidetextfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Outsidetextfont& lineposition(std::string f);
    Bar::Outsidetextfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Bar::Outsidetextfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Outsidetextfont& shadow(std::string f);
    Bar::Outsidetextfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Bar::Outsidetextfont& shadowsrc(std::string f);

    Bar::Outsidetextfont& size(double f);
    Bar::Outsidetextfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Bar::Outsidetextfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Outsidetextfont& style(enum Style f);
    Bar::Outsidetextfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Bar::Outsidetextfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Outsidetextfont& textcase(enum Textcase f);
    Bar::Outsidetextfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Bar::Outsidetextfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Outsidetextfont& variant(enum Variant f);
    Bar::Outsidetextfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Bar::Outsidetextfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Bar::Outsidetextfont& weight(int f);
    Bar::Outsidetextfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Bar::Outsidetextfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Selected {
 public:

    class Marker;
    class Textfont;

    Bar::Selected& marker(class Marker f);

    Bar::Selected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Selected::Marker {
 public:

    // Sets the marker color of selected points.
    Bar::Selected::Marker& color(std::string f);
    Bar::Selected::Marker& color(double f);

    // Sets the marker opacity of selected points.
    Bar::Selected::Marker& opacity(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Selected::Textfont {
 public:

    // Sets the text font color of selected points.
    Bar::Selected::Textfont& color(std::string f);
    Bar::Selected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Bar::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Bar::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used for `text`.
class Bar::Textfont {
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

    Bar::Textfont& color(std::string f);
    Bar::Textfont& color(double f);
    Bar::Textfont& color(std::vector<std::string> f);
    Bar::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Bar::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Bar::Textfont& family(std::string f);
    Bar::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Bar::Textfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Bar::Textfont& lineposition(std::string f);
    Bar::Textfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Bar::Textfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Bar::Textfont& shadow(std::string f);
    Bar::Textfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Bar::Textfont& shadowsrc(std::string f);

    Bar::Textfont& size(double f);
    Bar::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Bar::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Bar::Textfont& style(enum Style f);
    Bar::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Bar::Textfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Bar::Textfont& textcase(enum Textcase f);
    Bar::Textfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Bar::Textfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Bar::Textfont& variant(enum Variant f);
    Bar::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Bar::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Bar::Textfont& weight(int f);
    Bar::Textfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Bar::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Unselected {
 public:

    class Marker;
    class Textfont;

    Bar::Unselected& marker(class Marker f);

    Bar::Unselected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Unselected::Marker {
 public:

    // Sets the marker color of unselected points, applied only when a selection exists.
    Bar::Unselected::Marker& color(std::string f);
    Bar::Unselected::Marker& color(double f);

    // Sets the marker opacity of unselected points, applied only when a selection exists.
    Bar::Unselected::Marker& opacity(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Bar::Unselected::Textfont {
 public:

    // Sets the text font color of unselected points, applied only when a selection exists.
    Bar::Unselected::Textfont& color(std::string f);
    Bar::Unselected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/bar_impl.hpp"
