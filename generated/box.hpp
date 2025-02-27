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
    std::string to_string(Boxmean e) {
        switch (e) {
        case Boxmean::TRUE:
            return "True";
        case Boxmean::SD:
            return "sd";
        case Boxmean::FALSE:
            return "False";
        }
    }

    enum class Boxpoints {
        ALL,
        OUTLIERS,
        SUSPECTEDOUTLIERS,
        FALSE,
    };
    std::string to_string(Boxpoints e) {
        switch (e) {
        case Boxpoints::ALL:
            return "all";
        case Boxpoints::OUTLIERS:
            return "outliers";
        case Boxpoints::SUSPECTEDOUTLIERS:
            return "suspectedoutliers";
        case Boxpoints::FALSE:
            return "False";
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

    enum class Quartilemethod {
        LINEAR,
        EXCLUSIVE,
        INCLUSIVE,
    };
    std::string to_string(Quartilemethod e) {
        switch (e) {
        case Quartilemethod::LINEAR:
            return "linear";
        case Quartilemethod::EXCLUSIVE:
            return "exclusive";
        case Quartilemethod::INCLUSIVE:
            return "inclusive";
        }
    }

    enum class Sizemode {
        QUARTILES,
        SD,
    };
    std::string to_string(Sizemode e) {
        switch (e) {
        case Sizemode::QUARTILES:
            return "quartiles";
        case Sizemode::SD:
            return "sd";
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

            enum class Style {
                NORMAL,
                ITALIC,
            };
            std::string to_string(Style e) {
                switch (e) {
                case Style::NORMAL:
                    return "normal";
                case Style::ITALIC:
                    return "italic";
                }
            }

            enum class Textcase {
                NORMAL,
                WORD_CAPS,
                UPPER,
                LOWER,
            };
            std::string to_string(Textcase e) {
                switch (e) {
                case Textcase::NORMAL:
                    return "normal";
                case Textcase::WORD_CAPS:
                    return "word caps";
                case Textcase::UPPER:
                    return "upper";
                case Textcase::LOWER:
                    return "lower";
                }
            }

            enum class Variant {
                NORMAL,
                SMALL_CAPS,
                ALL_SMALL_CAPS,
                ALL_PETITE_CAPS,
                PETITE_CAPS,
                UNICASE,
            };
            std::string to_string(Variant e) {
                switch (e) {
                case Variant::NORMAL:
                    return "normal";
                case Variant::SMALL_CAPS:
                    return "small-caps";
                case Variant::ALL_SMALL_CAPS:
                    return "all-small-caps";
                case Variant::ALL_PETITE_CAPS:
                    return "all-petite-caps";
                case Variant::PETITE_CAPS:
                    return "petite-caps";
                case Variant::UNICASE:
                    return "unicase";
                }
            }

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
            // *Courier New*, *Droid Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open
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

            // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
            // combinations e.g. *under+over*, etc.
            // - Default: none
            // - Flags: ['under', 'over', 'through']
            // - Extras ['none']
            Font& lineposition(std::string f) {
                json["lineposition"] = std::move(f);
                return *this;
            }
            Font& lineposition(std::vector<std::string> f) {
                json["lineposition"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `lineposition`.
            Font& linepositionsrc(std::string f) {
                json["linepositionsrc"] = std::move(f);
                return *this;
            }

            // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast
            // text font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
            Font& shadow(std::string f) {
                json["shadow"] = std::move(f);
                return *this;
            }
            Font& shadow(std::vector<std::string> f) {
                json["shadow"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `shadow`.
            Font& shadowsrc(std::string f) {
                json["shadowsrc"] = std::move(f);
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

            // Sets whether a font should be styled with a normal or italic face from its family.
            // - Default: normal
            Font& style(enum Style f) {
                json["style"] = to_string(f);
                return *this;
            }
            Font& style(const std::vector<enum Style>& f) {
                std::vector<std::string> stringified(f.size());
                std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
                json["style"] = std::move(stringified);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `style`.
            Font& stylesrc(std::string f) {
                json["stylesrc"] = std::move(f);
                return *this;
            }

            // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or
            // with each word capitalized.
            // - Default: normal
            Font& textcase(enum Textcase f) {
                json["textcase"] = to_string(f);
                return *this;
            }
            Font& textcase(const std::vector<enum Textcase>& f) {
                std::vector<std::string> stringified(f.size());
                std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
                json["textcase"] = std::move(stringified);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `textcase`.
            Font& textcasesrc(std::string f) {
                json["textcasesrc"] = std::move(f);
                return *this;
            }

            // Sets the variant of the font.
            // - Default: normal
            Font& variant(enum Variant f) {
                json["variant"] = to_string(f);
                return *this;
            }
            Font& variant(const std::vector<enum Variant>& f) {
                std::vector<std::string> stringified(f.size());
                std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
                json["variant"] = std::move(stringified);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `variant`.
            Font& variantsrc(std::string f) {
                json["variantsrc"] = std::move(f);
                return *this;
            }

            // Sets the weight (or boldness) of the font.
            Font& weight(int f) {
                json["weight"] = std::move(f);
                return *this;
            }
            Font& weight(std::vector<int> f) {
                json["weight"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `weight`.
            Font& weightsrc(std::string f) {
                json["weightsrc"] = std::move(f);
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

            enum class Style {
                NORMAL,
                ITALIC,
            };
            std::string to_string(Style e) {
                switch (e) {
                case Style::NORMAL:
                    return "normal";
                case Style::ITALIC:
                    return "italic";
                }
            }

            enum class Textcase {
                NORMAL,
                WORD_CAPS,
                UPPER,
                LOWER,
            };
            std::string to_string(Textcase e) {
                switch (e) {
                case Textcase::NORMAL:
                    return "normal";
                case Textcase::WORD_CAPS:
                    return "word caps";
                case Textcase::UPPER:
                    return "upper";
                case Textcase::LOWER:
                    return "lower";
                }
            }

            enum class Variant {
                NORMAL,
                SMALL_CAPS,
                ALL_SMALL_CAPS,
                ALL_PETITE_CAPS,
                PETITE_CAPS,
                UNICASE,
            };
            std::string to_string(Variant e) {
                switch (e) {
                case Variant::NORMAL:
                    return "normal";
                case Variant::SMALL_CAPS:
                    return "small-caps";
                case Variant::ALL_SMALL_CAPS:
                    return "all-small-caps";
                case Variant::ALL_PETITE_CAPS:
                    return "all-petite-caps";
                case Variant::PETITE_CAPS:
                    return "petite-caps";
                case Variant::UNICASE:
                    return "unicase";
                }
            }

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
            // *Courier New*, *Droid Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open
            // Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
            Font& family(std::string f) {
                json["family"] = std::move(f);
                return *this;
            }

            // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
            // combinations e.g. *under+over*, etc.
            // - Default: none
            // - Flags: ['under', 'over', 'through']
            // - Extras ['none']
            Font& lineposition(std::string f) {
                json["lineposition"] = std::move(f);
                return *this;
            }

            // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast
            // text font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
            Font& shadow(std::string f) {
                json["shadow"] = std::move(f);
                return *this;
            }

            Font& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Sets whether a font should be styled with a normal or italic face from its family.
            // - Default: normal
            Font& style(enum Style f) {
                json["style"] = to_string(f);
                return *this;
            }

            // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or
            // with each word capitalized.
            // - Default: normal
            Font& textcase(enum Textcase f) {
                json["textcase"] = to_string(f);
                return *this;
            }

            // Sets the variant of the font.
            // - Default: normal
            Font& variant(enum Variant f) {
                json["variant"] = to_string(f);
                return *this;
            }

            // Sets the weight (or boldness) of the font.
            Font& weight(int f) {
                json["weight"] = std::move(f);
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

        // Sets the color of line bounding the box(es).
        Line& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Line& color(double f) {
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

    class Marker {
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
        std::string to_string(Symbol e) {
            switch (e) {
            case Symbol::NUM_0:
                return "0";
            case Symbol::CIRCLE:
                return "circle";
            case Symbol::NUM_100:
                return "100";
            case Symbol::CIRCLE_OPEN:
                return "circle-open";
            case Symbol::NUM_200:
                return "200";
            case Symbol::CIRCLE_DOT:
                return "circle-dot";
            case Symbol::NUM_300:
                return "300";
            case Symbol::CIRCLE_OPEN_DOT:
                return "circle-open-dot";
            case Symbol::NUM_1:
                return "1";
            case Symbol::SQUARE:
                return "square";
            case Symbol::NUM_101:
                return "101";
            case Symbol::SQUARE_OPEN:
                return "square-open";
            case Symbol::NUM_201:
                return "201";
            case Symbol::SQUARE_DOT:
                return "square-dot";
            case Symbol::NUM_301:
                return "301";
            case Symbol::SQUARE_OPEN_DOT:
                return "square-open-dot";
            case Symbol::NUM_2:
                return "2";
            case Symbol::DIAMOND:
                return "diamond";
            case Symbol::NUM_102:
                return "102";
            case Symbol::DIAMOND_OPEN:
                return "diamond-open";
            case Symbol::NUM_202:
                return "202";
            case Symbol::DIAMOND_DOT:
                return "diamond-dot";
            case Symbol::NUM_302:
                return "302";
            case Symbol::DIAMOND_OPEN_DOT:
                return "diamond-open-dot";
            case Symbol::NUM_3:
                return "3";
            case Symbol::CROSS:
                return "cross";
            case Symbol::NUM_103:
                return "103";
            case Symbol::CROSS_OPEN:
                return "cross-open";
            case Symbol::NUM_203:
                return "203";
            case Symbol::CROSS_DOT:
                return "cross-dot";
            case Symbol::NUM_303:
                return "303";
            case Symbol::CROSS_OPEN_DOT:
                return "cross-open-dot";
            case Symbol::NUM_4:
                return "4";
            case Symbol::X:
                return "x";
            case Symbol::NUM_104:
                return "104";
            case Symbol::X_OPEN:
                return "x-open";
            case Symbol::NUM_204:
                return "204";
            case Symbol::X_DOT:
                return "x-dot";
            case Symbol::NUM_304:
                return "304";
            case Symbol::X_OPEN_DOT:
                return "x-open-dot";
            case Symbol::NUM_5:
                return "5";
            case Symbol::TRIANGLE_UP:
                return "triangle-up";
            case Symbol::NUM_105:
                return "105";
            case Symbol::TRIANGLE_UP_OPEN:
                return "triangle-up-open";
            case Symbol::NUM_205:
                return "205";
            case Symbol::TRIANGLE_UP_DOT:
                return "triangle-up-dot";
            case Symbol::NUM_305:
                return "305";
            case Symbol::TRIANGLE_UP_OPEN_DOT:
                return "triangle-up-open-dot";
            case Symbol::NUM_6:
                return "6";
            case Symbol::TRIANGLE_DOWN:
                return "triangle-down";
            case Symbol::NUM_106:
                return "106";
            case Symbol::TRIANGLE_DOWN_OPEN:
                return "triangle-down-open";
            case Symbol::NUM_206:
                return "206";
            case Symbol::TRIANGLE_DOWN_DOT:
                return "triangle-down-dot";
            case Symbol::NUM_306:
                return "306";
            case Symbol::TRIANGLE_DOWN_OPEN_DOT:
                return "triangle-down-open-dot";
            case Symbol::NUM_7:
                return "7";
            case Symbol::TRIANGLE_LEFT:
                return "triangle-left";
            case Symbol::NUM_107:
                return "107";
            case Symbol::TRIANGLE_LEFT_OPEN:
                return "triangle-left-open";
            case Symbol::NUM_207:
                return "207";
            case Symbol::TRIANGLE_LEFT_DOT:
                return "triangle-left-dot";
            case Symbol::NUM_307:
                return "307";
            case Symbol::TRIANGLE_LEFT_OPEN_DOT:
                return "triangle-left-open-dot";
            case Symbol::NUM_8:
                return "8";
            case Symbol::TRIANGLE_RIGHT:
                return "triangle-right";
            case Symbol::NUM_108:
                return "108";
            case Symbol::TRIANGLE_RIGHT_OPEN:
                return "triangle-right-open";
            case Symbol::NUM_208:
                return "208";
            case Symbol::TRIANGLE_RIGHT_DOT:
                return "triangle-right-dot";
            case Symbol::NUM_308:
                return "308";
            case Symbol::TRIANGLE_RIGHT_OPEN_DOT:
                return "triangle-right-open-dot";
            case Symbol::NUM_9:
                return "9";
            case Symbol::TRIANGLE_NE:
                return "triangle-ne";
            case Symbol::NUM_109:
                return "109";
            case Symbol::TRIANGLE_NE_OPEN:
                return "triangle-ne-open";
            case Symbol::NUM_209:
                return "209";
            case Symbol::TRIANGLE_NE_DOT:
                return "triangle-ne-dot";
            case Symbol::NUM_309:
                return "309";
            case Symbol::TRIANGLE_NE_OPEN_DOT:
                return "triangle-ne-open-dot";
            case Symbol::NUM_10:
                return "10";
            case Symbol::TRIANGLE_SE:
                return "triangle-se";
            case Symbol::NUM_110:
                return "110";
            case Symbol::TRIANGLE_SE_OPEN:
                return "triangle-se-open";
            case Symbol::NUM_210:
                return "210";
            case Symbol::TRIANGLE_SE_DOT:
                return "triangle-se-dot";
            case Symbol::NUM_310:
                return "310";
            case Symbol::TRIANGLE_SE_OPEN_DOT:
                return "triangle-se-open-dot";
            case Symbol::NUM_11:
                return "11";
            case Symbol::TRIANGLE_SW:
                return "triangle-sw";
            case Symbol::NUM_111:
                return "111";
            case Symbol::TRIANGLE_SW_OPEN:
                return "triangle-sw-open";
            case Symbol::NUM_211:
                return "211";
            case Symbol::TRIANGLE_SW_DOT:
                return "triangle-sw-dot";
            case Symbol::NUM_311:
                return "311";
            case Symbol::TRIANGLE_SW_OPEN_DOT:
                return "triangle-sw-open-dot";
            case Symbol::NUM_12:
                return "12";
            case Symbol::TRIANGLE_NW:
                return "triangle-nw";
            case Symbol::NUM_112:
                return "112";
            case Symbol::TRIANGLE_NW_OPEN:
                return "triangle-nw-open";
            case Symbol::NUM_212:
                return "212";
            case Symbol::TRIANGLE_NW_DOT:
                return "triangle-nw-dot";
            case Symbol::NUM_312:
                return "312";
            case Symbol::TRIANGLE_NW_OPEN_DOT:
                return "triangle-nw-open-dot";
            case Symbol::NUM_13:
                return "13";
            case Symbol::PENTAGON:
                return "pentagon";
            case Symbol::NUM_113:
                return "113";
            case Symbol::PENTAGON_OPEN:
                return "pentagon-open";
            case Symbol::NUM_213:
                return "213";
            case Symbol::PENTAGON_DOT:
                return "pentagon-dot";
            case Symbol::NUM_313:
                return "313";
            case Symbol::PENTAGON_OPEN_DOT:
                return "pentagon-open-dot";
            case Symbol::NUM_14:
                return "14";
            case Symbol::HEXAGON:
                return "hexagon";
            case Symbol::NUM_114:
                return "114";
            case Symbol::HEXAGON_OPEN:
                return "hexagon-open";
            case Symbol::NUM_214:
                return "214";
            case Symbol::HEXAGON_DOT:
                return "hexagon-dot";
            case Symbol::NUM_314:
                return "314";
            case Symbol::HEXAGON_OPEN_DOT:
                return "hexagon-open-dot";
            case Symbol::NUM_15:
                return "15";
            case Symbol::HEXAGON2:
                return "hexagon2";
            case Symbol::NUM_115:
                return "115";
            case Symbol::HEXAGON2_OPEN:
                return "hexagon2-open";
            case Symbol::NUM_215:
                return "215";
            case Symbol::HEXAGON2_DOT:
                return "hexagon2-dot";
            case Symbol::NUM_315:
                return "315";
            case Symbol::HEXAGON2_OPEN_DOT:
                return "hexagon2-open-dot";
            case Symbol::NUM_16:
                return "16";
            case Symbol::OCTAGON:
                return "octagon";
            case Symbol::NUM_116:
                return "116";
            case Symbol::OCTAGON_OPEN:
                return "octagon-open";
            case Symbol::NUM_216:
                return "216";
            case Symbol::OCTAGON_DOT:
                return "octagon-dot";
            case Symbol::NUM_316:
                return "316";
            case Symbol::OCTAGON_OPEN_DOT:
                return "octagon-open-dot";
            case Symbol::NUM_17:
                return "17";
            case Symbol::STAR:
                return "star";
            case Symbol::NUM_117:
                return "117";
            case Symbol::STAR_OPEN:
                return "star-open";
            case Symbol::NUM_217:
                return "217";
            case Symbol::STAR_DOT:
                return "star-dot";
            case Symbol::NUM_317:
                return "317";
            case Symbol::STAR_OPEN_DOT:
                return "star-open-dot";
            case Symbol::NUM_18:
                return "18";
            case Symbol::HEXAGRAM:
                return "hexagram";
            case Symbol::NUM_118:
                return "118";
            case Symbol::HEXAGRAM_OPEN:
                return "hexagram-open";
            case Symbol::NUM_218:
                return "218";
            case Symbol::HEXAGRAM_DOT:
                return "hexagram-dot";
            case Symbol::NUM_318:
                return "318";
            case Symbol::HEXAGRAM_OPEN_DOT:
                return "hexagram-open-dot";
            case Symbol::NUM_19:
                return "19";
            case Symbol::STAR_TRIANGLE_UP:
                return "star-triangle-up";
            case Symbol::NUM_119:
                return "119";
            case Symbol::STAR_TRIANGLE_UP_OPEN:
                return "star-triangle-up-open";
            case Symbol::NUM_219:
                return "219";
            case Symbol::STAR_TRIANGLE_UP_DOT:
                return "star-triangle-up-dot";
            case Symbol::NUM_319:
                return "319";
            case Symbol::STAR_TRIANGLE_UP_OPEN_DOT:
                return "star-triangle-up-open-dot";
            case Symbol::NUM_20:
                return "20";
            case Symbol::STAR_TRIANGLE_DOWN:
                return "star-triangle-down";
            case Symbol::NUM_120:
                return "120";
            case Symbol::STAR_TRIANGLE_DOWN_OPEN:
                return "star-triangle-down-open";
            case Symbol::NUM_220:
                return "220";
            case Symbol::STAR_TRIANGLE_DOWN_DOT:
                return "star-triangle-down-dot";
            case Symbol::NUM_320:
                return "320";
            case Symbol::STAR_TRIANGLE_DOWN_OPEN_DOT:
                return "star-triangle-down-open-dot";
            case Symbol::NUM_21:
                return "21";
            case Symbol::STAR_SQUARE:
                return "star-square";
            case Symbol::NUM_121:
                return "121";
            case Symbol::STAR_SQUARE_OPEN:
                return "star-square-open";
            case Symbol::NUM_221:
                return "221";
            case Symbol::STAR_SQUARE_DOT:
                return "star-square-dot";
            case Symbol::NUM_321:
                return "321";
            case Symbol::STAR_SQUARE_OPEN_DOT:
                return "star-square-open-dot";
            case Symbol::NUM_22:
                return "22";
            case Symbol::STAR_DIAMOND:
                return "star-diamond";
            case Symbol::NUM_122:
                return "122";
            case Symbol::STAR_DIAMOND_OPEN:
                return "star-diamond-open";
            case Symbol::NUM_222:
                return "222";
            case Symbol::STAR_DIAMOND_DOT:
                return "star-diamond-dot";
            case Symbol::NUM_322:
                return "322";
            case Symbol::STAR_DIAMOND_OPEN_DOT:
                return "star-diamond-open-dot";
            case Symbol::NUM_23:
                return "23";
            case Symbol::DIAMOND_TALL:
                return "diamond-tall";
            case Symbol::NUM_123:
                return "123";
            case Symbol::DIAMOND_TALL_OPEN:
                return "diamond-tall-open";
            case Symbol::NUM_223:
                return "223";
            case Symbol::DIAMOND_TALL_DOT:
                return "diamond-tall-dot";
            case Symbol::NUM_323:
                return "323";
            case Symbol::DIAMOND_TALL_OPEN_DOT:
                return "diamond-tall-open-dot";
            case Symbol::NUM_24:
                return "24";
            case Symbol::DIAMOND_WIDE:
                return "diamond-wide";
            case Symbol::NUM_124:
                return "124";
            case Symbol::DIAMOND_WIDE_OPEN:
                return "diamond-wide-open";
            case Symbol::NUM_224:
                return "224";
            case Symbol::DIAMOND_WIDE_DOT:
                return "diamond-wide-dot";
            case Symbol::NUM_324:
                return "324";
            case Symbol::DIAMOND_WIDE_OPEN_DOT:
                return "diamond-wide-open-dot";
            case Symbol::NUM_25:
                return "25";
            case Symbol::HOURGLASS:
                return "hourglass";
            case Symbol::NUM_125:
                return "125";
            case Symbol::HOURGLASS_OPEN:
                return "hourglass-open";
            case Symbol::NUM_26:
                return "26";
            case Symbol::BOWTIE:
                return "bowtie";
            case Symbol::NUM_126:
                return "126";
            case Symbol::BOWTIE_OPEN:
                return "bowtie-open";
            case Symbol::NUM_27:
                return "27";
            case Symbol::CIRCLE_CROSS:
                return "circle-cross";
            case Symbol::NUM_127:
                return "127";
            case Symbol::CIRCLE_CROSS_OPEN:
                return "circle-cross-open";
            case Symbol::NUM_28:
                return "28";
            case Symbol::CIRCLE_X:
                return "circle-x";
            case Symbol::NUM_128:
                return "128";
            case Symbol::CIRCLE_X_OPEN:
                return "circle-x-open";
            case Symbol::NUM_29:
                return "29";
            case Symbol::SQUARE_CROSS:
                return "square-cross";
            case Symbol::NUM_129:
                return "129";
            case Symbol::SQUARE_CROSS_OPEN:
                return "square-cross-open";
            case Symbol::NUM_30:
                return "30";
            case Symbol::SQUARE_X:
                return "square-x";
            case Symbol::NUM_130:
                return "130";
            case Symbol::SQUARE_X_OPEN:
                return "square-x-open";
            case Symbol::NUM_31:
                return "31";
            case Symbol::DIAMOND_CROSS:
                return "diamond-cross";
            case Symbol::NUM_131:
                return "131";
            case Symbol::DIAMOND_CROSS_OPEN:
                return "diamond-cross-open";
            case Symbol::NUM_32:
                return "32";
            case Symbol::DIAMOND_X:
                return "diamond-x";
            case Symbol::NUM_132:
                return "132";
            case Symbol::DIAMOND_X_OPEN:
                return "diamond-x-open";
            case Symbol::NUM_33:
                return "33";
            case Symbol::CROSS_THIN:
                return "cross-thin";
            case Symbol::NUM_133:
                return "133";
            case Symbol::CROSS_THIN_OPEN:
                return "cross-thin-open";
            case Symbol::NUM_34:
                return "34";
            case Symbol::X_THIN:
                return "x-thin";
            case Symbol::NUM_134:
                return "134";
            case Symbol::X_THIN_OPEN:
                return "x-thin-open";
            case Symbol::NUM_35:
                return "35";
            case Symbol::ASTERISK:
                return "asterisk";
            case Symbol::NUM_135:
                return "135";
            case Symbol::ASTERISK_OPEN:
                return "asterisk-open";
            case Symbol::NUM_36:
                return "36";
            case Symbol::HASH:
                return "hash";
            case Symbol::NUM_136:
                return "136";
            case Symbol::HASH_OPEN:
                return "hash-open";
            case Symbol::NUM_236:
                return "236";
            case Symbol::HASH_DOT:
                return "hash-dot";
            case Symbol::NUM_336:
                return "336";
            case Symbol::HASH_OPEN_DOT:
                return "hash-open-dot";
            case Symbol::NUM_37:
                return "37";
            case Symbol::Y_UP:
                return "y-up";
            case Symbol::NUM_137:
                return "137";
            case Symbol::Y_UP_OPEN:
                return "y-up-open";
            case Symbol::NUM_38:
                return "38";
            case Symbol::Y_DOWN:
                return "y-down";
            case Symbol::NUM_138:
                return "138";
            case Symbol::Y_DOWN_OPEN:
                return "y-down-open";
            case Symbol::NUM_39:
                return "39";
            case Symbol::Y_LEFT:
                return "y-left";
            case Symbol::NUM_139:
                return "139";
            case Symbol::Y_LEFT_OPEN:
                return "y-left-open";
            case Symbol::NUM_40:
                return "40";
            case Symbol::Y_RIGHT:
                return "y-right";
            case Symbol::NUM_140:
                return "140";
            case Symbol::Y_RIGHT_OPEN:
                return "y-right-open";
            case Symbol::NUM_41:
                return "41";
            case Symbol::LINE_EW:
                return "line-ew";
            case Symbol::NUM_141:
                return "141";
            case Symbol::LINE_EW_OPEN:
                return "line-ew-open";
            case Symbol::NUM_42:
                return "42";
            case Symbol::LINE_NS:
                return "line-ns";
            case Symbol::NUM_142:
                return "142";
            case Symbol::LINE_NS_OPEN:
                return "line-ns-open";
            case Symbol::NUM_43:
                return "43";
            case Symbol::LINE_NE:
                return "line-ne";
            case Symbol::NUM_143:
                return "143";
            case Symbol::LINE_NE_OPEN:
                return "line-ne-open";
            case Symbol::NUM_44:
                return "44";
            case Symbol::LINE_NW:
                return "line-nw";
            case Symbol::NUM_144:
                return "144";
            case Symbol::LINE_NW_OPEN:
                return "line-nw-open";
            case Symbol::NUM_45:
                return "45";
            case Symbol::ARROW_UP:
                return "arrow-up";
            case Symbol::NUM_145:
                return "145";
            case Symbol::ARROW_UP_OPEN:
                return "arrow-up-open";
            case Symbol::NUM_46:
                return "46";
            case Symbol::ARROW_DOWN:
                return "arrow-down";
            case Symbol::NUM_146:
                return "146";
            case Symbol::ARROW_DOWN_OPEN:
                return "arrow-down-open";
            case Symbol::NUM_47:
                return "47";
            case Symbol::ARROW_LEFT:
                return "arrow-left";
            case Symbol::NUM_147:
                return "147";
            case Symbol::ARROW_LEFT_OPEN:
                return "arrow-left-open";
            case Symbol::NUM_48:
                return "48";
            case Symbol::ARROW_RIGHT:
                return "arrow-right";
            case Symbol::NUM_148:
                return "148";
            case Symbol::ARROW_RIGHT_OPEN:
                return "arrow-right-open";
            case Symbol::NUM_49:
                return "49";
            case Symbol::ARROW_BAR_UP:
                return "arrow-bar-up";
            case Symbol::NUM_149:
                return "149";
            case Symbol::ARROW_BAR_UP_OPEN:
                return "arrow-bar-up-open";
            case Symbol::NUM_50:
                return "50";
            case Symbol::ARROW_BAR_DOWN:
                return "arrow-bar-down";
            case Symbol::NUM_150:
                return "150";
            case Symbol::ARROW_BAR_DOWN_OPEN:
                return "arrow-bar-down-open";
            case Symbol::NUM_51:
                return "51";
            case Symbol::ARROW_BAR_LEFT:
                return "arrow-bar-left";
            case Symbol::NUM_151:
                return "151";
            case Symbol::ARROW_BAR_LEFT_OPEN:
                return "arrow-bar-left-open";
            case Symbol::NUM_52:
                return "52";
            case Symbol::ARROW_BAR_RIGHT:
                return "arrow-bar-right";
            case Symbol::NUM_152:
                return "152";
            case Symbol::ARROW_BAR_RIGHT_OPEN:
                return "arrow-bar-right-open";
            case Symbol::NUM_53:
                return "53";
            case Symbol::ARROW:
                return "arrow";
            case Symbol::NUM_153:
                return "153";
            case Symbol::ARROW_OPEN:
                return "arrow-open";
            case Symbol::NUM_54:
                return "54";
            case Symbol::ARROW_WIDE:
                return "arrow-wide";
            case Symbol::NUM_154:
                return "154";
            case Symbol::ARROW_WIDE_OPEN:
                return "arrow-wide-open";
            }
        }

        class Line {
         public:

            // Sets the marker.line color. It accepts either a specific color or an array of numbers that are mapped to
            // the colorscale relative to the max and min values of the array or relative to `marker.line.cmin` and
            // `marker.line.cmax` if set.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the border line color of the outlier sample points. Defaults to marker.color
            Line& outliercolor(std::string f) {
                json["outliercolor"] = std::move(f);
                return *this;
            }
            Line& outliercolor(double f) {
                json["outliercolor"] = std::move(f);
                return *this;
            }

            // Sets the border line width (in px) of the outlier sample points.
            Line& outlierwidth(double f) {
                json["outlierwidth"] = std::move(f);
                return *this;
            }

            // Sets the width (in px) of the lines bounding the marker points.
            Line& width(double f) {
                json["width"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the marker angle in respect to `angleref`.
        Marker& angle(double f) {
            json["angle"] = std::move(f);
            return *this;
        }

        // Sets the marker color. It accepts either a specific color or an array of numbers that are mapped to the
        // colorscale relative to the max and min values of the array or relative to `marker.cmin` and `marker.cmax` if
        // set.
        Marker& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Marker& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }

        Marker& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Sets the marker opacity.
        Marker& opacity(double f) {
            json["opacity"] = std::move(f);
            return *this;
        }

        // Sets the color of the outlier sample points.
        Marker& outliercolor(std::string f) {
            json["outliercolor"] = std::move(f);
            return *this;
        }
        Marker& outliercolor(double f) {
            json["outliercolor"] = std::move(f);
            return *this;
        }

        // Sets the marker size (in px).
        Marker& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Sets the marker symbol type. Adding 100 is equivalent to appending *-open* to a symbol name. Adding 200 is
        // equivalent to appending *-dot* to a symbol name. Adding 300 is equivalent to appending *-open-dot* or
        // *dot-open* to a symbol name.
        // - Default: circle
        Marker& symbol(enum Symbol f) {
            json["symbol"] = to_string(f);
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
            Marker& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the marker opacity of selected points.
            Marker& opacity(double f) {
                json["opacity"] = std::move(f);
                return *this;
            }

            // Sets the marker size of selected points.
            Marker& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Selected& marker(class Marker f) {
            json["marker"] = std::move(f.json);
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

    class Unselected {
     public:

        class Marker {
         public:

            // Sets the marker color of unselected points, applied only when a selection exists.
            Marker& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Marker& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the marker opacity of unselected points, applied only when a selection exists.
            Marker& opacity(double f) {
                json["opacity"] = std::move(f);
                return *this;
            }

            // Sets the marker size of unselected points, applied only when a selection exists.
            Marker& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Unselected& marker(class Marker f) {
            json["marker"] = std::move(f.json);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // Set several traces linked to the same position axis or matching axes to the same alignmentgroup. This controls
    // whether bars compute their positional range dependently or independently.
    Box& alignmentgroup(std::string f) {
        json["alignmentgroup"] = std::move(f);
        return *this;
    }

    // If *true*, the mean of the box(es)' underlying distribution is drawn as a dashed line inside the box(es). If *sd*
    // the standard deviation is also drawn. Defaults to *true* when `mean` is set. Defaults to *sd* when `sd` is set
    // Otherwise defaults to *false*.
    Box& boxmean(enum Boxmean f) {
        json["boxmean"] = to_string(f);
        return *this;
    }

    // If *outliers*, only the sample points lying outside the whiskers are shown If *suspectedoutliers*, the outlier
    // points are shown and points either less than 4*Q1-3*Q3 or greater than 4*Q3-3*Q1 are highlighted (see
    // `outliercolor`) If *all*, all sample points are shown If *false*, only the box(es) are shown with no sample
    // points Defaults to *suspectedoutliers* when `marker.outliercolor` or `marker.line.outliercolor` is set. Defaults
    // to *all* under the q1/median/q3 signature. Otherwise defaults to *outliers*.
    Box& boxpoints(enum Boxpoints f) {
        json["boxpoints"] = to_string(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Box& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the x coordinate step for multi-box traces set using q1/median/q3.
    Box& dx(double f) {
        json["dx"] = std::move(f);
        return *this;
    }

    // Sets the y coordinate step for multi-box traces set using q1/median/q3.
    Box& dy(double f) {
        json["dy"] = std::move(f);
        return *this;
    }

    // Sets the fill color. Defaults to a half-transparent variant of the line color, marker color, or marker line
    // color, whichever is available.
    Box& fillcolor(std::string f) {
        json["fillcolor"] = std::move(f);
        return *this;
    }
    Box& fillcolor(double f) {
        json["fillcolor"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Box& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Box& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Box& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Box& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

    // Do the hover effects highlight individual boxes  or sample points or both?
    // - Default: boxes+points
    // - Flags: ['boxes', 'points']
    Box& hoveron(std::string f) {
        json["hoveron"] = std::move(f);
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
    // specified per-point (the ones that are `arrayOk: true`) are available.  Anything contained in tag `<extra>` is
    // displayed in the secondary box, for example "<extra>{fullData.name}</extra>". To hide the secondary box
    // completely, use an empty tag `<extra></extra>`.
    Box& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Box& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Box& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Same as `text`.
    Box& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Box& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Box& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Box& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the amount of jitter in the sample points drawn. If *0*, the sample points align along the distribution
    // axis. If *1*, the sample points are drawn in a random jitter of width equal to the width of the box(es).
    Box& jitter(double f) {
        json["jitter"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Box& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Box& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Box& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Box& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Box& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Box& line(class Line f) {
        json["line"] = std::move(f.json);
        return *this;
    }

    // Sets the lower fence values. There should be as many items as the number of boxes desired. This attribute has
    // effect only under the q1/median/q3 signature. If `lowerfence` is not provided but a sample (in `y` or `x`) is
    // set, we compute the lower as the last sample point below 1.5 times the IQR.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& lowerfence(std::vector<T> f) {
        json["lowerfence"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `lowerfence`.
    Box& lowerfencesrc(std::string f) {
        json["lowerfencesrc"] = std::move(f);
        return *this;
    }

    Box& marker(class Marker f) {
        json["marker"] = std::move(f.json);
        return *this;
    }

    // Sets the mean values. There should be as many items as the number of boxes desired. This attribute has effect
    // only under the q1/median/q3 signature. If `mean` is not provided but a sample (in `y` or `x`) is set, we compute
    // the mean for each box using the sample values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& mean(std::vector<T> f) {
        json["mean"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `mean`.
    Box& meansrc(std::string f) {
        json["meansrc"] = std::move(f);
        return *this;
    }

    // Sets the median values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& median(std::vector<T> f) {
        json["median"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `median`.
    Box& mediansrc(std::string f) {
        json["mediansrc"] = std::move(f);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Box& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Box& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Box& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover. For box traces, the name will also
    // be used for the position coordinate, if `x` and `x0` (`y` and `y0` if horizontal) are missing and the position
    // axis is categorical
    Box& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Determines whether or not notches are drawn. Notches displays a confidence interval around the median. We compute
    // the confidence interval as median +/- 1.57 * IQR / sqrt(N), where IQR is the interquartile range and N is the
    // sample size. If two boxes' notches do not overlap there is 95% confidence their medians differ. See
    // https://sites.google.com/site/davidsstatistics/home/notched-box-plots for more info. Defaults to *false* unless
    // `notchwidth` or `notchspan` is set.
    Box& notched(bool f) {
        json["notched"] = std::move(f);
        return *this;
    }

    // Sets the notch span from the boxes' `median` values. There should be as many items as the number of boxes
    // desired. This attribute has effect only under the q1/median/q3 signature. If `notchspan` is not provided but a
    // sample (in `y` or `x`) is set, we compute it as 1.57 * IQR / sqrt(N), where N is the sample size.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& notchspan(std::vector<T> f) {
        json["notchspan"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `notchspan`.
    Box& notchspansrc(std::string f) {
        json["notchspansrc"] = std::move(f);
        return *this;
    }

    // Sets the width of the notches relative to the box' width. For example, with 0, the notches are as wide as the
    // box(es).
    Box& notchwidth(double f) {
        json["notchwidth"] = std::move(f);
        return *this;
    }

    // Set several traces linked to the same position axis or matching axes to the same offsetgroup where bars of the
    // same position coordinate will line up.
    Box& offsetgroup(std::string f) {
        json["offsetgroup"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Box& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Sets the orientation of the box(es). If *v* (*h*), the distribution is visualized along the vertical
    // (horizontal).
    Box& orientation(enum Orientation f) {
        json["orientation"] = to_string(f);
        return *this;
    }

    // Sets the position of the sample points in relation to the box(es). If *0*, the sample points are places over the
    // center of the box(es). Positive (negative) values correspond to positions to the right (left) for vertical boxes
    // and above (below) for horizontal boxes
    Box& pointpos(double f) {
        json["pointpos"] = std::move(f);
        return *this;
    }

    // Sets the Quartile 1 values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& q1(std::vector<T> f) {
        json["q1"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `q1`.
    Box& q1src(std::string f) {
        json["q1src"] = std::move(f);
        return *this;
    }

    // Sets the Quartile 3 values. There should be as many items as the number of boxes desired.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& q3(std::vector<T> f) {
        json["q3"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `q3`.
    Box& q3src(std::string f) {
        json["q3src"] = std::move(f);
        return *this;
    }

    // Sets the method used to compute the sample's Q1 and Q3 quartiles. The *linear* method uses the 25th percentile
    // for Q1 and 75th percentile for Q3 as computed using method #10 (listed on
    // http://jse.amstat.org/v14n3/langford.html). The *exclusive* method uses the median to divide the ordered dataset
    // into two halves if the sample is odd, it does not include the median in either half - Q1 is then the median of
    // the lower half and Q3 the median of the upper half. The *inclusive* method also uses the median to divide the
    // ordered dataset into two halves but if the sample is odd, it includes the median in both halves - Q1 is then the
    // median of the lower half and Q3 the median of the upper half.
    // - Default: linear
    Box& quartilemethod(enum Quartilemethod f) {
        json["quartilemethod"] = to_string(f);
        return *this;
    }

    // Sets the standard deviation values. There should be as many items as the number of boxes desired. This attribute
    // has effect only under the q1/median/q3 signature. If `sd` is not provided but a sample (in `y` or `x`) is set, we
    // compute the standard deviation for each box using the sample values.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& sd(std::vector<T> f) {
        json["sd"] = std::move(f);
        return *this;
    }

    // Scales the box size when sizemode=sd Allowing boxes to be drawn across any stddev range For example 1-stddev,
    // 3-stddev, 5-stddev
    Box& sdmultiple(double f) {
        json["sdmultiple"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `sd`.
    Box& sdsrc(std::string f) {
        json["sdsrc"] = std::move(f);
        return *this;
    }

    Box& selected(class Selected f) {
        json["selected"] = std::move(f.json);
        return *this;
    }

    // Array containing integer indices of selected points. Has an effect only for traces that support selections. Note
    // that an empty array means an empty selection where the `unselected` are turned on for all points, whereas, any
    // other non-array values means no selection all where the `selected` and `unselected` styles have no effect.
    template <typename T>
    Box& selectedpoints(T f) {
        json["selectedpoints"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Box& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    // Determines whether or not whiskers are visible. Defaults to true for `sizemode` *quartiles*, false for *sd*.
    Box& showwhiskers(bool f) {
        json["showwhiskers"] = std::move(f);
        return *this;
    }

    // Sets the upper and lower bound for the boxes quartiles means box is drawn between Q1 and Q3 SD means the box is
    // drawn between Mean +- Standard Deviation Argument sdmultiple (default 1) to scale the box size So it could be
    // drawn 1-stddev, 3-stddev etc
    // - Default: quartiles
    Box& sizemode(enum Sizemode f) {
        json["sizemode"] = to_string(f);
        return *this;
    }

    Box& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets the text elements associated with each sample value. If a single string, the same string appears over all
    // the data points. If an array of string, the items are mapped in order to the this trace's (x,y) coordinates. To
    // be seen, trace `hoverinfo` must contain a *text* flag.
    Box& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Box& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Box& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Box& uid(std::string f) {
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
    Box& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    Box& unselected(class Unselected f) {
        json["unselected"] = std::move(f.json);
        return *this;
    }

    // Sets the upper fence values. There should be as many items as the number of boxes desired. This attribute has
    // effect only under the q1/median/q3 signature. If `upperfence` is not provided but a sample (in `y` or `x`) is
    // set, we compute the upper as the last sample point above 1.5 times the IQR.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& upperfence(std::vector<T> f) {
        json["upperfence"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `upperfence`.
    Box& upperfencesrc(std::string f) {
        json["upperfencesrc"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Box& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the width of the whiskers relative to the box' width. For example, with 1, the whiskers are as wide as the
    // box(es).
    Box& whiskerwidth(double f) {
        json["whiskerwidth"] = std::move(f);
        return *this;
    }

    // Sets the width of the box in data coordinate If *0* (default value) the width is automatically selected based on
    // the positions of other box traces in the same subplot.
    Box& width(double f) {
        json["width"] = std::move(f);
        return *this;
    }

    // Sets the x sample data or coordinates. See overview for more info.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Sets the x coordinate for single-box traces or the starting coordinate for multi-box traces set using
    // q1/median/q3. See overview for more info.
    template <typename T>
    Box& x0(T f) {
        json["x0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Box& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Box& xcalendar(enum Xcalendar f) {
        json["xcalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Box& xhoverformat(std::string f) {
        json["xhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the x
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Box& xperiod(T f) {
        json["xperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the x0 axis. When `x0period` is round number of weeks, the `x0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Box& xperiod0(T f) {
        json["xperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the x axis.
    // - Default: middle
    Box& xperiodalignment(enum Xperiodalignment f) {
        json["xperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Box& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Sets the y sample data or coordinates. See overview for more info.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Box& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Sets the y coordinate for single-box traces or the starting coordinate for multi-box traces set using
    // q1/median/q3. See overview for more info.
    template <typename T>
    Box& y0(T f) {
        json["y0"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Box& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Box& ycalendar(enum Ycalendar f) {
        json["ycalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Box& yhoverformat(std::string f) {
        json["yhoverformat"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the period positioning in milliseconds or *M<n>* on the y
    // axis. Special values in the form of *M<n>* could be used to declare the number of months. In this case `n` must
    // be a positive integer.
    template <typename T>
    Box& yperiod(T f) {
        json["yperiod"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the base for period positioning in milliseconds or date string
    // on the y0 axis. When `y0period` is round number of weeks, the `y0period0` by default would be on a Sunday i.e.
    // 2000-01-02, otherwise it would be at 2000-01-01.
    template <typename T>
    Box& yperiod0(T f) {
        json["yperiod0"] = std::move(f);
        return *this;
    }

    // Only relevant when the axis `type` is *date*. Sets the alignment of data points on the y axis.
    // - Default: middle
    Box& yperiodalignment(enum Yperiodalignment f) {
        json["yperiodalignment"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Box& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Box& zorder(int f) {
        json["zorder"] = std::move(f);
        return *this;
    }
};
} // namespace plotlypp
