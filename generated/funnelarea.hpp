// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Funnelarea : public Trace {
 public:
    Funnelarea()
    : Trace() {
        json["type"] = "funnelarea";
    }

    enum class Textposition {
        INSIDE,
        NONE,
    };
    std::string to_string(Textposition e) {
        switch (e) {
        case Textposition::INSIDE:
            return "inside";
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

    class Domain {
     public:

        // If there is a layout grid, use the domain for this column in the grid for this funnelarea trace .
        Domain& column(int f) {
            json["column"] = std::move(f);
            return *this;
        }

        // If there is a layout grid, use the domain for this row in the grid for this funnelarea trace .
        Domain& row(int f) {
            json["row"] = std::move(f);
            return *this;
        }

        // Sets the horizontal domain of this funnelarea trace (in plot fraction).
        Domain& x(std::vector<std::string> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the vertical domain of this funnelarea trace (in plot fraction).
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

    // Sets the font used for `textinfo` lying inside the sector.
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

    class Marker {
     public:

        class Line {
         public:

            // Sets the color of the line enclosing each sector. Defaults to the `paper_bgcolor` value.
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

            // Sets the width (in px) of the line enclosing each sector.
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

        // Sets the pattern within the marker.
        class Pattern {
         public:

            enum class Fillmode {
                REPLACE,
                OVERLAY,
            };
            std::string to_string(Fillmode e) {
                switch (e) {
                case Fillmode::REPLACE:
                    return "replace";
                case Fillmode::OVERLAY:
                    return "overlay";
                }
            }

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
            std::string to_string(Shape e) {
                switch (e) {
                case Shape::EMPTY:
                    return "";
                case Shape::SLASH:
                    return "/";
                case Shape::DOUBLEBACKSLASH:
                    return "\\";
                case Shape::X:
                    return "x";
                case Shape::HYPHEN:
                    return "-";
                case Shape::OR:
                    return "|";
                case Shape::PLUS:
                    return "+";
                case Shape::DOT:
                    return ".";
                }
            }

            // When there is no colorscale sets the color of background pattern fill. Defaults to a `marker.color`
            // background when `fillmode` is *overlay*. Otherwise, defaults to a transparent background.
            Pattern& bgcolor(std::string f) {
                json["bgcolor"] = std::move(f);
                return *this;
            }
            Pattern& bgcolor(std::vector<std::string> f) {
                json["bgcolor"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `bgcolor`.
            Pattern& bgcolorsrc(std::string f) {
                json["bgcolorsrc"] = std::move(f);
                return *this;
            }

            // When there is no colorscale sets the color of foreground pattern fill. Defaults to a `marker.color`
            // background when `fillmode` is *replace*. Otherwise, defaults to dark grey or white to increase contrast
            // with the `bgcolor`.
            Pattern& fgcolor(std::string f) {
                json["fgcolor"] = std::move(f);
                return *this;
            }
            Pattern& fgcolor(std::vector<std::string> f) {
                json["fgcolor"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `fgcolor`.
            Pattern& fgcolorsrc(std::string f) {
                json["fgcolorsrc"] = std::move(f);
                return *this;
            }

            // Sets the opacity of the foreground pattern fill. Defaults to a 0.5 when `fillmode` is *overlay*.
            // Otherwise, defaults to 1.
            Pattern& fgopacity(double f) {
                json["fgopacity"] = std::move(f);
                return *this;
            }

            // Determines whether `marker.color` should be used as a default to `bgcolor` or a `fgcolor`.
            // - Default: replace
            Pattern& fillmode(enum Fillmode f) {
                json["fillmode"] = to_string(f);
                return *this;
            }

            // Sets the shape of the pattern fill. By default, no pattern is used for filling the area.
            // - Default:
            Pattern& shape(enum Shape f) {
                json["shape"] = to_string(f);
                return *this;
            }
            Pattern& shape(const std::vector<enum Shape>& f) {
                std::vector<std::string> stringified(f.size());
                std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
                json["shape"] = std::move(stringified);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `shape`.
            Pattern& shapesrc(std::string f) {
                json["shapesrc"] = std::move(f);
                return *this;
            }

            // Sets the size of unit squares of the pattern fill in pixels, which corresponds to the interval of
            // repetition of the pattern.
            Pattern& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }
            Pattern& size(std::vector<double> f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `size`.
            Pattern& sizesrc(std::string f) {
                json["sizesrc"] = std::move(f);
                return *this;
            }

            // Sets the solidity of the pattern fill. Solidity is roughly the fraction of the area filled by the
            // pattern. Solidity of 0 shows only the background color without pattern and solidty of 1 shows only the
            // foreground color without pattern.
            Pattern& solidity(double f) {
                json["solidity"] = std::move(f);
                return *this;
            }
            Pattern& solidity(std::vector<double> f) {
                json["solidity"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `solidity`.
            Pattern& soliditysrc(std::string f) {
                json["soliditysrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the color of each sector. If not specified, the default trace color set is used to pick the sector
        // colors.
        template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
        Marker& colors(std::vector<T> f) {
            json["colors"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `colors`.
        Marker& colorssrc(std::string f) {
            json["colorssrc"] = std::move(f);
            return *this;
        }

        Marker& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Sets the pattern within the marker.
        Marker& pattern(class Pattern f) {
            json["pattern"] = std::move(f.json);
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

    // Sets the font used for `textinfo`.
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

    class Title {
     public:

        enum class Position {
            TOP_LEFT,
            TOP_CENTER,
            TOP_RIGHT,
        };
        std::string to_string(Position e) {
            switch (e) {
            case Position::TOP_LEFT:
                return "top left";
            case Position::TOP_CENTER:
                return "top center";
            case Position::TOP_RIGHT:
                return "top right";
            }
        }

        // Sets the font used for `title`. Note that the title's font used to be set by the now deprecated `titlefont`
        // attribute.
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

        // Sets the font used for `title`. Note that the title's font used to be set by the now deprecated `titlefont`
        // attribute.
        Title& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Specifies the location of the `title`. Note that the title's position used to be set by the now deprecated
        // `titleposition` attribute.
        // - Default: top center
        Title& position(enum Position f) {
            json["position"] = to_string(f);
            return *this;
        }

        // Sets the title of the chart. If it is empty, no title is displayed. Note that before the existence of
        // `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been
        // deprecated.
        Title& text(std::string f) {
            json["text"] = std::move(f);
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

    // Sets the ratio between height and width
    Funnelarea& aspectratio(double f) {
        json["aspectratio"] = std::move(f);
        return *this;
    }

    // Sets the ratio between bottom length and maximum top length.
    Funnelarea& baseratio(double f) {
        json["baseratio"] = std::move(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Funnelarea& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Funnelarea& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the label step. See `label0` for more info.
    Funnelarea& dlabel(double f) {
        json["dlabel"] = std::move(f);
        return *this;
    }

    Funnelarea& domain(class Domain f) {
        json["domain"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['label', 'text', 'value', 'percent', 'name']
    // - Extras ['all', 'none', 'skip']
    Funnelarea& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Funnelarea& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Funnelarea& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Funnelarea& hoverlabel(class Hoverlabel f) {
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
    // variables `label`, `color`, `value`, `text` and `percent`. Anything contained in tag `<extra>` is displayed in
    // the secondary box, for example "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an
    // empty tag `<extra></extra>`.
    Funnelarea& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Funnelarea& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Funnelarea& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Sets hover text elements associated with each sector. If a single string, the same string appears for all data
    // points. If an array of string, the items are mapped in order of this trace's sectors. To be seen, trace
    // `hoverinfo` must contain a *text* flag.
    Funnelarea& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Funnelarea& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Funnelarea& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Funnelarea& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Funnelarea& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the font used for `textinfo` lying inside the sector.
    Funnelarea& insidetextfont(class Insidetextfont f) {
        json["insidetextfont"] = std::move(f.json);
        return *this;
    }

    // Alternate to `labels`. Builds a numeric set of labels. Use with `dlabel` where `label0` is the starting label and
    // `dlabel` the step.
    Funnelarea& label0(double f) {
        json["label0"] = std::move(f);
        return *this;
    }

    // Sets the sector labels. If `labels` entries are duplicated, we sum associated `values` or simply count
    // occurrences if `values` is not provided. For other array attributes (including color) we use the first non-empty
    // entry among all occurrences of the label.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Funnelarea& labels(std::vector<T> f) {
        json["labels"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `labels`.
    Funnelarea& labelssrc(std::string f) {
        json["labelssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Funnelarea& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Funnelarea& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Funnelarea& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Funnelarea& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Funnelarea& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Funnelarea& marker(class Marker f) {
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
    Funnelarea& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Funnelarea& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Funnelarea& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Funnelarea& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Funnelarea& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // If there are multiple funnelareas that should be sized according to their totals, link them by providing a
    // non-empty group id here shared by every trace in the same group.
    Funnelarea& scalegroup(std::string f) {
        json["scalegroup"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Funnelarea& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    Funnelarea& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets text elements associated with each sector. If trace `textinfo` contains a *text* flag, these elements will
    // be seen on the chart. If trace `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will
    // be seen in the hover labels.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Funnelarea& text(std::vector<T> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the font used for `textinfo`.
    Funnelarea& textfont(class Textfont f) {
        json["textfont"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on the graph.
    // - Flags: ['label', 'text', 'value', 'percent']
    // - Extras ['none']
    Funnelarea& textinfo(std::string f) {
        json["textinfo"] = std::move(f);
        return *this;
    }

    // Specifies the location of the `textinfo`.
    // - Default: inside
    Funnelarea& textposition(enum Textposition f) {
        json["textposition"] = to_string(f);
        return *this;
    }
    Funnelarea& textposition(const std::vector<enum Textposition>& f) {
        std::vector<std::string> stringified(f.size());
        std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
        json["textposition"] = std::move(stringified);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Funnelarea& textpositionsrc(std::string f) {
        json["textpositionsrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Funnelarea& textsrc(std::string f) {
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
    // template string has access to variables `label`, `color`, `value`, `text` and `percent`.
    Funnelarea& texttemplate(std::string f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }
    Funnelarea& texttemplate(std::vector<std::string> f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Funnelarea& texttemplatesrc(std::string f) {
        json["texttemplatesrc"] = std::move(f);
        return *this;
    }

    Funnelarea& title(class Title f) {
        json["title"] = std::move(f.json);
        return *this;
    }

    Funnelarea& transforms(class Transforms f) {
        json["transforms"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Funnelarea& uid(std::string f) {
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
    Funnelarea& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Sets the values of the sectors. If omitted, we count occurrences of each label.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Funnelarea& values(std::vector<T> f) {
        json["values"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `values`.
    Funnelarea& valuessrc(std::string f) {
        json["valuessrc"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Funnelarea& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }
};
} // namespace plotlypp
