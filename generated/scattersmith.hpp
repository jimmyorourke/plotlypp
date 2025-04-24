// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <json.hpp>

namespace plotlypp {

class Scattersmith : public Trace {
 public:
    Scattersmith()
    : Trace() {
        json["type"] = "scattersmith";
    }

    enum class Fill {
        NONE,
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

    class Hoverlabel;
    class Legendgrouptitle;
    class Line;
    class Marker;
    class Selected;
    class Stream;
    // Sets the text font.
    class Textfont;
    class Unselected;

    // Determines whether or not markers and text nodes are clipped about the subplot axes. To show markers and text
    // nodes above axis lines and tick labels, make sure to set `xaxis.layer` and `yaxis.layer` to *below traces*.
    Scattersmith& cliponaxis(bool f);

    // Determines whether or not gaps (i.e. {nan} or missing values) in the provided data arrays are connected.
    Scattersmith& connectgaps(bool f);

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith& customdata(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Scattersmith& customdatasrc(std::string f);

    // Sets the area to fill with a solid color. Use with `fillcolor` if not *none*. scattersmith has a subset of the
    // options available to scatter. *toself* connects the endpoints of the trace (or each segment of the trace if it
    // has gaps) into a closed shape. *tonext* fills the space between two traces if one completely encloses the other
    // (eg consecutive contour lines), and behaves like *toself* if there is no trace before it. *tonext* should not be
    // used if one trace does not enclose the other.
    // - Default: none
    Scattersmith& fill(enum Fill f);

    // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
    // color, whichever is available.
    Scattersmith& fillcolor(std::string f);
    Scattersmith& fillcolor(double f);

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['real', 'imag', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Scattersmith& hoverinfo(std::string f);
    Scattersmith& hoverinfo(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Scattersmith& hoverinfosrc(std::string f);

    Scattersmith& hoverlabel(class Hoverlabel f);

    // Do the hover effects highlight individual points (markers or line points) or do they highlight filled regions? If
    // the fill is *toself* or *tonext* and there are no markers or text, then the default is *fills*, otherwise it is
    // *points*.
    // - Flags: ['points', 'fills']
    Scattersmith& hoveron(std::string f);

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
    Scattersmith& hovertemplate(std::string f);
    Scattersmith& hovertemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Scattersmith& hovertemplatesrc(std::string f);

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Scattersmith& hovertext(std::string f);
    Scattersmith& hovertext(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Scattersmith& hovertextsrc(std::string f);

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith& ids(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Scattersmith& idssrc(std::string f);

    // Sets the imaginary component of the data, in units of normalized impedance such that real=1, imag=0 is the center
    // of the chart.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith& imag(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `imag`.
    Scattersmith& imagsrc(std::string f);

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Scattersmith& legend(std::string f);

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Scattersmith& legendgroup(std::string f);

    Scattersmith& legendgrouptitle(class Legendgrouptitle f);

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Scattersmith& legendrank(double f);

    // Sets the width (in px or fraction) of the legend for this trace.
    Scattersmith& legendwidth(double f);

    Scattersmith& line(class Line f);

    Scattersmith& marker(class Marker f);

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Scattersmith& meta(T f);
    template <typename T>
    Scattersmith& meta(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Scattersmith& metasrc(std::string f);

    // Determines the drawing mode for this scatter trace. If the provided `mode` includes *text* then the `text`
    // elements appear at the coordinates. Otherwise, the `text` elements appear on hover. If there are less than 20
    // points and the trace is not stacked then the default is *lines+markers*. Otherwise, *lines*.
    // - Flags: ['lines', 'markers', 'text']
    // - Extras ['none']
    Scattersmith& mode(std::string f);

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Scattersmith& name(std::string f);

    // Sets the opacity of the trace.
    Scattersmith& opacity(double f);

    // Sets the real component of the data, in units of normalized impedance such that real=1, imag=0 is the center of
    // the chart.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith& real(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `real`.
    Scattersmith& realsrc(std::string f);

    Scattersmith& selected(class Selected f);

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Scattersmith& selectedpoints(T f);

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Scattersmith& showlegend(bool f);

    Scattersmith& stream(class Stream f);

    // Sets a reference between this trace's data coordinates and a smith subplot. If *smith* (the default value), the
    // data refer to `layout.smith`. If *smith2*, the data refer to `layout.smith2`, and so on.
    Scattersmith& subplot(std::string f);

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Scattersmith& text(std::string f);
    Scattersmith& text(std::vector<std::string> f);

    // Sets the text font.
    Scattersmith& textfont(class Textfont f);

    // Sets the positions of the `text` elements with respects to the (x,y) coordinates.
    // - Default: middle center
    Scattersmith& textposition(enum Textposition f);
    Scattersmith& textposition(const std::vector<enum Textposition>& f);

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Scattersmith& textpositionsrc(std::string f);

    // Sets the source reference on Chart Studio Cloud for `text`.
    Scattersmith& textsrc(std::string f);

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available. Finally, the
    // template string has access to variables `real`, `imag` and `text`.
    Scattersmith& texttemplate(std::string f);
    Scattersmith& texttemplate(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Scattersmith& texttemplatesrc(std::string f);

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Scattersmith& uid(std::string f);

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Scattersmith& uirevision(T f);

    Scattersmith& unselected(class Unselected f);

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Scattersmith& visible(enum Visible f);
};

class Scattersmith::Hoverlabel {
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
    Scattersmith::Hoverlabel& align(enum Align f);
    Scattersmith::Hoverlabel& align(const std::vector<enum Align>& f);

    // Sets the source reference on Chart Studio Cloud for `align`.
    Scattersmith::Hoverlabel& alignsrc(std::string f);

    // Sets the background color of the hover labels for this trace
    Scattersmith::Hoverlabel& bgcolor(std::string f);
    Scattersmith::Hoverlabel& bgcolor(double f);
    Scattersmith::Hoverlabel& bgcolor(std::vector<std::string> f);
    Scattersmith::Hoverlabel& bgcolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bgcolor`.
    Scattersmith::Hoverlabel& bgcolorsrc(std::string f);

    // Sets the border color of the hover labels for this trace.
    Scattersmith::Hoverlabel& bordercolor(std::string f);
    Scattersmith::Hoverlabel& bordercolor(double f);
    Scattersmith::Hoverlabel& bordercolor(std::vector<std::string> f);
    Scattersmith::Hoverlabel& bordercolor(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `bordercolor`.
    Scattersmith::Hoverlabel& bordercolorsrc(std::string f);

    // Sets the font used in hover labels.
    Scattersmith::Hoverlabel& font(class Font f);

    // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows
    // the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole
    // name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters
    // and add an ellipsis.
    Scattersmith::Hoverlabel& namelength(int f);
    Scattersmith::Hoverlabel& namelength(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `namelength`.
    Scattersmith::Hoverlabel& namelengthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the font used in hover labels.
class Scattersmith::Hoverlabel::Font {
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

    Scattersmith::Hoverlabel::Font& color(std::string f);
    Scattersmith::Hoverlabel::Font& color(double f);
    Scattersmith::Hoverlabel::Font& color(std::vector<std::string> f);
    Scattersmith::Hoverlabel::Font& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattersmith::Hoverlabel::Font& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattersmith::Hoverlabel::Font& family(std::string f);
    Scattersmith::Hoverlabel::Font& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scattersmith::Hoverlabel::Font& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattersmith::Hoverlabel::Font& lineposition(std::string f);
    Scattersmith::Hoverlabel::Font& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Scattersmith::Hoverlabel::Font& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattersmith::Hoverlabel::Font& shadow(std::string f);
    Scattersmith::Hoverlabel::Font& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Scattersmith::Hoverlabel::Font& shadowsrc(std::string f);

    Scattersmith::Hoverlabel::Font& size(double f);
    Scattersmith::Hoverlabel::Font& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattersmith::Hoverlabel::Font& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattersmith::Hoverlabel::Font& style(enum Style f);
    Scattersmith::Hoverlabel::Font& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scattersmith::Hoverlabel::Font& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattersmith::Hoverlabel::Font& textcase(enum Textcase f);
    Scattersmith::Hoverlabel::Font& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Scattersmith::Hoverlabel::Font& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scattersmith::Hoverlabel::Font& variant(enum Variant f);
    Scattersmith::Hoverlabel::Font& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scattersmith::Hoverlabel::Font& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Scattersmith::Hoverlabel::Font& weight(int f);
    Scattersmith::Hoverlabel::Font& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scattersmith::Hoverlabel::Font& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Legendgrouptitle {
 public:

    // Sets this legend group's title font.
    class Font;

    // Sets this legend group's title font.
    Scattersmith::Legendgrouptitle& font(class Font f);

    // Sets the title of the legend group.
    Scattersmith::Legendgrouptitle& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this legend group's title font.
class Scattersmith::Legendgrouptitle::Font {
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

    Scattersmith::Legendgrouptitle::Font& color(std::string f);
    Scattersmith::Legendgrouptitle::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattersmith::Legendgrouptitle::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattersmith::Legendgrouptitle::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattersmith::Legendgrouptitle::Font& shadow(std::string f);

    Scattersmith::Legendgrouptitle::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattersmith::Legendgrouptitle::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattersmith::Legendgrouptitle::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattersmith::Legendgrouptitle::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattersmith::Legendgrouptitle::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Line {
 public:

    enum class Shape {
        LINEAR,
        SPLINE,
    };
    static std::string to_string(Shape e);

    // Sets the line back off from the end point of the nth line segment (in px). This option is useful e.g. to avoid
    // overlap with arrowhead markers. With *auto* the lines would trim before markers if `marker.angleref` is set to
    // *previous*.
    Scattersmith::Line& backoff(double f);
    Scattersmith::Line& backoff(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `backoff`.
    Scattersmith::Line& backoffsrc(std::string f);

    // Sets the line color.
    Scattersmith::Line& color(std::string f);
    Scattersmith::Line& color(double f);

    // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
    // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
    Scattersmith::Line& dash(std::string f);

    // Determines the line shape. With *spline* the lines are drawn using spline interpolation. The other available
    // values correspond to step-wise line shapes.
    // - Default: linear
    Scattersmith::Line& shape(enum Shape f);

    // Has an effect only if `shape` is set to *spline* Sets the amount of smoothing. *0* corresponds to no smoothing
    // (equivalent to a *linear* shape).
    Scattersmith::Line& smoothing(double f);

    // Sets the line width (in px).
    Scattersmith::Line& width(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker {
 public:

    enum class Angleref {
        PREVIOUS,
        UP,
    };
    static std::string to_string(Angleref e);

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
    class Gradient;
    class Line;

    // Sets the marker angle in respect to `angleref`.
    Scattersmith::Marker& angle(double f);
    Scattersmith::Marker& angle(std::vector<double> f);

    // Sets the reference for marker angle. With *previous*, angle 0 points along the line from the previous point to
    // this one. With *up*, angle 0 points toward the top of the screen.
    // - Default: up
    Scattersmith::Marker& angleref(enum Angleref f);

    // Sets the source reference on Chart Studio Cloud for `angle`.
    Scattersmith::Marker& anglesrc(std::string f);

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.colorscale`. Has an effect only if in `marker.color` is set to a numerical array. In case `colorscale` is
    // unspecified or `autocolorscale` is true, the default palette will be chosen according to whether numbers in the
    // `color` array are all positive, all negative or mixed.
    Scattersmith::Marker& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in `marker.color`) or
    // the bounds set in `marker.cmin` and `marker.cmax` Has an effect only if in `marker.color` is set to a numerical
    // array. Defaults to `false` when `marker.cmin` and `marker.cmax` are set by the user.
    Scattersmith::Marker& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmin` must be set as well.
    Scattersmith::Marker& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to this
    // point. Has an effect only if in `marker.color` is set to a numerical array. Value should have the same units as
    // in `marker.color`. Has no effect when `marker.cauto` is `false`.
    Scattersmith::Marker& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.color` is set to a numerical array.
    // Value should have the same units as in `marker.color` and if set, `marker.cmax` must be set as well.
    Scattersmith::Marker& cmin(double f);

    // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if set.
    Scattersmith::Marker& color(std::string f);
    Scattersmith::Marker& color(double f);
    Scattersmith::Marker& color(std::vector<std::string> f);
    Scattersmith::Marker& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scattersmith::Marker& coloraxis(std::string f);

    Scattersmith::Marker& colorbar(class Colorbar f);

    // Sets the colorscale. Has an effect only if in `marker.color` is set to a numerical array. The colorscale must be
    // an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color string. At
    // minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'],
    // [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use `marker.cmin` and
    // `marker.cmax`. Alternatively, `colorscale` may be a palette name string of the following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scattersmith::Marker& colorscale(std::string f);
    Scattersmith::Marker& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattersmith::Marker& colorsrc(std::string f);

    Scattersmith::Marker& gradient(class Gradient f);

    Scattersmith::Marker& line(class Line f);

    // Sets a maximum number of points to be drawn on the graph. *0* corresponds to no limit.
    Scattersmith::Marker& maxdisplayed(double f);

    // Sets the marker opacity.
    Scattersmith::Marker& opacity(double f);
    Scattersmith::Marker& opacity(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `opacity`.
    Scattersmith::Marker& opacitysrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.color` is set to a numerical array. If true,
    // `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the first
    // color.
    Scattersmith::Marker& reversescale(bool f);

    // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `marker.color` is set
    // to a numerical array.
    Scattersmith::Marker& showscale(bool f);

    // Sets the marker size (in px).
    Scattersmith::Marker& size(double f);
    Scattersmith::Marker& size(std::vector<double> f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the minimum size (in px) of the rendered
    // marker points.
    Scattersmith::Marker& sizemin(double f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the rule for which the data in `size` is
    // converted to pixels.
    // - Default: diameter
    Scattersmith::Marker& sizemode(enum Sizemode f);

    // Has an effect only if `marker.size` is set to a numerical array. Sets the scale factor used to determine the
    // rendered size of marker points. Use with `sizemin` and `sizemode`.
    Scattersmith::Marker& sizeref(double f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattersmith::Marker& sizesrc(std::string f);

    // Moves the marker away from the data point in the direction of `angle` (in px). This can be useful for example if
    // you have another marker at this location and you want to point an arrowhead marker at it.
    Scattersmith::Marker& standoff(double f);
    Scattersmith::Marker& standoff(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `standoff`.
    Scattersmith::Marker& standoffsrc(std::string f);

    // Sets the marker symbol type. Adding 100 is equivalent to appending *-open* to a symbol name. Adding 200 is
    // equivalent to appending *-dot* to a symbol name. Adding 300 is equivalent to appending *-open-dot* or *dot-open*
    // to a symbol name.
    // - Default: circle
    Scattersmith::Marker& symbol(enum Symbol f);
    Scattersmith::Marker& symbol(const std::vector<enum Symbol>& f);

    // Sets the source reference on Chart Studio Cloud for `symbol`.
    Scattersmith::Marker& symbolsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Colorbar {
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
    Scattersmith::Marker::Colorbar& bgcolor(std::string f);
    Scattersmith::Marker::Colorbar& bgcolor(double f);

    // Sets the axis line color.
    Scattersmith::Marker::Colorbar& bordercolor(std::string f);
    Scattersmith::Marker::Colorbar& bordercolor(double f);

    // Sets the width (in px) or the border enclosing this color bar.
    Scattersmith::Marker::Colorbar& borderwidth(double f);

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
    Scattersmith::Marker::Colorbar& dtick(T f);

    // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If *none*,
    // it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super script). If *SI*,
    // 1G. If *B*, 1B.
    // - Default: B
    Scattersmith::Marker::Colorbar& exponentformat(enum Exponentformat f);

    // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to USA
    // and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix or
    // ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash. That
    // means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if needed) and
    // values (if desired) can include html-like tags or MathJax.
    template <typename T>
    Scattersmith::Marker::Colorbar& labelalias(T f);

    // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar length is
    // this length minus the padding on both ends.
    Scattersmith::Marker::Colorbar& len(double f);

    // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in units of
    // plot *fraction* or in *pixels. Use `len` to set the value.
    // - Default: fraction
    Scattersmith::Marker::Colorbar& lenmode(enum Lenmode f);

    // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or *B*.
    Scattersmith::Marker::Colorbar& minexponent(double f);

    // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
    // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
    Scattersmith::Marker::Colorbar& nticks(int f);

    // Sets the orientation of the colorbar.
    // - Default: v
    Scattersmith::Marker::Colorbar& orientation(enum Orientation f);

    // Sets the axis line color.
    Scattersmith::Marker::Colorbar& outlinecolor(std::string f);
    Scattersmith::Marker::Colorbar& outlinecolor(double f);

    // Sets the width (in px) of the axis line.
    Scattersmith::Marker::Colorbar& outlinewidth(double f);

    // If "true", even 4-digit integers are separated
    Scattersmith::Marker::Colorbar& separatethousands(bool f);

    // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick is
    // shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
    // - Default: all
    Scattersmith::Marker::Colorbar& showexponent(enum Showexponent f);

    // Determines whether or not the tick labels are drawn.
    Scattersmith::Marker::Colorbar& showticklabels(bool f);

    // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
    // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
    // - Default: all
    Scattersmith::Marker::Colorbar& showtickprefix(enum Showtickprefix f);

    // Same as `showtickprefix` but for tick suffixes.
    // - Default: all
    Scattersmith::Marker::Colorbar& showticksuffix(enum Showticksuffix f);

    // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
    Scattersmith::Marker::Colorbar& thickness(double f);

    // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in units
    // of plot *fraction* or in *pixels*. Use `thickness` to set the value.
    // - Default: pixels
    Scattersmith::Marker::Colorbar& thicknessmode(enum Thicknessmode f);

    // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you must
    // take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when
    // `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string, like date
    // data. If the axis `type` is *category*, it should be a number, using the scale where each category is assigned a
    // serial number from zero in the order it appears.
    template <typename T>
    Scattersmith::Marker::Colorbar& tick0(T f);

    // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
    // tick labels vertically.
    Scattersmith::Marker::Colorbar& tickangle(double f);

    // Sets the tick color.
    Scattersmith::Marker::Colorbar& tickcolor(std::string f);
    Scattersmith::Marker::Colorbar& tickcolor(double f);

    // Sets the color bar's tick label font
    Scattersmith::Marker::Colorbar& tickfont(class Tickfont f);

    // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python.
    // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
    Scattersmith::Marker::Colorbar& tickformat(std::string f);

    Scattersmith::Marker::Colorbar& tickformatstops(class Tickformatstops f);

    // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
    // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
    Scattersmith::Marker::Colorbar& ticklabeloverflow(enum Ticklabeloverflow f);

    // Determines where tick labels are drawn relative to the ticks. Left and right options are used when `orientation`
    // is *h*, top and bottom when `orientation` is *v*.
    // - Default: outside
    Scattersmith::Marker::Colorbar& ticklabelposition(enum Ticklabelposition f);

    // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each
    // tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is
    // labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
    // *multicategory*, or when `tickmode` is *array*.
    Scattersmith::Marker::Colorbar& ticklabelstep(int f);

    // Sets the tick length (in px).
    Scattersmith::Marker::Colorbar& ticklen(double f);

    // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the placement
    // of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the default value
    // if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via `tickvals` and the tick
    // text is `ticktext`. (*array* is the default value if `tickvals` is provided).
    Scattersmith::Marker::Colorbar& tickmode(enum Tickmode f);

    // Sets a tick label prefix.
    Scattersmith::Marker::Colorbar& tickprefix(std::string f);

    // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*), this
    // axis' are drawn outside (inside) the axis lines.
    // - Default:
    Scattersmith::Marker::Colorbar& ticks(enum Ticks f);

    // Sets a tick label suffix.
    Scattersmith::Marker::Colorbar& ticksuffix(std::string f);

    // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to *array*.
    // Used with `tickvals`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith::Marker::Colorbar& ticktext(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `ticktext`.
    Scattersmith::Marker::Colorbar& ticktextsrc(std::string f);

    // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used with
    // `ticktext`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Scattersmith::Marker::Colorbar& tickvals(std::vector<T> f);

    // Sets the source reference on Chart Studio Cloud for `tickvals`.
    Scattersmith::Marker::Colorbar& tickvalssrc(std::string f);

    // Sets the tick width (in px).
    Scattersmith::Marker::Colorbar& tickwidth(double f);

    Scattersmith::Marker::Colorbar& title(class Title f);

    // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*, defaults
    // to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*, defaults to *1*
    // when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if `xref` is *container*
    // and between *-2* and *3* if `xref` is *paper*.
    Scattersmith::Marker::Colorbar& x(double f);

    // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center* or
    // *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is *h*.
    Scattersmith::Marker::Colorbar& xanchor(enum Xanchor f);

    // Sets the amount of padding (in px) along the x direction.
    Scattersmith::Marker::Colorbar& xpad(double f);

    // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the width
    // of the plotting area only.
    // - Default: paper
    Scattersmith::Marker::Colorbar& xref(enum Xref f);

    // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*, defaults
    // to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*, defaults to 0.5
    // when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if `yref` is *container*
    // and between *-2* and *3* if `yref` is *paper*.
    Scattersmith::Marker::Colorbar& y(double f);

    // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
    // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is *h*.
    Scattersmith::Marker::Colorbar& yanchor(enum Yanchor f);

    // Sets the amount of padding (in px) along the y direction.
    Scattersmith::Marker::Colorbar& ypad(double f);

    // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the height
    // of the plotting area only.
    // - Default: paper
    Scattersmith::Marker::Colorbar& yref(enum Yref f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the color bar's tick label font
class Scattersmith::Marker::Colorbar::Tickfont {
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

    Scattersmith::Marker::Colorbar::Tickfont& color(std::string f);
    Scattersmith::Marker::Colorbar::Tickfont& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattersmith::Marker::Colorbar::Tickfont& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattersmith::Marker::Colorbar::Tickfont& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattersmith::Marker::Colorbar::Tickfont& shadow(std::string f);

    Scattersmith::Marker::Colorbar::Tickfont& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Tickfont& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Tickfont& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Tickfont& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattersmith::Marker::Colorbar::Tickfont& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Colorbar::Tickformatstops {
 public:

    class Tickformatstop;

    Scattersmith::Marker::Colorbar::Tickformatstops& tickformatstop(class Tickformatstop f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop {
 public:

    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is possible to omit
    // *min* or *max* value by passing *null*
    Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop& dtickrange(std::vector<std::string> f);

    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its `dtickrange`.
    Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop& enabled(bool f);

    // When used in a template, named items are created in the output figure in addition to any items the figure already
    // has in this array. You can modify these items in the output figure by making your own item with
    // `templateitemname` matching this `name` alongside your modifications (including `visible: false` or `enabled:
    // false` to hide it). Has no effect outside of a template.
    Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop& name(std::string f);

    // Used to refer to a named item in this array in the template. Named items from the template will be created even
    // without a matching item in the input figure, but you can modify one by making an item with `templateitemname`
    // matching its `name`, alongside your modifications (including `visible: false` or `enabled: false` to hide it). If
    // there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible:
    // true`.
    Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop& templateitemname(std::string f);

    // string - dtickformat for described zoom level, the same as *tickformat*
    Scattersmith::Marker::Colorbar::Tickformatstops::Tickformatstop& value(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Colorbar::Title {
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
    Scattersmith::Marker::Colorbar::Title& font(class Font f);

    // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when `orientation`
    // if *v* and  defaults to *right* when `orientation` if *h*.
    Scattersmith::Marker::Colorbar::Title& side(enum Side f);

    // Sets the title of the color bar.
    Scattersmith::Marker::Colorbar::Title& text(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets this color bar's title font.
class Scattersmith::Marker::Colorbar::Title::Font {
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

    Scattersmith::Marker::Colorbar::Title::Font& color(std::string f);
    Scattersmith::Marker::Colorbar::Title::Font& color(double f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattersmith::Marker::Colorbar::Title::Font& family(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattersmith::Marker::Colorbar::Title::Font& lineposition(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattersmith::Marker::Colorbar::Title::Font& shadow(std::string f);

    Scattersmith::Marker::Colorbar::Title::Font& size(double f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Title::Font& style(enum Style f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Title::Font& textcase(enum Textcase f);

    // Sets the variant of the font.
    // - Default: normal
    Scattersmith::Marker::Colorbar::Title::Font& variant(enum Variant f);

    // Sets the weight (or boldness) of the font.
    Scattersmith::Marker::Colorbar::Title::Font& weight(int f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Gradient {
 public:

    enum class Type {
        RADIAL,
        HORIZONTAL,
        VERTICAL,
        NONE,
    };
    static std::string to_string(Type e);

    // Sets the final color of the gradient fill: the center color for radial, the right for horizontal, or the bottom
    // for vertical.
    Scattersmith::Marker::Gradient& color(std::string f);
    Scattersmith::Marker::Gradient& color(double f);
    Scattersmith::Marker::Gradient& color(std::vector<std::string> f);
    Scattersmith::Marker::Gradient& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattersmith::Marker::Gradient& colorsrc(std::string f);

    // Sets the type of gradient used to fill the markers
    // - Default: none
    Scattersmith::Marker::Gradient& type(enum Type f);
    Scattersmith::Marker::Gradient& type(const std::vector<enum Type>& f);

    // Sets the source reference on Chart Studio Cloud for `type`.
    Scattersmith::Marker::Gradient& typesrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Marker::Line {
 public:

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `marker.line.colorscale`. Has an effect only if in `marker.line.color` is set to a numerical array. In case
    // `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen according to whether
    // numbers in the `color` array are all positive, all negative or mixed.
    Scattersmith::Marker::Line& autocolorscale(bool f);

    // Determines whether or not the color domain is computed with respect to the input data (here in
    // `marker.line.color`) or the bounds set in `marker.line.cmin` and `marker.line.cmax` Has an effect only if in
    // `marker.line.color` is set to a numerical array. Defaults to `false` when `marker.line.cmin` and
    // `marker.line.cmax` are set by the user.
    Scattersmith::Marker::Line& cauto(bool f);

    // Sets the upper bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmin` must be set as
    // well.
    Scattersmith::Marker::Line& cmax(double f);

    // Sets the mid-point of the color domain by scaling `marker.line.cmin` and/or `marker.line.cmax` to be equidistant
    // to this point. Has an effect only if in `marker.line.color` is set to a numerical array. Value should have the
    // same units as in `marker.line.color`. Has no effect when `marker.line.cauto` is `false`.
    Scattersmith::Marker::Line& cmid(double f);

    // Sets the lower bound of the color domain. Has an effect only if in `marker.line.color` is set to a numerical
    // array. Value should have the same units as in `marker.line.color` and if set, `marker.line.cmax` must be set as
    // well.
    Scattersmith::Marker::Line& cmin(double f);

    // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to the
    // colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
    // `marker.line.cmax` if set.
    Scattersmith::Marker::Line& color(std::string f);
    Scattersmith::Marker::Line& color(double f);
    Scattersmith::Marker::Line& color(std::vector<std::string> f);
    Scattersmith::Marker::Line& color(std::vector<double> f);

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Scattersmith::Marker::Line& coloraxis(std::string f);

    // Sets the colorscale. Has an effect only if in `marker.line.color` is set to a numerical array. The colorscale
    // must be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color
    // string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0,
    // 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use
    // `marker.line.cmin` and `marker.line.cmax`. Alternatively, `colorscale` may be a palette name string of the
    // following list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Scattersmith::Marker::Line& colorscale(std::string f);
    Scattersmith::Marker::Line& colorscale(std::vector<std::pair<double, std::string>> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattersmith::Marker::Line& colorsrc(std::string f);

    // Reverses the color mapping if true. Has an effect only if in `marker.line.color` is set to a numerical array. If
    // true, `marker.line.cmin` will correspond to the last color in the array and `marker.line.cmax` will correspond to
    // the first color.
    Scattersmith::Marker::Line& reversescale(bool f);

    // Sets the width (in px) of the lines bounding the marker points.
    Scattersmith::Marker::Line& width(double f);
    Scattersmith::Marker::Line& width(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `width`.
    Scattersmith::Marker::Line& widthsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Selected {
 public:

    class Marker;
    class Textfont;

    Scattersmith::Selected& marker(class Marker f);

    Scattersmith::Selected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Selected::Marker {
 public:

    // Sets the marker color of selected points.
    Scattersmith::Selected::Marker& color(std::string f);
    Scattersmith::Selected::Marker& color(double f);

    // Sets the marker opacity of selected points.
    Scattersmith::Selected::Marker& opacity(double f);

    // Sets the marker size of selected points.
    Scattersmith::Selected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Selected::Textfont {
 public:

    // Sets the text font color of selected points.
    Scattersmith::Selected::Textfont& color(std::string f);
    Scattersmith::Selected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Stream {
 public:

    // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to *50*,
    // only the newest 50 points will be displayed on the plot.
    Scattersmith::Stream& maxpoints(double f);

    // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings for
    // more details.
    Scattersmith::Stream& token(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

// Sets the text font.
class Scattersmith::Textfont {
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

    Scattersmith::Textfont& color(std::string f);
    Scattersmith::Textfont& color(double f);
    Scattersmith::Textfont& color(std::vector<std::string> f);
    Scattersmith::Textfont& color(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `color`.
    Scattersmith::Textfont& colorsrc(std::string f);

    // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
    // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
    // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
    // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select
    // number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid
    // Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
    // *Raleway*, *Times New Roman*.
    Scattersmith::Textfont& family(std::string f);
    Scattersmith::Textfont& family(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `family`.
    Scattersmith::Textfont& familysrc(std::string f);

    // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as combinations
    // e.g. *under+over*, etc.
    // - Default: none
    // - Flags: ['under', 'over', 'through']
    // - Extras ['none']
    Scattersmith::Textfont& lineposition(std::string f);
    Scattersmith::Textfont& lineposition(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `lineposition`.
    Scattersmith::Textfont& linepositionsrc(std::string f);

    // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text font
    // color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
    Scattersmith::Textfont& shadow(std::string f);
    Scattersmith::Textfont& shadow(std::vector<std::string> f);

    // Sets the source reference on Chart Studio Cloud for `shadow`.
    Scattersmith::Textfont& shadowsrc(std::string f);

    Scattersmith::Textfont& size(double f);
    Scattersmith::Textfont& size(std::vector<double> f);

    // Sets the source reference on Chart Studio Cloud for `size`.
    Scattersmith::Textfont& sizesrc(std::string f);

    // Sets whether a font should be styled with a normal or italic face from its family.
    // - Default: normal
    Scattersmith::Textfont& style(enum Style f);
    Scattersmith::Textfont& style(const std::vector<enum Style>& f);

    // Sets the source reference on Chart Studio Cloud for `style`.
    Scattersmith::Textfont& stylesrc(std::string f);

    // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with each
    // word capitalized.
    // - Default: normal
    Scattersmith::Textfont& textcase(enum Textcase f);
    Scattersmith::Textfont& textcase(const std::vector<enum Textcase>& f);

    // Sets the source reference on Chart Studio Cloud for `textcase`.
    Scattersmith::Textfont& textcasesrc(std::string f);

    // Sets the variant of the font.
    // - Default: normal
    Scattersmith::Textfont& variant(enum Variant f);
    Scattersmith::Textfont& variant(const std::vector<enum Variant>& f);

    // Sets the source reference on Chart Studio Cloud for `variant`.
    Scattersmith::Textfont& variantsrc(std::string f);

    // Sets the weight (or boldness) of the font.
    Scattersmith::Textfont& weight(int f);
    Scattersmith::Textfont& weight(std::vector<int> f);

    // Sets the source reference on Chart Studio Cloud for `weight`.
    Scattersmith::Textfont& weightsrc(std::string f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Unselected {
 public:

    class Marker;
    class Textfont;

    Scattersmith::Unselected& marker(class Marker f);

    Scattersmith::Unselected& textfont(class Textfont f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Unselected::Marker {
 public:

    // Sets the marker color of unselected points, applied only when a selection exists.
    Scattersmith::Unselected::Marker& color(std::string f);
    Scattersmith::Unselected::Marker& color(double f);

    // Sets the marker opacity of unselected points, applied only when a selection exists.
    Scattersmith::Unselected::Marker& opacity(double f);

    // Sets the marker size of unselected points, applied only when a selection exists.
    Scattersmith::Unselected::Marker& size(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

class Scattersmith::Unselected::Textfont {
 public:

    // Sets the text font color of unselected points, applied only when a selection exists.
    Scattersmith::Unselected::Textfont& color(std::string f);
    Scattersmith::Unselected::Textfont& color(double f);

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp

#include "impl/scattersmith_impl.hpp"
