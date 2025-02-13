// TODO: includes, copyright, etc
#include <string>
#include <type_traits>
#include <vector>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Mesh3d {
 public:
    Mesh3d() { json["type"] = "mesh3d"; }

    enum class Delaunayaxis {
        X,
        Y,
        Z,
    };
    std::string to_string(Delaunayaxis e) {
        switch (e) {
        case Delaunayaxis::X:
            return "x";
        case Delaunayaxis::Y:
            return "y";
        case Delaunayaxis::Z:
            return "z";
        }
    }

    enum class Intensitymode {
        VERTEX,
        CELL,
    };
    std::string to_string(Intensitymode e) {
        switch (e) {
        case Intensitymode::VERTEX:
            return "vertex";
        case Intensitymode::CELL:
            return "cell";
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

    enum class Zcalendar {
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
    std::string to_string(Zcalendar e) {
        switch (e) {
        case Zcalendar::CHINESE:
            return "chinese";
        case Zcalendar::COPTIC:
            return "coptic";
        case Zcalendar::DISCWORLD:
            return "discworld";
        case Zcalendar::ETHIOPIAN:
            return "ethiopian";
        case Zcalendar::GREGORIAN:
            return "gregorian";
        case Zcalendar::HEBREW:
            return "hebrew";
        case Zcalendar::ISLAMIC:
            return "islamic";
        case Zcalendar::JALALI:
            return "jalali";
        case Zcalendar::JULIAN:
            return "julian";
        case Zcalendar::MAYAN:
            return "mayan";
        case Zcalendar::NANAKSHAHI:
            return "nanakshahi";
        case Zcalendar::NEPALI:
            return "nepali";
        case Zcalendar::PERSIAN:
            return "persian";
        case Zcalendar::TAIWAN:
            return "taiwan";
        case Zcalendar::THAI:
            return "thai";
        case Zcalendar::UMMALQURA:
            return "ummalqura";
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

            Tickfont& color(std::string f) {
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

            // Sets this color bar's title font. Note that the title's font used to be set by the now deprecated
            // `titlefont` attribute.
            class Font {
             public:

                Font& color(std::string f) {
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
            // `orientation` if *v* and  defaults to *right* when `orientation` if *h*. Note that the title's location
            // used to be set by the now deprecated `titleside` attribute.
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
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
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
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
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

    class Contour {
     public:

        // Sets the color of the contour lines.
        Contour& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }

        // Sets whether or not dynamic contours are shown on hover
        Contour& show(bool f) {
            json["show"] = std::move(f);
            return *this;
        }

        // Sets the width of the contour lines.
        Contour& width(double f) {
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

    class Lighting {
     public:

        // Ambient light increases overall color visibility but can wash out the image.
        Lighting& ambient(double f) {
            json["ambient"] = std::move(f);
            return *this;
        }

        // Represents the extent that incident rays are reflected in a range of angles.
        Lighting& diffuse(double f) {
            json["diffuse"] = std::move(f);
            return *this;
        }

        // Epsilon for face normals calculation avoids math issues arising from degenerate geometry.
        Lighting& facenormalsepsilon(double f) {
            json["facenormalsepsilon"] = std::move(f);
            return *this;
        }

        // Represents the reflectance as a dependency of the viewing angle; e.g. paper is reflective when viewing it
        // from the edge of the paper (almost 90 degrees), causing shine.
        Lighting& fresnel(double f) {
            json["fresnel"] = std::move(f);
            return *this;
        }

        // Alters specular reflection; the rougher the surface, the wider and less contrasty the shine.
        Lighting& roughness(double f) {
            json["roughness"] = std::move(f);
            return *this;
        }

        // Represents the level that incident rays are reflected in a single direction, causing shine.
        Lighting& specular(double f) {
            json["specular"] = std::move(f);
            return *this;
        }

        // Epsilon for vertex normals calculation avoids math issues arising from degenerate geometry.
        Lighting& vertexnormalsepsilon(double f) {
            json["vertexnormalsepsilon"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Lightposition {
     public:

        // Numeric vector, representing the X coordinate for each vertex.
        Lightposition& x(double f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Numeric vector, representing the Y coordinate for each vertex.
        Lightposition& y(double f) {
            json["y"] = std::move(f);
            return *this;
        }

        // Numeric vector, representing the Z coordinate for each vertex.
        Lightposition& z(double f) {
            json["z"] = std::move(f);
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

    // Determines how the mesh surface triangles are derived from the set of vertices (points) represented by the `x`,
    // `y` and `z` arrays, if the `i`, `j`, `k` arrays are not supplied. For general use of `mesh3d` it is preferred
    // that `i`, `j`, `k` are supplied. If *-1*, Delaunay triangulation is used, which is mainly suitable if the mesh is
    // a single, more or less layer surface that is perpendicular to `delaunayaxis`. In case the `delaunayaxis`
    // intersects the mesh surface at more than one point it will result triangles that are very long in the dimension
    // of `delaunayaxis`. If *>0*, the alpha-shape algorithm is used. In this case, the positive `alphahull` value
    // signals the use of the alpha-shape algorithm, _and_ its value acts as the parameter for the mesh fitting. If *0*,
    // the convex-hull algorithm is used. It is suitable for convex bodies or if the intention is to enclose the `x`,
    // `y` and `z` point set into a convex hull.
    Mesh3d& alphahull(double f) {
        json["alphahull"] = std::move(f);
        return *this;
    }

    // Determines whether the colorscale is a default palette (`autocolorscale: true`) or the palette determined by
    // `colorscale`. In case `colorscale` is unspecified or `autocolorscale` is true, the default palette will be chosen
    // according to whether numbers in the `color` array are all positive, all negative or mixed.
    Mesh3d& autocolorscale(bool f) {
        json["autocolorscale"] = std::move(f);
        return *this;
    }

    // Determines whether or not the color domain is computed with respect to the input data (here `intensity`) or the
    // bounds set in `cmin` and `cmax` Defaults to `false` when `cmin` and `cmax` are set by the user.
    Mesh3d& cauto(bool f) {
        json["cauto"] = std::move(f);
        return *this;
    }

    // Sets the upper bound of the color domain. Value should have the same units as `intensity` and if set, `cmin` must
    // be set as well.
    Mesh3d& cmax(double f) {
        json["cmax"] = std::move(f);
        return *this;
    }

    // Sets the mid-point of the color domain by scaling `cmin` and/or `cmax` to be equidistant to this point. Value
    // should have the same units as `intensity`. Has no effect when `cauto` is `false`.
    Mesh3d& cmid(double f) {
        json["cmid"] = std::move(f);
        return *this;
    }

    // Sets the lower bound of the color domain. Value should have the same units as `intensity` and if set, `cmax` must
    // be set as well.
    Mesh3d& cmin(double f) {
        json["cmin"] = std::move(f);
        return *this;
    }

    // Sets the color of the whole mesh
    Mesh3d& color(std::string f) {
        json["color"] = std::move(f);
        return *this;
    }

    // Sets a reference to a shared color axis. References to these shared color axes are *coloraxis*, *coloraxis2*,
    // *coloraxis3*, etc. Settings for these shared color axes are set in the layout, under `layout.coloraxis`,
    // `layout.coloraxis2`, etc. Note that multiple color scales can be linked to the same color axis.
    Mesh3d& coloraxis(std::string f) {
        json["coloraxis"] = std::move(f);
        return *this;
    }

    Mesh3d& colorbar(class Colorbar f) {
        json["colorbar"] = std::move(f.json);
        return *this;
    }

    // Sets the colorscale. The colorscale must be an array containing arrays mapping a normalized value to an rgb,
    // rgba, hex, hsl, hsv, or named color string. At minimum, a mapping for the lowest (0) and highest (1) values are
    // required. For example, `[[0, 'rgb(0,0,255)'], [1, 'rgb(255,0,0)']]`. To control the bounds of the colorscale in
    // color space, use `cmin` and `cmax`. Alternatively, `colorscale` may be a palette name string of the following
    // list:
    // Blackbody,Bluered,Blues,Cividis,Earth,Electric,Greens,Greys,Hot,Jet,Picnic,Portland,Rainbow,RdBu,Reds,Viridis,YlGnBu,YlOrRd.
    Mesh3d& colorscale(std::string f) {
        json["colorscale"] = std::move(f);
        return *this;
    }

    Mesh3d& contour(class Contour f) {
        json["contour"] = std::move(f.json);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Mesh3d& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the Delaunay axis, which is the axis that is perpendicular to the surface of the Delaunay triangulation. It
    // has an effect if `i`, `j`, `k` are not provided and `alphahull` is set to indicate Delaunay triangulation.
    // - Default: z
    Mesh3d& delaunayaxis(enum Delaunayaxis f) {
        json["delaunayaxis"] = to_string(f);
        return *this;
    }

    // Sets the color of each face Overrides *color* and *vertexcolor*.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& facecolor(std::vector<T> f) {
        json["facecolor"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `facecolor`.
    Mesh3d& facecolorsrc(std::string f) {
        json["facecolorsrc"] = std::move(f);
        return *this;
    }

    // Determines whether or not normal smoothing is applied to the meshes, creating meshes with an angular, low-poly
    // look via flat reflections.
    Mesh3d& flatshading(bool f) {
        json["flatshading"] = std::move(f);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Mesh3d& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Mesh3d& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Mesh3d& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Mesh3d& hoverlabel(class Hoverlabel f) {
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
    // specified per-point (the ones that are `arrayOk: true`) are available.  Anything contained in tag `<extra>` is
    // displayed in the secondary box, for example "<extra>{fullData.name}</extra>". To hide the secondary box
    // completely, use an empty tag `<extra></extra>`.
    Mesh3d& hovertemplate(std::string f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }
    Mesh3d& hovertemplate(std::vector<std::string> f) {
        json["hovertemplate"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertemplate`.
    Mesh3d& hovertemplatesrc(std::string f) {
        json["hovertemplatesrc"] = std::move(f);
        return *this;
    }

    // Same as `text`.
    Mesh3d& hovertext(std::string f) {
        json["hovertext"] = std::move(f);
        return *this;
    }
    Mesh3d& hovertext(std::vector<std::string> f) {
        json["hovertext"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hovertext`.
    Mesh3d& hovertextsrc(std::string f) {
        json["hovertextsrc"] = std::move(f);
        return *this;
    }

    // A vector of vertex indices, i.e. integer values between 0 and the length of the vertex vectors, representing the
    // *first* vertex of a triangle. For example, `{i[m], j[m], k[m]}` together represent face m (triangle m) in the
    // mesh, where `i[m] = n` points to the triplet `{x[n], y[n], z[n]}` in the vertex arrays. Therefore, each element
    // in `i` represents a point in space, which is the first vertex of a triangle.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& i(std::vector<T> f) {
        json["i"] = std::move(f);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Mesh3d& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the intensity values for vertices or cells as defined by `intensitymode`. It can be used for plotting fields
    // on meshes.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& intensity(std::vector<T> f) {
        json["intensity"] = std::move(f);
        return *this;
    }

    // Determines the source of `intensity` values.
    // - Default: vertex
    Mesh3d& intensitymode(enum Intensitymode f) {
        json["intensitymode"] = to_string(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `intensity`.
    Mesh3d& intensitysrc(std::string f) {
        json["intensitysrc"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `i`.
    Mesh3d& isrc(std::string f) {
        json["isrc"] = std::move(f);
        return *this;
    }

    // A vector of vertex indices, i.e. integer values between 0 and the length of the vertex vectors, representing the
    // *second* vertex of a triangle. For example, `{i[m], j[m], k[m]}`  together represent face m (triangle m) in the
    // mesh, where `j[m] = n` points to the triplet `{x[n], y[n], z[n]}` in the vertex arrays. Therefore, each element
    // in `j` represents a point in space, which is the second vertex of a triangle.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& j(std::vector<T> f) {
        json["j"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `j`.
    Mesh3d& jsrc(std::string f) {
        json["jsrc"] = std::move(f);
        return *this;
    }

    // A vector of vertex indices, i.e. integer values between 0 and the length of the vertex vectors, representing the
    // *third* vertex of a triangle. For example, `{i[m], j[m], k[m]}` together represent face m (triangle m) in the
    // mesh, where `k[m] = n` points to the triplet  `{x[n], y[n], z[n]}` in the vertex arrays. Therefore, each element
    // in `k` represents a point in space, which is the third vertex of a triangle.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& k(std::vector<T> f) {
        json["k"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `k`.
    Mesh3d& ksrc(std::string f) {
        json["ksrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Mesh3d& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    // Sets the legend group for this trace. Traces and shapes part of the same legend group hide/show at the same time
    // when toggling legend items.
    Mesh3d& legendgroup(std::string f) {
        json["legendgroup"] = std::move(f);
        return *this;
    }

    Mesh3d& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Mesh3d& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Mesh3d& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    Mesh3d& lighting(class Lighting f) {
        json["lighting"] = std::move(f.json);
        return *this;
    }

    Mesh3d& lightposition(class Lightposition f) {
        json["lightposition"] = std::move(f.json);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Mesh3d& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Mesh3d& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Mesh3d& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Mesh3d& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the surface. Please note that in the case of using high `opacity` values for example a value
    // greater than or equal to 0.5 on two surfaces (and 0.25 with four surfaces), an overlay of multiple transparent
    // surfaces may not perfectly be sorted in depth by the webgl API. This behavior may be improved in the near future
    // and is subject to change.
    Mesh3d& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    // Reverses the color mapping if true. If true, `cmin` will correspond to the last color in the array and `cmax`
    // will correspond to the first color.
    Mesh3d& reversescale(bool f) {
        json["reversescale"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's 3D coordinate system and a 3D scene. If *scene* (the default value), the
    // (x,y,z) coordinates refer to `layout.scene`. If *scene2*, the (x,y,z) coordinates refer to `layout.scene2`, and
    // so on.
    Mesh3d& scene(std::string f) {
        json["scene"] = std::move(f);
        return *this;
    }

    // Determines whether or not an item corresponding to this trace is shown in the legend.
    Mesh3d& showlegend(bool f) {
        json["showlegend"] = std::move(f);
        return *this;
    }

    // Determines whether or not a colorbar is displayed for this trace.
    Mesh3d& showscale(bool f) {
        json["showscale"] = std::move(f);
        return *this;
    }

    Mesh3d& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Sets the text elements associated with the vertices. If trace `hoverinfo` contains a *text* flag and *hovertext*
    // is not set, these elements will be seen in the hover labels.
    Mesh3d& text(std::string f) {
        json["text"] = std::move(f);
        return *this;
    }
    Mesh3d& text(std::vector<std::string> f) {
        json["text"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `text`.
    Mesh3d& textsrc(std::string f) {
        json["textsrc"] = std::move(f);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Mesh3d& uid(std::string f) {
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
    Mesh3d& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Sets the color of each vertex Overrides *color*. While Red, green and blue colors are in the range of 0 and 255;
    // in the case of having vertex color data in RGBA format, the alpha color should be normalized to be between 0
    // and 1.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& vertexcolor(std::vector<T> f) {
        json["vertexcolor"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `vertexcolor`.
    Mesh3d& vertexcolorsrc(std::string f) {
        json["vertexcolorsrc"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Mesh3d& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Sets the X coordinates of the vertices. The nth element of vectors `x`, `y` and `z` jointly represent the X, Y
    // and Z coordinates of the nth vertex.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `x` date data.
    // - Default: gregorian
    Mesh3d& xcalendar(enum Xcalendar f) {
        json["xcalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `x`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `xaxis.hoverformat`.
    Mesh3d& xhoverformat(std::string f) {
        json["xhoverformat"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Mesh3d& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // Sets the Y coordinates of the vertices. The nth element of vectors `x`, `y` and `z` jointly represent the X, Y
    // and Z coordinates of the nth vertex.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `y` date data.
    // - Default: gregorian
    Mesh3d& ycalendar(enum Ycalendar f) {
        json["ycalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `y`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `yaxis.hoverformat`.
    Mesh3d& yhoverformat(std::string f) {
        json["yhoverformat"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Mesh3d& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }

    // Sets the Z coordinates of the vertices. The nth element of vectors `x`, `y` and `z` jointly represent the X, Y
    // and Z coordinates of the nth vertex.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Mesh3d& z(std::vector<T> f) {
        json["z"] = std::move(f);
        return *this;
    }

    // Sets the calendar system to use with `z` date data.
    // - Default: gregorian
    Mesh3d& zcalendar(enum Zcalendar f) {
        json["zcalendar"] = to_string(f);
        return *this;
    }

    // Sets the hover text formatting rulefor `z`  using d3 formatting mini-languages which are very similar to those in
    // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
    // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h* for
    // half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For example,
    // *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*By default the values are
    // formatted using `zaxis.hoverformat`.
    Mesh3d& zhoverformat(std::string f) {
        json["zhoverformat"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `z`.
    Mesh3d& zsrc(std::string f) {
        json["zsrc"] = std::move(f);
        return *this;
    }

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};
} // namespace plotlypp
