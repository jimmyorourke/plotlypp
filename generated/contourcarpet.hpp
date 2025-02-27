// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Contourcarpet : public Trace {
 public:
    Contourcarpet()
    : Trace() {
        json["type"] = "contourcarpet";
    }

    enum class Atype {
        ARRAY,
        SCALED,
    };
    std::string to_string(Atype e) {
        switch (e) {
        case Atype::ARRAY:
            return "array";
        case Atype::SCALED:
            return "scaled";
        }
    }

    enum class Btype {
        ARRAY,
        SCALED,
    };
    std::string to_string(Btype e) {
        switch (e) {
        case Btype::ARRAY:
            return "array";
        case Btype::SCALED:
            return "scaled";
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

            Tickfont& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Tickfont& color(double f) {
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
            Tickfont& family(std::string f) {
                json["family"] = std::move(f);
                return *this;
            }

            // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
            // combinations e.g. *under+over*, etc.
            // - Default: none
            // - Flags: ['under', 'over', 'through']
            // - Extras ['none']
            Tickfont& lineposition(std::string f) {
                json["lineposition"] = std::move(f);
                return *this;
            }

            // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast
            // text font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
            Tickfont& shadow(std::string f) {
                json["shadow"] = std::move(f);
                return *this;
            }

            Tickfont& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Sets whether a font should be styled with a normal or italic face from its family.
            // - Default: normal
            Tickfont& style(enum Style f) {
                json["style"] = to_string(f);
                return *this;
            }

            // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or
            // with each word capitalized.
            // - Default: normal
            Tickfont& textcase(enum Textcase f) {
                json["textcase"] = to_string(f);
                return *this;
            }

            // Sets the variant of the font.
            // - Default: normal
            Tickfont& variant(enum Variant f) {
                json["variant"] = to_string(f);
                return *this;
            }

            // Sets the weight (or boldness) of the font.
            Tickfont& weight(int f) {
                json["weight"] = std::move(f);
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

                // When used in a template, named items are created in the output figure in addition to any items the
                // figure already has in this array. You can modify these items in the output figure by making your own
                // item with `templateitemname` matching this `name` alongside your modifications (including `visible:
                // false` or `enabled: false` to hide it). Has no effect outside of a template.
                Tickformatstop& name(std::string f) {
                    json["name"] = std::move(f);
                    return *this;
                }

                // Used to refer to a named item in this array in the template. Named items from the template will be
                // created even without a matching item in the input figure, but you can modify one by making an item
                // with `templateitemname` matching its `name`, alongside your modifications (including `visible: false`
                // or `enabled: false` to hide it). If there is no template or no matching item, this item will be
                // hidden unless you explicitly show it with `visible: true`.
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

            // Sets this color bar's title font.
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
                // able to apply a font if it is available on the system which it operates. Provide multiple font
                // families, separated by commas, to indicate the preference in which to apply fonts if they aren't
                // available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise)
                // generates images on a server, where only a select number of fonts are installed and supported. These
                // include *Arial*, *Balto*, *Courier New*, *Droid Sans*, *Droid Serif*, *Droid Sans Mono*, *Gravitas
                // One*, *Old Standard TT*, *Open Sans*, *Overpass*, *PT Sans Narrow*, *Raleway*, *Times New Roman*.
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
                // text font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional
                // options.
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

            // Sets this color bar's title font.
            Title& font(class Font f) {
                json["font"] = std::move(f.json);
                return *this;
            }

            // Determines the location of color bar's title with respect to the color bar. Defaults to *top* when
            // `orientation` if *v* and  defaults to *right* when `orientation` if *h*.
            Title& side(enum Side f) {
                json["side"] = to_string(f);
                return *this;
            }

            // Sets the title of the color bar.
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
        Colorbar& bgcolor(double f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }

        // Sets the axis line color.
        Colorbar& bordercolor(std::string f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }
        Colorbar& bordercolor(double f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) or the border enclosing this color bar.
        Colorbar& borderwidth(double f) {
            json["borderwidth"] = std::move(f);
            return *this;
        }

        // Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings
        // available to *log* and *date* axes. If the axis `type` is *log*, then ticks are set every 10^(n*dtick) where
        // n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick
        // marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to
        // log_10(5), or 0.69897000433. *log* has several special values; *L<f>*, where `f` is a positive number, gives
        // ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = *L0.5* will put ticks
        // at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use *D1* (all digits) or *D2*
        // (only 2 and 5). `tick0` is ignored for *D1* and *D2*. If the axis `type` is *date*, then you must convert the
        // time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0.
        // *date* also has special values *M<n>* gives ticks spaced by a number of months. `n` must be a positive
        // integer. To set ticks on the 15th of every third month, set `tick0` to *2000-01-15* and `dtick` to *M3*. To
        // set ticks every 4 years, set `dtick` to *M48*
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

        // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to
        // USA and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix
        // or ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash.
        // That means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if
        // needed) and values (if desired) can include html-like tags or MathJax.
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
        Colorbar& outlinecolor(double f) {
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

        // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick
        // is shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
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

        // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
        // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
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

        // Determines whether this color bar's thickness (i.e. the measure in the constant color direction) is set in
        // units of plot *fraction* or in *pixels*. Use `thickness` to set the value.
        // - Default: pixels
        Colorbar& thicknessmode(enum Thicknessmode f) {
            json["thicknessmode"] = to_string(f);
            return *this;
        }

        // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then you
        // must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except
        // when `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date string,
        // like date data. If the axis `type` is *category*, it should be a number, using the scale where each category
        // is assigned a serial number from zero in the order it appears.
        template <typename T>
        Colorbar& tick0(T f) {
            json["tick0"] = std::move(f);
            return *this;
        }

        // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
        // tick labels vertically.
        Colorbar& tickangle(double f) {
            json["tickangle"] = std::move(f);
            return *this;
        }

        // Sets the tick color.
        Colorbar& tickcolor(std::string f) {
            json["tickcolor"] = std::move(f);
            return *this;
        }
        Colorbar& tickcolor(double f) {
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
        // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h*
        // for half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For
        // example, *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
        Colorbar& tickformat(std::string f) {
            json["tickformat"] = std::move(f);
            return *this;
        }

        Colorbar& tickformatstops(class Tickformatstops f) {
            json["tickformatstops"] = std::move(f.json);
            return *this;
        }

        // Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The
        // default value for inside tick labels is *hide past domain*. In other cases the default is *hide past div*.
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

        // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means
        // each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick
        // is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` *log* or
        // *multicategory*, or when `tickmode` is *array*.
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
        // placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is the
        // default value if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via
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

        // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside* (*inside*),
        // this axis' are drawn outside (inside) the axis lines.
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

        // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used
        // with `ticktext`.
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
        // defaults to *1* when `orientation` is *v* and 0.5 when `orientation` is *h*. Must be between *0* and *1* if
        // `xref` is *container* and between *-2* and *3* if `xref` is *paper*.
        Colorbar& x(double f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets this color bar's horizontal position anchor. This anchor binds the `x` position to the *left*, *center*
        // or *right* of the color bar. Defaults to *left* when `orientation` is *v* and *center* when `orientation` is
        // *h*.
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

        // Sets this color bar's vertical position anchor This anchor binds the `y` position to the *top*, *middle* or
        // *bottom* of the color bar. Defaults to *middle* when `orientation` is *v* and *bottom* when `orientation` is
        // *h*.
        Colorbar& yanchor(enum Yanchor f) {
            json["yanchor"] = to_string(f);
            return *this;
        }

        // Sets the amount of padding (in px) along the y direction.
        Colorbar& ypad(double f) {
            json["ypad"] = std::move(f);
            return *this;
        }

        // Sets the container `y` refers to. *container* spans the entire `height` of the plot. *paper* refers to the
        // height of the plotting area only.
        // - Default: paper
        Colorbar& yref(enum Yref f) {
            json["yref"] = to_string(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Contours {
     public:

        enum class Coloring {
            FILL,
            LINES,
            NONE,
        };
        std::string to_string(Coloring e) {
            switch (e) {
            case Coloring::FILL:
                return "fill";
            case Coloring::LINES:
                return "lines";
            case Coloring::NONE:
                return "none";
            }
        }

        enum class Operation {
            EQ,
            LT,
            >=,
            GT,
            <=,
            [],
            (),
            [),
            (],
            ][,
            )(,
            ](,
            )[,
        };
        std::string to_string(Operation e) {
            switch (e) {
            case Operation::EQ:
                return "=";
            case Operation::LT:
                return "<";
            case Operation:: >=:
                return ">=";
            case Operation::GT:
                return ">";
            case Operation:: <=:
                return "<=";
            case Operation::[]:
                return "[]";
            case Operation::():
                return "()";
                case Operation::[):
                    return "[)";
                case Operation::(]:
                    return "(]";
                case Operation::][:
                    return "][";
                case Operation::)(:
                    return ")(";
                case Operation::](:
                    return "](";
                case Operation::)[:
                    return ")[";
                }
        }

        enum class Type {
            LEVELS,
            CONSTRAINT,
        };
        std::string to_string(Type e) {
            switch (e) {
            case Type::LEVELS:
                return "levels";
            case Type::CONSTRAINT:
                return "constraint";
            }
        }

        class Impliededits {
         public:

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Sets the font used for labeling the contour levels. The default color comes from the lines, if shown. The
        // default family and size come from `layout.font`.
        class Labelfont {
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

            Labelfont& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Labelfont& color(double f) {
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
            Labelfont& family(std::string f) {
                json["family"] = std::move(f);
                return *this;
            }

            // Sets the kind of decoration line(s) with text, such as an *under*, *over* or *through* as well as
            // combinations e.g. *under+over*, etc.
            // - Default: none
            // - Flags: ['under', 'over', 'through']
            // - Extras ['none']
            Labelfont& lineposition(std::string f) {
                json["lineposition"] = std::move(f);
                return *this;
            }

            // Sets the shape and color of the shadow behind text. *auto* places minimal shadow and applies contrast
            // text font color. See https://developer.mozilla.org/en-US/docs/Web/CSS/text-shadow for additional options.
            Labelfont& shadow(std::string f) {
                json["shadow"] = std::move(f);
                return *this;
            }

            Labelfont& size(double f) {
                json["size"] = std::move(f);
                return *this;
            }

            // Sets whether a font should be styled with a normal or italic face from its family.
            // - Default: normal
            Labelfont& style(enum Style f) {
                json["style"] = to_string(f);
                return *this;
            }

            // Sets capitalization of text. It can be used to make text appear in all-uppercase or all-lowercase, or
            // with each word capitalized.
            // - Default: normal
            Labelfont& textcase(enum Textcase f) {
                json["textcase"] = to_string(f);
                return *this;
            }

            // Sets the variant of the font.
            // - Default: normal
            Labelfont& variant(enum Variant f) {
                json["variant"] = to_string(f);
                return *this;
            }

            // Sets the weight (or boldness) of the font.
            Labelfont& weight(int f) {
                json["weight"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Determines the coloring method showing the contour values. If *fill*, coloring is done evenly between each
        // contour level If *lines*, coloring is done on the contour lines. If *none*, no coloring is applied on this
        // trace.
        // - Default: fill
        Contours& coloring(enum Coloring f) {
            json["coloring"] = to_string(f);
            return *this;
        }

        // Sets the end contour level value. Must be more than `contours.start`
        Contours& end(double f) {
            json["end"] = std::move(f);
            return *this;
        }

        Contours& impliedEdits(class Impliededits f) {
            json["impliedEdits"] = std::move(f.json);
            return *this;
        }

        // Sets the font used for labeling the contour levels. The default color comes from the lines, if shown. The
        // default family and size come from `layout.font`.
        Contours& labelfont(class Labelfont f) {
            json["labelfont"] = std::move(f.json);
            return *this;
        }

        // Sets the contour label formatting rule using d3 formatting mini-languages which are very similar to those in
        // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
        Contours& labelformat(std::string f) {
            json["labelformat"] = std::move(f);
            return *this;
        }

        // Sets the constraint operation. *=* keeps regions equal to `value` *<* and *<=* keep regions less than `value`
        // *>* and *>=* keep regions greater than `value` *[]*, *()*, *[)*, and *(]* keep regions inside `value[0]` to
        // `value[1]` *][*, *)(*, *](*, *)[* keep regions outside `value[0]` to value[1]` Open vs. closed intervals make
        // no difference to constraint display, but all versions are allowed for consistency with filter transforms.
        // - Default: =
        Contours& operation(enum Operation f) {
            json["operation"] = to_string(f);
            return *this;
        }

        // Determines whether to label the contour lines with their values.
        Contours& showlabels(bool f) {
            json["showlabels"] = std::move(f);
            return *this;
        }

        // Determines whether or not the contour lines are drawn. Has an effect only if `contours.coloring` is set to
        // *fill*.
        Contours& showlines(bool f) {
            json["showlines"] = std::move(f);
            return *this;
        }

        // Sets the step between each contour level. Must be positive.
        Contours& size(double f) {
            json["size"] = std::move(f);
            return *this;
        }

        // Sets the starting contour level value. Must be less than `contours.end`
        Contours& start(double f) {
            json["start"] = std::move(f);
            return *this;
        }

        // If `levels`, the data is represented as a contour plot with multiple levels displayed. If `constraint`, the
        // data is represented as constraints with the invalid region shaded as specified by the `operation` and `value`
        // parameters.
        // - Default: levels
        Contours& type(enum Type f) {
            json["type"] = to_string(f);
            return *this;
        }

        // Sets the value or values of the constraint boundary. When `operation` is set to one of the comparison values
        // (=,<,>=,>,<=) *value* is expected to be a number. When `operation` is set to one of the interval values
        // ([],(),[),(],][,)(,](,)[) *value* is expected to be an array of two numbers where the first is the lower
        // bound and the second is the upper bound.
        template <typename T>
        Contours& value(T f) {
            json["value"] = std::move(f);
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

        // Sets the color of the contour level. Has no effect if `contours.coloring` is set to *lines*.
        Line& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }
        Line& color(double f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
        // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
        Line& dash(std::string f) {
            json["dash"] = std::move(f);
            return *this;
        }

        // Sets the amount of smoothing for the contour lines, where *0* corresponds to no smoothing.
        Line& smoothing(double f) {
            json["smoothing"] = std::move(f);
            return *this;
        }

        // Sets the contour line width in (in px) Defaults to *0.5* when `contours.type` is *levels*. Defaults to *2*
        // when `contour.type` is *constraint*.
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

    // Sets the x coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& a(std::vector<T> f) {
        json["a"] = std::move(f);
        return *this;
    }

    // Alternate to `x`. Builds a linear space of x coordinates. Use with `dx` where `x0` is the starting coordinate and
    // `dx` the step.
    template <typename T>
    Contourcarpet& a0(T f) {
        json["a0"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `a`.
    Contourcarpet& asrc(std::string f) {
        json["asrc"] = std::move(f);
        return *this;
    }

    // If *array*, the heatmap's x coordinates are given by *x* (the default behavior when `x` is provided). If
    // *scaled*, the heatmap's x coordinates are given by *x0* and *dx* (the default behavior when `x` is not provided).
    Contourcarpet& atype(enum Atype f) {
        json["atype"] = to_string(f);
        return *this;
    }

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `colorscale`. In case `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen
    // according to whether numbers in the `color` array are all positive, all negative or mixed.
    Contourcarpet& autocolorscale(bool f) {
        json["autocolorscale"] = std::move(f);
        return *this;
    }

    // Determines whether or not the contour level attributes are picked by an algorithm. If *true*, the number of
    // contour levels can be set in `ncontours`. If *false*, set the contour level attributes in `contours`.
    Contourcarpet& autocontour(bool f) {
        json["autocontour"] = std::move(f);
        return *this;
    }

    // Sets the y coordinates.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& b(std::vector<T> f) {
        json["b"] = std::move(f);
        return *this;
    }

    // Alternate to `y`. Builds a linear space of y coordinates. Use with `dy` where `y0` is the starting coordinate and
    // `dy` the step.
    template <typename T>
    Contourcarpet& b0(T f) {
        json["b0"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `b`.
    Contourcarpet& bsrc(std::string f) {
        json["bsrc"] = std::move(f);
        return *this;
    }

    // If *array*, the heatmap's y coordinates are given by *y* (the default behavior when `y` is provided) If *scaled*,
    // the heatmap's y coordinates are given by *y0* and *dy* (the default behavior when `y` is not provided)
    Contourcarpet& btype(enum Btype f) {
        json["btype"] = to_string(f);
        return *this;
    }

    // The `carpet` of the carpet axes on which this contour trace lies
    Contourcarpet& carpet(std::string f) {
        json["carpet"] = std::move(f);
        return *this;
    }

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Contourcarpet& coloraxis(std::string f) {
        json["coloraxis"] = std::move(f);
        return *this;
    }

    Contourcarpet& colorbar(class Colorbar f) {
        json["colorbar"] = std::move(f.json);
        return *this;
    }

    // Sets the colorscale. The colorscale must be an array containing arrays mapping a normalized value to an rgb,
    // rgba, hex, hsl, hsv, or named color string. At minimum, a mapping for the lowest (0) and highest (1) values are
    // required. For example, `[[0, 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in
    // color space, use `zmin` and `zmax`. Alternatively, `colorscale` may be a palette name string of the following
    // list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Contourcarpet& colorscale(std::string f) {
        json["colorscale"] = std::move(f);
        return *this;
    }
    Contourcarpet& colorscale(std::vector<std::pair<double, std::string>> f) {
        json["colorscale"] = std::move(f);
        return *this;
    }

    Contourcarpet& contours(class Contours f) {
        json["contours"] = std::move(f.json);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Contourcarpet& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the x coordinate step. See `x0` for more info.
    Contourcarpet& da(double f) {
        json["da"] = std::move(f);
        return *this;
    }

    // Sets the y coordinate step. See `y0` for more info.
    Contourcarpet& db(double f) {
        json["db"] = std::move(f);
        return *this;
    }

    // Sets the fill color if `contours.type` is *constraint*. Defaults to a half-transparent variant of the line color,
    // marker color, or marker line color, whichever is available.
    Contourcarpet& fillcolor(std::string f) {
        json["fillcolor"] = std::move(f);
        return *this;
    }
    Contourcarpet& fillcolor(double f) {
        json["fillcolor"] = std::move(f);
        return *this;
    }

    // Same as `text`.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& hovertext(std::vector<T> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Contourcarpet& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Contourcarpet& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Contourcarpet& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Contourcarpet& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Contourcarpet& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Contourcarpet& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Contourcarpet& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Contourcarpet& line(class Line f) {
        json["line"] = std::move(f.json);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Contourcarpet& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Contourcarpet& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Contourcarpet& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Contourcarpet& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the maximum number of contour levels. The actual number of contours will be chosen automatically to be less
    // than or equal to the value of `ncontours`. Has an effect only if `autocontour` is *true* or if `contours.size` is
    // missing.
    Contourcarpet& ncontours(int f) {
        json["ncontours"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Contourcarpet& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Reverses the color mapping if true. If true, `zmin` will correspond to the last color in the array and `zmax`
    // will correspond to the first color.
    Contourcarpet& reversescale(bool f) {
        json["reversescale"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Contourcarpet& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    // Determines whether or not a colorbar is displayed for this trace.
    Contourcarpet& showscale(bool f) {
        json["showscale"] = std::move(f);
        return *this;
    }

    Contourcarpet& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets the text elements associated with each z value.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& text(std::vector<T> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Contourcarpet& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    // Transposes the z data.
    Contourcarpet& transpose(bool f) {
        json["transpose"] = std::move(f);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Contourcarpet& uid(std::string f) {
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
    Contourcarpet& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Contourcarpet& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Contourcarpet& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Contourcarpet& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the z data.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Contourcarpet& z(std::vector<T> f) {
        json["z"] = std::move(f);
        return *this;
    }

    // Determines whether or not the color domain is computed with respect to the input data (here in `z`) or the bounds
    // set in `zmin` and `zmax` Defaults to `false` when `zmin` and `zmax` are set by the user.
    Contourcarpet& zauto(bool f) {
        json["zauto"] = std::move(f);
        return *this;
    }

    // Sets the upper bound of the color domain. Value should have the same units as in `z` and if set, `zmin` must be
    // set as well.
    Contourcarpet& zmax(double f) {
        json["zmax"] = std::move(f);
        return *this;
    }

    // Sets the mid-point of the color domain by scaling `zmin` and/or `zmax` to be equidistant to this point. Value
    // should have the same units as in `z`. Has no effect when `zauto` is `false`.
    Contourcarpet& zmid(double f) {
        json["zmid"] = std::move(f);
        return *this;
    }

    // Sets the lower bound of the color domain. Value should have the same units as in `z` and if set, `zmax` must be
    // set as well.
    Contourcarpet& zmin(double f) {
        json["zmin"] = std::move(f);
        return *this;
    }

    // Sets the layer on which this trace is displayed, relative to other SVG traces on the same subplot. SVG traces
    // with higher `zorder` appear in front of those with lower `zorder`.
    Contourcarpet& zorder(int f) {
        json["zorder"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `z`.
    Contourcarpet& zsrc(std::string f) {
        json["zsrc"] = std::move(f);
        return *this;
    }
};
} // namespace plotlypp
