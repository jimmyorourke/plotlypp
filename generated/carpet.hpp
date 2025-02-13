// TODO: includes, copyright, etc
#include <string>
#include <type_traits>
#include <vector>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Carpet {
 public:
    Carpet() { json["type"] = "carpet"; }

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

    class Aaxis {
     public:

        enum class Autorange {
            TRUE,
            FALSE,
            REVERSED,
        };
        std::string to_string(Autorange e) {
            switch (e) {
            case Autorange::TRUE:
                return "True";
            case Autorange::FALSE:
                return "False";
            case Autorange::REVERSED:
                return "reversed";
            }
        }

        enum class Autotypenumbers {
            CONVERT_TYPES,
            STRICT,
        };
        std::string to_string(Autotypenumbers e) {
            switch (e) {
            case Autotypenumbers::CONVERT_TYPES:
                return "convert types";
            case Autotypenumbers::STRICT:
                return "strict";
            }
        }

        enum class Categoryorder {
            TRACE,
            CATEGORY_ASCENDING,
            CATEGORY_DESCENDING,
            ARRAY,
        };
        std::string to_string(Categoryorder e) {
            switch (e) {
            case Categoryorder::TRACE:
                return "trace";
            case Categoryorder::CATEGORY_ASCENDING:
                return "category ascending";
            case Categoryorder::CATEGORY_DESCENDING:
                return "category descending";
            case Categoryorder::ARRAY:
                return "array";
            }
        }

        enum class Cheatertype {
            INDEX,
            VALUE,
        };
        std::string to_string(Cheatertype e) {
            switch (e) {
            case Cheatertype::INDEX:
                return "index";
            case Cheatertype::VALUE:
                return "value";
            }
        }

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

        enum class Rangemode {
            NORMAL,
            TOZERO,
            NONNEGATIVE,
        };
        std::string to_string(Rangemode e) {
            switch (e) {
            case Rangemode::NORMAL:
                return "normal";
            case Rangemode::TOZERO:
                return "tozero";
            case Rangemode::NONNEGATIVE:
                return "nonnegative";
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

        enum class Showticklabels {
            START,
            END,
            BOTH,
            NONE,
        };
        std::string to_string(Showticklabels e) {
            switch (e) {
            case Showticklabels::START:
                return "start";
            case Showticklabels::END:
                return "end";
            case Showticklabels::BOTH:
                return "both";
            case Showticklabels::NONE:
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
            LINEAR,
            ARRAY,
        };
        std::string to_string(Tickmode e) {
            switch (e) {
            case Tickmode::LINEAR:
                return "linear";
            case Tickmode::ARRAY:
                return "array";
            }
        }

        enum class Type {
            HYPHEN,
            LINEAR,
            DATE,
            CATEGORY,
        };
        std::string to_string(Type e) {
            switch (e) {
            case Type::HYPHEN:
                return "-";
            case Type::LINEAR:
                return "linear";
            case Type::DATE:
                return "date";
            case Type::CATEGORY:
                return "category";
            }
        }

        // Sets the tick font.
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

            // Sets this axis' title font. Note that the title's font used to be set by the now deprecated `titlefont`
            // attribute.
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

            // Sets this axis' title font. Note that the title's font used to be set by the now deprecated `titlefont`
            // attribute.
            Title& font(class Font f) {
                json["font"] = std::move(f.json);
                return *this;
            }

            // An additional amount by which to offset the title from the tick labels, given in pixels. Note that this
            // used to be set by the now deprecated `titleoffset` attribute.
            Title& offset(double f) {
                json["offset"] = std::move(f);
                return *this;
            }

            // Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to
            // be defined as the `title` attribute itself. This behavior has been deprecated.
            Title& text(std::string f) {
                json["text"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // The stride between grid lines along the axis
        Aaxis& arraydtick(int f) {
            json["arraydtick"] = std::move(f);
            return *this;
        }

        // The starting index of grid lines along the axis
        Aaxis& arraytick0(int f) {
            json["arraytick0"] = std::move(f);
            return *this;
        }

        // Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode`
        // for more info. If `range` is provided, then `autorange` is set to *false*.
        // - Default: True
        Aaxis& autorange(enum Autorange f) {
            json["autorange"] = to_string(f);
            return *this;
        }

        // Using *strict* a numeric string in trace data is not converted to a number. Using *convert types* a numeric
        // string in trace data may be treated as a number during automatic axis `type` detection. Defaults to
        // layout.autotypenumbers.
        // - Default: convert types
        Aaxis& autotypenumbers(enum Autotypenumbers f) {
            json["autotypenumbers"] = to_string(f);
            return *this;
        }

        // Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to
        // *array*. Used with `categoryorder`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Aaxis& categoryarray(std::vector<T> f) {
            json["categoryarray"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `categoryarray`.
        Aaxis& categoryarraysrc(std::string f) {
            json["categoryarraysrc"] = std::move(f);
            return *this;
        }

        // Specifies the ordering logic for the case of categorical variables. By default, plotly uses *trace*, which
        // specifies the order that is present in the data supplied. Set `categoryorder` to *category ascending* or
        // *category descending* if order should be determined by the alphanumerical order of the category names. Set
        // `categoryorder` to *array* to derive the ordering from the attribute `categoryarray`. If a category is not
        // found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the *trace*
        // mode. The unspecified categories will follow the categories in `categoryarray`.
        // - Default: trace
        Aaxis& categoryorder(enum Categoryorder f) {
            json["categoryorder"] = to_string(f);
            return *this;
        }

        //
        // - Default: value
        Aaxis& cheatertype(enum Cheatertype f) {
            json["cheatertype"] = to_string(f);
            return *this;
        }

        // Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid
        // color is lightened by blending this with the plot background Individual pieces can override this.
        Aaxis& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }

        // The stride between grid lines along the axis
        Aaxis& dtick(double f) {
            json["dtick"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line is drawn at along the final value of this axis. If *true*, the end line is
        // drawn on top of the grid lines.
        Aaxis& endline(bool f) {
            json["endline"] = std::move(f);
            return *this;
        }

        // Sets the line color of the end line.
        Aaxis& endlinecolor(std::string f) {
            json["endlinecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the end line.
        Aaxis& endlinewidth(double f) {
            json["endlinewidth"] = std::move(f);
            return *this;
        }

        // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If
        // *none*, it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super
        // script). If *SI*, 1G. If *B*, 1B.
        // - Default: B
        Aaxis& exponentformat(enum Exponentformat f) {
            json["exponentformat"] = to_string(f);
            return *this;
        }

        // Determines whether or not this axis is zoom-able. If true, then zoom is disabled.
        Aaxis& fixedrange(bool f) {
            json["fixedrange"] = std::move(f);
            return *this;
        }

        // Sets the axis line color.
        Aaxis& gridcolor(std::string f) {
            json["gridcolor"] = std::move(f);
            return *this;
        }

        // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
        // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
        Aaxis& griddash(std::string f) {
            json["griddash"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the axis line.
        Aaxis& gridwidth(double f) {
            json["gridwidth"] = std::move(f);
            return *this;
        }

        // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to
        // USA and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix
        // or ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash.
        // That means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if
        // needed) and values (if desired) can include html-like tags or MathJax.
        template <typename T>
        Aaxis& labelalias(T f) {
            json["labelalias"] = std::move(f);
            return *this;
        }

        // Extra padding between label and the axis
        Aaxis& labelpadding(int f) {
            json["labelpadding"] = std::move(f);
            return *this;
        }

        // Sets a axis label prefix.
        Aaxis& labelprefix(std::string f) {
            json["labelprefix"] = std::move(f);
            return *this;
        }

        // Sets a axis label suffix.
        Aaxis& labelsuffix(std::string f) {
            json["labelsuffix"] = std::move(f);
            return *this;
        }

        // Sets the axis line color.
        Aaxis& linecolor(std::string f) {
            json["linecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the axis line.
        Aaxis& linewidth(double f) {
            json["linewidth"] = std::move(f);
            return *this;
        }

        // Hide SI prefix for 10^n if |n| is below this number
        Aaxis& minexponent(double f) {
            json["minexponent"] = std::move(f);
            return *this;
        }

        // Sets the color of the grid lines.
        Aaxis& minorgridcolor(std::string f) {
            json["minorgridcolor"] = std::move(f);
            return *this;
        }

        // Sets the number of minor grid ticks per major grid tick
        Aaxis& minorgridcount(int f) {
            json["minorgridcount"] = std::move(f);
            return *this;
        }

        // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
        // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
        Aaxis& minorgriddash(std::string f) {
            json["minorgriddash"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the grid lines.
        Aaxis& minorgridwidth(double f) {
            json["minorgridwidth"] = std::move(f);
            return *this;
        }

        // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
        // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
        Aaxis& nticks(int f) {
            json["nticks"] = std::move(f);
            return *this;
        }

        // Sets the range of this axis. If the axis `type` is *log*, then you must take the log of your desired range
        // (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is *date*, it should be
        // date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to
        // strings. If the axis `type` is *category*, it should be numbers, using the scale where each category is
        // assigned a serial number from zero in the order it appears.
        Aaxis& range(std::vector<std::string> f) {
            json["range"] = std::move(f);
            return *this;
        }

        // If *normal*, the range is computed in relation to the extrema of the input data. If *tozero*`, the range
        // extends to 0, regardless of the input data If *nonnegative*, the range is non-negative, regardless of the
        // input data.
        // - Default: normal
        Aaxis& rangemode(enum Rangemode f) {
            json["rangemode"] = to_string(f);
            return *this;
        }

        // If "true", even 4-digit integers are separated
        Aaxis& separatethousands(bool f) {
            json["separatethousands"] = std::move(f);
            return *this;
        }

        // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick
        // is shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
        // - Default: all
        Aaxis& showexponent(enum Showexponent f) {
            json["showexponent"] = to_string(f);
            return *this;
        }

        // Determines whether or not grid lines are drawn. If *true*, the grid lines are drawn at every tick mark.
        Aaxis& showgrid(bool f) {
            json["showgrid"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line bounding this axis is drawn.
        Aaxis& showline(bool f) {
            json["showline"] = std::move(f);
            return *this;
        }

        // Determines whether axis labels are drawn on the low side, the high side, both, or neither side of the axis.
        // - Default: start
        Aaxis& showticklabels(enum Showticklabels f) {
            json["showticklabels"] = to_string(f);
            return *this;
        }

        // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
        // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
        // - Default: all
        Aaxis& showtickprefix(enum Showtickprefix f) {
            json["showtickprefix"] = to_string(f);
            return *this;
        }

        // Same as `showtickprefix` but for tick suffixes.
        // - Default: all
        Aaxis& showticksuffix(enum Showticksuffix f) {
            json["showticksuffix"] = to_string(f);
            return *this;
        }

        Aaxis& smoothing(double f) {
            json["smoothing"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line is drawn at along the starting value of this axis. If *true*, the start line
        // is drawn on top of the grid lines.
        Aaxis& startline(bool f) {
            json["startline"] = std::move(f);
            return *this;
        }

        // Sets the line color of the start line.
        Aaxis& startlinecolor(std::string f) {
            json["startlinecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the start line.
        Aaxis& startlinewidth(double f) {
            json["startlinewidth"] = std::move(f);
            return *this;
        }

        // The starting index of grid lines along the axis
        Aaxis& tick0(double f) {
            json["tick0"] = std::move(f);
            return *this;
        }

        // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
        // tick labels vertically.
        Aaxis& tickangle(double f) {
            json["tickangle"] = std::move(f);
            return *this;
        }

        // Sets the tick font.
        Aaxis& tickfont(class Tickfont f) {
            json["tickfont"] = std::move(f.json);
            return *this;
        }

        // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in
        // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
        // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h*
        // for half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For
        // example, *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
        Aaxis& tickformat(std::string f) {
            json["tickformat"] = std::move(f);
            return *this;
        }

        Aaxis& tickformatstops(class Tickformatstops f) {
            json["tickformatstops"] = std::move(f.json);
            return *this;
        }

        //
        // - Default: array
        Aaxis& tickmode(enum Tickmode f) {
            json["tickmode"] = to_string(f);
            return *this;
        }

        // Sets a tick label prefix.
        Aaxis& tickprefix(std::string f) {
            json["tickprefix"] = std::move(f);
            return *this;
        }

        // Sets a tick label suffix.
        Aaxis& ticksuffix(std::string f) {
            json["ticksuffix"] = std::move(f);
            return *this;
        }

        // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to
        // *array*. Used with `tickvals`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Aaxis& ticktext(std::vector<T> f) {
            json["ticktext"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `ticktext`.
        Aaxis& ticktextsrc(std::string f) {
            json["ticktextsrc"] = std::move(f);
            return *this;
        }

        // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used
        // with `ticktext`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Aaxis& tickvals(std::vector<T> f) {
            json["tickvals"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `tickvals`.
        Aaxis& tickvalssrc(std::string f) {
            json["tickvalssrc"] = std::move(f);
            return *this;
        }

        Aaxis& title(class Title f) {
            json["title"] = std::move(f.json);
            return *this;
        }

        // Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the
        // traces that referenced the axis in question.
        // - Default: -
        Aaxis& type(enum Type f) {
            json["type"] = to_string(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Baxis {
     public:

        enum class Autorange {
            TRUE,
            FALSE,
            REVERSED,
        };
        std::string to_string(Autorange e) {
            switch (e) {
            case Autorange::TRUE:
                return "True";
            case Autorange::FALSE:
                return "False";
            case Autorange::REVERSED:
                return "reversed";
            }
        }

        enum class Autotypenumbers {
            CONVERT_TYPES,
            STRICT,
        };
        std::string to_string(Autotypenumbers e) {
            switch (e) {
            case Autotypenumbers::CONVERT_TYPES:
                return "convert types";
            case Autotypenumbers::STRICT:
                return "strict";
            }
        }

        enum class Categoryorder {
            TRACE,
            CATEGORY_ASCENDING,
            CATEGORY_DESCENDING,
            ARRAY,
        };
        std::string to_string(Categoryorder e) {
            switch (e) {
            case Categoryorder::TRACE:
                return "trace";
            case Categoryorder::CATEGORY_ASCENDING:
                return "category ascending";
            case Categoryorder::CATEGORY_DESCENDING:
                return "category descending";
            case Categoryorder::ARRAY:
                return "array";
            }
        }

        enum class Cheatertype {
            INDEX,
            VALUE,
        };
        std::string to_string(Cheatertype e) {
            switch (e) {
            case Cheatertype::INDEX:
                return "index";
            case Cheatertype::VALUE:
                return "value";
            }
        }

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

        enum class Rangemode {
            NORMAL,
            TOZERO,
            NONNEGATIVE,
        };
        std::string to_string(Rangemode e) {
            switch (e) {
            case Rangemode::NORMAL:
                return "normal";
            case Rangemode::TOZERO:
                return "tozero";
            case Rangemode::NONNEGATIVE:
                return "nonnegative";
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

        enum class Showticklabels {
            START,
            END,
            BOTH,
            NONE,
        };
        std::string to_string(Showticklabels e) {
            switch (e) {
            case Showticklabels::START:
                return "start";
            case Showticklabels::END:
                return "end";
            case Showticklabels::BOTH:
                return "both";
            case Showticklabels::NONE:
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
            LINEAR,
            ARRAY,
        };
        std::string to_string(Tickmode e) {
            switch (e) {
            case Tickmode::LINEAR:
                return "linear";
            case Tickmode::ARRAY:
                return "array";
            }
        }

        enum class Type {
            HYPHEN,
            LINEAR,
            DATE,
            CATEGORY,
        };
        std::string to_string(Type e) {
            switch (e) {
            case Type::HYPHEN:
                return "-";
            case Type::LINEAR:
                return "linear";
            case Type::DATE:
                return "date";
            case Type::CATEGORY:
                return "category";
            }
        }

        // Sets the tick font.
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

            // Sets this axis' title font. Note that the title's font used to be set by the now deprecated `titlefont`
            // attribute.
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

            // Sets this axis' title font. Note that the title's font used to be set by the now deprecated `titlefont`
            // attribute.
            Title& font(class Font f) {
                json["font"] = std::move(f.json);
                return *this;
            }

            // An additional amount by which to offset the title from the tick labels, given in pixels. Note that this
            // used to be set by the now deprecated `titleoffset` attribute.
            Title& offset(double f) {
                json["offset"] = std::move(f);
                return *this;
            }

            // Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to
            // be defined as the `title` attribute itself. This behavior has been deprecated.
            Title& text(std::string f) {
                json["text"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

        // The stride between grid lines along the axis
        Baxis& arraydtick(int f) {
            json["arraydtick"] = std::move(f);
            return *this;
        }

        // The starting index of grid lines along the axis
        Baxis& arraytick0(int f) {
            json["arraytick0"] = std::move(f);
            return *this;
        }

        // Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode`
        // for more info. If `range` is provided, then `autorange` is set to *false*.
        // - Default: True
        Baxis& autorange(enum Autorange f) {
            json["autorange"] = to_string(f);
            return *this;
        }

        // Using *strict* a numeric string in trace data is not converted to a number. Using *convert types* a numeric
        // string in trace data may be treated as a number during automatic axis `type` detection. Defaults to
        // layout.autotypenumbers.
        // - Default: convert types
        Baxis& autotypenumbers(enum Autotypenumbers f) {
            json["autotypenumbers"] = to_string(f);
            return *this;
        }

        // Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to
        // *array*. Used with `categoryorder`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Baxis& categoryarray(std::vector<T> f) {
            json["categoryarray"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `categoryarray`.
        Baxis& categoryarraysrc(std::string f) {
            json["categoryarraysrc"] = std::move(f);
            return *this;
        }

        // Specifies the ordering logic for the case of categorical variables. By default, plotly uses *trace*, which
        // specifies the order that is present in the data supplied. Set `categoryorder` to *category ascending* or
        // *category descending* if order should be determined by the alphanumerical order of the category names. Set
        // `categoryorder` to *array* to derive the ordering from the attribute `categoryarray`. If a category is not
        // found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the *trace*
        // mode. The unspecified categories will follow the categories in `categoryarray`.
        // - Default: trace
        Baxis& categoryorder(enum Categoryorder f) {
            json["categoryorder"] = to_string(f);
            return *this;
        }

        //
        // - Default: value
        Baxis& cheatertype(enum Cheatertype f) {
            json["cheatertype"] = to_string(f);
            return *this;
        }

        // Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid
        // color is lightened by blending this with the plot background Individual pieces can override this.
        Baxis& color(std::string f) {
            json["color"] = std::move(f);
            return *this;
        }

        // The stride between grid lines along the axis
        Baxis& dtick(double f) {
            json["dtick"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line is drawn at along the final value of this axis. If *true*, the end line is
        // drawn on top of the grid lines.
        Baxis& endline(bool f) {
            json["endline"] = std::move(f);
            return *this;
        }

        // Sets the line color of the end line.
        Baxis& endlinecolor(std::string f) {
            json["endlinecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the end line.
        Baxis& endlinewidth(double f) {
            json["endlinewidth"] = std::move(f);
            return *this;
        }

        // Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If
        // *none*, it appears as 1,000,000,000. If *e*, 1e+9. If *E*, 1E+9. If *power*, 1x10^9 (with 9 in a super
        // script). If *SI*, 1G. If *B*, 1B.
        // - Default: B
        Baxis& exponentformat(enum Exponentformat f) {
            json["exponentformat"] = to_string(f);
            return *this;
        }

        // Determines whether or not this axis is zoom-able. If true, then zoom is disabled.
        Baxis& fixedrange(bool f) {
            json["fixedrange"] = std::move(f);
            return *this;
        }

        // Sets the axis line color.
        Baxis& gridcolor(std::string f) {
            json["gridcolor"] = std::move(f);
            return *this;
        }

        // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
        // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
        Baxis& griddash(std::string f) {
            json["griddash"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the axis line.
        Baxis& gridwidth(double f) {
            json["gridwidth"] = std::move(f);
            return *this;
        }

        // Replacement text for specific tick or hover labels. For example using {US: 'USA', CA: 'Canada'} changes US to
        // USA and CA to Canada. The labels we would have shown must match the keys exactly, after adding any tickprefix
        // or ticksuffix. For negative numbers the minus sign symbol used (U+2212) is wider than the regular ascii dash.
        // That means you need to use −1 instead of -1. labelalias can be used with any axis type, and both keys (if
        // needed) and values (if desired) can include html-like tags or MathJax.
        template <typename T>
        Baxis& labelalias(T f) {
            json["labelalias"] = std::move(f);
            return *this;
        }

        // Extra padding between label and the axis
        Baxis& labelpadding(int f) {
            json["labelpadding"] = std::move(f);
            return *this;
        }

        // Sets a axis label prefix.
        Baxis& labelprefix(std::string f) {
            json["labelprefix"] = std::move(f);
            return *this;
        }

        // Sets a axis label suffix.
        Baxis& labelsuffix(std::string f) {
            json["labelsuffix"] = std::move(f);
            return *this;
        }

        // Sets the axis line color.
        Baxis& linecolor(std::string f) {
            json["linecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the axis line.
        Baxis& linewidth(double f) {
            json["linewidth"] = std::move(f);
            return *this;
        }

        // Hide SI prefix for 10^n if |n| is below this number
        Baxis& minexponent(double f) {
            json["minexponent"] = std::move(f);
            return *this;
        }

        // Sets the color of the grid lines.
        Baxis& minorgridcolor(std::string f) {
            json["minorgridcolor"] = std::move(f);
            return *this;
        }

        // Sets the number of minor grid ticks per major grid tick
        Baxis& minorgridcount(int f) {
            json["minorgridcount"] = std::move(f);
            return *this;
        }

        // Sets the dash style of lines. Set to a dash type string (*solid*, *dot*, *dash*, *longdash*, *dashdot*, or
        // *longdashdot*) or a dash length list in px (eg *5px,10px,2px,2px*).
        Baxis& minorgriddash(std::string f) {
            json["minorgriddash"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the grid lines.
        Baxis& minorgridwidth(double f) {
            json["minorgridwidth"] = std::move(f);
            return *this;
        }

        // Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen
        // automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to *auto*.
        Baxis& nticks(int f) {
            json["nticks"] = std::move(f);
            return *this;
        }

        // Sets the range of this axis. If the axis `type` is *log*, then you must take the log of your desired range
        // (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is *date*, it should be
        // date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to
        // strings. If the axis `type` is *category*, it should be numbers, using the scale where each category is
        // assigned a serial number from zero in the order it appears.
        Baxis& range(std::vector<std::string> f) {
            json["range"] = std::move(f);
            return *this;
        }

        // If *normal*, the range is computed in relation to the extrema of the input data. If *tozero*`, the range
        // extends to 0, regardless of the input data If *nonnegative*, the range is non-negative, regardless of the
        // input data.
        // - Default: normal
        Baxis& rangemode(enum Rangemode f) {
            json["rangemode"] = to_string(f);
            return *this;
        }

        // If "true", even 4-digit integers are separated
        Baxis& separatethousands(bool f) {
            json["separatethousands"] = std::move(f);
            return *this;
        }

        // If *all*, all exponents are shown besides their significands. If *first*, only the exponent of the first tick
        // is shown. If *last*, only the exponent of the last tick is shown. If *none*, no exponents appear.
        // - Default: all
        Baxis& showexponent(enum Showexponent f) {
            json["showexponent"] = to_string(f);
            return *this;
        }

        // Determines whether or not grid lines are drawn. If *true*, the grid lines are drawn at every tick mark.
        Baxis& showgrid(bool f) {
            json["showgrid"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line bounding this axis is drawn.
        Baxis& showline(bool f) {
            json["showline"] = std::move(f);
            return *this;
        }

        // Determines whether axis labels are drawn on the low side, the high side, both, or neither side of the axis.
        // - Default: start
        Baxis& showticklabels(enum Showticklabels f) {
            json["showticklabels"] = to_string(f);
            return *this;
        }

        // If *all*, all tick labels are displayed with a prefix. If *first*, only the first tick is displayed with a
        // prefix. If *last*, only the last tick is displayed with a suffix. If *none*, tick prefixes are hidden.
        // - Default: all
        Baxis& showtickprefix(enum Showtickprefix f) {
            json["showtickprefix"] = to_string(f);
            return *this;
        }

        // Same as `showtickprefix` but for tick suffixes.
        // - Default: all
        Baxis& showticksuffix(enum Showticksuffix f) {
            json["showticksuffix"] = to_string(f);
            return *this;
        }

        Baxis& smoothing(double f) {
            json["smoothing"] = std::move(f);
            return *this;
        }

        // Determines whether or not a line is drawn at along the starting value of this axis. If *true*, the start line
        // is drawn on top of the grid lines.
        Baxis& startline(bool f) {
            json["startline"] = std::move(f);
            return *this;
        }

        // Sets the line color of the start line.
        Baxis& startlinecolor(std::string f) {
            json["startlinecolor"] = std::move(f);
            return *this;
        }

        // Sets the width (in px) of the start line.
        Baxis& startlinewidth(double f) {
            json["startlinewidth"] = std::move(f);
            return *this;
        }

        // The starting index of grid lines along the axis
        Baxis& tick0(double f) {
            json["tick0"] = std::move(f);
            return *this;
        }

        // Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the
        // tick labels vertically.
        Baxis& tickangle(double f) {
            json["tickangle"] = std::move(f);
            return *this;
        }

        // Sets the tick font.
        Baxis& tickfont(class Tickfont f) {
            json["tickfont"] = std::move(f.json);
            return *this;
        }

        // Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in
        // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see:
        // https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: *%h*
        // for half of the year as a decimal number as well as *%{n}f* for fractional seconds with n digits. For
        // example, *2016-10-13 09:15:23.456* with tickformat *%H~%M~%S.%2f* would display *09~15~23.46*
        Baxis& tickformat(std::string f) {
            json["tickformat"] = std::move(f);
            return *this;
        }

        Baxis& tickformatstops(class Tickformatstops f) {
            json["tickformatstops"] = std::move(f.json);
            return *this;
        }

        //
        // - Default: array
        Baxis& tickmode(enum Tickmode f) {
            json["tickmode"] = to_string(f);
            return *this;
        }

        // Sets a tick label prefix.
        Baxis& tickprefix(std::string f) {
            json["tickprefix"] = std::move(f);
            return *this;
        }

        // Sets a tick label suffix.
        Baxis& ticksuffix(std::string f) {
            json["ticksuffix"] = std::move(f);
            return *this;
        }

        // Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to
        // *array*. Used with `tickvals`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Baxis& ticktext(std::vector<T> f) {
            json["ticktext"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `ticktext`.
        Baxis& ticktextsrc(std::string f) {
            json["ticktextsrc"] = std::move(f);
            return *this;
        }

        // Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to *array*. Used
        // with `ticktext`.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Baxis& tickvals(std::vector<T> f) {
            json["tickvals"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `tickvals`.
        Baxis& tickvalssrc(std::string f) {
            json["tickvalssrc"] = std::move(f);
            return *this;
        }

        Baxis& title(class Title f) {
            json["title"] = std::move(f.json);
            return *this;
        }

        // Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the
        // traces that referenced the axis in question.
        // - Default: -
        Baxis& type(enum Type f) {
            json["type"] = to_string(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    // The default font used for axis & tick labels on this carpet
    class Font {
     public:

        Font& color(std::string f) {
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

    // An array containing values of the first parameter value
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& a(std::vector<T> f) {
        json["a"] = std::move(f);
        return *this;
    }

    // Alternate to `a`. Builds a linear space of a coordinates. Use with `da` where `a0` is the starting coordinate and
    // `da` the step.
    Carpet& a0(double f) {
        json["a0"] = std::move(f);
        return *this;
    }

    Carpet& aaxis(class Aaxis f) {
        json["aaxis"] = std::move(f.json);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `a`.
    Carpet& asrc(std::string f) {
        json["asrc"] = std::move(f);
        return *this;
    }

    // A two dimensional array of y coordinates at each carpet point.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& b(std::vector<T> f) {
        json["b"] = std::move(f);
        return *this;
    }

    // Alternate to `b`. Builds a linear space of a coordinates. Use with `db` where `b0` is the starting coordinate and
    // `db` the step.
    Carpet& b0(double f) {
        json["b0"] = std::move(f);
        return *this;
    }

    Carpet& baxis(class Baxis f) {
        json["baxis"] = std::move(f.json);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `b`.
    Carpet& bsrc(std::string f) {
        json["bsrc"] = std::move(f);
        return *this;
    }

    // An identifier for this carpet, so that `scattercarpet` and `contourcarpet` traces can specify a carpet plot on
    // which they lie
    Carpet& carpet(std::string f) {
        json["carpet"] = std::move(f);
        return *this;
    }

    // The shift applied to each successive row of data in creating a cheater plot. Only used if `x` is been omitted.
    Carpet& cheaterslope(double f) {
        json["cheaterslope"] = std::move(f);
        return *this;
    }

    // Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color
    // is lightened by blending this with the plot background Individual pieces can override this.
    Carpet& color(std::string f) {
        json["color"] = std::move(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Carpet& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    // Sets the a coordinate step. See `a0` for more info.
    Carpet& da(double f) {
        json["da"] = std::move(f);
        return *this;
    }

    // Sets the b coordinate step. See `b0` for more info.
    Carpet& db(double f) {
        json["db"] = std::move(f);
        return *this;
    }

    // The default font used for axis & tick labels on this carpet
    Carpet& font(class Font f) {
        json["font"] = std::move(f.json);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Carpet& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Carpet& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    Carpet& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Carpet& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Carpet& legendwidth(double f) {
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
    Carpet& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Carpet& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Carpet& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Carpet& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    // Sets the opacity of the trace.
    Carpet& opacity(double f) {
        json["opacity"] = std::move(f);
        return *this;
    }

    Carpet& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Carpet& uid(std::string f) {
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
    Carpet& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Carpet& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // A two dimensional array of x coordinates at each carpet point. If omitted, the plot is a cheater plot and the
    // xaxis is hidden by default.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& x(std::vector<T> f) {
        json["x"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's x coordinates and a 2D cartesian x axis. If *x* (the default value), the x
    // coordinates refer to `layout.xaxis`. If *x2*, the x coordinates refer to `layout.xaxis2`, and so on.
    Carpet& xaxis(std::string f) {
        json["xaxis"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `x`.
    Carpet& xsrc(std::string f) {
        json["xsrc"] = std::move(f);
        return *this;
    }

    // A two dimensional array of y coordinates at each carpet point.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Carpet& y(std::vector<T> f) {
        json["y"] = std::move(f);
        return *this;
    }

    // Sets a reference between this trace's y coordinates and a 2D cartesian y axis. If *y* (the default value), the y
    // coordinates refer to `layout.yaxis`. If *y2*, the y coordinates refer to `layout.yaxis2`, and so on.
    Carpet& yaxis(std::string f) {
        json["yaxis"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `y`.
    Carpet& ysrc(std::string f) {
        json["ysrc"] = std::move(f);
        return *this;
    }

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};
} // namespace plotlypp
