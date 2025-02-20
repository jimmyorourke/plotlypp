// TODO: includes, copyright, etc
#pragma once

#include <string>
#include <type_traits>
#include <vector>

#include <trace.hpp>
#include <traits.hpp>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Indicator : public Trace {
 public:
    Indicator()
    : Trace() {
        json["type"] = "indicator";
    }

    enum class Align {
        LEFT,
        CENTER,
        RIGHT,
    };
    std::string to_string(Align e) {
        switch (e) {
        case Align::LEFT:
            return "left";
        case Align::CENTER:
            return "center";
        case Align::RIGHT:
            return "right";
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

    class Delta {
     public:

        enum class Position {
            TOP,
            BOTTOM,
            LEFT,
            RIGHT,
        };
        std::string to_string(Position e) {
            switch (e) {
            case Position::TOP:
                return "top";
            case Position::BOTTOM:
                return "bottom";
            case Position::LEFT:
                return "left";
            case Position::RIGHT:
                return "right";
            }
        }

        class Decreasing {
         public:

            // Sets the color for increasing value.
            Decreasing& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the symbol to display for increasing value
            Decreasing& symbol(std::string f) {
                json["symbol"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Set the font used to display the delta
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

        class Increasing {
         public:

            // Sets the color for increasing value.
            Increasing& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the symbol to display for increasing value
            Increasing& symbol(std::string f) {
                json["symbol"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Delta& decreasing(class Decreasing f) {
            json["decreasing"] = std::move(f.json);
            return *this;
        }

        // Set the font used to display the delta
        Delta& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        Delta& increasing(class Increasing f) {
            json["increasing"] = std::move(f.json);
            return *this;
        }

        // Sets the position of delta with respect to the number.
        // - Default: bottom
        Delta& position(enum Position f) {
            json["position"] = to_string(f);
            return *this;
        }

        // Sets a prefix appearing before the delta.
        Delta& prefix(std::string f) {
            json["prefix"] = std::move(f);
            return *this;
        }

        // Sets the reference value to compute the delta. By default, it is set to the current value.
        Delta& reference(double f) {
            json["reference"] = std::move(f);
            return *this;
        }

        // Show relative change
        Delta& relative(bool f) {
            json["relative"] = std::move(f);
            return *this;
        }

        // Sets a suffix appearing next to the delta.
        Delta& suffix(std::string f) {
            json["suffix"] = std::move(f);
            return *this;
        }

        // Sets the value formatting rule using d3 formatting mini-languages which are very similar to those in Python.
        // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
        Delta& valueformat(std::string f) {
            json["valueformat"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Domain {
     public:

        // If there is a layout grid, use the domain for this column in the grid for this indicator trace .
        Domain& column(int f) {
            json["column"] = std::move(f);
            return *this;
        }

        // If there is a layout grid, use the domain for this row in the grid for this indicator trace .
        Domain& row(int f) {
            json["row"] = std::move(f);
            return *this;
        }

        // Sets the horizontal domain of this indicator trace (in plot fraction).
        Domain& x(std::vector<std::string> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the vertical domain of this indicator trace (in plot fraction).
        Domain& y(std::vector<std::string> f) {
            json["y"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // The gauge of the Indicator plot.
    class Gauge {
     public:

        enum class Shape {
            ANGULAR,
            BULLET,
        };
        std::string to_string(Shape e) {
            switch (e) {
            case Shape::ANGULAR:
                return "angular";
            case Shape::BULLET:
                return "bullet";
            }
        }

        class Axis {
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
            Axis& dtick(T f) {
                json["dtick"] = std::move(f);
                return *this;
            }

            // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If
            // *none*, it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super
            // script). If *SI*, 1G. If *B*, 1B.
            // - Default: B
            Axis& exponentformat(enum Exponentformat f) {
                json["exponentformat"] = to_string(f);
                return *this;
            }

            // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes
            // US to USA and CA to Canada. The labels we would have shown must match the keys exactly, after adding any
            // tickprefix or ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the
            // regular ascii dash. That means you need to use −1 instead of -1. labelalias can be used with any axis
            // type, and both keys (if needed) and values (if desired) can include html-like tags or MathJax.
            template <typename T>
            Axis& labelalias(T f) {
                json["labelalias"] = std::move(f);
                return *this;
            }

            // Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is *SI* or
            // *B*.
            Axis& minexponent(double f) {
                json["minexponent"] = std::move(f);
                return *this;
            }

            // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
            // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
            Axis& nticks(int f) {
                json["nticks"] = std::move(f);
                return *this;
            }

            // Sets the range of this axis.
            Axis& range(std::vector<std::string> f) {
                json["range"] = std::move(f);
                return *this;
            }

            // If "true", even 4-digit integers are separated
            Axis& separatethousands(bool f) {
                json["separatethousands"] = std::move(f);
                return *this;
            }

            // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first
            // tick is shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
            // - Default: all
            Axis& showexponent(enum Showexponent f) {
                json["showexponent"] = to_string(f);
                return *this;
            }

            // Determines whether or not the tick labels are drawn.
            Axis& showticklabels(bool f) {
                json["showticklabels"] = std::move(f);
                return *this;
            }

            // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with
            // a prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
            // - Default: all
            Axis& showtickprefix(enum Showtickprefix f) {
                json["showtickprefix"] = to_string(f);
                return *this;
            }

            // Same as `showtickprefix` but for tick suffixes.
            // - Default: all
            Axis& showticksuffix(enum Showticksuffix f) {
                json["showticksuffix"] = to_string(f);
                return *this;
            }

            // Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is *log*, then
            // you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2)
            // except when `dtick`=*L<f>* (see `dtick` for more info). If the axis `type` is *date*, it should be a date
            // string, like date data. If the axis `type` is *category*, it should be a number, using the scale where
            // each category is assigned a serial number from zero in the order it appears.
            template <typename T>
            Axis& tick0(T f) {
                json["tick0"] = std::move(f);
                return *this;
            }

            // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws
            // the tick labels vertically.
            Axis& tickangle(double f) {
                json["tickangle"] = std::move(f);
                return *this;
            }

            // Sets the tick color.
            Axis& tickcolor(std::string f) {
                json["tickcolor"] = std::move(f);
                return *this;
            }

            // Sets the color bar's tick label font
            Axis& tickfont(class Tickfont f) {
                json["tickfont"] = std::move(f.json);
                return *this;
            }

            // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in
            // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
            // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter:
            // *%h* for half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits.
            // For example, *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
            Axis& tickformat(std::string f) {
                json["tickformat"] = std::move(f);
                return *this;
            }

            Axis& tickformatstops(class Tickformatstops f) {
                json["tickformatstops"] = std::move(f.json);
                return *this;
            }

            // Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default)
            // means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every
            // nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type`
            // *log* or *multicategory*, or when `tickmode` is *array*.
            Axis& ticklabelstep(int f) {
                json["ticklabelstep"] = std::move(f);
                return *this;
            }

            // Sets the tick length (in px).
            Axis& ticklen(double f) {
                json["ticklen"] = std::move(f);
                return *this;
            }

            // Sets the tick mode for this axis. If *auto*, the number of ticks is set via `nticks`. If *linear*, the
            // placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` (*linear* is
            // the default value if `tick0` and `dtick` are provided). If *array*, the placement of the ticks is set via
            // `tickvals` and the tick text is `ticktext`. (*array* is the default value if `tickvals` is provided).
            Axis& tickmode(enum Tickmode f) {
                json["tickmode"] = to_string(f);
                return *this;
            }

            // Sets a tick label prefix.
            Axis& tickprefix(std::string f) {
                json["tickprefix"] = std::move(f);
                return *this;
            }

            // Determines whether ticks are drawn or not. If **, this axis' ticks are not drawn. If *outside*
            // (*inside*), this axis' are drawn outside (inside) the axis lines.
            // - Default: outside
            Axis& ticks(enum Ticks f) {
                json["ticks"] = to_string(f);
                return *this;
            }

            // Sets a tick label suffix.
            Axis& ticksuffix(std::string f) {
                json["ticksuffix"] = std::move(f);
                return *this;
            }

            // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to
            // *array*. Used with `tickvals`.
            template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
            Axis& ticktext(std::vector<T> f) {
                json["ticktext"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `ticktext`.
            Axis& ticktextsrc(std::string f) {
                json["ticktextsrc"] = std::move(f);
                return *this;
            }

            // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*.
            // Used with `ticktext`.
            template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
            Axis& tickvals(std::vector<T> f) {
                json["tickvals"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `tickvals`.
            Axis& tickvalssrc(std::string f) {
                json["tickvalssrc"] = std::move(f);
                return *this;
            }

            // Sets the tick width (in px).
            Axis& tickwidth(double f) {
                json["tickwidth"] = std::move(f);
                return *this;
            }

            // A single toggle to hide the axis while preserving interaction like dragging. Default is true when a
            // cheater plot is present on the axis, otherwise false
            Axis& visible(bool f) {
                json["visible"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // Set the appearance of the gauge's value
        class Bar {
         public:

            class Line {
             public:

                // Sets the color of the line enclosing each sector.
                Line& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // Sets the width (in px) of the line enclosing each sector.
                Line& width(double f) {
                    json["width"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            // Sets the background color of the arc.
            Bar& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }

            Bar& line(class Line f) {
                json["line"] = std::move(f.json);
                return *this;
            }

            // Sets the thickness of the bar as a fraction of the total thickness of the gauge.
            Bar& thickness(double f) {
                json["thickness"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        class Steps {
         public:

            class Step {
             public:

                class Line {
                 public:

                    // Sets the color of the line enclosing each sector.
                    Line& color(std::string f) {
                        json["color"] = std::move(f);
                        return *this;
                    }

                    // Sets the width (in px) of the line enclosing each sector.
                    Line& width(double f) {
                        json["width"] = std::move(f);
                        return *this;
                    }

                    // Advanced users may modify the JSON representation directly, at their own peril!
                    nlohmann::json json{};
                };

                // Sets the background color of the arc.
                Step& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                Step& line(class Line f) {
                    json["line"] = std::move(f.json);
                    return *this;
                }

                // When used in a template, named items are created in the output figure in addition to any items the
                // figure already has in this array. You can modify these items in the output figure by making your own
                // item with `templateitemname` matching this `name` alongside your modifications (including `visible:
                // false` or `enabled: false` to hide it). Has no effect outside of a template.
                Step& name(std::string f) {
                    json["name"] = std::move(f);
                    return *this;
                }

                // Sets the range of this axis.
                Step& range(std::vector<std::string> f) {
                    json["range"] = std::move(f);
                    return *this;
                }

                // Used to refer to a named item in this array in the template. Named items from the template will be
                // created even without a matching item in the input figure, but you can modify one by making an item
                // with `templateitemname` matching its `name`, alongside your modifications (including `visible: false`
                // or `enabled: false` to hide it). If there is no template or no matching item, this item will be
                // hidden unless you explicitly show it with `visible: true`.
                Step& templateitemname(std::string f) {
                    json["templateitemname"] = std::move(f);
                    return *this;
                }

                // Sets the thickness of the bar as a fraction of the total thickness of the gauge.
                Step& thickness(double f) {
                    json["thickness"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            Steps& step(class Step f) {
                json["step"] = std::move(f.json);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        class Threshold {
         public:

            class Line {
             public:

                // Sets the color of the threshold line.
                Line& color(std::string f) {
                    json["color"] = std::move(f);
                    return *this;
                }

                // Sets the width (in px) of the threshold line.
                Line& width(double f) {
                    json["width"] = std::move(f);
                    return *this;
                }

                // Advanced users may modify the JSON representation directly, at their own peril!
                nlohmann::json json{};
            };

            Threshold& line(class Line f) {
                json["line"] = std::move(f.json);
                return *this;
            }

            // Sets the thickness of the threshold line as a fraction of the thickness of the gauge.
            Threshold& thickness(double f) {
                json["thickness"] = std::move(f);
                return *this;
            }

            // Sets a treshold value drawn as a line.
            Threshold& value(double f) {
                json["value"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        Gauge& axis(class Axis f) {
            json["axis"] = std::move(f.json);
            return *this;
        }

        // Set the appearance of the gauge's value
        Gauge& bar(class Bar f) {
            json["bar"] = std::move(f.json);
            return *this;
        }

        // Sets the gauge background color.
        Gauge& bgcolor(std::string f) {
            json["bgcolor"] = std::move(f);
            return *this;
        }

        // Sets the color of the border enclosing the gauge.
        Gauge& bordercolor(std::string f) {
            json["bordercolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the border enclosing the gauge.
        Gauge& borderwidth(double f) {
            json["borderwidth"] = std::move(f);
            return *this;
        }

        // Set the shape of the gauge
        // - Default: angular
        Gauge& shape(enum Shape f) {
            json["shape"] = to_string(f);
            return *this;
        }

        Gauge& steps(class Steps f) {
            json["steps"] = std::move(f.json);
            return *this;
        }

        Gauge& threshold(class Threshold f) {
            json["threshold"] = std::move(f.json);
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

    class Number {
     public:

        // Set the font used to display main number
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

        // Set the font used to display main number
        Number& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets a prefix appearing before the number.
        Number& prefix(std::string f) {
            json["prefix"] = std::move(f);
            return *this;
        }

        // Sets a suffix appearing next to the number.
        Number& suffix(std::string f) {
            json["suffix"] = std::move(f);
            return *this;
        }

        // Sets the value formatting rule using d3 formatting mini-languages which are very similar to those in Python.
        // For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
        Number& valueformat(std::string f) {
            json["valueformat"] = std::move(f);
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

    class Title {
     public:

        enum class Align {
            LEFT,
            CENTER,
            RIGHT,
        };
        std::string to_string(Align e) {
            switch (e) {
            case Align::LEFT:
                return "left";
            case Align::CENTER:
                return "center";
            case Align::RIGHT:
                return "right";
            }
        }

        // Set the font used to display the title
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

        // Sets the horizontal alignment of the title. It defaults to `center` except for bullet charts for which it
        // defaults to right.
        Title& align(enum Align f) {
            json["align"] = to_string(f);
            return *this;
        }

        // Set the font used to display the title
        Title& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets the title of this indicator.
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

    // Sets the horizontal alignment of the `text` within the box. Note that this attribute has no effect if an angular
    // gauge is displayed: in this case, it is always centered
    Indicator& align(enum Align f) {
        json["align"] = to_string(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Indicator& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    Indicator& delta(class Delta f) {
        json["delta"] = std::move(f.json);
        return *this;
    }

    Indicator& domain(class Domain f) {
        json["domain"] = std::move(f.json);
        return *this;
    }

    // The gauge of the Indicator plot.
    Indicator& gauge(class Gauge f) {
        json["gauge"] = std::move(f.json);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<is_data_array_element_v<T>>>
    Indicator& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Indicator& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Indicator& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    Indicator& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Indicator& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Indicator& legendwidth(double f) {
        json["legendwidth"] = std::move(f);
        return *this;
    }

    // Assigns extra meta information associated with this trace that can be used in various text attributes. Attributes
    // such as trace `name`, graph, axis and colorbar `title.text`, annotation `text` `rangeselector`, `updatemenues`
    // and `sliders` `label` text all support `meta`. To access the trace `meta` values in an attribute in the same
    // trace, simply use `%{meta[i]}` where `i` is the index or key of the `meta` item in question. To access trace
    // `meta` in layout attributes, use `%{data[n[.meta[i]}` where `i` is the index or key of the `meta` and `n` is the
    // trace index.
    template <typename T>
    Indicator& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Indicator& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Indicator& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Determines how the value is displayed on the graph. `number` displays the value numerically in text. `delta`
    // displays the difference to a reference value in text. Finally, `gauge` displays the value graphically on an axis.
    // - Default: number
    // - Flags: ['number', 'delta', 'gauge']
    Indicator& mode(std::string f) {
        json["mode"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Indicator& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    Indicator& number(class Number f) {
        json["number"] = std::move(f.json);
        return *this;
    }

    Indicator& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    Indicator& title(class Title f) {
        json["title"] = std::move(f.json);
        return *this;
    }

    Indicator& transforms(class Transforms f) {
        json["transforms"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Indicator& uid(std::string f) {
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
    Indicator& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Sets the number to be displayed.
    Indicator& value(double f) {
        json["value"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Indicator& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }
};
} // namespace plotlypp
