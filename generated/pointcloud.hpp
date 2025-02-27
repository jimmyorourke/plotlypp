// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Pointcloud : public Trace {
 public:
    Pointcloud()
    : Trace() {
        json["type"] = "pointcloud";
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
            Font& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }
            Font& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }
            Font& color(std::vector<double> f) {
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
        Hoverlabel& bgcolor(double f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bgcolor(std::vector<std::string> f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bgcolor(std::vector<double> f) {
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
        Hoverlabel& bordercolor(double f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bordercolor(std::vector<std::string> f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }
        Hoverlabel& bordercolor(std::vector<double> f) {
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
            Font& color(double f) {
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

    class Marker {
     public:

        class Border {
         public:

            // Specifies what fraction of the marker area is covered with the border.
            Border& arearatio(double f) {
                json["arearatio"] = std::move(f);
                return *this;
            }

            // Sets the stroke color. It accepts a specific color. If the color is not fully opaque and there are
            // hundreds of thousands of points, it may cause slower zooming and panning.
            Border& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Border& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Determines if colors are blended together for a translucency effect in case `opacity` is specified as a value
        // less then `1`. Setting `blend` to `true` reduces zoom/pan speed if used with large numbers of points.
        Marker& blend(bool f) {
            json["blend"] = std::move(f);
            return *this;
        }

        Marker& border(class Border f) {
            json["border"] = std::move(f.json);
            return *this;
        }

        // Sets the marker fill color. It accepts a specific color. If the color is not fully opaque and there are
        // hundreds of thousands of points, it may cause slower zooming and panning.
        Marker& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Marker& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the marker opacity. The default value is `1` (fully opaque). If the markers are not fully opaque and
        // there are hundreds of thousands of points, it may cause slower zooming and panning. Opacity fades the color
        // even if `blend` is left on `false` even if there is no translucency effect in that case.
        Marker& opacity(double f) {
            json["opacity"] = std::move(f);
            return *this;
        }

        // Sets the maximum size (in px) of the rendered marker points. Effective when the `pointcloud` shows only few
        // points.
        Marker& sizemax(double f) {
            json["sizemax"] = std::move(f);
            return *this;
        }

        // Sets the minimum size (in px) of the rendered marker points, effective when the `pointcloud` shows a million
        // or more points.
        Marker& sizemin(double f) {
            json["sizemin"] = std::move(f);
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

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Pointcloud& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Pointcloud& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Pointcloud& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Pointcloud& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Pointcloud& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Pointcloud& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // A sequential value, 0..n, supply it to avoid creating this array inside plotting. If specified, it must be a
    // typed `Int32Array` array. Its length must be equal to or greater than the number of points. For the best
    // performance and memory use, create one large `indices` typed array that is guaranteed to be at least as long as
    // the largest number of points during use, and reuse it on each `Plotly.restyle()` call.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& indices(std::vector<T> f) {
        json["indices"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `indices`.
    Pointcloud& indicessrc(std::string f) {
        json["indicessrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Pointcloud& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Pointcloud& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Pointcloud& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Pointcloud& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Pointcloud& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Pointcloud& marker(class Marker f) {
        json["marker"] = std::move(f.json);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Pointcloud& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Pointcloud& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Pointcloud& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Pointcloud& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Pointcloud& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Pointcloud& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    Pointcloud& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Pointcloud& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Pointcloud& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Pointcloud& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Pointcloud& uid(std::string f) {
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
    Pointcloud& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Pointcloud& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Pointcloud& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Specify `xbounds` in the shape of `[xMin, xMax] to avoid looping through the `xy` typed array. Use it in
    // conjunction with `xy` and `ybounds` for the performance benefits.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& xbounds(std::vector<T> f) {
        json["xbounds"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `xbounds`.
    Pointcloud& xboundssrc(std::string f) {
        json["xboundssrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Pointcloud& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Faster alternative to specifying `x` and `y` separately. If supplied, it must be a typed `Float32Array` array
    // that represents points such that `xy[i * 2] = x[i]` and `xy[i * 2 + 1] = y[i]`
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& xy(std::vector<T> f) {
        json["xy"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `xy`.
    Pointcloud& xysrc(std::string f) {
        json["xysrc"] = std::move(f);
        return *this;
    }

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Pointcloud& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Specify `ybounds` in the shape of `[yMin, yMax] to avoid looping through the `xy` typed array. Use it in
    // conjunction with `xy` and `xbounds` for the performance benefits.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pointcloud& ybounds(std::vector<T> f) {
        json["ybounds"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ybounds`.
    Pointcloud& yboundssrc(std::string f) {
        json["yboundssrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Pointcloud& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }
};
} // namespace plotlypp
