// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Scattergl : public Trace {
 public:
    Scattergl()
    : Trace() {
        json["type"] = "scattergl";
    }

    enum class Fill {
        NONE,
        TOZEROY,
        TOZEROX,
        TONEXTY,
        TONEXTX,
        TOSELF,
        TONEXT,
    };
    static std::string to_string(Fill e);

    enum class Textposition {
        TOP_LEFT,
        TOP_CENTER,
        TOP_RIGHT,
        MIDDLE_LEFT,
        MIDDLE_CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_CENTER,
        BOTTOM_RIGHT,
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
    class Legendgrouptitle;
    class Line;
    class Marker;
    class Selected;
    class Stream;
    // Sets the text font.
    class Textfont;
    class Unselected;

    // Determines whether or not gaps (i.e. {nan} or missing values) in the provided data arrays are connected.
    Scattergl& connectgaps(bool f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Scattergl& customdatasrc(std::string f);

    // Sets the x coordinate step. See `x0` for more info.
    Scattergl& dx(double f);

    // Sets the y coordinate step. See `y0` for more info.
    Scattergl& dy(double f);

    Scattergl& error_x(class Error_X f);

    Scattergl& error_y(class Error_Y f);

    // Sets the area to fill with a solid color. Defaults to *none* unless this trace is stacked, then it gets *tonexty*
    // (*tonextx*) if `orientation` is *v* (*h*) Use with `fillcolor` if not *none*. *tozerox* and *tozeroy* fill to x=0
    // and y=0 respectively. *tonextx* and *tonexty* fill between the endpoints of this trace and the endpoints of the
    // trace before it, connecting those endpoints with straight lines (to make a stacked area graph); if there is no
    // trace before it, they behave like *tozerox* and *tozeroy*. *toself* connects the endpoints of the trace (or each
    // segment of the trace if it has gaps) into a closed shape. *tonext* fills the space between two traces if one
    // completely encloses the other (eg consecutive contour lines), and behaves like *toself* if there is no trace
    // before it. *tonext* should not be used if one trace does not enclose the other. Traces in a `stackgroup` will
    // only fill to (or be filled to) other traces in the same group. With multiple `stackgroup`s or some traces stacked
    // and some not, if fill-linked traces are not already consecutive, the later ones will be pushed down in the
    // drawing order.
    // - Default: none
    Scattergl& fill(enum Fill f);

    // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
    // color, whichever is available.
    Scattergl& fillcolor(std::string f);
    Scattergl& fillcolor(double f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Scattergl& hoverinfo(std::string f);
    Scattergl& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Scattergl& hoverinfosrc(std::string f);

    Scattergl& hoverlabel(class Hoverlabel f);

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
    // specified per-point (the ones that are `arrayOk: true`) are available.  Anything contained in tag `<extra>` is
    // displayed in the secondary box, for example "<extra>{fullData.name}</extra>". To hide the secondary box
    // completely, use an empty tag `<extra></extra>`.
    Scattergl& hovertemplate(std::string f);
    Scattergl& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Scattergl& hovertemplatesrc(std::string f);

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Scattergl& hovertext(std::string f);
    Scattergl& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Scattergl& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Scattergl& idssrc(std::string f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Scattergl& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Scattergl& legendgroup(std::string f);

    Scattergl& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Scattergl& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Scattergl& legendwidth(double f);

    Scattergl& line(class Line f);

    Scattergl& marker(class Marker f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Scattergl& meta(T f);
    template <typename T>
    Scattergl& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Scattergl& metasrc(std::string f);

    // Determines the drawing mode for this scatter trace.
    // - Flags: ['lines', 'markers', 'text']
    // - Extras ['none']
    Scattergl& mode(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Scattergl& name(std::string f);

    // Sets the opacity of the trace.
    Scattergl& opacity(double f);

    Scattergl& selected(class Selected f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Scattergl& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Scattergl& showlegend(bool f);

    Scattergl& stream(class Stream f);

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Scattergl& text(std::string f);
    Scattergl& text(std::vector<std::string> f);

    // Sets the text font.
    Scattergl& textfont(class Textfont f);

    // Sets the positions of the `text` elements with respects to the (x,y) coordinates.
    // - Default: middle center
    Scattergl& textposition(enum Textposition f);
    Scattergl& textposition(const std::vector<enum Textposition>& f);

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Scattergl& textpositionsrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Scattergl& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available.
    Scattergl& texttemplate(std::string f);
    Scattergl& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Scattergl& texttemplatesrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Scattergl& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Scattergl& uirevision(T f);

    Scattergl& unselected(class Unselected f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Scattergl& visible(enum Visible f);

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl& x(std::vector<T> f);

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Scattergl& x0(T f);

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Scattergl& xaxis(std::string f);

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Scattergl& xcalendar(enum Xcalendar f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Scattergl& xhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Scattergl& xperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Scattergl& xperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Scattergl& xperiodalignment(enum Xperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Scattergl& xsrc(std::string f);

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl& y(std::vector<T> f);

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Scattergl& y0(T f);

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Scattergl& yaxis(std::string f);

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Scattergl& ycalendar(enum Ycalendar f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Scattergl& yhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Scattergl& yperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Scattergl& yperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Scattergl& yperiodalignment(enum Yperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `y`.
    Scattergl& ysrc(std::string f);
};

class Scattergl::Error_X {
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
    Scattergl::Error_X& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl::Error_X& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Scattergl::Error_X& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Scattergl::Error_X& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Scattergl::Error_X& color(std::string f);
    Scattergl::Error_X& color(double f);

    Scattergl::Error_X& copy_ystyle(bool f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Scattergl::Error_X& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Scattergl::Error_X& thickness(double f);

    Scattergl::Error_X& traceref(int f);

    Scattergl::Error_X& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Scattergl::Error_X& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Scattergl::Error_X& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Scattergl::Error_X& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Scattergl::Error_X& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Scattergl::Error_X& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Error_Y {
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
    Scattergl::Error_Y& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl::Error_Y& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Scattergl::Error_Y& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Scattergl::Error_Y& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Scattergl::Error_Y& color(std::string f);
    Scattergl::Error_Y& color(double f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Scattergl::Error_Y& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Scattergl::Error_Y& thickness(double f);

    Scattergl::Error_Y& traceref(int f);

    Scattergl::Error_Y& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Scattergl::Error_Y& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Scattergl::Error_Y& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Scattergl::Error_Y& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Scattergl::Error_Y& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Scattergl::Error_Y& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Hoverlabel {
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
    Scattergl::Hoverlabel& align(enum Align f);
    Scattergl::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Scattergl::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Scattergl::Hoverlabel& bgcolor(std::string f);
    Scattergl::Hoverlabel& bgcolor(double f);
    Scattergl::Hoverlabel& bgcolor(std::vector<std::string> f);
    Scattergl::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Scattergl::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Scattergl::Hoverlabel& bordercolor(std::string f);
    Scattergl::Hoverlabel& bordercolor(double f);
    Scattergl::Hoverlabel& bordercolor(std::vector<std::string> f);
    Scattergl::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Scattergl::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Scattergl::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Scattergl::Hoverlabel& namelength(int f);
    Scattergl::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Scattergl::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used in hover labels.
class Scattergl::Hoverlabel::Font {
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

    Scattergl::Hoverlabel::Font& color(std::string f);
    Scattergl::Hoverlabel::Font& color(double f);
    Scattergl::Hoverlabel::Font& color(std::vector<std::string> f);
    Scattergl::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattergl::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattergl::Hoverlabel::Font& family(std::string f);
    Scattergl::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scattergl::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattergl::Hoverlabel::Font& lineposition(std::string f);
    Scattergl::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Scattergl::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattergl::Hoverlabel::Font& shadow(std::string f);
    Scattergl::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Scattergl::Hoverlabel::Font& shadowsrc(std::string f);

    Scattergl::Hoverlabel::Font& size(double f);
    Scattergl::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattergl::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattergl::Hoverlabel::Font& style(enum Style f);
    Scattergl::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scattergl::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattergl::Hoverlabel::Font& textcase(enum Textcase f);
    Scattergl::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Scattergl::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scattergl::Hoverlabel::Font& variant(enum Variant f);
    Scattergl::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scattergl::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Scattergl::Hoverlabel::Font& weight(int f);
    Scattergl::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scattergl::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Scattergl::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Scattergl::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Scattergl::Legendgrouptitle::Font {
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

    Scattergl::Legendgrouptitle::Font& color(std::string f);
    Scattergl::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattergl::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattergl::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattergl::Legendgrouptitle::Font& shadow(std::string f);

    Scattergl::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattergl::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattergl::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattergl::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattergl::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Line {
 public:

    enum class Dash {
        DASH,
        DASHDOT,
        DOT,
        LONGDASH,
        LONGDASHDOT,
        SOLID,
    };
    static std::string to_string(Dash e);

    enum class Shape {
        LINEAR,
        HV,
        VH,
        HVH,
        VHV,
    };
    static std::string to_string(Shape e);

    // Sets the line color.
    Scattergl::Line& color(std::string f);
    Scattergl::Line& color(double f);

    // Sets the style of the lines.
    // - Default: solid
    Scattergl::Line& dash(enum Dash f);

    // Determines the line shape. The values correspond to step-wise line shapes.
    // - Default: linear
    Scattergl::Line& shape(enum Shape f);

    // Sets the line width (in px).
    Scattergl::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker {
 public:

    enum class Sizemode {
        DIAMETER,
        AREA,
    };
    static std::string to_string(Sizemode e);

    enum class Symbol {
        NUM_0,
        CIRCLE,
        NUM_100,
        CIRCLE_OPEN,
        NUM_200,
        CIRCLE_DOT,
        NUM_300,
        CIRCLE_OPEN_DOT,
        NUM_1,
        SQUARE,
        NUM_101,
        SQUARE_OPEN,
        NUM_201,
        SQUARE_DOT,
        NUM_301,
        SQUARE_OPEN_DOT,
        NUM_2,
        DIAMOND,
        NUM_102,
        DIAMOND_OPEN,
        NUM_202,
        DIAMOND_DOT,
        NUM_302,
        DIAMOND_OPEN_DOT,
        NUM_3,
        CROSS,
        NUM_103,
        CROSS_OPEN,
        NUM_203,
        CROSS_DOT,
        NUM_303,
        CROSS_OPEN_DOT,
        NUM_4,
        X,
        NUM_104,
        X_OPEN,
        NUM_204,
        X_DOT,
        NUM_304,
        X_OPEN_DOT,
        NUM_5,
        TRIANGLE_UP,
        NUM_105,
        TRIANGLE_UP_OPEN,
        NUM_205,
        TRIANGLE_UP_DOT,
        NUM_305,
        TRIANGLE_UP_OPEN_DOT,
        NUM_6,
        TRIANGLE_DOWN,
        NUM_106,
        TRIANGLE_DOWN_OPEN,
        NUM_206,
        TRIANGLE_DOWN_DOT,
        NUM_306,
        TRIANGLE_DOWN_OPEN_DOT,
        NUM_7,
        TRIANGLE_LEFT,
        NUM_107,
        TRIANGLE_LEFT_OPEN,
        NUM_207,
        TRIANGLE_LEFT_DOT,
        NUM_307,
        TRIANGLE_LEFT_OPEN_DOT,
        NUM_8,
        TRIANGLE_RIGHT,
        NUM_108,
        TRIANGLE_RIGHT_OPEN,
        NUM_208,
        TRIANGLE_RIGHT_DOT,
        NUM_308,
        TRIANGLE_RIGHT_OPEN_DOT,
        NUM_9,
        TRIANGLE_NE,
        NUM_109,
        TRIANGLE_NE_OPEN,
        NUM_209,
        TRIANGLE_NE_DOT,
        NUM_309,
        TRIANGLE_NE_OPEN_DOT,
        NUM_10,
        TRIANGLE_SE,
        NUM_110,
        TRIANGLE_SE_OPEN,
        NUM_210,
        TRIANGLE_SE_DOT,
        NUM_310,
        TRIANGLE_SE_OPEN_DOT,
        NUM_11,
        TRIANGLE_SW,
        NUM_111,
        TRIANGLE_SW_OPEN,
        NUM_211,
        TRIANGLE_SW_DOT,
        NUM_311,
        TRIANGLE_SW_OPEN_DOT,
        NUM_12,
        TRIANGLE_NW,
        NUM_112,
        TRIANGLE_NW_OPEN,
        NUM_212,
        TRIANGLE_NW_DOT,
        NUM_312,
        TRIANGLE_NW_OPEN_DOT,
        NUM_13,
        PENTAGON,
        NUM_113,
        PENTAGON_OPEN,
        NUM_213,
        PENTAGON_DOT,
        NUM_313,
        PENTAGON_OPEN_DOT,
        NUM_14,
        HEXAGON,
        NUM_114,
        HEXAGON_OPEN,
        NUM_214,
        HEXAGON_DOT,
        NUM_314,
        HEXAGON_OPEN_DOT,
        NUM_15,
        HEXAGON2,
        NUM_115,
        HEXAGON2_OPEN,
        NUM_215,
        HEXAGON2_DOT,
        NUM_315,
        HEXAGON2_OPEN_DOT,
        NUM_16,
        OCTAGON,
        NUM_116,
        OCTAGON_OPEN,
        NUM_216,
        OCTAGON_DOT,
        NUM_316,
        OCTAGON_OPEN_DOT,
        NUM_17,
        STAR,
        NUM_117,
        STAR_OPEN,
        NUM_217,
        STAR_DOT,
        NUM_317,
        STAR_OPEN_DOT,
        NUM_18,
        HEXAGRAM,
        NUM_118,
        HEXAGRAM_OPEN,
        NUM_218,
        HEXAGRAM_DOT,
        NUM_318,
        HEXAGRAM_OPEN_DOT,
        NUM_19,
        STAR_TRIANGLE_UP,
        NUM_119,
        STAR_TRIANGLE_UP_OPEN,
        NUM_219,
        STAR_TRIANGLE_UP_DOT,
        NUM_319,
        STAR_TRIANGLE_UP_OPEN_DOT,
        NUM_20,
        STAR_TRIANGLE_DOWN,
        NUM_120,
        STAR_TRIANGLE_DOWN_OPEN,
        NUM_220,
        STAR_TRIANGLE_DOWN_DOT,
        NUM_320,
        STAR_TRIANGLE_DOWN_OPEN_DOT,
        NUM_21,
        STAR_SQUARE,
        NUM_121,
        STAR_SQUARE_OPEN,
        NUM_221,
        STAR_SQUARE_DOT,
        NUM_321,
        STAR_SQUARE_OPEN_DOT,
        NUM_22,
        STAR_DIAMOND,
        NUM_122,
        STAR_DIAMOND_OPEN,
        NUM_222,
        STAR_DIAMOND_DOT,
        NUM_322,
        STAR_DIAMOND_OPEN_DOT,
        NUM_23,
        DIAMOND_TALL,
        NUM_123,
        DIAMOND_TALL_OPEN,
        NUM_223,
        DIAMOND_TALL_DOT,
        NUM_323,
        DIAMOND_TALL_OPEN_DOT,
        NUM_24,
        DIAMOND_WIDE,
        NUM_124,
        DIAMOND_WIDE_OPEN,
        NUM_224,
        DIAMOND_WIDE_DOT,
        NUM_324,
        DIAMOND_WIDE_OPEN_DOT,
        NUM_25,
        HOURGLASS,
        NUM_125,
        HOURGLASS_OPEN,
        NUM_26,
        BOWTIE,
        NUM_126,
        BOWTIE_OPEN,
        NUM_27,
        CIRCLE_CROSS,
        NUM_127,
        CIRCLE_CROSS_OPEN,
        NUM_28,
        CIRCLE_X,
        NUM_128,
        CIRCLE_X_OPEN,
        NUM_29,
        SQUARE_CROSS,
        NUM_129,
        SQUARE_CROSS_OPEN,
        NUM_30,
        SQUARE_X,
        NUM_130,
        SQUARE_X_OPEN,
        NUM_31,
        DIAMOND_CROSS,
        NUM_131,
        DIAMOND_CROSS_OPEN,
        NUM_32,
        DIAMOND_X,
        NUM_132,
        DIAMOND_X_OPEN,
        NUM_33,
        CROSS_THIN,
        NUM_133,
        CROSS_THIN_OPEN,
        NUM_34,
        X_THIN,
        NUM_134,
        X_THIN_OPEN,
        NUM_35,
        ASTERISK,
        NUM_135,
        ASTERISK_OPEN,
        NUM_36,
        HASH,
        NUM_136,
        HASH_OPEN,
        NUM_236,
        HASH_DOT,
        NUM_336,
        HASH_OPEN_DOT,
        NUM_37,
        Y_UP,
        NUM_137,
        Y_UP_OPEN,
        NUM_38,
        Y_DOWN,
        NUM_138,
        Y_DOWN_OPEN,
        NUM_39,
        Y_LEFT,
        NUM_139,
        Y_LEFT_OPEN,
        NUM_40,
        Y_RIGHT,
        NUM_140,
        Y_RIGHT_OPEN,
        NUM_41,
        LINE_EW,
        NUM_141,
        LINE_EW_OPEN,
        NUM_42,
        LINE_NS,
        NUM_142,
        LINE_NS_OPEN,
        NUM_43,
        LINE_NE,
        NUM_143,
        LINE_NE_OPEN,
        NUM_44,
        LINE_NW,
        NUM_144,
        LINE_NW_OPEN,
        NUM_45,
        ARROW_UP,
        NUM_145,
        ARROW_UP_OPEN,
        NUM_46,
        ARROW_DOWN,
        NUM_146,
        ARROW_DOWN_OPEN,
        NUM_47,
        ARROW_LEFT,
        NUM_147,
        ARROW_LEFT_OPEN,
        NUM_48,
        ARROW_RIGHT,
        NUM_148,
        ARROW_RIGHT_OPEN,
        NUM_49,
        ARROW_BAR_UP,
        NUM_149,
        ARROW_BAR_UP_OPEN,
        NUM_50,
        ARROW_BAR_DOWN,
        NUM_150,
        ARROW_BAR_DOWN_OPEN,
        NUM_51,
        ARROW_BAR_LEFT,
        NUM_151,
        ARROW_BAR_LEFT_OPEN,
        NUM_52,
        ARROW_BAR_RIGHT,
        NUM_152,
        ARROW_BAR_RIGHT_OPEN,
        NUM_53,
        ARROW,
        NUM_153,
        ARROW_OPEN,
        NUM_54,
        ARROW_WIDE,
        NUM_154,
        ARROW_WIDE_OPEN,
    };
    static std::string to_string(Symbol e);

    class Colorbar;
    class Line;

    // Sets the marker angle in respect to `angleref`.
    Scattergl::Marker& angle(double f);
    Scattergl::Marker& angle(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `angle`.
    Scattergl::Marker& anglesrc(std::string f);

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.colorscale`. Has an effect only if in `marker.color` is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Scattergl::Marker& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in `marker.color`) or
    // the bounds set in `marker.cmin` and `marker.cmax` Has an effect only if in `marker.color` is set to a numerical
    // array. Defaults to `false` when `marker.cmin` and `marker.cmax` are set by the user.
    Scattergl::Marker& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmin` must be set as well.
    Scattergl::Marker& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to this
    // point. Has an effect only if in `marker.color` is set to a numerical array. Value should have the same units as
    // in `marker.color`. Has no effect when `marker.cauto` is `false`.
    Scattergl::Marker& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmax` must be set as well.
    Scattergl::Marker& cmin(double f);

    // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if set.
    Scattergl::Marker& color(std::string f);
    Scattergl::Marker& color(double f);
    Scattergl::Marker& color(std::vector<std::string> f);
    Scattergl::Marker& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scattergl::Marker& coloraxis(std::string f);

    Scattergl::Marker& colorbar(class Colorbar f);

    // Sets the colorscale. Has an effect only if in `marker.color` is set to a numerical array. The colorscale must be
    // an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At
    // minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'],
    // [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `marker.cmin` and
    // `marker.cmax`. Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scattergl::Marker& colorscale(std::string f);
    Scattergl::Marker& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattergl::Marker& colorsrc(std::string f);

    Scattergl::Marker& line(class Line f);

    // Sets the marker opacity.
    Scattergl::Marker& opacity(double f);
    Scattergl::Marker& opacity(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `opacity`.
    Scattergl::Marker& opacitysrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.color` is set to a numerical array. If true,
    // `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the first
    // color.
    Scattergl::Marker& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `marker.color` is set
    // to a numerical array.
    Scattergl::Marker& showscale(bool f);

    // Sets the marker size (in px).
    Scattergl::Marker& size(double f);
    Scattergl::Marker& size(std::vector<double> f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the minimum size (in px) of the rendered
    // marker points.
    Scattergl::Marker& sizemin(double f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the rule for which the data in `size` is
    // converted to pixels.
    // - Default: diameter
    Scattergl::Marker& sizemode(enum Sizemode f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the scale factor used to determine the
    // rendered size of marker points. Use with `sizemin` and `sizemode`.
    Scattergl::Marker& sizeref(double f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattergl::Marker& sizesrc(std::string f);

    // Sets the marker symbol type. Adding 100 is equivalent to appending *-open* to a symbol name. Adding 200 is
    // equivalent to appending *-dot* to a symbol name. Adding 300 is equivalent to appending *-open-dot* or *dot-open*
    // to a symbol name.
    // - Default: circle
    Scattergl::Marker& symbol(enum Symbol f);
    Scattergl::Marker& symbol(const std::vector<enum Symbol>& f);

    // Sets the source reference on Chart Studio Cloud for `symbol`.
    Scattergl::Marker& symbolsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker::Colorbar {
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
    Scattergl::Marker::Colorbar& bgcolor(std::string f);
    Scattergl::Marker::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Scattergl::Marker::Colorbar& bordercolor(std::string f);
    Scattergl::Marker::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Scattergl::Marker::Colorbar& borderwidth(double f);

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
    Scattergl::Marker::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Scattergl::Marker::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Scattergl::Marker::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Scattergl::Marker::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Scattergl::Marker::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Scattergl::Marker::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Scattergl::Marker::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Scattergl::Marker::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Scattergl::Marker::Colorbar& outlinecolor(std::string f);
    Scattergl::Marker::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Scattergl::Marker::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Scattergl::Marker::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Scattergl::Marker::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Scattergl::Marker::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Scattergl::Marker::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Scattergl::Marker::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Scattergl::Marker::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Scattergl::Marker::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Scattergl::Marker::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Scattergl::Marker::Colorbar& tickangle(double f);

    // Sets the tick color.
    Scattergl::Marker::Colorbar& tickcolor(std::string f);
    Scattergl::Marker::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Scattergl::Marker::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Scattergl::Marker::Colorbar& tickformat(std::string f);

    Scattergl::Marker::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Scattergl::Marker::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Scattergl::Marker::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Scattergl::Marker::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Scattergl::Marker::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Scattergl::Marker::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Scattergl::Marker::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Scattergl::Marker::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Scattergl::Marker::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl::Marker::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Scattergl::Marker::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattergl::Marker::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Scattergl::Marker::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Scattergl::Marker::Colorbar& tickwidth(double f);

    Scattergl::Marker::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Scattergl::Marker::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Scattergl::Marker::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Scattergl::Marker::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Scattergl::Marker::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Scattergl::Marker::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Scattergl::Marker::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Scattergl::Marker::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Scattergl::Marker::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the color bar's tick label font
class Scattergl::Marker::Colorbar::Tickfont {
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

    Scattergl::Marker::Colorbar::Tickfont& color(std::string f);
    Scattergl::Marker::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattergl::Marker::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattergl::Marker::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattergl::Marker::Colorbar::Tickfont& shadow(std::string f);

    Scattergl::Marker::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattergl::Marker::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattergl::Marker::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattergl::Marker::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattergl::Marker::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Scattergl::Marker::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Scattergl::Marker::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker::Colorbar::Title {
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
    Scattergl::Marker::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Scattergl::Marker::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Scattergl::Marker::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this color bar's title font.
class Scattergl::Marker::Colorbar::Title::Font {
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

    Scattergl::Marker::Colorbar::Title::Font& color(std::string f);
    Scattergl::Marker::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattergl::Marker::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattergl::Marker::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattergl::Marker::Colorbar::Title::Font& shadow(std::string f);

    Scattergl::Marker::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattergl::Marker::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattergl::Marker::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattergl::Marker::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattergl::Marker::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Marker::Line {
 public:

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.line.colorscale`. Has an effect only if in `marker.line.color` is set to a numerical array. In case
    // `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen according to whether
    // numbers in the `color` array are all positive, all negative or mixed.
    Scattergl::Marker::Line& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in
    // `marker.line.color`) or the bounds set in `marker.line.cmin` and `marker.line.cmax` Has an effect only if in
    // `marker.line.color` is set to a numerical array. Defaults to `false` when `marker.line.cmin` and
    // `marker.line.cmax` are set by the user.
    Scattergl::Marker::Line& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmin` must be set as
    // well.
    Scattergl::Marker::Line& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.line.cmin` and/or `marker.line.cmax` to be equidistant
    // to this point. Has an effect only if in `marker.line.color` is set to a numerical array. Value should have the
    // same units as in `marker.line.color`. Has no effect when `marker.line.cauto` is `false`.
    Scattergl::Marker::Line& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmax` must be set as
    // well.
    Scattergl::Marker::Line& cmin(double f);

    // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
    // `marker.line.cmax` if set.
    Scattergl::Marker::Line& color(std::string f);
    Scattergl::Marker::Line& color(double f);
    Scattergl::Marker::Line& color(std::vector<std::string> f);
    Scattergl::Marker::Line& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scattergl::Marker::Line& coloraxis(std::string f);

    // Sets the colorscale. Has an effect only if in `marker.line.color` is set to a numerical array. The colorscale
    // must be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color
    // string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0,
    // 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use
    // `marker.line.cmin` and `marker.line.cmax`. Alternatively, `colorscale` may be a palette name string of the
    // following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scattergl::Marker::Line& colorscale(std::string f);
    Scattergl::Marker::Line& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattergl::Marker::Line& colorsrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.line.color` is set to a numerical array. If
    // true, `marker.line.cmin` will correspond to the last color in the array and `marker.line.cmax` will correspond to
    // the first color.
    Scattergl::Marker::Line& reversescale(bool f);

    // Sets the width (in px) of the lines bounding the marker points.
    Scattergl::Marker::Line& width(double f);
    Scattergl::Marker::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Scattergl::Marker::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Selected {
 public:

    class Marker;
    class Textfont;

    Scattergl::Selected& marker(class Marker f);

    Scattergl::Selected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Selected::Marker {
 public:

    // Sets the marker color of selected points.
    Scattergl::Selected::Marker& color(std::string f);
    Scattergl::Selected::Marker& color(double f);

    // Sets the marker opacity of selected points.
    Scattergl::Selected::Marker& opacity(double f);

    // Sets the marker size of selected points.
    Scattergl::Selected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Selected::Textfont {
 public:

    // Sets the text font color of selected points.
    Scattergl::Selected::Textfont& color(std::string f);
    Scattergl::Selected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Scattergl::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Scattergl::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the text font.
class Scattergl::Textfont {
 public:

    enum class Style {
        NORMAL,
        ITALIC,
    };
    static std::string to_string(Style e);

    enum class Variant {
        NORMAL,
        SMALL_CAPS,
    };
    static std::string to_string(Variant e);

    enum class Weight {
        NORMAL,
        BOLD,
    };
    static std::string to_string(Weight e);

    Scattergl::Textfont& color(std::string f);
    Scattergl::Textfont& color(double f);
    Scattergl::Textfont& color(std::vector<std::string> f);
    Scattergl::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattergl::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattergl::Textfont& family(std::string f);
    Scattergl::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scattergl::Textfont& familysrc(std::string f);

    Scattergl::Textfont& size(double f);
    Scattergl::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattergl::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattergl::Textfont& style(enum Style f);
    Scattergl::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scattergl::Textfont& stylesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scattergl::Textfont& variant(enum Variant f);
    Scattergl::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scattergl::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    // - Default: normal
    Scattergl::Textfont& weight(enum Weight f);
    Scattergl::Textfont& weight(const std::vector<enum Weight>& f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scattergl::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Unselected {
 public:

    class Marker;
    class Textfont;

    Scattergl::Unselected& marker(class Marker f);

    Scattergl::Unselected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Unselected::Marker {
 public:

    // Sets the marker color of unselected points, applied only when a selection exists.
    Scattergl::Unselected::Marker& color(std::string f);
    Scattergl::Unselected::Marker& color(double f);

    // Sets the marker opacity of unselected points, applied only when a selection exists.
    Scattergl::Unselected::Marker& opacity(double f);

    // Sets the marker size of unselected points, applied only when a selection exists.
    Scattergl::Unselected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Scattergl::Unselected::Textfont {
 public:

    // Sets the text font color of unselected points, applied only when a selection exists.
    Scattergl::Unselected::Textfont& color(std::string f);
    Scattergl::Unselected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/scattergl_impl.hpp"
