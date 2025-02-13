// TODO: includes, copyright, etc
#include <string>
#include <type_traits>
#include <vector>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Sankey {
 public:
    Sankey() { json["type"] = "sankey"; }

    enum class Arrangement {
        SNAP,
        PERPENDICULAR,
        FREEFORM,
        FIXED,
    };
    std::string to_string(Arrangement e) {
        switch (e) {
        case Arrangement::SNAP:
            return "snap";
        case Arrangement::PERPENDICULAR:
            return "perpendicular";
        case Arrangement::FREEFORM:
            return "freeform";
        case Arrangement::FIXED:
            return "fixed";
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

    class Domain {
     public:

        // If there is a layout grid, use the domain for this column in the grid for this sankey trace .
        Domain& column(int f) {
            json["column"] = std::move(f);
            return *this;
        }

        // If there is a layout grid, use the domain for this row in the grid for this sankey trace .
        Domain& row(int f) {
            json["row"] = std::move(f);
            return *this;
        }

        // Sets the horizontal domain of this sankey trace (in plot fraction).
        Domain& x(std::vector<std::string> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the vertical domain of this sankey trace (in plot fraction).
        Domain& y(std::vector<std::string> f) {
            json["y"] = std::move(f);
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

    // The links of the Sankey plot.
    class Link {
     public:

        enum class Hoverinfo {
            ALL,
            NONE,
            SKIP,
        };
        std::string to_string(Hoverinfo e) {
            switch (e) {
            case Hoverinfo::ALL:
                return "all";
            case Hoverinfo::NONE:
                return "none";
            case Hoverinfo::SKIP:
                return "skip";
            }
        }

        class Colorscales {
         public:

            class Concentrationscales {
             public:

                // Sets the upper bound of the color domain.
                Concentrationscales& cmax(double f) {
                    json["cmax"] = std::move(f);
                    return *this;
                }

                // Sets the lower bound of the color domain.
                Concentrationscales& cmin(double f) {
                    json["cmin"] = std::move(f);
                    return *this;
                }

                // Sets the colorscale. The colorscale must be an array containing arrays mapping a normalized value to
                // an rgb, rgba, hex, hsl, hsv, or named color string. At minimum, a mapping for the lowest (0) and
                // highest (1) values are required. For example, `[[0, 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To
                // control the bounds of the colorscale in color space, use `cmin` and `cmax`. Alternatively,
                // `colorscale` may be a palette name string of the following list:
                // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
                Concentrationscales& colorscale(std::string f) {
                    json["colorscale"] = std::move(f);
                    return *this;
                }

                // The label of the links to color based on their concentration within a flow.
                Concentrationscales& label(std::string f) {
                    json["label"] = std::move(f);
                    return *this;
                }

                // When used in a template, named items are created in the output figure in addition to any items the
                // figure already has in this array. You can modify these items in the output figure by making your own
                // item with `templateitemname` matching this `name` alongside your modifications (including `visible:
                // false` or `enabled: false` to hide it). Has no effect outside of a template.
                Concentrationscales& name(std::string f) {
                    json["name"] = std::move(f);
                    return *this;
                }

                // Used to refer to a named item in this array in the template. Named items from the template will be
                // created even without a matching item in the input figure, but you can modify one by making an item
                // with `templateitemname` matching its `name`, alongside your modifications (including `visible: false`
                // or `enabled: false` to hide it). If there is no template or no matching item, this item will be
                // hidden unless you explicitly show it with `visible: true`.
                Concentrationscales& templateitemname(std::string f) {
                    json["templateitemname"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            Colorscales& concentrationscales(class Concentrationscales f) {
                json["concentrationscales"] = std::move(f.json);
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
                // able to apply a font if it is available on the system which it operates. Provide multiple font
                // families, separated by commas, to indicate the preference in which to apply fonts if they aren't
                // available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise)
                // generates images on a server, where only a select number of fonts are installed and supported. These
                // include *Arial*, *Balto*, *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas
                // One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
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

            // Sets the default length (in number of characters) of the trace name in the hover labels for all traces.
            // -1 shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will
            // show the whole name if it is less than that many characters, but if it is longer, will truncate to
            // `namelength - 3` characters and add an ellipsis.
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

        class Line {
         public:

            // Sets the color of the `line` around each `link`.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Line& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of the `line` around each `link`.
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }
            Line& width(std::vector<double> f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `width`.
            Line& widthsrc(std::string f) {
                json["widthsrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the length (in px) of the links arrow, if 0 no arrow will be drawn.
        Link& arrowlen(double f) {
            json["arrowlen"] = std::move(f);
            return *this;
        }

        // Sets the `link` color. It can be a single value, or an array for specifying color for each `link`. If
        // `link.color` is omitted, then by default, a translucent grey link will be used.
        Link& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Link& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        Link& colorscales(class Colorscales f) {
            json["colorscales"] = std::move(f.json);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Link& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        // Assigns extra data to each link.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Link& customdata(std::vector<T> f) {
            json["customdata"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `customdata`.
        Link& customdatasrc(std::string f) {
            json["customdatasrc"] = std::move(f);
            return *this;
        }

        // Determines which trace information appear when hovering links. If `none` or `skip` are set, no information is
        // displayed upon hovering. But, if `none` is set, click and hover events are still fired.
        // - Default: all
        Link& hoverinfo(enum Hoverinfo f) {
            json["hoverinfo"] = to_string(f);
            return *this;
        }

        Link& hoverlabel(class Hoverlabel f) {
            json["hoverlabel"] = std::move(f.json);
            return *this;
        }

        // Template string used for rendering the information that appear on hover box. Note that this will override
        // `hoverinfo`. Variables are inserted using %{variable}, for example "y: %{y}" as well as %{xother},
        // {%_xother}, {%_xother_}, {%xother_}. When showing info for several points, *xother* will be added to those
        // with different x positions from the first point. An underscore before or after *(x|y)other* will add a space
        // on that side, only when this field is shown. Numbers are formatted using d3-format's syntax
        // %{variable:d3-format}, for example "Price: %{y:$.2f}". https://github.com/d3/d3-format/tree/v1.4.5#d3-format
        // for details on the formatting syntax. Dates are formatted using d3-time-format's syntax
        // %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
        // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. The
        // variables available in `hovertemplate` are the ones emitted as event data described at this link
        // https://plotly.com/javascript/plotlyjs-events/#event-data. Additionally, every attributes that can be
        // specified per-point (the ones that are `arrayOk: true`) are available.  Variables `source` and `target` are
        // node objects.Finally, the template string has access to variables `value` and `label`. Anything contained in
        // tag `<extra>` is displayed in the secondary box, for example "<extra>{fullData.name}</extra>". To hide the
        // secondary box completely, use an empty tag `<extra></extra>`.
        Link& hovertemplate(std::string f) {
            json["hovertemplate"] = std::move(f);
            return *this;
        }
        Link& hovertemplate(std::vector<std::string> f) {
            json["hovertemplate"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
        Link& hovertemplatesrc(std::string f) {
            json["hovertemplatesrc"] = std::move(f);
            return *this;
        }

        // The shown name of the link.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Link& label(std::vector<T> f) {
            json["label"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `label`.
        Link& labelsrc(std::string f) {
            json["labelsrc"] = std::move(f);
            return *this;
        }

        Link& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // An integer number `[0..nodes.length - 1]` that represents the source node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Link& source(std::vector<T> f) {
            json["source"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `source`.
        Link& sourcesrc(std::string f) {
            json["sourcesrc"] = std::move(f);
            return *this;
        }

        // An integer number `[0..nodes.length - 1]` that represents the target node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Link& target(std::vector<T> f) {
            json["target"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `target`.
        Link& targetsrc(std::string f) {
            json["targetsrc"] = std::move(f);
            return *this;
        }

        // A numeric value representing the flow volume value.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Link& value(std::vector<T> f) {
            json["value"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `value`.
        Link& valuesrc(std::string f) {
            json["valuesrc"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // The nodes of the Sankey plot.
    class Node {
     public:

        enum class Hoverinfo {
            ALL,
            NONE,
            SKIP,
        };
        std::string to_string(Hoverinfo e) {
            switch (e) {
            case Hoverinfo::ALL:
                return "all";
            case Hoverinfo::NONE:
                return "none";
            case Hoverinfo::SKIP:
                return "skip";
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
                // able to apply a font if it is available on the system which it operates. Provide multiple font
                // families, separated by commas, to indicate the preference in which to apply fonts if they aren't
                // available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise)
                // generates images on a server, where only a select number of fonts are installed and supported. These
                // include *Arial*, *Balto*, *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas
                // One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
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

            // Sets the default length (in number of characters) of the trace name in the hover labels for all traces.
            // -1 shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will
            // show the whole name if it is less than that many characters, but if it is longer, will truncate to
            // `namelength - 3` characters and add an ellipsis.
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

        class Line {
         public:

            // Sets the color of the `line` around each `node`.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Line& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of the `line` around each `node`.
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }
            Line& width(std::vector<double> f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `width`.
            Line& widthsrc(std::string f) {
                json["widthsrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the `node` color. It can be a single value, or an array for specifying color for each `node`. If
        // `node.color` is omitted, then the default `Plotly` color palette will be cycled through to have a variety of
        // colors. These defaults are not fully opaque, to allow some visibility of what is beneath the node.
        Node& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Node& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Node& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        // Assigns extra data to each node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Node& customdata(std::vector<T> f) {
            json["customdata"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `customdata`.
        Node& customdatasrc(std::string f) {
            json["customdatasrc"] = std::move(f);
            return *this;
        }

        // Groups of nodes. Each group is defined by an array with the indices of the nodes it contains. Multiple groups
        // can be specified.
        Node& groups(std::vector<std::string> f) {
            json["groups"] = std::move(f);
            return *this;
        }

        // Determines which trace information appear when hovering nodes. If `none` or `skip` are set, no information is
        // displayed upon hovering. But, if `none` is set, click and hover events are still fired.
        // - Default: all
        Node& hoverinfo(enum Hoverinfo f) {
            json["hoverinfo"] = to_string(f);
            return *this;
        }

        Node& hoverlabel(class Hoverlabel f) {
            json["hoverlabel"] = std::move(f.json);
            return *this;
        }

        // Template string used for rendering the information that appear on hover box. Note that this will override
        // `hoverinfo`. Variables are inserted using %{variable}, for example "y: %{y}" as well as %{xother},
        // {%_xother}, {%_xother_}, {%xother_}. When showing info for several points, *xother* will be added to those
        // with different x positions from the first point. An underscore before or after *(x|y)other* will add a space
        // on that side, only when this field is shown. Numbers are formatted using d3-format's syntax
        // %{variable:d3-format}, for example "Price: %{y:$.2f}". https://github.com/d3/d3-format/tree/v1.4.5#d3-format
        // for details on the formatting syntax. Dates are formatted using d3-time-format's syntax
        // %{variable|d3-time-format}, for example "Day: %{2019-01-01|%A}".
        // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format for details on the date formatting syntax. The
        // variables available in `hovertemplate` are the ones emitted as event data described at this link
        // https://plotly.com/javascript/plotlyjs-events/#event-data. Additionally, every attributes that can be
        // specified per-point (the ones that are `arrayOk: true`) are available.  Variables `sourceLinks` and
        // `targetLinks` are arrays of link objects.Finally, the template string has access to variables `value` and
        // `label`. Anything contained in tag `<extra>` is displayed in the secondary box, for example
        // "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an empty tag `<extra></extra>`.
        Node& hovertemplate(std::string f) {
            json["hovertemplate"] = std::move(f);
            return *this;
        }
        Node& hovertemplate(std::vector<std::string> f) {
            json["hovertemplate"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
        Node& hovertemplatesrc(std::string f) {
            json["hovertemplatesrc"] = std::move(f);
            return *this;
        }

        // The shown name of the node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Node& label(std::vector<T> f) {
            json["label"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `label`.
        Node& labelsrc(std::string f) {
            json["labelsrc"] = std::move(f);
            return *this;
        }

        Node& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Sets the padding (in px) between the `nodes`.
        Node& pad(double f) {
            json["pad"] = std::move(f);
            return *this;
        }

        // Sets the thickness (in px) of the `nodes`.
        Node& thickness(double f) {
            json["thickness"] = std::move(f);
            return *this;
        }

        // The normalized horizontal position of the node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Node& x(std::vector<T> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `x`.
        Node& xsrc(std::string f) {
            json["xsrc"] = std::move(f);
            return *this;
        }

        // The normalized vertical position of the node.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Node& y(std::vector<T> f) {
            json["y"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `y`.
        Node& ysrc(std::string f) {
            json["ysrc"] = std::move(f);
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

    // Sets the font for node labels
    class Textfont {
     public:

        Textfont& color(std::string f) {
            json["color"] = std::move(f);
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

        Textfont& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // If value is `snap` (the default), the node arrangement is assisted by automatic snapping of elements to preserve
    // space between nodes specified via `nodepad`. If value is `perpendicular`, the nodes can only move along a line
    // perpendicular to the flow. If value is `freeform`, the nodes can freely move on the plane. If value is `fixed`,
    // the nodes are stationary.
    // - Default: snap
    Sankey& arrangement(enum Arrangement f) {
        json["arrangement"] = to_string(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Sankey& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Sankey& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    Sankey& domain(class Domain f) {
        json["domain"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired. Note that this attribute is superseded
    // by `node.hoverinfo` and `node.hoverinfo` for nodes and links respectively.
    // - Default: all
    // - Flags: []
    // - Extras ['all', 'none', 'skip']
    Sankey& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    Sankey& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Sankey& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Sankey& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Sankey& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    Sankey& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Sankey& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Sankey& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    // The links of the Sankey plot.
    Sankey& link(class Link f) {
        json["link"] = std::move(f.json);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Sankey& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Sankey& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Sankey& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Sankey& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // The nodes of the Sankey plot.
    Sankey& node(class Node f) {
        json["node"] = std::move(f.json);
        return *this;
    }

    // Sets the orientation of the Sankey diagram.
    // - Default: h
    Sankey& orientation(enum Orientation f) {
        json["orientation"] = to_string(f);
        return *this;
    }

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Sankey& selectedpoints(T f) {
        json["selectedpoints"] = std::move(f);
        return *this;
    }

    Sankey& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets the font for node labels
    Sankey& textfont(class Textfont f) {
        json["textfont"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Sankey& uid(std::string f) {
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
    Sankey& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Sets the value formatting rule using d3 formatting mini-languages which are very similar to those in Python. For
    // numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
    Sankey& valueformat(std::string f) {
        json["valueformat"] = std::move(f);
        return *this;
    }

    // Adds a unit to follow the value in the hover tooltip. Add a space if a separation is necessary from the value.
    Sankey& valuesuffix(std::string f) {
        json["valuesuffix"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Sankey& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};
} // namespace plotlypp
