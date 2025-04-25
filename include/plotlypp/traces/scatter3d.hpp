// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <plotlypp/trace.hpp>
#include <plotlypp/traits.hpp>

#include <plotlypp/json.hpp>

namespace plotlypp {

class Scatter3D : public Trace {
 public:
    Scatter3D()
    : Trace() {
        json["type"] = "scatter3d";
    }

    enum class Surfaceaxis {
        _1,
        NUM_0,
        NUM_1,
        NUM_2,
    };
    static std::string to_string(Surfaceaxis e);

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

    enum class Zcalendar {
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
    static std::string to_string(Zcalendar e);

    class Error_X;
    class Error_Y;
    class Error_Z;
    class Hoverlabel;
    class Legendgrouptitle;
    class Line;
    class Marker;
    class Projection;
    class Stream;
    // Sets the text font.
    class Textfont;

    // Determines whether or not gaps (i.e. {nan} or missing values) in the provided data arrays are connected.
    Scatter3D& connectgaps(bool f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Scatter3D& customdatasrc(std::string f);

    Scatter3D& error_x(class Error_X f);

    Scatter3D& error_y(class Error_Y f);

    Scatter3D& error_z(class Error_Z f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Scatter3D& hoverinfo(std::string f);
    Scatter3D& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Scatter3D& hoverinfosrc(std::string f);

    Scatter3D& hoverlabel(class Hoverlabel f);

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
    Scatter3D& hovertemplate(std::string f);
    Scatter3D& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Scatter3D& hovertemplatesrc(std::string f);

    // Sets text elements associated with each (x,y,z) triplet. If a single string, the same string appears over all the
    // data points. If an array of string, the items are mapped in order to the this trace's (x,y,z) coordinates. To be
    // seen, trace `hoverinfo` must contain a *text* flag.
    Scatter3D& hovertext(std::string f);
    Scatter3D& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Scatter3D& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Scatter3D& idssrc(std::string f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Scatter3D& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Scatter3D& legendgroup(std::string f);

    Scatter3D& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Scatter3D& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Scatter3D& legendwidth(double f);

    Scatter3D& line(class Line f);

    Scatter3D& marker(class Marker f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Scatter3D& meta(T f);
    template <typename T>
    Scatter3D& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Scatter3D& metasrc(std::string f);

    // Determines the drawing mode for this scatter trace. If the provided `mode` includes *text* then the `text`
    // elements appear at the coordinates. Otherwise, the `text` elements appear on hover. If there are less than 20
    // points and the trace is not stacked then the default is *lines+markers*. Otherwise, *lines*.
    // - Default: lines+markers
    // - Flags: ['lines', 'markers', 'text']
    // - Extras ['none']
    Scatter3D& mode(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Scatter3D& name(std::string f);

    // Sets the opacity of the trace.
    Scatter3D& opacity(double f);

    Scatter3D& projection(class Projection f);

    // Sets a reference between this trace's 3D coordinate system and a 3D scene. If *scene* (the default value), the
    // (x,y,z) coordinates refer to `layout.scene`. If *scene2*, the (x,y,z) coordinates refer to `layout.scene2`, and
    // so on.
    Scatter3D& scene(std::string f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Scatter3D& showlegend(bool f);

    Scatter3D& stream(class Stream f);

    // If *-1*, the scatter points are not fill with a surface If *0*, *1*, *2*, the scatter points are filled with a
    // Delaunay surface about the x, y, z respectively.
    // - Default: -1
    Scatter3D& surfaceaxis(enum Surfaceaxis f);

    // Sets the surface fill color.
    Scatter3D& surfacecolor(std::string f);
    Scatter3D& surfacecolor(double f);

    // Sets text elements associated with each (x,y,z) triplet. If a single string, the same string appears over all the
    // data points. If an array of string, the items are mapped in order to the this trace's (x,y,z) coordinates. If
    // trace `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover
    // labels.
    Scatter3D& text(std::string f);
    Scatter3D& text(std::vector<std::string> f);

    // Sets the text font.
    Scatter3D& textfont(class Textfont f);

    // Sets the positions of the `text` elements with respects to the (x,y) coordinates.
    // - Default: top center
    Scatter3D& textposition(enum Textposition f);
    Scatter3D& textposition(const std::vector<enum Textposition>& f);

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Scatter3D& textpositionsrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Scatter3D& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available.
    Scatter3D& texttemplate(std::string f);
    Scatter3D& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Scatter3D& texttemplatesrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Scatter3D& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Scatter3D& uirevision(T f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Scatter3D& visible(enum Visible f);

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D& x(std::vector<T> f);

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Scatter3D& xcalendar(enum Xcalendar f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Scatter3D& xhoverformat(std::string f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Scatter3D& xsrc(std::string f);

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D& y(std::vector<T> f);

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Scatter3D& ycalendar(enum Ycalendar f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Scatter3D& yhoverformat(std::string f);

    // Sets the source reference on Chart Studio Cloud for `y`.
    Scatter3D& ysrc(std::string f);

    // Sets the z coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D& z(std::vector<T> f);

    // Sets the calendar system to use with `z` date data.
    // - Default: gregorian
    Scatter3D& zcalendar(enum Zcalendar f);

    // Sets the hover text formatting rulefor `z`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `zaxis.hoverformat`.
    Scatter3D& zhoverformat(std::string f);

    // Sets the source reference on Chart Studio Cloud for `z`.
    Scatter3D& zsrc(std::string f);
};

class Scatter3D::Error_X {
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
    Scatter3D::Error_X& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Error_X& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Scatter3D::Error_X& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Scatter3D::Error_X& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Scatter3D::Error_X& color(std::string f);
    Scatter3D::Error_X& color(double f);

    Scatter3D::Error_X& copy_zstyle(bool f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Scatter3D::Error_X& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Scatter3D::Error_X& thickness(double f);

    Scatter3D::Error_X& traceref(int f);

    Scatter3D::Error_X& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Scatter3D::Error_X& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Scatter3D::Error_X& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Scatter3D::Error_X& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Scatter3D::Error_X& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Scatter3D::Error_X& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Error_Y {
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
    Scatter3D::Error_Y& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Error_Y& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Scatter3D::Error_Y& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Scatter3D::Error_Y& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Scatter3D::Error_Y& color(std::string f);
    Scatter3D::Error_Y& color(double f);

    Scatter3D::Error_Y& copy_zstyle(bool f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Scatter3D::Error_Y& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Scatter3D::Error_Y& thickness(double f);

    Scatter3D::Error_Y& traceref(int f);

    Scatter3D::Error_Y& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Scatter3D::Error_Y& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Scatter3D::Error_Y& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Scatter3D::Error_Y& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Scatter3D::Error_Y& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Scatter3D::Error_Y& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Error_Z {
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
    Scatter3D::Error_Z& array(std::vector<T> f);

    // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical (horizontal)
    // bars Values are plotted relative to the underlying data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Error_Z& arrayminus(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `arrayminus`.
    Scatter3D::Error_Z& arrayminussrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `array`.
    Scatter3D::Error_Z& arraysrc(std::string f);

    // Sets the stroke color of the error bars.
    Scatter3D::Error_Z& color(std::string f);
    Scatter3D::Error_Z& color(double f);

    // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical bars,
    // left/right for horizontal bars.
    Scatter3D::Error_Z& symmetric(bool f);

    // Sets the thickness (in px) of the error bars.
    Scatter3D::Error_Z& thickness(double f);

    Scatter3D::Error_Z& traceref(int f);

    Scatter3D::Error_Z& tracerefminus(int f);

    // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value. Set
    // this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data. Set this
    // percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data. If *data*, the
    // bar lengths are set with data set `array`.
    Scatter3D::Error_Z& type(enum Type f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars.
    Scatter3D::Error_Z& value(double f);

    // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
    // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
    // (horizontal) bars
    Scatter3D::Error_Z& valueminus(double f);

    // Determines whether or not this set of error bars is visible.
    Scatter3D::Error_Z& visible(bool f);

    // Sets the width (in px) of the cross-bar at both ends of the error bars.
    Scatter3D::Error_Z& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Hoverlabel {
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
    Scatter3D::Hoverlabel& align(enum Align f);
    Scatter3D::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Scatter3D::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Scatter3D::Hoverlabel& bgcolor(std::string f);
    Scatter3D::Hoverlabel& bgcolor(double f);
    Scatter3D::Hoverlabel& bgcolor(std::vector<std::string> f);
    Scatter3D::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Scatter3D::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Scatter3D::Hoverlabel& bordercolor(std::string f);
    Scatter3D::Hoverlabel& bordercolor(double f);
    Scatter3D::Hoverlabel& bordercolor(std::vector<std::string> f);
    Scatter3D::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Scatter3D::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Scatter3D::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Scatter3D::Hoverlabel& namelength(int f);
    Scatter3D::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Scatter3D::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used in hover labels.
class Scatter3D::Hoverlabel::Font {
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

    Scatter3D::Hoverlabel::Font& color(std::string f);
    Scatter3D::Hoverlabel::Font& color(double f);
    Scatter3D::Hoverlabel::Font& color(std::vector<std::string> f);
    Scatter3D::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scatter3D::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Hoverlabel::Font& family(std::string f);
    Scatter3D::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scatter3D::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Hoverlabel::Font& lineposition(std::string f);
    Scatter3D::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Scatter3D::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Hoverlabel::Font& shadow(std::string f);
    Scatter3D::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Scatter3D::Hoverlabel::Font& shadowsrc(std::string f);

    Scatter3D::Hoverlabel::Font& size(double f);
    Scatter3D::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scatter3D::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Hoverlabel::Font& style(enum Style f);
    Scatter3D::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scatter3D::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Hoverlabel::Font& textcase(enum Textcase f);
    Scatter3D::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Scatter3D::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Hoverlabel::Font& variant(enum Variant f);
    Scatter3D::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scatter3D::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Hoverlabel::Font& weight(int f);
    Scatter3D::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scatter3D::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Scatter3D::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Scatter3D::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this legend group's title font.
class Scatter3D::Legendgrouptitle::Font {
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

    Scatter3D::Legendgrouptitle::Font& color(std::string f);
    Scatter3D::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Legendgrouptitle::Font& shadow(std::string f);

    Scatter3D::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Line {
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

    class Colorbar;

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `line.colorscale`. Has an effect only if in `line.color` is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Scatter3D::Line& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in `line.color`) or
    // the bounds set in `line.cmin` and `line.cmax` Has an effect only if in `line.color` is set to a numerical array.
    // Defaults to `false` when `line.cmin` and `line.cmax` are set by the user.
    Scatter3D::Line& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `line.color` is set to a numerical array.
    // Value should have the same units as in `line.color` and if set, `line.cmin` must be set as well.
    Scatter3D::Line& cmax(double f);

    // Sets the mid-point of the color domain by scaling `line.cmin` and/or `line.cmax` to be equidistant to this point.
    // Has an effect only if in `line.color` is set to a numerical array. Value should have the same units as in
    // `line.color`. Has no effect when `line.cauto` is `false`.
    Scatter3D::Line& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `line.color` is set to a numerical array.
    // Value should have the same units as in `line.color` and if set, `line.cmax` must be set as well.
    Scatter3D::Line& cmin(double f);

    // Sets the line color. It accepts either a specific color or an array of numbers that are mapped to the colorscale
    // relative to the max and min values of the array or relative to `line.cmin` and `line.cmax` if set.
    Scatter3D::Line& color(std::string f);
    Scatter3D::Line& color(double f);
    Scatter3D::Line& color(std::vector<std::string> f);
    Scatter3D::Line& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scatter3D::Line& coloraxis(std::string f);

    Scatter3D::Line& colorbar(class Colorbar f);

    // Sets the colorscale. Has an effect only if in `line.color` is set to a numerical array. The colorscale must be an
    // array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At
    // minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'],
    // [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `line.cmin` and `line.cmax`.
    // Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scatter3D::Line& colorscale(std::string f);
    Scatter3D::Line& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scatter3D::Line& colorsrc(std::string f);

    // Sets the dash style of the lines.
    // - Default: solid
    Scatter3D::Line& dash(enum Dash f);

    // Reverses the color mapping if true. Has an effect only if in `line.color` is set to a numerical array. If true,
    // `line.cmin` will correspond to the last color in the array and `line.cmax` will correspond to the first color.
    Scatter3D::Line& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `line.color` is set to
    // a numerical array.
    Scatter3D::Line& showscale(bool f);

    // Sets the line width (in px).
    Scatter3D::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Line::Colorbar {
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
    Scatter3D::Line::Colorbar& bgcolor(std::string f);
    Scatter3D::Line::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Scatter3D::Line::Colorbar& bordercolor(std::string f);
    Scatter3D::Line::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Scatter3D::Line::Colorbar& borderwidth(double f);

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
    Scatter3D::Line::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Scatter3D::Line::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Scatter3D::Line::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Scatter3D::Line::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Scatter3D::Line::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Scatter3D::Line::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Scatter3D::Line::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Scatter3D::Line::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Scatter3D::Line::Colorbar& outlinecolor(std::string f);
    Scatter3D::Line::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Scatter3D::Line::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Scatter3D::Line::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Scatter3D::Line::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Scatter3D::Line::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Scatter3D::Line::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Scatter3D::Line::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Scatter3D::Line::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Scatter3D::Line::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Scatter3D::Line::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Scatter3D::Line::Colorbar& tickangle(double f);

    // Sets the tick color.
    Scatter3D::Line::Colorbar& tickcolor(std::string f);
    Scatter3D::Line::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Scatter3D::Line::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Scatter3D::Line::Colorbar& tickformat(std::string f);

    Scatter3D::Line::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Scatter3D::Line::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Scatter3D::Line::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Scatter3D::Line::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Scatter3D::Line::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Scatter3D::Line::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Scatter3D::Line::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Scatter3D::Line::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Scatter3D::Line::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Line::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Scatter3D::Line::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Line::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Scatter3D::Line::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Scatter3D::Line::Colorbar& tickwidth(double f);

    Scatter3D::Line::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Scatter3D::Line::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Scatter3D::Line::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Scatter3D::Line::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Scatter3D::Line::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Scatter3D::Line::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Scatter3D::Line::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Scatter3D::Line::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Scatter3D::Line::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the color bar's tick label font
class Scatter3D::Line::Colorbar::Tickfont {
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

    Scatter3D::Line::Colorbar::Tickfont& color(std::string f);
    Scatter3D::Line::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Line::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Line::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Line::Colorbar::Tickfont& shadow(std::string f);

    Scatter3D::Line::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Line::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Line::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Line::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Line::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Line::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Scatter3D::Line::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Scatter3D::Line::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Line::Colorbar::Title {
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
    Scatter3D::Line::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Scatter3D::Line::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Scatter3D::Line::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this color bar's title font.
class Scatter3D::Line::Colorbar::Title::Font {
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

    Scatter3D::Line::Colorbar::Title::Font& color(std::string f);
    Scatter3D::Line::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Line::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Line::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Line::Colorbar::Title::Font& shadow(std::string f);

    Scatter3D::Line::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Line::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Line::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Line::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Line::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker {
 public:

    enum class Sizemode {
        DIAMETER,
        AREA,
    };
    static std::string to_string(Sizemode e);

    enum class Symbol {
        CIRCLE,
        CIRCLE_OPEN,
        CROSS,
        DIAMOND,
        DIAMOND_OPEN,
        SQUARE,
        SQUARE_OPEN,
        X,
    };
    static std::string to_string(Symbol e);

    class Colorbar;
    class Line;

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.colorscale`. Has an effect only if in `marker.color` is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Scatter3D::Marker& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in `marker.color`) or
    // the bounds set in `marker.cmin` and `marker.cmax` Has an effect only if in `marker.color` is set to a numerical
    // array. Defaults to `false` when `marker.cmin` and `marker.cmax` are set by the user.
    Scatter3D::Marker& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmin` must be set as well.
    Scatter3D::Marker& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to this
    // point. Has an effect only if in `marker.color` is set to a numerical array. Value should have the same units as
    // in `marker.color`. Has no effect when `marker.cauto` is `false`.
    Scatter3D::Marker& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmax` must be set as well.
    Scatter3D::Marker& cmin(double f);

    // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if set.
    Scatter3D::Marker& color(std::string f);
    Scatter3D::Marker& color(double f);
    Scatter3D::Marker& color(std::vector<std::string> f);
    Scatter3D::Marker& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scatter3D::Marker& coloraxis(std::string f);

    Scatter3D::Marker& colorbar(class Colorbar f);

    // Sets the colorscale. Has an effect only if in `marker.color` is set to a numerical array. The colorscale must be
    // an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At
    // minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'],
    // [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `marker.cmin` and
    // `marker.cmax`. Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scatter3D::Marker& colorscale(std::string f);
    Scatter3D::Marker& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scatter3D::Marker& colorsrc(std::string f);

    Scatter3D::Marker& line(class Line f);

    // Sets the marker opacity. Note that the marker opacity for scatter3d traces must be a scalar value for performance
    // reasons. To set a blending opacity value (i.e. which is not transparent), set *marker.color* to an rgba color and
    // use its alpha channel.
    Scatter3D::Marker& opacity(double f);

    // Reverses the color mapping if true. Has an effect only if in `marker.color` is set to a numerical array. If true,
    // `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the first
    // color.
    Scatter3D::Marker& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `marker.color` is set
    // to a numerical array.
    Scatter3D::Marker& showscale(bool f);

    // Sets the marker size (in px).
    Scatter3D::Marker& size(double f);
    Scatter3D::Marker& size(std::vector<double> f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the minimum size (in px) of the rendered
    // marker points.
    Scatter3D::Marker& sizemin(double f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the rule for which the data in `size` is
    // converted to pixels.
    // - Default: diameter
    Scatter3D::Marker& sizemode(enum Sizemode f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the scale factor used to determine the
    // rendered size of marker points. Use with `sizemin` and `sizemode`.
    Scatter3D::Marker& sizeref(double f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scatter3D::Marker& sizesrc(std::string f);

    // Sets the marker symbol type.
    // - Default: circle
    Scatter3D::Marker& symbol(enum Symbol f);
    Scatter3D::Marker& symbol(const std::vector<enum Symbol>& f);

    // Sets the source reference on Chart Studio Cloud for `symbol`.
    Scatter3D::Marker& symbolsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker::Colorbar {
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
    Scatter3D::Marker::Colorbar& bgcolor(std::string f);
    Scatter3D::Marker::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Scatter3D::Marker::Colorbar& bordercolor(std::string f);
    Scatter3D::Marker::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Scatter3D::Marker::Colorbar& borderwidth(double f);

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
    Scatter3D::Marker::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Scatter3D::Marker::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Scatter3D::Marker::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Scatter3D::Marker::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Scatter3D::Marker::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Scatter3D::Marker::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Scatter3D::Marker::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Scatter3D::Marker::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Scatter3D::Marker::Colorbar& outlinecolor(std::string f);
    Scatter3D::Marker::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Scatter3D::Marker::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Scatter3D::Marker::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Scatter3D::Marker::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Scatter3D::Marker::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Scatter3D::Marker::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Scatter3D::Marker::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Scatter3D::Marker::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Scatter3D::Marker::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Scatter3D::Marker::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Scatter3D::Marker::Colorbar& tickangle(double f);

    // Sets the tick color.
    Scatter3D::Marker::Colorbar& tickcolor(std::string f);
    Scatter3D::Marker::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Scatter3D::Marker::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Scatter3D::Marker::Colorbar& tickformat(std::string f);

    Scatter3D::Marker::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Scatter3D::Marker::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Scatter3D::Marker::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Scatter3D::Marker::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Scatter3D::Marker::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Scatter3D::Marker::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Scatter3D::Marker::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Scatter3D::Marker::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Scatter3D::Marker::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Marker::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Scatter3D::Marker::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scatter3D::Marker::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Scatter3D::Marker::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Scatter3D::Marker::Colorbar& tickwidth(double f);

    Scatter3D::Marker::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Scatter3D::Marker::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Scatter3D::Marker::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Scatter3D::Marker::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Scatter3D::Marker::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Scatter3D::Marker::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Scatter3D::Marker::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Scatter3D::Marker::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Scatter3D::Marker::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the color bar's tick label font
class Scatter3D::Marker::Colorbar::Tickfont {
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

    Scatter3D::Marker::Colorbar::Tickfont& color(std::string f);
    Scatter3D::Marker::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Marker::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Marker::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Marker::Colorbar::Tickfont& shadow(std::string f);

    Scatter3D::Marker::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Marker::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Scatter3D::Marker::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Scatter3D::Marker::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker::Colorbar::Title {
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
    Scatter3D::Marker::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Scatter3D::Marker::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Scatter3D::Marker::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this color bar's title font.
class Scatter3D::Marker::Colorbar::Title::Font {
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

    Scatter3D::Marker::Colorbar::Title::Font& color(std::string f);
    Scatter3D::Marker::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Marker::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scatter3D::Marker::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scatter3D::Marker::Colorbar::Title::Font& shadow(std::string f);

    Scatter3D::Marker::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Marker::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Marker::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Marker::Line {
 public:

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.line.colorscale`. Has an effect only if in `marker.line.color` is set to a numerical array. In case
    // `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen according to whether
    // numbers in the `color` array are all positive, all negative or mixed.
    Scatter3D::Marker::Line& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in
    // `marker.line.color`) or the bounds set in `marker.line.cmin` and `marker.line.cmax` Has an effect only if in
    // `marker.line.color` is set to a numerical array. Defaults to `false` when `marker.line.cmin` and
    // `marker.line.cmax` are set by the user.
    Scatter3D::Marker::Line& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmin` must be set as
    // well.
    Scatter3D::Marker::Line& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.line.cmin` and/or `marker.line.cmax` to be equidistant
    // to this point. Has an effect only if in `marker.line.color` is set to a numerical array. Value should have the
    // same units as in `marker.line.color`. Has no effect when `marker.line.cauto` is `false`.
    Scatter3D::Marker::Line& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmax` must be set as
    // well.
    Scatter3D::Marker::Line& cmin(double f);

    // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
    // `marker.line.cmax` if set.
    Scatter3D::Marker::Line& color(std::string f);
    Scatter3D::Marker::Line& color(double f);
    Scatter3D::Marker::Line& color(std::vector<std::string> f);
    Scatter3D::Marker::Line& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scatter3D::Marker::Line& coloraxis(std::string f);

    // Sets the colorscale. Has an effect only if in `marker.line.color` is set to a numerical array. The colorscale
    // must be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color
    // string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0,
    // 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use
    // `marker.line.cmin` and `marker.line.cmax`. Alternatively, `colorscale` may be a palette name string of the
    // following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scatter3D::Marker::Line& colorscale(std::string f);
    Scatter3D::Marker::Line& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scatter3D::Marker::Line& colorsrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.line.color` is set to a numerical array. If
    // true, `marker.line.cmin` will correspond to the last color in the array and `marker.line.cmax` will correspond to
    // the first color.
    Scatter3D::Marker::Line& reversescale(bool f);

    // Sets the width (in px) of the lines bounding the marker points.
    Scatter3D::Marker::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Projection {
 public:

    class X;
    class Y;
    class Z;

    Scatter3D::Projection& x(class X f);

    Scatter3D::Projection& y(class Y f);

    Scatter3D::Projection& z(class Z f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Projection::X {
 public:

    // Sets the projection color.
    Scatter3D::Projection::X& opacity(double f);

    // Sets the scale factor determining the size of the projection marker points.
    Scatter3D::Projection::X& scale(double f);

    // Sets whether or not projections are shown along the x axis.
    Scatter3D::Projection::X& show(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Projection::Y {
 public:

    // Sets the projection color.
    Scatter3D::Projection::Y& opacity(double f);

    // Sets the scale factor determining the size of the projection marker points.
    Scatter3D::Projection::Y& scale(double f);

    // Sets whether or not projections are shown along the y axis.
    Scatter3D::Projection::Y& show(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Projection::Z {
 public:

    // Sets the projection color.
    Scatter3D::Projection::Z& opacity(double f);

    // Sets the scale factor determining the size of the projection marker points.
    Scatter3D::Projection::Z& scale(double f);

    // Sets whether or not projections are shown along the z axis.
    Scatter3D::Projection::Z& show(bool f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scatter3D::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Scatter3D::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Scatter3D::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the text font.
class Scatter3D::Textfont {
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

    Scatter3D::Textfont& color(std::string f);
    Scatter3D::Textfont& color(double f);
    Scatter3D::Textfont& color(std::vector<std::string> f);
    Scatter3D::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scatter3D::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scatter3D::Textfont& family(std::string f);
    Scatter3D::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scatter3D::Textfont& familysrc(std::string f);

    Scatter3D::Textfont& size(double f);
    Scatter3D::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scatter3D::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scatter3D::Textfont& style(enum Style f);
    Scatter3D::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scatter3D::Textfont& stylesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scatter3D::Textfont& variant(enum Variant f);
    Scatter3D::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scatter3D::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Scatter3D::Textfont& weight(int f);
    Scatter3D::Textfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scatter3D::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp

#include "impl/scatter3d_impl.hpp"
