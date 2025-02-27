// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Pie : public Trace {
 public:
    Pie()
    : Trace() {
        json["type"] = "pie";
    }

    enum class Direction {
        CLOCKWISE,
        COUNTERCLOCKWISE,
    };
    std::string to_string(Direction e) {
        switch (e) {
        case Direction::CLOCKWISE:
            return "clockwise";
        case Direction::COUNTERCLOCKWISE:
            return "counterclockwise";
        }
    }

    enum class Insidetextorientation {
        HORIZONTAL,
        RADIAL,
        TANGENTIAL,
        AUTO,
    };
    std::string to_string(Insidetextorientation e) {
        switch (e) {
        case Insidetextorientation::HORIZONTAL:
            return "horizontal";
        case Insidetextorientation::RADIAL:
            return "radial";
        case Insidetextorientation::TANGENTIAL:
            return "tangential";
        case Insidetextorientation::AUTO:
            return "auto";
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

    class Domain {
     public:

        // If there is a layout grid, use the domain for this column in the grid for this pie trace .
        Domain& column(int f) {
            json["column"] = std::move(f);
            return *this;
        }

        // If there is a layout grid, use the domain for this row in the grid for this pie trace .
        Domain& row(int f) {
            json["row"] = std::move(f);
            return *this;
        }

        // Sets the horizontal domain of this pie trace (in plot fraction).
        Domain& x(std::vector<std::string> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the vertical domain of this pie trace (in plot fraction).
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

    // Sets the font used for `textinfo` lying inside the sector.
    class Insidetextfont {
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

        Insidetextfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Insidetextfont& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }
        Insidetextfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }
        Insidetextfont& color(std::vector<double> f) {
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
        // Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans
        // Narrow*, *Raleway*, *Times New Roman*.
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

        // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
        // combinations e.g. *under+over*, etc.
        // - Default: none
        // - Flags: ['under', 'over', 'through']
        // - Extras ['none']
        Insidetextfont& lineposition(std::string f) {
            json["lineposition"] = std::move(f);
            return *this;
        }
        Insidetextfont& lineposition(std::vector<std::string> f) {
            json["lineposition"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `lineposition`.
        Insidetextfont& linepositionsrc(std::string f) {
            json["linepositionsrc"] = std::move(f);
            return *this;
        }

        // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text
        // font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
        Insidetextfont& shadow(std::string f) {
            json["shadow"] = std::move(f);
            return *this;
        }
        Insidetextfont& shadow(std::vector<std::string> f) {
            json["shadow"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `shadow`.
        Insidetextfont& shadowsrc(std::string f) {
            json["shadowsrc"] = std::move(f);
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

        // Sets whether a font should be styled with a normal or italic face from its family.
        // - Default: normal
        Insidetextfont& style(enum Style f) {
            json["style"] = to_string(f);
            return *this;
        }
        Insidetextfont& style(const std::vector<enum Style>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["style"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `style`.
        Insidetextfont& stylesrc(std::string f) {
            json["stylesrc"] = std::move(f);
            return *this;
        }

        // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with
        // each word capitalized.
        // - Default: normal
        Insidetextfont& textcase(enum Textcase f) {
            json["textcase"] = to_string(f);
            return *this;
        }
        Insidetextfont& textcase(const std::vector<enum Textcase>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["textcase"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `textcase`.
        Insidetextfont& textcasesrc(std::string f) {
            json["textcasesrc"] = std::move(f);
            return *this;
        }

        // Sets the variant of the font.
        // - Default: normal
        Insidetextfont& variant(enum Variant f) {
            json["variant"] = to_string(f);
            return *this;
        }
        Insidetextfont& variant(const std::vector<enum Variant>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["variant"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `variant`.
        Insidetextfont& variantsrc(std::string f) {
            json["variantsrc"] = std::move(f);
            return *this;
        }

        // Sets the weight (or boldness) of the font.
        Insidetextfont& weight(int f) {
            json["weight"] = std::move(f);
            return *this;
        }
        Insidetextfont& weight(std::vector<int> f) {
            json["weight"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `weight`.
        Insidetextfont& weightsrc(std::string f) {
            json["weightsrc"] = std::move(f);
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

    class Marker {
     public:

        class Line {
         public:

            // Sets the color of the line enclosing each sector.
            Line& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(double f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }
            Line& color(std::vector<double> f) {
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
            Pattern& bgcolor(double f) {
                json["bgcolor"] = std::move(f);
                return *this;
            }
            Pattern& bgcolor(std::vector<std::string> f) {
                json["bgcolor"] = std::move(f);
                return *this;
            }
            Pattern& bgcolor(std::vector<double> f) {
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
            Pattern& fgcolor(double f) {
                json["fgcolor"] = std::move(f);
                return *this;
            }
            Pattern& fgcolor(std::vector<std::string> f) {
                json["fgcolor"] = std::move(f);
                return *this;
            }
            Pattern& fgcolor(std::vector<double> f) {
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

    // Sets the font used for `textinfo` lying outside the sector.
    class Outsidetextfont {
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

        Outsidetextfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Outsidetextfont& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }
        Outsidetextfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }
        Outsidetextfont& color(std::vector<double> f) {
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
        // Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans
        // Narrow*, *Raleway*, *Times New Roman*.
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

        // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
        // combinations e.g. *under+over*, etc.
        // - Default: none
        // - Flags: ['under', 'over', 'through']
        // - Extras ['none']
        Outsidetextfont& lineposition(std::string f) {
            json["lineposition"] = std::move(f);
            return *this;
        }
        Outsidetextfont& lineposition(std::vector<std::string> f) {
            json["lineposition"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `lineposition`.
        Outsidetextfont& linepositionsrc(std::string f) {
            json["linepositionsrc"] = std::move(f);
            return *this;
        }

        // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text
        // font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
        Outsidetextfont& shadow(std::string f) {
            json["shadow"] = std::move(f);
            return *this;
        }
        Outsidetextfont& shadow(std::vector<std::string> f) {
            json["shadow"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `shadow`.
        Outsidetextfont& shadowsrc(std::string f) {
            json["shadowsrc"] = std::move(f);
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

        // Sets whether a font should be styled with a normal or italic face from its family.
        // - Default: normal
        Outsidetextfont& style(enum Style f) {
            json["style"] = to_string(f);
            return *this;
        }
        Outsidetextfont& style(const std::vector<enum Style>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["style"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `style`.
        Outsidetextfont& stylesrc(std::string f) {
            json["stylesrc"] = std::move(f);
            return *this;
        }

        // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with
        // each word capitalized.
        // - Default: normal
        Outsidetextfont& textcase(enum Textcase f) {
            json["textcase"] = to_string(f);
            return *this;
        }
        Outsidetextfont& textcase(const std::vector<enum Textcase>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["textcase"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `textcase`.
        Outsidetextfont& textcasesrc(std::string f) {
            json["textcasesrc"] = std::move(f);
            return *this;
        }

        // Sets the variant of the font.
        // - Default: normal
        Outsidetextfont& variant(enum Variant f) {
            json["variant"] = to_string(f);
            return *this;
        }
        Outsidetextfont& variant(const std::vector<enum Variant>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["variant"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `variant`.
        Outsidetextfont& variantsrc(std::string f) {
            json["variantsrc"] = std::move(f);
            return *this;
        }

        // Sets the weight (or boldness) of the font.
        Outsidetextfont& weight(int f) {
            json["weight"] = std::move(f);
            return *this;
        }
        Outsidetextfont& weight(std::vector<int> f) {
            json["weight"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `weight`.
        Outsidetextfont& weightsrc(std::string f) {
            json["weightsrc"] = std::move(f);
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

        Textfont& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Textfont& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }
        Textfont& color(std::vector<std::string> f) {
            json["color"] = std::move(f);
            return *this;
        }
        Textfont& color(std::vector<double> f) {
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
        // Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans
        // Narrow*, *Raleway*, *Times New Roman*.
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

        // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
        // combinations e.g. *under+over*, etc.
        // - Default: none
        // - Flags: ['under', 'over', 'through']
        // - Extras ['none']
        Textfont& lineposition(std::string f) {
            json["lineposition"] = std::move(f);
            return *this;
        }
        Textfont& lineposition(std::vector<std::string> f) {
            json["lineposition"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `lineposition`.
        Textfont& linepositionsrc(std::string f) {
            json["linepositionsrc"] = std::move(f);
            return *this;
        }

        // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast text
        // font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
        Textfont& shadow(std::string f) {
            json["shadow"] = std::move(f);
            return *this;
        }
        Textfont& shadow(std::vector<std::string> f) {
            json["shadow"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `shadow`.
        Textfont& shadowsrc(std::string f) {
            json["shadowsrc"] = std::move(f);
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

        // Sets whether a font should be styled with a normal or italic face from its family.
        // - Default: normal
        Textfont& style(enum Style f) {
            json["style"] = to_string(f);
            return *this;
        }
        Textfont& style(const std::vector<enum Style>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["style"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `style`.
        Textfont& stylesrc(std::string f) {
            json["stylesrc"] = std::move(f);
            return *this;
        }

        // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or with
        // each word capitalized.
        // - Default: normal
        Textfont& textcase(enum Textcase f) {
            json["textcase"] = to_string(f);
            return *this;
        }
        Textfont& textcase(const std::vector<enum Textcase>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["textcase"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `textcase`.
        Textfont& textcasesrc(std::string f) {
            json["textcasesrc"] = std::move(f);
            return *this;
        }

        // Sets the variant of the font.
        // - Default: normal
        Textfont& variant(enum Variant f) {
            json["variant"] = to_string(f);
            return *this;
        }
        Textfont& variant(const std::vector<enum Variant>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["variant"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `variant`.
        Textfont& variantsrc(std::string f) {
            json["variantsrc"] = std::move(f);
            return *this;
        }

        // Sets the weight (or boldness) of the font.
        Textfont& weight(int f) {
            json["weight"] = std::move(f);
            return *this;
        }
        Textfont& weight(std::vector<int> f) {
            json["weight"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `weight`.
        Textfont& weightsrc(std::string f) {
            json["weightsrc"] = std::move(f);
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
            MIDDLE_CENTER,
            BOTTOM_LEFT,
            BOTTOM_CENTER,
            BOTTOM_RIGHT,
        };
        std::string to_string(Position e) {
            switch (e) {
            case Position::TOP_LEFT:
                return "top left";
            case Position::TOP_CENTER:
                return "top center";
            case Position::TOP_RIGHT:
                return "top right";
            case Position::MIDDLE_CENTER:
                return "middle center";
            case Position::BOTTOM_LEFT:
                return "bottom left";
            case Position::BOTTOM_CENTER:
                return "bottom center";
            case Position::BOTTOM_RIGHT:
                return "bottom right";
            }
        }

        // Sets the font used for `title`.
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

        // Sets the font used for `title`.
        Title& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Specifies the location of the `title`.
        Title& position(enum Position f) {
            json["position"] = to_string(f);
            return *this;
        }

        // Sets the title of the chart. If it is empty, no title is displayed.
        Title& text(std::string f) {
            json["text"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // Determines whether outside text labels can push the margins.
    Pie& automargin(bool f) {
        json["automargin"] = std::move(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pie& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Pie& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Specifies the direction at which succeeding sectors follow one another.
    // - Default: counterclockwise
    Pie& direction(enum Direction f) {
        json["direction"] = to_string(f);
        return *this;
    }

    // Sets the label step. See `label0` for more info.
    Pie& dlabel(double f) {
        json["dlabel"] = std::move(f);
        return *this;
    }

    Pie& domain(class Domain f) {
        json["domain"] = std::move(f.json);
        return *this;
    }

    // Sets the fraction of the radius to cut out of the pie. Use this to make a donut chart.
    Pie& hole(double f) {
        json["hole"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['label', 'text', 'value', 'percent', 'name']
    // - Extras ['all', 'none', 'skip']
    Pie& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Pie& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Pie& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Pie& hoverlabel(class Hoverlabel f) {
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
    // variables `label`, `color`, `value`, `percent` and `text`. Anything contained in tag `<extra>` is displayed in
    // the secondary box, for example "<extra>{fullData.name}</extra>". To hide the secondary box completely, use an
    // empty tag `<extra></extra>`.
    Pie& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Pie& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Pie& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Sets hover text elements associated with each sector. If a single string, the same string appears for all data
    // points. If an array of string, the items are mapped in order of this trace's sectors. To be seen, trace
    // `hoverinfo` must contain a *text* flag.
    Pie& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Pie& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Pie& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pie& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Pie& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the font used for `textinfo` lying inside the sector.
    Pie& insidetextfont(class Insidetextfont f) {
        json["insidetextfont"] = std::move(f.json);
        return *this;
    }

    // Controls the orientation of the text inside chart sectors. When set to *auto*, text may be oriented in any
    // direction in order to be as big as possible in the middle of a sector. The *horizontal* option orients text to be
    // parallel with the bottom of the chart, and may make text smaller in order to achieve that goal. The *radial*
    // option orients text along the radius of the sector. The *tangential* option orients text perpendicular to the
    // radius of the sector.
    // - Default: auto
    Pie& insidetextorientation(enum Insidetextorientation f) {
        json["insidetextorientation"] = to_string(f);
        return *this;
    }

    // Alternate to `labels`. Builds a numeric set of labels. Use with `dlabel` where `label0` is the starting label and
    // `dlabel` the step.
    Pie& label0(double f) {
        json["label0"] = std::move(f);
        return *this;
    }

    // Sets the sector labels. If `labels` entries are duplicated, we sum associated `values` or simply count
    // occurrences if `values` is not provided. For other array attributes (including color) we use the first non-empty
    // entry among all occurrences of the label.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pie& labels(std::vector<T> f) {
        json["labels"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `labels`.
    Pie& labelssrc(std::string f) {
        json["labelssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Pie& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Pie& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Pie& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Pie& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Pie& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Pie& marker(class Marker f) {
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
    Pie& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Pie& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Pie& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Pie& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Pie& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Sets the font used for `textinfo` lying outside the sector.
    Pie& outsidetextfont(class Outsidetextfont f) {
        json["outsidetextfont"] = std::move(f.json);
        return *this;
    }

    // Sets the fraction of larger radius to pull the sectors out from the center. This can be a constant to pull all
    // slices apart from each other equally or an array to highlight one or more slices.
    Pie& pull(double f) {
        json["pull"] = std::move(f);
        return *this;
    }
    Pie& pull(std::vector<double> f) {
        json["pull"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `pull`.
    Pie& pullsrc(std::string f) {
        json["pullsrc"] = std::move(f);
        return *this;
    }

    // Instead of the first slice starting at 12 o'clock, rotate to some other angle.
    Pie& rotation(double f) {
        json["rotation"] = std::move(f);
        return *this;
    }

    // If there are multiple pie charts that should be sized according to their totals, link them by providing a
    // non-empty group id here shared by every trace in the same group.
    Pie& scalegroup(std::string f) {
        json["scalegroup"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Pie& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    // Determines whether or not the sectors are reordered from largest to smallest.
    Pie& sort(bool f) {
        json["sort"] = std::move(f);
        return *this;
    }

    Pie& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets text elements associated with each sector. If trace `textinfo` contains a *text* flag, these elements will
    // be seen on the chart. If trace `hoverinfo` contains a *text* flag and *hovertext* is not set, these elements will
    // be seen in the hover labels.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pie& text(std::vector<T> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the font used for `textinfo`.
    Pie& textfont(class Textfont f) {
        json["textfont"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on the graph.
    // - Flags: ['label', 'text', 'value', 'percent']
    // - Extras ['none']
    Pie& textinfo(std::string f) {
        json["textinfo"] = std::move(f);
        return *this;
    }

    // Specifies the location of the `textinfo`.
    // - Default: auto
    Pie& textposition(enum Textposition f) {
        json["textposition"] = to_string(f);
        return *this;
    }
    Pie& textposition(const std::vector<enum Textposition>& f) {
        std::vector<std::string> stringified(f.size());
        std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
        json["textposition"] = std::move(stringified);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `textposition`.
    Pie& textpositionsrc(std::string f) {
        json["textpositionsrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Pie& textsrc(std::string f) {
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
    // template string has access to variables `label`, `color`, `value`, `percent` and `text`.
    Pie& texttemplate(std::string f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }
    Pie& texttemplate(std::vector<std::string> f) {
        json["texttemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `texttemplate`.
    Pie& texttemplatesrc(std::string f) {
        json["texttemplatesrc"] = std::move(f);
        return *this;
    }

    Pie& title(class Title f) {
        json["title"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Pie& uid(std::string f) {
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
    Pie& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Sets the values of the sectors. If omitted, we count occurrences of each label.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Pie& values(std::vector<T> f) {
        json["values"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `values`.
    Pie& valuessrc(std::string f) {
        json["valuessrc"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Pie& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }
};
} // namespace plotlypp
