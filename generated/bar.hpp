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
    std::string to_string(Ycalendar e) {
        switch (e) {
        case Ycalendar::CHINESE:
            return "chinese";
        case Ycalendar::COPTIC:
            return "coptic";
        case Ycalendar::DISCWORLD:
            return "discworld";
        case Ycalendar::ETHIOPIAN:
            return "ethiopian";
        case Ycalendar::GREGORIAN:
            return "gregorian";
        case Ycalendar::HEBREW:
            return "hebrew";
        case Ycalendar::ISLAMIC:
            return "islamic";
        case Ycalendar::JALALI:
            return "jalali";
        case Ycalendar::JULIAN:
            return "julian";
        case Ycalendar::MAYAN:
            return "mayan";
        case Ycalendar::NANAKSHAHI:
            return "nanakshahi";
        case Ycalendar::NEPALI:
            return "nepali";
        case Ycalendar::PERSIAN:
            return "persian";
        case Ycalendar::TAIWAN:
            return "taiwan";
        case Ycalendar::THAI:
            return "thai";
        case Ycalendar::UMMALQURA:
            return "ummalqura";
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

    class Error_x {
     public:

        enum class Type {
            PERCENT,
            CONSTANT,
            SQRT,
            DATA,
        };
        std::string to_string(Type e) {
            switch (e) {
            case Type::PERCENT:
                return "percent";
            case Type::CONSTANT:
                return "constant";
            case Type::SQRT:
                return "sqrt";
            case Type::DATA:
                return "data";
            }
        }

        // Sets the data corresponding the length of each error bar. Values are plotted relative to the underlying data.
        template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
        Error_x& array(std::vector<T> f) {
            json["array"] = std::move(f);
            return *this;
        }

        // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical
        // (horizontal) bars Values are plotted relative to the underlying data.
        template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
        Error_x& arrayminus(std::vector<T> f) {
            json["arrayminus"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `arrayminus`.
        Error_x& arrayminussrc(std::string f) {
            json["arrayminussrc"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `array`.
        Error_x& arraysrc(std::string f) {
            json["arraysrc"] = std::move(f);
            return *this;
        }

        // Sets the stoke color of the error bars.
        Error_x& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }

        Error_x& copy_ystyle(bool f) {
            json["copy_ystyle"] = std::move(f);
            return *this;
        }

        // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical
        // bars, left/right for horizontal bars.
        Error_x& symmetric(bool f) {
            json["symmetric"] = std::move(f);
            return *this;
        }

        // Sets the thickness (in px) of the error bars.
        Error_x& thickness(double f) {
            json["thickness"] = std::move(f);
            return *this;
        }

        Error_x& traceref(int f) {
            json["traceref"] = std::move(f);
            return *this;
        }

        Error_x& tracerefminus(int f) {
            json["tracerefminus"] = std::move(f);
            return *this;
        }

        // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value.
        // Set this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data.
        // Set this percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data.
        // If *data*, the bar lengths are set with data set `array`.
        Error_x& type(enum Type f) {
            json["type"] = to_string(f);
            return *this;
        }

        // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
        // *constant*) corresponding to the lengths of the error bars.
        Error_x& value(double f) {
            json["value"] = std::move(f);
            return *this;
        }

        // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
        // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
        // (horizontal) bars
        Error_x& valueminus(double f) {
            json["valueminus"] = std::move(f);
            return *this;
        }

        // Determines whether or not this set of error bars is visible.
        Error_x& visible(bool f) {
            json["visible"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the cross-bar at both ends of the error bars.
        Error_x& width(double f) {
            json["width"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Error_y {
     public:

        enum class Type {
            PERCENT,
            CONSTANT,
            SQRT,
            DATA,
        };
        std::string to_string(Type e) {
            switch (e) {
            case Type::PERCENT:
                return "percent";
            case Type::CONSTANT:
                return "constant";
            case Type::SQRT:
                return "sqrt";
            case Type::DATA:
                return "data";
            }
        }

        // Sets the data corresponding the length of each error bar. Values are plotted relative to the underlying data.
        template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
        Error_y& array(std::vector<T> f) {
            json["array"] = std::move(f);
            return *this;
        }

        // Sets the data corresponding the length of each error bar in the bottom (left) direction for vertical
        // (horizontal) bars Values are plotted relative to the underlying data.
        template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
        Error_y& arrayminus(std::vector<T> f) {
            json["arrayminus"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `arrayminus`.
        Error_y& arrayminussrc(std::string f) {
            json["arrayminussrc"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `array`.
        Error_y& arraysrc(std::string f) {
            json["arraysrc"] = std::move(f);
            return *this;
        }

        // Sets the stoke color of the error bars.
        Error_y& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Determines whether or not the error bars have the same length in both direction (top/bottom for vertical
        // bars, left/right for horizontal bars.
        Error_y& symmetric(bool f) {
            json["symmetric"] = std::move(f);
            return *this;
        }

        // Sets the thickness (in px) of the error bars.
        Error_y& thickness(double f) {
            json["thickness"] = std::move(f);
            return *this;
        }

        Error_y& traceref(int f) {
            json["traceref"] = std::move(f);
            return *this;
        }

        Error_y& tracerefminus(int f) {
            json["tracerefminus"] = std::move(f);
            return *this;
        }

        // Determines the rule used to generate the error bars. If *constant`, the bar lengths are of a constant value.
        // Set this constant in `value`. If *percent*, the bar lengths correspond to a percentage of underlying data.
        // Set this percentage in `value`. If *sqrt*, the bar lengths correspond to the square of the underlying data.
        // If *data*, the bar lengths are set with data set `array`.
        Error_y& type(enum Type f) {
            json["type"] = to_string(f);
            return *this;
        }

        // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
        // *constant*) corresponding to the lengths of the error bars.
        Error_y& value(double f) {
            json["value"] = std::move(f);
            return *this;
        }

        // Sets the value of either the percentage (if `type` is set to *percent*) or the constant (if `type` is set to
        // *constant*) corresponding to the lengths of the error bars in the bottom (left) direction for vertical
        // (horizontal) bars
        Error_y& valueminus(double f) {
            json["valueminus"] = std::move(f);
            return *this;
        }

        // Determines whether or not this set of error bars is visible.
        Error_y& visible(bool f) {
            json["visible"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the cross-bar at both ends of the error bars.
        Error_y& width(double f) {
            json["width"] = std::move(f);
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

    class Marker {
     public:

        class Colorbar {
         public:

            enum class Exponentformat {
                NONE,
                E,
                POWER,
                SI,
                B,
            };
            std::string to_string(Exponentformat e) {
                switch (e) {
                case Exponentformat::NONE:
                    return "none";
                case Exponentformat::E:
                    return "E";
                case Exponentformat::POWER:
                    return "power";
                case Exponentformat::SI:
                    return "SI";
                case Exponentformat::B:
                    return "B";
                }
            }

            enum class Lenmode {
                FRACTION,
                PIXELS,
            };
            std::string to_string(Lenmode e) {
                switch (e) {
                case Lenmode::FRACTION:
                    return "fraction";
                case Lenmode::PIXELS:
                    return "pixels";
                }
            }

            enum class Orientation {
                H,
                V,
            };
            std::string to_string(Orientation e) {
                switch (e) {
                case Orientation::H:
                    return "h";
                case Orientation::V:
                    return "v";
                }
            }

            enum class Showexponent {
                ALL,
                FIRST,
                LAST,
                NONE,
            };
            std::string to_string(Showexponent e) {
                switch (e) {
                case Showexponent::ALL:
                    return "all";
                case Showexponent::FIRST:
                    return "first";
                case Showexponent::LAST:
                    return "last";
                case Showexponent::NONE:
                    return "none";
                }
            }

            enum class Showtickprefix {
                ALL,
                FIRST,
                LAST,
                NONE,
            };
            std::string to_string(Showtickprefix e) {
                switch (e) {
                case Showtickprefix::ALL:
                    return "all";
                case Showtickprefix::FIRST:
                    return "first";
                case Showtickprefix::LAST:
                    return "last";
                case Showtickprefix::NONE:
                    return "none";
                }
            }

            enum class Showticksuffix {
                ALL,
                FIRST,
                LAST,
                NONE,
            };
            std::string to_string(Showticksuffix e) {
                switch (e) {
                case Showticksuffix::ALL:
                    return "all";
                case Showticksuffix::FIRST:
                    return "first";
                case Showticksuffix::LAST:
                    return "last";
                case Showticksuffix::NONE:
                    return "none";
                }
            }

            enum class Thicknessmode {
                FRACTION,
                PIXELS,
            };
            std::string to_string(Thicknessmode e) {
                switch (e) {
                case Thicknessmode::FRACTION:
                    return "fraction";
                case Thicknessmode::PIXELS:
                    return "pixels";
                }
            }

            enum class Ticklabeloverflow {
                ALLOW,
                HIDE_PAST_DIV,
                HIDE_PAST_DOMAIN,
            };
            std::string to_string(Ticklabeloverflow e) {
                switch (e) {
                case Ticklabeloverflow::ALLOW:
                    return "allow";
                case Ticklabeloverflow::HIDE_PAST_DIV:
                    return "hide past div";
                case Ticklabeloverflow::HIDE_PAST_DOMAIN:
                    return "hide past domain";
                }
            }

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
            std::string to_string(Ticklabelposition e) {
                switch (e) {
                case Ticklabelposition::OUTSIDE:
                    return "outside";
                case Ticklabelposition::INSIDE:
                    return "inside";
                case Ticklabelposition::OUTSIDE_TOP:
                    return "outside top";
                case Ticklabelposition::INSIDE_TOP:
                    return "inside top";
                case Ticklabelposition::OUTSIDE_LEFT:
                    return "outside left";
                case Ticklabelposition::INSIDE_LEFT:
                    return "inside left";
                case Ticklabelposition::OUTSIDE_RIGHT:
                    return "outside right";
                case Ticklabelposition::INSIDE_RIGHT:
                    return "inside right";
                case Ticklabelposition::OUTSIDE_BOTTOM:
                    return "outside bottom";
                case Ticklabelposition::INSIDE_BOTTOM:
                    return "inside bottom";
                }
            }

            enum class Tickmode {
                AUTO,
                LINEAR,
                ARRAY,
            };
            std::string to_string(Tickmode e) {
                switch (e) {
                case Tickmode::AUTO:
                    return "auto";
                case Tickmode::LINEAR:
                    return "linear";
                case Tickmode::ARRAY:
                    return "array";
                }
            }

            enum class Ticks {
                OUTSIDE,
                INSIDE,
                EMPTY,
            };
            std::string to_string(Ticks e) {
                switch (e) {
                case Ticks::OUTSIDE:
                    return "outside";
                case Ticks::INSIDE:
                    return "inside";
                case Ticks::EMPTY:
                    return "";
                }
            }

            enum class Xanchor {
                LEFT,
                CENTER,
                RIGHT,
            };
            std::string to_string(Xanchor e) {
                switch (e) {
                case Xanchor::LEFT:
                    return "left";
                case Xanchor::CENTER:
                    return "center";
                case Xanchor::RIGHT:
                    return "right";
                }
            }

            enum class Xref {
                CONTAINER,
                PAPER,
            };
            std::string to_string(Xref e) {
                switch (e) {
                case Xref::CONTAINER:
                    return "container";
                case Xref::PAPER:
                    return "paper";
                }
            }

            enum class Yanchor {
                TOP,
                MIDDLE,
                BOTTOM,
            };
            std::string to_string(Yanchor e) {
                switch (e) {
                case Yanchor::TOP:
                    return "top";
                case Yanchor::MIDDLE:
                    return "middle";
                case Yanchor::BOTTOM:
                    return "bottom";
                }
            }

            enum class Yref {
                CONTAINER,
                PAPER,
            };
            std::string to_string(Yref e) {
                switch (e) {
                case Yref::CONTAINER:
                    return "container";
                case Yref::PAPER:
                    return "paper";
                }
            }

            // Sets the color bar's tick label font
            class Tickfont {
             public:

                Tickfont& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // HTML font family - the typeface that will be applied by the web browser. The web browser will only be
                // able to apply a font if it is available on the system which it operates. Provide multiple font
                // families, separated by commas, to indicate the preference in which to apply fonts if they aren't
                // available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise)
                // generates images on a server, where only a select number of fonts are installed and supported. These
                // include *Arial*, *Balto*, *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid Sans Mono*, *Gravitas
                // One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
                Tickfont& family(std::string f) {
                    json["family"] = std::move(f);
                    return *this;
                }

                Tickfont& size(double f) {
                    json["size"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            class Tickformatstops {
             public:

                class Tickformatstop {
                 public:

                    // range [*min*, *max*], where *min*, *max* - dtick values which describe some zoom level, it is
                    // possible to omit *min* or *max* value by passing *null*
                    Tickformatstop& dtickrange(std::vector<std::string> f) {
                        json["dtickrange"] = std::move(f);
                        return *this;
                    }

                    // Determines whether or not this stop is used. If `false`, this stop is ignored even within its
                    // `dtickrange`.
                    Tickformatstop& enabled(bool f) {
                        json["enabled"] = std::move(f);
                        return *this;
                    }

                    // When used in a template, named items are created in the output figure in addition to any items
                    // the figure already has in this array. You can modify these items in the output figure by making
                    // your own item with `templateitemname` matching this `name` alongside your modifications
                    // (including `visible: false` or `enabled: false` to hide it). Has no effect outside of a template.
                    Tickformatstop& name(std::string f) {
                        json["name"] = std::move(f);
                        return *this;
                    }

                    // Used to refer to a named item in this array in the template. Named items from the template will
                    // be created even without a matching item in the input figure, but you can modify one by making an
                    // item with `templateitemname` matching its `name`, alongside your modifications (including
                    // `visible: false` or `enabled: false` to hide it). If there is no template or no matching item,
                    // this item will be hidden unless you explicitly show it with `visible: true`.
                    Tickformatstop& templateitemname(std::string f) {
                        json["templateitemname"] = std::move(f);
                        return *this;
                    }

                    // string - dtickformat for described zoom level, the same as *tickformat*
                    Tickformatstop& value(std::string f) {
                        json["value"] = std::move(f);
                        return *this;
                    }

                    // Advanced users may modify the JSON representation directly, at their own peril!
                    nlohmann::json json{};
                };

                Tickformatstops& tickformatstop(class Tickformatstop f) {
                    json["tickformatstop"] = std::move(f.json);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            class Title {
             public:

                enum class Side {
                    RIGHT,
                    TOP,
                    BOTTOM,
                };
                std::string to_string(Side e) {
                    switch (e) {
                    case Side::RIGHT:
                        return "right";
                    case Side::TOP:
                        return "top";
                    case Side::BOTTOM:
                        return "bottom";
                    }
                }

                // Sets this color bar's title font. Note that the title's font used to be set by the now deprecated
                // `titlefont` attribute.
                class Font {
                 public:

                    Font& color(std::string f) {
                        json["color"] = std::move(f);
                        return *this;
                    }

                    // HTML font family - the typeface that will be applied by the web browser. The web browser will
                    // only be able to apply a font if it is available on the system which it operates. Provide multiple
                    // font families, separated by commas, to indicate the preference in which to apply fonts if they
                    // aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or
                    // on-premise) generates images on a server, where only a select number of fonts are installed and
                    // supported. These include *Arial*, *Balto*, *Courier New*, *Droid Sans*,, *Droid Serif*, *Droid
                    // Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*,
                    // *Raleway*, *Times New Roman*.
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

                // Sets this color bar's title font. Note that the title's font used to be set by the now deprecated
                // `titlefont` attribute.
                Title& font(class Font f) {
                    json["font"] = std::move(f.json);
                    return *this;
                }

                // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when
                // `orientation` if *v* and  defaults to *right* when `orientation` if *h*. Note that the title's
                // location used to be set by the now deprecated `titleside` attribute.
                Title& side(enum Side f) {
                    json["side"] = to_string(f);
                    return *this;
                }

                // Sets the title of the color bar. Note that before the existence of `title.text`, the title's contents
                // used to be defined as the `title` attribute itself. This behavior has been deprecated.
                Title& text(std::string f) {
                    json["text"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            // Sets the color of padded area.
            Colorbar& bgcolor(std::string f) {
                json["bgcolor"] = std::move(f);
                return *this;
            }

            // Sets the axis line color.
            Colorbar& bordercolor(std::string f) {
                json["bordercolor"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) or the border enclosing this color bar.
            Colorbar& borderwidth(double f) {
                json["borderwidth"] = std::move(f);
                return *this;
            }

            // Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special
            // strings available to *log* and *date* axes. If the axis `type` is *log*, then ticks are set every
            // 10^(n*dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set
            // dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125,
            // 625, 3125, ... set dtick to log_10(5), or 0.69897000433. *log* has several special values; *L<f>*, where
            // `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` =
            // 0.1, `dtick` = *L0.5* will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits
            // between, use *D1* (all digits) or *D2* (only 2 and 5). `tick0` is ignored for *D1* and *D2*. If the axis
            // `type` is *date*, then you must convert the time to milliseconds. For example, to set the interval
            // between ticks to one day, set `dtick` to 86400000.0. *date* also has special values *M<n>* gives ticks
            // spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third
            // month, set `tick0` to *2000-01-15* and `dtick` to *M3*. To set ticks every 4 years, set `dtick` to *M48*
            template <typename T>
            Colorbar& dtick(T f) {
                json["dtick"] = std::move(f);
                return *this;
            }

            // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If
            // *none*, it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super
            // script). If *SI*, 1G. If *B*, 1B.
            // - Default: B
            Colorbar& exponentformat(enum Exponentformat f) {
                json["exponentformat"] = to_string(f);
                return *this;
            }

            // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes
            // US to USA and CA to Canada. The labels we would have shown must match the keys exactly, after adding any
            // tickprefix or ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the
            // regular ascii dash. That means you need to use −1 instead of -1. labelalias can be used with any axis
            // type, and both keys (if needed) and values (if desired) can include html-like tags or MathJax.
            template <typename T>
            Colorbar& labelalias(T f) {
                json["labelalias"] = std::move(f);
                return *this;
            }

            // Sets the length of the color bar This measure excludes the padding of both ends. That is, the color bar
            // length is this length minus the padding on both ends.
            Colorbar& len(double f) {
                json["len"] = std::move(f);
                return *this;
            }

            // Determines whether this color bar's length (i.e. the measure in the color variation direction) is set in
            // units of plot *fraction* or in *pixels. Use `len` to set the value.
            // - Default: fraction
            Colorbar& lenmode(enum Lenmode f) {
                json["lenmode"] = to_string(f);
                return *this;
            }

            // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or
            // *B*.
            Colorbar& minexponent(double f) {
                json["minexponent"] = std::move(f);
                return *this;
            }

            // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
            // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
            Colorbar& nticks(int f) {
                json["nticks"] = std::move(f);
                return *this;
            }

            // Sets the orientation of the colorbar.
            // - Default: v
            Colorbar& orientation(enum Orientation f) {
                json["orientation"] = to_string(f);
                return *this;
            }

            // Sets the axis line color.
            Colorbar& outlinecolor(std::string f) {
                json["outlinecolor"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of the axis line.
            Colorbar& outlinewidth(double f) {
                json["outlinewidth"] = std::move(f);
                return *this;
            }

            // If "true", even 4-digit integers are separated
            Colorbar& separatethousands(bool f) {
                json["separatethousands"] = std::move(f);
                return *this;
            }

            // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first
            // tick is shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
            // - Default: all
            Colorbar& showexponent(enum Showexponent f) {
                json["showexponent"] = to_string(f);
                return *this;
            }

            // Determines whether or not the tick labels are drawn.
            Colorbar& showticklabels(bool f) {
                json["showticklabels"] = std::move(f);
                return *this;
            }

            // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with
            // a prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
            // - Default: all
            Colorbar& showtickprefix(enum Showtickprefix f) {
                json["showtickprefix"] = to_string(f);
                return *this;
            }

            // Same as `showtickprefix` but for tick suffixes.
            // - Default: all
            Colorbar& showticksuffix(enum Showticksuffix f) {
                json["showticksuffix"] = to_string(f);
                return *this;
            }

            // Sets the thickness of the color bar This measure excludes the size of the padding, ticks and labels.
            Colorbar& thickness(double f) {
                json["thickness"] = std::move(f);
                return *this;
            }

            // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set
            // in units of plot *fraction* or in *pixels*. Use `thickness` to set the value.
            // - Default: pixels
            Colorbar& thicknessmode(enum Thicknessmode f) {
                json["thicknessmode"] = to_string(f);
                return *this;
            }

            // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then
            // you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2)
            // except when `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date
            // string, like date data. If the axis `type` is *category*, it should be a number, using the scale where
            // each category is assigned a serial number from zero in the order it appears.
            template <typename T>
            Colorbar& tick0(T f) {
                json["tick0"] = std::move(f);
                return *this;
            }

            // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws
            // the tick labels vertically.
            Colorbar& tickangle(double f) {
                json["tickangle"] = std::move(f);
                return *this;
            }

            // Sets the tick color.
            Colorbar& tickcolor(std::string f) {
                json["tickcolor"] = std::move(f);
                return *this;
            }

            // Sets the color bar's tick label font
            Colorbar& tickfont(class Tickfont f) {
                json["tickfont"] = std::move(f.json);
                return *this;
            }

            // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in
            // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
            // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter:
            // *%h* for half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits.
            // For example, *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
            Colorbar& tickformat(std::string f) {
                json["tickformat"] = std::move(f);
                return *this;
            }

            Colorbar& tickformatstops(class Tickformatstops f) {
                json["tickformatstops"] = std::move(f.json);
                return *this;
            }

            // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis.
            // The default value for inside tick labels is *hide past domain*. In other cases the default is *hide past
            // div*.
            Colorbar& ticklabeloverflow(enum Ticklabeloverflow f) {
                json["ticklabeloverflow"] = to_string(f);
                return *this;
            }

            // Determines where tick labels are drawn relative to the ticks. Left and right options are used when
            // `orientation` is *h*, top and bottom when `orientation` is *v*.
            // - Default: outside
            Colorbar& ticklabelposition(enum Ticklabelposition f) {
                json["ticklabelposition"] = to_string(f);
                return *this;
            }

            // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default)
            // means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every
            // nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type`
            // *log* or *multicategory*, or when `tickmode` is *array*.
            Colorbar& ticklabelstep(int f) {
                json["ticklabelstep"] = std::move(f);
                return *this;
            }

            // Sets the tick length (in px).
            Colorbar& ticklen(double f) {
                json["ticklen"] = std::move(f);
                return *this;
            }

            // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the
            // placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is
            // the default value if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via
            // `tickvals` and the tick text is `ticktext`. (*array* is the default value if `tickvals` is provided).
            Colorbar& tickmode(enum Tickmode f) {
                json["tickmode"] = to_string(f);
                return *this;
            }

            // Sets a tick label prefix.
            Colorbar& tickprefix(std::string f) {
                json["tickprefix"] = std::move(f);
                return *this;
            }

            // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside*
            // (*inside*), this axis' are drawn outside (inside) the axis lines.
            // - Default:
            Colorbar& ticks(enum Ticks f) {
                json["ticks"] = to_string(f);
                return *this;
            }

            // Sets a tick label suffix.
            Colorbar& ticksuffix(std::string f) {
                json["ticksuffix"] = std::move(f);
                return *this;
            }

            // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to
            // *array*. Used with `tickvals`.
            template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
            Colorbar& ticktext(std::vector<T> f) {
                json["ticktext"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `ticktext`.
            Colorbar& ticktextsrc(std::string f) {
                json["ticktextsrc"] = std::move(f);
                return *this;
            }

            // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*.
            // Used with `ticktext`.
            template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
            Colorbar& tickvals(std::vector<T> f) {
                json["tickvals"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `tickvals`.
            Colorbar& tickvalssrc(std::string f) {
                json["tickvalssrc"] = std::move(f);
                return *this;
            }

            // Sets the tick width (in px).
            Colorbar& tickwidth(double f) {
                json["tickwidth"] = std::move(f);
                return *this;
            }

            Colorbar& title(class Title f) {
                json["title"] = std::move(f.json);
                return *this;
            }

            // Sets the x position with respect to `xref` of the color bar (in plot fraction). When `xref` is *paper*,
            // defaults to 1.02 when `orientation` is *v* and 0.5 when `orientation` is *h*. When `xref` is *container*,
            // defaults to *1* when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1*
            // if `xref` is *container* and between *-2* and *3* if `xref` is *paper*.
            Colorbar& x(double f) {
                json["x"] = std::move(f);
                return *this;
            }

            // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*,
            // *center* or *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when
            // `orientation` is *h*.
            Colorbar& xanchor(enum Xanchor f) {
                json["xanchor"] = to_string(f);
                return *this;
            }

            // Sets the amount of padding (in px) along the x direction.
            Colorbar& xpad(double f) {
                json["xpad"] = std::move(f);
                return *this;
            }

            // Sets the container `x` refers to. *container* spans the entire `width` of the plot. *paper* refers to the
            // width of the plotting area only.
            // - Default: paper
            Colorbar& xref(enum Xref f) {
                json["xref"] = to_string(f);
                return *this;
            }

            // Sets the y position with respect to `yref` of the color bar (in plot fraction). When `yref` is *paper*,
            // defaults to 0.5 when `orientation` is *v* and 1.02 when `orientation` is *h*. When `yref` is *container*,
            // defaults to 0.5 when `orientation` is *v* and 1 when `orientation` is *h*. Must be between *0* and *1* if
            // `yref` is *container* and between *-2* and *3* if `yref` is *paper*.
            Colorbar& y(double f) {
                json["y"] = std::move(f);
                return *this;
            }

            // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle*
            // or *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when
            // `orientation` is *h*.
            Colorbar& yanchor(enum Yanchor f) {
                json["yanchor"] = to_string(f);
                return *this;
            }

            // Sets the amount of padding (in px) along the y direction.
            Colorbar& ypad(double f) {
                json["ypad"] = std::move(f);
                return *this;
            }

            // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to
            // the height of the plotting area only.
            // - Default: paper
            Colorbar& yref(enum Yref f) {
                json["yref"] = to_string(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        class Line {
         public:

            // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined
            // by `marker.line.colorscale`. Has an effect only if in `marker.line.color` is set to a numerical array. In
            // case `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen
            // according to whether numbers in the `color` array are all positive, all negative or mixed.
            Line& autocolorscale(bool f) {
                json["autocolorscale"] = std::move(f);
                return *this;
            }

            // Determines whether or not the color domain is computed with respect to the input data (here in
            // `marker.line.color`) or the bounds set in `marker.line.cmin` and `marker.line.cmax` Has an effect only if
            // in `marker.line.color` is set to a numerical array. Defaults to `false` when `marker.line.cmin` and
            // `marker.line.cmax` are set by the user.
            Line& cauto(bool f) {
                json["cauto"] = std::move(f);
                return *this;
            }

            // Sets the upper bound of the color domain. Has an effect only if in `marker.line.color` is set to a
            // numerical array. Value should have the same units as in `marker.line.color` and if set,
            // `marker.line.cmin` must be set as well.
            Line& cmax(double f) {
                json["cmax"] = std::move(f);
                return *this;
            }

            // Sets the mid-point of the color domain by scaling `marker.line.cmin` and/or `marker.line.cmax` to be
            // equidistant to this point. Has an effect only if in `marker.line.color` is set to a numerical array.
            // Value should have the same units as in `marker.line.color`. Has no effect when `marker.line.cauto` is
            // `false`.
            Line& cmid(double f) {
                json["cmid"] = std::move(f);
                return *this;
            }

            // Sets the lower bound of the color domain. Has an effect only if in `marker.line.color` is set to a
            // numerical array. Value should have the same units as in `marker.line.color` and if set,
            // `marker.line.cmax` must be set as well.
            Line& cmin(double f) {
                json["cmin"] = std::move(f);
                return *this;
            }

            // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to
            // the colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
            // `marker.line.cmax` if set.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*,
            // *coloraxis2*, *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under
            // `layout.coloraxis`, `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same
            // color axis.
            Line& coloraxis(std::string f) {
                json["coloraxis"] = std::move(f);
                return *this;
            }

            // Sets the colorscale. Has an effect only if in `marker.line.color` is set to a numerical array. The
            // colorscale must be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv,
            // or named color string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For
            // example, `[[0, 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color
            // space, use `marker.line.cmin` and `marker.line.cmax`. Alternatively, `colorscale` may be a palette name
            // string of the following list:
            // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
            Line& colorscale(std::string f) {
                json["colorscale"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Line& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // Reverses the color mapping if true. Has an effect only if in `marker.line.color` is set to a numerical
            // array. If true, `marker.line.cmin` will correspond to the last color in the array and `marker.line.cmax`
            // will correspond to the first color.
            Line& reversescale(bool f) {
                json["reversescale"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of the lines bounding the marker points.
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

        // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
        // `marker.colorscale`. Has an effect only if in `marker.color` is set to a numerical array. In case
        // `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen according to
        // whether numbers in the `color` array are all positive, all negative or mixed.
        Marker& autocolorscale(bool f) {
            json["autocolorscale"] = std::move(f);
            return *this;
        }

        // Determines whether or not the color domain is computed with respect to the input data (here in
        // `marker.color`) or the bounds set in `marker.cmin` and `marker.cmax` Has an effect only if in `marker.color`
        // is set to a numerical array. Defaults to `false` when `marker.cmin` and `marker.cmax` are set by the user.
        Marker& cauto(bool f) {
            json["cauto"] = std::move(f);
            return *this;
        }

        // Sets the upper bound of the color domain. Has an effect only if in `marker.color` is set to a numerical
        // array. Value should have the same units as in `marker.color` and if set, `marker.cmin` must be set as well.
        Marker& cmax(double f) {
            json["cmax"] = std::move(f);
            return *this;
        }

        // Sets the mid-point of the color domain by scaling `marker.cmin` and/or `marker.cmax` to be equidistant to
        // this point. Has an effect only if in `marker.color` is set to a numerical array. Value should have the same
        // units as in `marker.color`. Has no effect when `marker.cauto` is `false`.
        Marker& cmid(double f) {
            json["cmid"] = std::move(f);
            return *this;
        }

        // Sets the lower bound of the color domain. Has an effect only if in `marker.color` is set to a numerical
        // array. Value should have the same units as in `marker.color` and if set, `marker.cmax` must be set as well.
        Marker& cmin(double f) {
            json["cmin"] = std::move(f);
            return *this;
        }

        // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
        // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if
        // set.
        Marker& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Marker& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
        // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
        // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
        Marker& coloraxis(std::string f) {
            json["coloraxis"] = std::move(f);
            return *this;
        }

        Marker& colorbar(class Colorbar f) {
            json["colorbar"] = std::move(f.json);
            return *this;
        }

        // Sets the colorscale. Has an effect only if in `marker.color` is set to a numerical array. The colorscale must
        // be an array containing arrays mapping a normalized value to an rgb, rgba, hex, hsl, hsv, or named color
        // string. At minimum, a mapping for the lowest (0) and highest (1) values are required. For example, `[[0,
        // 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in color space, use
        // `marker.cmin` and `marker.cmax`. Alternatively, `colorscale` may be a palette name string of the following
        // list:
        // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
        Marker& colorscale(std::string f) {
            json["colorscale"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `color`.
        Marker& colorsrc(std::string f) {
            json["colorsrc"] = std::move(f);
            return *this;
        }

        Marker& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Sets the opacity of the bars.
        Marker& opacity(double f) {
            json["opacity"] = std::move(f);
            return *this;
        }
        Marker& opacity(std::vector<double> f) {
            json["opacity"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `opacity`.
        Marker& opacitysrc(std::string f) {
            json["opacitysrc"] = std::move(f);
            return *this;
        }

        // Sets the pattern within the marker.
        Marker& pattern(class Pattern f) {
            json["pattern"] = std::move(f.json);
            return *this;
        }

        // Reverses the color mapping if true. Has an effect only if in `marker.color` is set to a numerical array. If
        // true, `marker.cmin` will correspond to the last color in the array and `marker.cmax` will correspond to the
        // first color.
        Marker& reversescale(bool f) {
            json["reversescale"] = std::move(f);
            return *this;
        }

        // Determines whether or not a colorbar is displayed for this trace. Has an effect only if in `marker.color` is
        // set to a numerical array.
        Marker& showscale(bool f) {
            json["showscale"] = std::move(f);
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

    class Selected {
     public:

        class Marker {
         public:

            // Sets the marker color of selected points.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the marker opacity of selected points.
            Marker& opacity(double f) {
                json["opacity"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        class Textfont {
         public:

            // Sets the text font color of selected points.
            Textfont& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Selected& marker(class Marker f) {
            json["marker"] = std::move(f.json);
            return *this;
        }

        Selected& textfont(class Textfont f) {
            json["textfont"] = std::move(f.json);
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

    class Unselected {
     public:

        class Marker {
         public:

            // Sets the marker color of unselected points, applied only when a selection exists.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the marker opacity of unselected points, applied only when a selection exists.
            Marker& opacity(double f) {
                json["opacity"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        class Textfont {
         public:

            // Sets the text font color of unselected points, applied only when a selection exists.
            Textfont& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Unselected& marker(class Marker f) {
            json["marker"] = std::move(f.json);
            return *this;
        }

        Unselected& textfont(class Textfont f) {
            json["textfont"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Bar& alignmentgroup(std::string f) {
        json["alignmentgroup"] = std::move(f);
        return *this;
    }

    // Sets where the bar base is drawn (in position axis units). In *stack* or *relative* barmode, traces that set
    // *base* will be excluded and drawn in *overlay* mode instead.
    template <typename T>
    Bar& base(T f) {
        json["base"] = std::move(f);
        return *this;
    }
    template <typename T>
    Bar& base(std::vector<T> f) {
        json["base"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `base`.
    Bar& basesrc(std::string f) {
        json["basesrc"] = std::move(f);
        return *this;
    }

    // Determines whether the text nodes are clipped about the subplot axes. To show the text nodes above axis lines and
    // tick labels, make sure to set `xaxis.layer` and `yaxis.layer` to *below traces*.
    Bar& cliponaxis(bool f) {
        json["cliponaxis"] = std::move(f);
        return *this;
    }

    // Constrain the size of text inside or outside a bar to be no larger than the bar itself.
    // - Default: both
    Bar& constraintext(enum Constraintext f) {
        json["constraintext"] = to_string(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Bar& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the x coordinate step. See `x0` for more info.
    Bar& dx(double f) {
        json["dx"] = std::move(f);
        return *this;
    }

    // Sets the y coordinate step. See `y0` for more info.
    Bar& dy(double f) {
        json["dy"] = std::move(f);
        return *this;
    }

    Bar& error_x(class Error_x f) {
        json["error_x"] = std::move(f.json);
        return *this;
    }

    Bar& error_y(class Error_y f) {
        json["error_y"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Bar& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Bar& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Bar& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Bar& hoverlabel(class Hoverlabel f) {
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
    // variables `value` and `label`. Anything contained in tag `<extra>` is displayed in the secondary box, for example
    // "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an empty tag `<extra></extra>`.
    Bar& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Bar& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Bar& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Sets hover text elements associated with each (x,y) pair. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Bar& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Bar& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Bar& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Bar& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Determines if texts are kept at center or start/end points in `textposition` *inside* mode.
    // - Default: end
    Bar& insidetextanchor(enum Insidetextanchor f) {
        json["insidetextanchor"] = to_string(f);
        return *this;
    }

    // Sets the font used for `text` lying inside the bar.
    Bar& insidetextfont(class Insidetextfont f) {
        json["insidetextfont"] = std::move(f.json);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Bar& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Bar& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Bar& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Bar& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Bar& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Bar& marker(class Marker f) {
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
    Bar& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Bar& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Bar& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Bar& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Shifts the position where the bar is drawn (in position axis units). In *group* barmode, traces that set *offset*
    // will be excluded and drawn in *overlay* mode instead.
    Bar& offset(double f) {
        json["offset"] = std::move(f);
        return *this;
    }
    Bar& offset(std::vector<double> f) {
        json["offset"] = std::move(f);
        return *this;
    }

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Bar& offsetgroup(std::string f) {
        json["offsetgroup"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `offset`.
    Bar& offsetsrc(std::string f) {
        json["offsetsrc"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Bar& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Sets the orientation of the bars. With *v* (*h*), the value of the each bar spans along the vertical
    // (horizontal).
    Bar& orientation(enum Orientation f) {
        json["orientation"] = to_string(f);
        return *this;
    }

    // Sets the font used for `text` lying outside the bar.
    Bar& outsidetextfont(class Outsidetextfont f) {
        json["outsidetextfont"] = std::move(f.json);
        return *this;
    }

    Bar& selected(class Selected f) {
        json["selected"] = std::move(f.json);
        return *this;
    }

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Bar& selectedpoints(T f) {
        json["selectedpoints"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Bar& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    Bar& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets text elements associated with each (x,y) pair. If a single string, the same string appears over all the data
    // points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. If trace
    // `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will be seen in the hover labels.
    Bar& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Bar& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the angle of the tick labels with respect to the bar. For example, a `tickangle` of -90 draws the tick
    // labels vertically. With *auto* the texts may automatically be rotated to fit with the maximum size in bars.
    Bar& textangle(double f) {
        json["textangle"] = std::move(f);
        return *this;
    }

    // Sets the font used for `text`.
    Bar& textfont(class Textfont f) {
        json["textfont"] = std::move(f.json);
        return *this;
    }

    // Specifies the location of the `text`. *inside* positions `text` inside, next to the bar end (rotated and scaled
    // if needed). *outside* positions `text` outside, next to the bar end (scaled if needed), unless there is another
    // bar stacked on this one, then the text gets pushed inside. *auto* tries to position `text` inside the bar, but if
    // the bar is too small and no bar is stacked on this one the text is moved outside. If *none*, no text appears.
    // - Default: auto
    Bar& textposition(enum Textposition f) {
        json["textposition"] = to_string(f);
        return *this;
    }
    Bar& textposition(const std::vector<enum Textposition>& f) {
        std::vector<std::string> stringified(f.size());
        std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
        json["textposition"] = std::move(stringified);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Bar& textpositionsrc(std::string f) {
        json["textpositionsrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Bar& textsrc(std::string f) {
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
    // template string has access to variables `value` and `label`.
    Bar& texttemplate(std::string f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }
    Bar& texttemplate(std::vector<std::string> f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Bar& texttemplatesrc(std::string f) {
        json["texttemplatesrc"] = std::move(f);
        return *this;
    }

    Bar& transforms(class Transforms f) {
        json["transforms"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Bar& uid(std::string f) {
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
    Bar& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    Bar& unselected(class Unselected f) {
        json["unselected"] = std::move(f.json);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Bar& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the bar width (in position axis units).
    Bar& width(double f) {
        json["width"] = std::move(f);
        return *this;
    }
    Bar& width(std::vector<double> f) {
        json["width"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `width`.
    Bar& widthsrc(std::string f) {
        json["widthsrc"] = std::move(f);
        return *this;
    }

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Bar& x0(T f) {
        json["x0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Bar& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Bar& xcalendar(enum Xcalendar f) {
        json["xcalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Bar& xhoverformat(std::string f) {
        json["xhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Bar& xperiod(T f) {
        json["xperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Bar& xperiod0(T f) {
        json["xperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Bar& xperiodalignment(enum Xperiodalignment f) {
        json["xperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Bar& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Bar& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Bar& y0(T f) {
        json["y0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Bar& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Bar& ycalendar(enum Ycalendar f) {
        json["ycalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Bar& yhoverformat(std::string f) {
        json["yhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Bar& yperiod(T f) {
        json["yperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Bar& yperiod0(T f) {
        json["yperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Bar& yperiodalignment(enum Yperiodalignment f) {
        json["yperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Bar& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }
};
} // namespace plotlypp
