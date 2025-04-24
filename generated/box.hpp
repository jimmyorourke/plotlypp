// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Box : public Trace {
 public:
    Box()
    : Trace() {
        json["type"] = "box";
    }

    enum class Boxmean {
        TRUE,
        SD,
        FALSE,
    };
    static std::string to_string(Boxmean e);

    enum class Boxpoints {
        ALL,
        OUTLIERS,
        SUSPECTEDOUTLIERS,
        FALSE,
    };
    static std::string to_string(Boxpoints e);

    enum class Orientation {
        V,
        H,
    };
    static std::string to_string(Orientation e);

    enum class Quartilemethod {
        LINEAR,
        EXCLUSIVE,
        INCLUSIVE,
    };
    static std::string to_string(Quartilemethod e);

    enum class Sizemode {
        QUARTILES,
        SD,
    };
    static std::string to_string(Sizemode e);

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

    class Hoverlabel;
    class Legendgrouptitle;
    class Line;
    class Marker;
    class Selected;
    class Stream;
    class Unselected;

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Box& alignmentgroup(std::string f);

    // If *true*, the mean of the box(es)' underlying distribution is drawn as a dashed line inside the box(es). If *sd*
    // the standard deviation is also drawn. Defaults to *true* when `mean` is set. Defaults to *sd* when `sd` is set
    // Otherwise defaults to *false*.
    Box& boxmean(enum Boxmean f);

    // If *outliers*, only the sample points lying outside the whiskers are shown If *suspectedoutliers*, the outlier
    // points are shown and points either less than 4*Q1-3*Q3 or greater than 4*Q3-3*Q1 are highlighted (see
    // `outliercolor`) If *all*, all sample points are shown If *false*, only the box(es) are shown with no sample
    // points Defaults to *suspectedoutliers* when `marker.outliercolor` or `marker.line.outliercolor` is set. Defaults
    // to *all* under the q1/median/q3 signature. Otherwise defaults to *outliers*.
    Box& boxpoints(enum Boxpoints f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Box& customdatasrc(std::string f);

    // Sets the x coordinate step for multi-box traces set using q1/median/q3.
    Box& dx(double f);

    // Sets the y coordinate step for multi-box traces set using q1/median/q3.
    Box& dy(double f);

    // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
    // color, whichever is available.
    Box& fillcolor(std::string f);
    Box& fillcolor(double f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Box& hoverinfo(std::string f);
    Box& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Box& hoverinfosrc(std::string f);

    Box& hoverlabel(class Hoverlabel f);

    // Do the hover effects highlight individual boxes  or sample points or both?
    // - Default: boxes+points
    // - Flags: ['boxes', 'points']
    Box& hoveron(std::string f);

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
    Box& hovertemplate(std::string f);
    Box& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Box& hovertemplatesrc(std::string f);

    // Same as `text`.
    Box& hovertext(std::string f);
    Box& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Box& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Box& idssrc(std::string f);

    // Sets the amount of jitter in the sample points drawn. If *0*, the sample points align along the distribution
    // axis. If *1*, the sample points are drawn in a random jitter of width equal to the width of the box(es).
    Box& jitter(double f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Box& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Box& legendgroup(std::string f);

    Box& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Box& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Box& legendwidth(double f);

    Box& line(class Line f);

    // Sets the lower fence values. There should be as many items as the number of boxes desired. This attribute has
    // effect only under the q1/median/q3 signature. If `lowerfence` is not provided but a sample (in `y` or `x`) is
    // set, we compute the lower as the last sample point below 1.5 times the IQR.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& lowerfence(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `lowerfence`.
    Box& lowerfencesrc(std::string f);

    Box& marker(class Marker f);

    // Sets the mean values. There should be as many items as the number of boxes desired. This attribute has effect
    // only under the q1/median/q3 signature. If `mean` is not provided but a sample (in `y` or `x`) is set, we compute
    // the mean for each box using the sample values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& mean(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `mean`.
    Box& meansrc(std::string f);

    // Sets the median values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& median(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `median`.
    Box& mediansrc(std::string f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Box& meta(T f);
    template <typename T>
    Box& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Box& metasrc(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover. For box traces, the name will also
    // be used for the position coordinate, if `x` and `x0` (`y` and `y0` if horizontal) are missing and the position
    // axis is categorical
    Box& name(std::string f);

    // Determines whether or not notches are drawn. Notches displays a confidence interval around the median. We compute
    // the confidence interval as median +/- 1.57 * IQR / sqrt(N), where IQR is the interquartile range and N is the
    // sample size. If two boxes' notches do not overlap there is 95% confidence their medians differ. See
    // https://sites.google.com/site/davidsstatistics/home/notched-box-plots for more info. Defaults to *false* unless
    // `notchwidth` or `notchspan` is set.
    Box& notched(bool f);

    // Sets the notch span from the boxes' `median` values. There should be as many items as the number of boxes
    // desired. This attribute has effect only under the q1/median/q3 signature. If `notchspan` is not provided but a
    // sample (in `y` or `x`) is set, we compute it as 1.57 * IQR / sqrt(N), where N is the sample size.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& notchspan(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `notchspan`.
    Box& notchspansrc(std::string f);

    // Sets the width of the notches relative to the box' width. For example, with 0, the notches are as wide as the
    // box(es).
    Box& notchwidth(double f);

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Box& offsetgroup(std::string f);

    // Sets the opacity of the trace.
    Box& opacity(double f);

    // Sets the orientation of the box(es). If *v* (*h*), the distribution is visualized along the vertical
    // (horizontal).
    Box& orientation(enum Orientation f);

    // Sets the position of the sample points in relation to the box(es). If *0*, the sample points are places over the
    // center of the box(es). Positive (negative) values correspond to positions to the right (left) for vertical boxes
    // and above (below) for horizontal boxes
    Box& pointpos(double f);

    // Sets the Quartile 1 values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& q1(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `q1`.
    Box& q1src(std::string f);

    // Sets the Quartile 3 values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& q3(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `q3`.
    Box& q3src(std::string f);

    // Sets the method used to compute the sample's Q1 and Q3 quartiles. The *linear* method uses the 25th percentile
    // for Q1 and 75th percentile for Q3 as computed using method #10 (listed on
    // http://jse.amstat.org/v14n3/langford.html). The *exclusive* method uses the median to divide the ordered dataset
    // into two halves if the sample is odd, it does not include the median in either half - Q1 is then the median of
    // the lower half and Q3 the median of the upper half. The *inclusive* method also uses the median to divide the
    // ordered dataset into two halves but if the sample is odd, it includes the median in both halves - Q1 is then the
    // median of the lower half and Q3 the median of the upper half.
    // - Default: linear
    Box& quartilemethod(enum Quartilemethod f);

    // Sets the standard deviation values. There should be as many items as the number of boxes desired. This attribute
    // has effect only under the q1/median/q3 signature. If `sd` is not provided but a sample (in `y` or `x`) is set, we
    // compute the standard deviation for each box using the sample values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& sd(std::vector<T> f);

    // Scales the box size when sizemode=sd Allowing boxes to be drawn across any stddev range For example 1-stddev,
    // 3-stddev, 5-stddev
    Box& sdmultiple(double f);

    // Sets the source reference on Chart Studio Cloud for `sd`.
    Box& sdsrc(std::string f);

    Box& selected(class Selected f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Box& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Box& showlegend(bool f);

    // Determines whether or not whiskers are visible. Defaults to true for `sizemode` *quartiles*, false for *sd*.
    Box& showwhiskers(bool f);

    // Sets the upper and lower bound for the boxes quartiles means box is drawn between Q1 and Q3 SD means the box is
    // drawn between Mean +- Standard Deviation Argument sdmultiple (default 1) to scale the box size So it could be
    // drawn 1-stddev, 3-stddev etc
    // - Default: quartiles
    Box& sizemode(enum Sizemode f);

    Box& stream(class Stream f);

    // Sets the text elements associated with each sample value. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Box& text(std::string f);
    Box& text(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Box& textsrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Box& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Box& uirevision(T f);

    Box& unselected(class Unselected f);

    // Sets the upper fence values. There should be as many items as the number of boxes desired. This attribute has
    // effect only under the q1/median/q3 signature. If `upperfence` is not provided but a sample (in `y` or `x`) is
    // set, we compute the upper as the last sample point above 1.5 times the IQR.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& upperfence(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `upperfence`.
    Box& upperfencesrc(std::string f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Box& visible(enum Visible f);

    // Sets the width of the whiskers relative to the box' width. For example, with 1, the whiskers are as wide as the
    // box(es).
    Box& whiskerwidth(double f);

    // Sets the width of the box in data coordinate If *0* (default value) the width is automatically selected based on
    // the positions of other box traces in the same subplot.
    Box& width(double f);

    // Sets the x sample data or coordinates. See overview for more info.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& x(std::vector<T> f);

    // Sets the x coordinate for single-box traces or the starting coordinate for multi-box traces set using
    // q1/median/q3. See overview for more info.
    template <typename T>
    Box& x0(T f);

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Box& xaxis(std::string f);

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Box& xcalendar(enum Xcalendar f);

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Box& xhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Box& xperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Box& xperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Box& xperiodalignment(enum Xperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `x`.
    Box& xsrc(std::string f);

    // Sets the y sample data or coordinates. See overview for more info.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& y(std::vector<T> f);

    // Sets the y coordinate for single-box traces or the starting coordinate for multi-box traces set using
    // q1/median/q3. See overview for more info.
    template <typename T>
    Box& y0(T f);

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Box& yaxis(std::string f);

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Box& ycalendar(enum Ycalendar f);

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Box& yhoverformat(std::string f);

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Box& yperiod(T f);

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Box& yperiod0(T f);

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Box& yperiodalignment(enum Yperiodalignment f);

    // Sets the source reference on Chart Studio Cloud for `y`.
    Box& ysrc(std::string f);

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Box& zorder(int f);
};

class Box::Hoverlabel {
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
    Box::Hoverlabel& align(enum Align f);
    Box::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Box::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Box::Hoverlabel& bgcolor(std::string f);
    Box::Hoverlabel& bgcolor(double f);
    Box::Hoverlabel& bgcolor(std::vector<std::string> f);
    Box::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Box::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Box::Hoverlabel& bordercolor(std::string f);
    Box::Hoverlabel& bordercolor(double f);
    Box::Hoverlabel& bordercolor(std::vector<std::string> f);
    Box::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Box::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Box::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Box::Hoverlabel& namelength(int f);
    Box::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Box::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets the font used in hover labels.
class Box::Hoverlabel::Font {
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

    Box::Hoverlabel::Font& color(std::string f);
    Box::Hoverlabel::Font& color(double f);
    Box::Hoverlabel::Font& color(std::vector<std::string> f);
    Box::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Box::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Box::Hoverlabel::Font& family(std::string f);
    Box::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Box::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Box::Hoverlabel::Font& lineposition(std::string f);
    Box::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Box::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Box::Hoverlabel::Font& shadow(std::string f);
    Box::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Box::Hoverlabel::Font& shadowsrc(std::string f);

    Box::Hoverlabel::Font& size(double f);
    Box::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Box::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Box::Hoverlabel::Font& style(enum Style f);
    Box::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Box::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Box::Hoverlabel::Font& textcase(enum Textcase f);
    Box::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Box::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Box::Hoverlabel::Font& variant(enum Variant f);
    Box::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Box::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Box::Hoverlabel::Font& weight(int f);
    Box::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Box::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Box::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Box::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

// Sets this legend group's title font.
class Box::Legendgrouptitle::Font {
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

    Box::Legendgrouptitle::Font& color(std::string f);
    Box::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Box::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Box::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Box::Legendgrouptitle::Font& shadow(std::string f);

    Box::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Box::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Box::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Box::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Box::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Line {
 public:

    // Sets the color of line bounding the box(es).
    Box::Line& color(std::string f);
    Box::Line& color(double f);

    // Sets the width (in px) of line bounding the box(es).
    Box::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Marker {
 public:

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

    class Line;

    // Sets the marker angle in respect to `angleref`.
    Box::Marker& angle(double f);

    // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if set.
    Box::Marker& color(std::string f);
    Box::Marker& color(double f);

    Box::Marker& line(class Line f);

    // Sets the marker opacity.
    Box::Marker& opacity(double f);

    // Sets the color of the outlier sample points.
    Box::Marker& outliercolor(std::string f);
    Box::Marker& outliercolor(double f);

    // Sets the marker size (in px).
    Box::Marker& size(double f);

    // Sets the marker symbol type. Adding 100 is equivalent to appending *-open* to a symbol name. Adding 200 is
    // equivalent to appending *-dot* to a symbol name. Adding 300 is equivalent to appending *-open-dot* or *dot-open*
    // to a symbol name.
    // - Default: circle
    Box::Marker& symbol(enum Symbol f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Marker::Line {
 public:

    // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
    // `marker.line.cmax` if set.
    Box::Marker::Line& color(std::string f);
    Box::Marker::Line& color(double f);

    // Sets the border line color of the outlier sample points. Defaults to marker.color
    Box::Marker::Line& outliercolor(std::string f);
    Box::Marker::Line& outliercolor(double f);

    // Sets the border line width (in px) of the outlier sample points.
    Box::Marker::Line& outlierwidth(double f);

    // Sets the width (in px) of the lines bounding the marker points.
    Box::Marker::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Selected {
 public:

    class Marker;

    Box::Selected& marker(class Marker f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Selected::Marker {
 public:

    // Sets the marker color of selected points.
    Box::Selected::Marker& color(std::string f);
    Box::Selected::Marker& color(double f);

    // Sets the marker opacity of selected points.
    Box::Selected::Marker& opacity(double f);

    // Sets the marker size of selected points.
    Box::Selected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Box::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Box::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Unselected {
 public:

    class Marker;

    Box::Unselected& marker(class Marker f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

class Box::Unselected::Marker {
 public:

    // Sets the marker color of unselected points, applied only when a selection exists.
    Box::Unselected::Marker& color(std::string f);
    Box::Unselected::Marker& color(double f);

    // Sets the marker opacity of unselected points, applied only when a selection exists.
    Box::Unselected::Marker& opacity(double f);

    // Sets the marker size of unselected points, applied only when a selection exists.
    Box::Unselected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

} // namespace plotlypp

#include "impl/box_impl.hpp"
