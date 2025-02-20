// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Candlestick : public Trace {
 public:
    Candlestick()
    : Trace() {
        json["type"] = "candlestick";
    }

    enum class Visible {
        TRUE,
        FALSE,
        LEGENDONLY,
    };
    std::string to_string(Visible e) {
        switch (e) {
        case Visible::TRUE:
            return "True";
        case Visible::FALSE:
            return "False";
        case Visible::LEGENDONLY:
            return "legendonly";
        }
    }

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
    std::string to_string(Xcalendar e) {
        switch (e) {
        case Xcalendar::CHINESE:
            return "chinese";
        case Xcalendar::COPTIC:
            return "coptic";
        case Xcalendar::DISCWORLD:
            return "discworld";
        case Xcalendar::ETHIOPIAN:
            return "ethiopian";
        case Xcalendar::GREGORIAN:
            return "gregorian";
        case Xcalendar::HEBREW:
            return "hebrew";
        case Xcalendar::ISLAMIC:
            return "islamic";
        case Xcalendar::JALALI:
            return "jalali";
        case Xcalendar::JULIAN:
            return "julian";
        case Xcalendar::MAYAN:
            return "mayan";
        case Xcalendar::NANAKSHAHI:
            return "nanakshahi";
        case Xcalendar::NEPALI:
            return "nepali";
        case Xcalendar::PERSIAN:
            return "persian";
        case Xcalendar::TAIWAN:
            return "taiwan";
        case Xcalendar::THAI:
            return "thai";
        case Xcalendar::UMMALQURA:
            return "ummalqura";
        }
    }

    enum class Xperiodalignment {
        START,
        MIDDLE,
        END,
    };
    std::string to_string(Xperiodalignment e) {
        switch (e) {
        case Xperiodalignment::START:
            return "start";
        case Xperiodalignment::MIDDLE:
            return "middle";
        case Xperiodalignment::END:
            return "end";
        }
    }

    class Decreasing {
     public:

        class Line {
         public:

            // Sets the color of line bounding the box(es).
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of line bounding the box(es).
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
        // color, whichever is available.
        Decreasing& fillcolor(std::string f) {
            json["fillcolor"] = std::move(f);
            return *this;
        }

        Decreasing& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Hoverlabel {
     public:

        enum class Align {
            LEFT,
            RIGHT,
            AUTO,
        };
        std::string to_string(Align e) {
            switch (e) {
            case Align::LEFT:
                return "left";
            case Align::RIGHT:
                return "right";
            case Align::AUTO:
                return "auto";
            }
        }

        // Sets the font used in hover labels.
        class Font {
         public:

            Font& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Font& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Font& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // HTML font family - the typeface that will be applied by the web browser. The web browser will only be
            // able to apply a font if it is available on the system which it operates. Provide multiple font families,
            // separated by commas, to indicate the preference in which to apply fonts if they aren't available on the
            // system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a
            // server, where only a select number of fonts are installed and supported. These include *Arial*, *Balto*,
            // *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open
            // Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
            Font& family(std::string f) {
                json["family"] = std::move(f);
                return *this;
            }
            Font& family(std::vector<std::string> f) {
                json["family"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `family`.
            Font& familysrc(std::string f) {
                json["familysrc"] = std::move(f);
                return *this;
            }

            Font& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }
            Font& size(std::vector<double> f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `size`.
            Font& sizesrc(std::string f) {
                json["sizesrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the horizontal alignment of the text content within hover label box. Has an effect only if the hover
        // label text spans more two or more lines
        // - Default: auto
        Hoverlabel& align(enum Align f) {
            json["align"] = to_string(f);
            return *this;
        }
        Hoverlabel& align(const std::vector<enum Align>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["align"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `align`.
        Hoverlabel& alignsrc(std::string f) {
            json["alignsrc"] = std::move(f);
            return *this;
        }

        // Sets the background color of the hover labels for this trace
        Hoverlabel& bgcolor(std::string f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bgcolor(std::vector<std::string> f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `bgcolor`.
        Hoverlabel& bgcolorsrc(std::string f) {
            json["bgcolorsrc"] = std::move(f);
            return *this;
        }

        // Sets the border color of the hover labels for this trace.
        Hoverlabel& bordercolor(std::string f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bordercolor(std::vector<std::string> f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `bordercolor`.
        Hoverlabel& bordercolorsrc(std::string f) {
            json["bordercolorsrc"] = std::move(f);
            return *this;
        }

        // Sets the font used in hover labels.
        Hoverlabel& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1
        // shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show
        // the whole name if it is less than that many characters, but if it is longer, will truncate to `namelength -
        // 3` characters and add an ellipsis.
        Hoverlabel& namelength(int f) {
            json["namelength"] = std::move(f);
            return *this;
        }
        Hoverlabel& namelength(std::vector<int> f) {
            json["namelength"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `namelength`.
        Hoverlabel& namelengthsrc(std::string f) {
            json["namelengthsrc"] = std::move(f);
            return *this;
        }

        // Show hover information (open, close, high, low) in separate labels.
        Hoverlabel& split(bool f) {
            json["split"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Increasing {
     public:

        class Line {
         public:

            // Sets the color of line bounding the box(es).
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of line bounding the box(es).
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
        // color, whichever is available.
        Increasing& fillcolor(std::string f) {
            json["fillcolor"] = std::move(f);
            return *this;
        }

        Increasing& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Legendgrouptitle {
     public:

        // Sets this legend group's title font.
        class Font {
         public:

            Font& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // HTML font family - the typeface that will be applied by the web browser. The web browser will only be
            // able to apply a font if it is available on the system which it operates. Provide multiple font families,
            // separated by commas, to indicate the preference in which to apply fonts if they aren't available on the
            // system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a
            // server, where only a select number of fonts are installed and supported. These include *Arial*, *Balto*,
            // *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open
            // Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
            Font& family(std::string f) {
                json["family"] = std::move(f);
                return *this;
            }

            Font& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets this legend group's title font.
        Legendgrouptitle& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets the title of the legend group.
        Legendgrouptitle& text(std::string f) {
            json["text"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Line {
     public:

        // Sets the width (in px) of line bounding the box(es). Note that this style setting can also be set per
        // direction via `increasing.line.width` and `decreasing.line.width`.
        Line& width(double f) {
            json["width"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Stream {
     public:

        // Sets the maximum number of points to keep on the plots from an incoming stream. If `maxpoints` is set to
        // *50*, only the newest 50 points will be displayed on the plot.
        Stream& maxpoints(double f) {
            json["maxpoints"] = std::move(f);
            return *this;
        }

        // The stream id number links a data trace on a plot with a stream. See https://chart-studio.plotly.com/settings
        // for more details.
        Stream& token(std::string f) {
            json["token"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Transforms {
     public:

        // WARNING: All transforms are deprecated and may be removed from the API in next major version. An array of
        // operations that manipulate the trace data, for example filtering or sorting the data arrays.
        class Transform {
         public:

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // WARNING: All transforms are deprecated and may be removed from the API in next major version. An array of
        // operations that manipulate the trace data, for example filtering or sorting the data arrays.
        Transforms& transform(class Transform f) {
            json["transform"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // Sets the close values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& close(std::vector<T> f) {
        json["close"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `close`.
    Candlestick& closesrc(std::string f) {
        json["closesrc"] = std::move(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Candlestick& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    Candlestick& decreasing(class Decreasing f) {
        json["decreasing"] = std::move(f.json);
        return *this;
    }

    // Sets the high values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& high(std::vector<T> f) {
        json["high"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `high`.
    Candlestick& highsrc(std::string f) {
        json["highsrc"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Candlestick& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Candlestick& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Candlestick& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Candlestick& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

    // Same as `text`.
    Candlestick& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Candlestick& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Candlestick& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Candlestick& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    Candlestick& increasing(class Increasing f) {
        json["increasing"] = std::move(f.json);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Candlestick& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Candlestick& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Candlestick& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Candlestick& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Candlestick& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Candlestick& line(class Line f) {
        json["line"] = std::move(f.json);
        return *this;
    }

    // Sets the low values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& low(std::vector<T> f) {
        json["low"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `low`.
    Candlestick& lowsrc(std::string f) {
        json["lowsrc"] = std::move(f);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Candlestick& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Candlestick& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Candlestick& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Candlestick& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Candlestick& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Sets the open values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& open(std::vector<T> f) {
        json["open"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `open`.
    Candlestick& opensrc(std::string f) {
        json["opensrc"] = std::move(f);
        return *this;
    }

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Candlestick& selectedpoints(T f) {
        json["selectedpoints"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Candlestick& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    Candlestick& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets hover text elements associated with each sample point. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to this trace's sample points.
    Candlestick& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Candlestick& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Candlestick& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    Candlestick& transforms(class Transforms f) {
        json["transforms"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Candlestick& uid(std::string f) {
        json["uid"] = std::move(f);
        return *this;
    }

    // Controls persistence of some user-driven changes to the trace: `constraintrange` in `parcoords` traces, as well
    // as some `editable: true` modifications such as `name` and `colorbar.title`. Defaults to `layout.uirevision`. Note
    // that other user-driven trace attribute changes are controlled by `layout` attributes: `trace.visible` is
    // controlled by `layout.legend.uirevision`, `selectedpoints` is controlled by `layout.selectionrevision`, and
    // `colorbar.(x|y)` (accessible with `config: {editable: true}`) is controlled by `layout.editrevision`. Trace
    // changes are tracked by `uid`, which only falls back on trace index if no `uid` is provided. So if your app can
    // add/remove traces before the end of the `data` array, such that the same trace has a different index, you can
    // still preserve user-driven changes if you give each trace a `uid` that stays with it as it moves.
    template <typename T>
    Candlestick& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Candlestick& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the width of the whiskers relative to the box' width. For example, with 1, the whiskers are as wide as the
    // box(es).
    Candlestick& whiskerwidth(double f) {
        json["whiskerwidth"] = std::move(f);
        return *this;
    }

    // Sets the x coordinates. If absent, linear coordinate will be generated.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Candlestick& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Candlestick& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Candlestick& xcalendar(enum Xcalendar f) {
        json["xcalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Candlestick& xhoverformat(std::string f) {
        json["xhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Candlestick& xperiod(T f) {
        json["xperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Candlestick& xperiod0(T f) {
        json["xperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Candlestick& xperiodalignment(enum Xperiodalignment f) {
        json["xperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Candlestick& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Candlestick& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Candlestick& yhoverformat(std::string f) {
        json["yhoverformat"] = std::move(f);
        return *this;
    }
};
} // namespace plotlypp
