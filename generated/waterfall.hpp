// TODO: includes, copyright, etc
#include <string>
#include <type_traits>
#include <vector>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Waterfall {
 public:
    Waterfall() { json["type"] = "waterfall"; }

    enum class Constraintext {
        INSIDE,
        OUTSIDE,
        BOTH,
        NONE,
    };
    std::string to_string(Constraintext e) {
        switch (e) {
        case Constraintext::INSIDE:
            return "inside";
        case Constraintext::OUTSIDE:
            return "outside";
        case Constraintext::BOTH:
            return "both";
        case Constraintext::NONE:
            return "none";
        }
    }

    enum class Insidetextanchor {
        END,
        MIDDLE,
        START,
    };
    std::string to_string(Insidetextanchor e) {
        switch (e) {
        case Insidetextanchor::END:
            return "end";
        case Insidetextanchor::MIDDLE:
            return "middle";
        case Insidetextanchor::START:
            return "start";
        }
    }

    enum class Orientation {
        V,
        H,
    };
    std::string to_string(Orientation e) {
        switch (e) {
        case Orientation::V:
            return "v";
        case Orientation::H:
            return "h";
        }
    }

    enum class Textposition {
        INSIDE,
        OUTSIDE,
        AUTO,
        NONE,
    };
    std::string to_string(Textposition e) {
        switch (e) {
        case Textposition::INSIDE:
            return "inside";
        case Textposition::OUTSIDE:
            return "outside";
        case Textposition::AUTO:
            return "auto";
        case Textposition::NONE:
            return "none";
        }
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

    enum class Yperiodalignment {
        START,
        MIDDLE,
        END,
    };
    std::string to_string(Yperiodalignment e) {
        switch (e) {
        case Yperiodalignment::START:
            return "start";
        case Yperiodalignment::MIDDLE:
            return "middle";
        case Yperiodalignment::END:
            return "end";
        }
    }

    class Connector {
     public:

        enum class Mode {
            SPANNING,
            BETWEEN,
        };
        std::string to_string(Mode e) {
            switch (e) {
            case Mode::SPANNING:
                return "spanning";
            case Mode::BETWEEN:
                return "between";
            }
        }

        class Line {
         public:

            // Sets the line color.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*,
            // or *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
            Line& dash(std::string f) {
                json["dash"] = std::move(f);
                return *this;
            }

            // Sets the line width (in px).
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Connector& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Sets the shape of connector lines.
        // - Default: between
        Connector& mode(enum Mode f) {
            json["mode"] = to_string(f);
            return *this;
        }

        // Determines if connector lines are drawn.
        Connector& visible(bool f) {
            json["visible"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Decreasing {
     public:

        class Marker {
         public:

            class Line {
             public:

                // Sets the line color of all decreasing values.
                Line& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // Sets the line width of all decreasing values.
                Line& width(double f) {
                    json["width"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            // Sets the marker color of all decreasing values.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            Marker& line(class Line f) {
                json["line"] = std::move(f.json);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Decreasing& marker(class Marker f) {
            json["marker"] = std::move(f.json);
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

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Increasing {
     public:

        class Marker {
         public:

            class Line {
             public:

                // Sets the line color of all increasing values.
                Line& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // Sets the line width of all increasing values.
                Line& width(double f) {
                    json["width"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            // Sets the marker color of all increasing values.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            Marker& line(class Line f) {
                json["line"] = std::move(f.json);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Increasing& marker(class Marker f) {
            json["marker"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // Sets the font used for `text` lying inside the bar.
    class Insidetextfont {
     public:

        Insidetextfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Insidetextfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Insidetextfont& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
        // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
        // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
        // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a
        // select number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid
        // Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT
        // Sans Narrow*, *Raleway*, *Times New Roman*.
        Insidetextfont& family(std::string f) {
            json["family"] = std::move(f);
            return *this;
        }
        Insidetextfont& family(std::vector<std::string> f) {
            json["family"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `family`.
        Insidetextfont& familysrc(std::string f) {
            json["familysrc"] = std::move(f);
            return *this;
        }

        Insidetextfont& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }
        Insidetextfont& size(std::vector<double> f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `size`.
        Insidetextfont& sizesrc(std::string f) {
            json["sizesrc"] = std::move(f);
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

    // Sets the font used for `text` lying outside the bar.
    class Outsidetextfont {
     public:

        Outsidetextfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Outsidetextfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Outsidetextfont& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
        // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
        // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
        // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a
        // select number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid
        // Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT
        // Sans Narrow*, *Raleway*, *Times New Roman*.
        Outsidetextfont& family(std::string f) {
            json["family"] = std::move(f);
            return *this;
        }
        Outsidetextfont& family(std::vector<std::string> f) {
            json["family"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `family`.
        Outsidetextfont& familysrc(std::string f) {
            json["familysrc"] = std::move(f);
            return *this;
        }

        Outsidetextfont& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }
        Outsidetextfont& size(std::vector<double> f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `size`.
        Outsidetextfont& sizesrc(std::string f) {
            json["sizesrc"] = std::move(f);
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

    // Sets the font used for `text`.
    class Textfont {
     public:

        Textfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Textfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Textfont& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        // HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to
        // apply a font if it is available on the system which it operates. Provide multiple font families, separated by
        // commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart
        // Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a
        // select number of fonts are installed and supported. These include *Arial*, *Balto*, *Courier New*, *Droid
        // Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT
        // Sans Narrow*, *Raleway*, *Times New Roman*.
        Textfont& family(std::string f) {
            json["family"] = std::move(f);
            return *this;
        }
        Textfont& family(std::vector<std::string> f) {
            json["family"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `family`.
        Textfont& familysrc(std::string f) {
            json["familysrc"] = std::move(f);
            return *this;
        }

        Textfont& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }
        Textfont& size(std::vector<double> f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `size`.
        Textfont& sizesrc(std::string f) {
            json["sizesrc"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Totals {
     public:

        class Marker {
         public:

            class Line {
             public:

                // Sets the line color of all intermediate sums and total values.
                Line& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // Sets the line width of all intermediate sums and total values.
                Line& width(double f) {
                    json["width"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            // Sets the marker color of all intermediate sums and total values.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            Marker& line(class Line f) {
                json["line"] = std::move(f.json);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Totals& marker(class Marker f) {
            json["marker"] = std::move(f.json);
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

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Waterfall& alignmentgroup(std::string f) {
        json["alignmentgroup"] = std::move(f);
        return *this;
    }

    // Sets where the bar base is drawn (in position axis units).
    Waterfall& base(double f) {
        json["base"] = std::move(f);
        return *this;
    }

    // Determines whether the text nodes are clipped about the subplot axes. To show the text nodes above axis lines and
    // tick labels, make sure to set `xaxis.layer` and `yaxis.layer` to *below traces*.
    Waterfall& cliponaxis(bool f) {
        json["cliponaxis"] = std::move(f);
        return *this;
    }

    Waterfall& connector(class Connector f) {
        json["connector"] = std::move(f.json);
        return *this;
    }

    // Constrain the size of text inside or outside a bar to be no larger than the bar itself.
    // - Default: both
    Waterfall& constraintext(enum Constraintext f) {
        json["constraintext"] = to_string(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Waterfall& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Waterfall& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    Waterfall& decreasing(class Decreasing f) {
        json["decreasing"] = std::move(f.json);
        return *this;
    }

    // Sets the x coordinate step. See `x0` for more info.
    Waterfall& dx(double f) {
        json["dx"] = std::move(f);
        return *this;
    }

    // Sets the y coordinate step. See `y0` for more info.
    Waterfall& dy(double f) {
        json["dy"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['name', 'x', 'y', 'text', 'initial', 'delta', 'final']
    // - Extras ['all', 'none', 'skip']
    Waterfall& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Waterfall& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Waterfall& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Waterfall& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

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
    Waterfall& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Waterfall& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Waterfall& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Waterfall& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Waterfall& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Waterfall& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Waterfall& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Waterfall& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    Waterfall& increasing(class Increasing f) {
        json["increasing"] = std::move(f.json);
        return *this;
    }

    // Determines if texts are kept at center or start/end points in `textposition` *inside* mode.
    // - Default: end
    Waterfall& insidetextanchor(enum Insidetextanchor f) {
        json["insidetextanchor"] = to_string(f);
        return *this;
    }

    // Sets the font used for `text` lying inside the bar.
    Waterfall& insidetextfont(class Insidetextfont f) {
        json["insidetextfont"] = std::move(f.json);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Waterfall& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Waterfall& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Waterfall& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Waterfall& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Waterfall& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    // An array containing types of values. By default the values are considered as 'relative'. However; it is possible
    // to use 'total' to compute the sums. Also 'absolute' could be applied to reset the computed total or to declare an
    // initial value where needed.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Waterfall& measure(std::vector<T> f) {
        json["measure"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `measure`.
    Waterfall& measuresrc(std::string f) {
        json["measuresrc"] = std::move(f);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Waterfall& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Waterfall& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Waterfall& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Waterfall& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Shifts the position where the bar is drawn (in position axis units). In *group* barmode, traces that set *offset*
    // will be excluded and drawn in *overlay* mode instead.
    Waterfall& offset(double f) {
        json["offset"] = std::move(f);
        return *this;
    }
    Waterfall& offset(std::vector<double> f) {
        json["offset"] = std::move(f);
        return *this;
    }

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Waterfall& offsetgroup(std::string f) {
        json["offsetgroup"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `offset`.
    Waterfall& offsetsrc(std::string f) {
        json["offsetsrc"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Waterfall& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Sets the orientation of the bars. With *v* (*h*), the value of the each bar spans along the vertical
    // (horizontal).
    Waterfall& orientation(enum Orientation f) {
        json["orientation"] = to_string(f);
        return *this;
    }

    // Sets the font used for `text` lying outside the bar.
    Waterfall& outsidetextfont(class Outsidetextfont f) {
        json["outsidetextfont"] = std::move(f.json);
        return *this;
    }

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Waterfall& selectedpoints(T f) {
        json["selectedpoints"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Waterfall& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    Waterfall& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Waterfall& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Waterfall& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the angle of the tick labels with respect to the bar. For example, a `tickangle` of -90 draws the tick
    // labels vertically. With *auto* the texts may automatically be rotated to fit with the maximum size in bars.
    Waterfall& textangle(double f) {
        json["textangle"] = std::move(f);
        return *this;
    }

    // Sets the font used for `text`.
    Waterfall& textfont(class Textfont f) {
        json["textfont"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on the graph. In the case of having multiple waterfalls, totals are
    // computed separately (per trace).
    // - Flags: ['label', 'text', 'initial', 'delta', 'final']
    // - Extras ['none']
    Waterfall& textinfo(std::string f) {
        json["textinfo"] = std::move(f);
        return *this;
    }

    // Specifies the location of the `text`. *inside* positions `text` inside, next to the bar end (rotated and scaled
    // if needed). *outside* positions `text` outside, next to the bar end (scaled if needed), unless there is another
    // bar stacked on this one, then the text gets pushed inside. *auto* tries to position `text` inside the bar, but if
    // the bar is too small and no bar is stacked on this one the text is moved outside. If *none*, no text appears.
    // - Default: auto
    Waterfall& textposition(enum Textposition f) {
        json["textposition"] = to_string(f);
        return *this;
    }
    Waterfall& textposition(const std::vector<enum Textposition>& f) {
        std::vector<std::string> stringified(f.size());
        std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
        json["textposition"] = std::move(stringified);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Waterfall& textpositionsrc(std::string f) {
        json["textpositionsrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Waterfall& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    // Template string used for rendering the information text that appear on points. Note that this will override
    // `textinfo`. Variables are inserted using %{variable}, for example "y: %{y}". Numbers are formatted using
    // d3-format's syntax %{variable:d3-format}, for example "Price: %{y:$.2f}".
    // https://github.com/d3/d3-format/tree/v1.4.5#d3-format for details on the formatting syntax. Dates are formatted
    // using d3-time-format's syntax %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. Every
    // attributes that can be specified per-point (the ones that are `arrayOk: true`) are available. Finally, the
    // template string has access to variables `initial`, `delta`, `final` and `label`.
    Waterfall& texttemplate(std::string f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }
    Waterfall& texttemplate(std::vector<std::string> f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Waterfall& texttemplatesrc(std::string f) {
        json["texttemplatesrc"] = std::move(f);
        return *this;
    }

    Waterfall& totals(class Totals f) {
        json["totals"] = std::move(f.json);
        return *this;
    }

    Waterfall& transforms(class Transforms f) {
        json["transforms"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Waterfall& uid(std::string f) {
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
    Waterfall& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Waterfall& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the bar width (in position axis units).
    Waterfall& width(double f) {
        json["width"] = std::move(f);
        return *this;
    }
    Waterfall& width(std::vector<double> f) {
        json["width"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `width`.
    Waterfall& widthsrc(std::string f) {
        json["widthsrc"] = std::move(f);
        return *this;
    }

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Waterfall& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Waterfall& x0(T f) {
        json["x0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Waterfall& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Waterfall& xhoverformat(std::string f) {
        json["xhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Waterfall& xperiod(T f) {
        json["xperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Waterfall& xperiod0(T f) {
        json["xperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Waterfall& xperiodalignment(enum Xperiodalignment f) {
        json["xperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Waterfall& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Waterfall& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Waterfall& y0(T f) {
        json["y0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Waterfall& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Waterfall& yhoverformat(std::string f) {
        json["yhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Waterfall& yperiod(T f) {
        json["yperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Waterfall& yperiod0(T f) {
        json["yperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Waterfall& yperiodalignment(enum Yperiodalignment f) {
        json["yperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Waterfall& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};
} // namespace plotlypp
