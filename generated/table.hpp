// TODO: includes, copyright, etc
#include <string>
#include <type_traits>
#include <vector>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Table {
 public:
    Table() { json["type"] = "table"; }

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

    class Cells {
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

        class Fill {
         public:

            // Sets the cell fill color. It accepts either a specific color or an array of colors or a 2D array of
            // colors.
            Fill& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Fill& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Fill& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

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

        class Line {
         public:

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

        // Sets the horizontal alignment of the `text` within the box. Has an effect only if `text` spans two or more
        // lines (i.e. `text` contains one or more <br> HTML tags) or if an explicit width is set to override the text
        // width.
        // - Default: center
        Cells& align(enum Align f) {
            json["align"] = to_string(f);
            return *this;
        }
        Cells& align(const std::vector<enum Align>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["align"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `align`.
        Cells& alignsrc(std::string f) {
            json["alignsrc"] = std::move(f);
            return *this;
        }

        Cells& fill(class Fill f) {
            json["fill"] = std::move(f.json);
            return *this;
        }

        Cells& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets the cell value formatting rule using d3 formatting mini-languages which are very similar to those in
        // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Cells& format(std::vector<T> f) {
            json["format"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `format`.
        Cells& formatsrc(std::string f) {
            json["formatsrc"] = std::move(f);
            return *this;
        }

        // The height of cells.
        Cells& height(double f) {
            json["height"] = std::move(f);
            return *this;
        }

        Cells& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Prefix for cell values.
        Cells& prefix(std::string f) {
            json["prefix"] = std::move(f);
            return *this;
        }
        Cells& prefix(std::vector<std::string> f) {
            json["prefix"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `prefix`.
        Cells& prefixsrc(std::string f) {
            json["prefixsrc"] = std::move(f);
            return *this;
        }

        // Suffix for cell values.
        Cells& suffix(std::string f) {
            json["suffix"] = std::move(f);
            return *this;
        }
        Cells& suffix(std::vector<std::string> f) {
            json["suffix"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `suffix`.
        Cells& suffixsrc(std::string f) {
            json["suffixsrc"] = std::move(f);
            return *this;
        }

        // Cell values. `values[m][n]` represents the value of the `n`th point in column `m`, therefore the `values[m]`
        // vector length for all columns must be the same (longer vectors will be truncated). Each value must be a
        // finite number or a string.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Cells& values(std::vector<T> f) {
            json["values"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `values`.
        Cells& valuessrc(std::string f) {
            json["valuessrc"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Domain {
     public:

        // If there is a layout grid, use the domain for this column in the grid for this table trace .
        Domain& column(int f) {
            json["column"] = std::move(f);
            return *this;
        }

        // If there is a layout grid, use the domain for this row in the grid for this table trace .
        Domain& row(int f) {
            json["row"] = std::move(f);
            return *this;
        }

        // Sets the horizontal domain of this table trace (in plot fraction).
        Domain& x(std::vector<std::string> f) {
            json["x"] = std::move(f);
            return *this;
        }

        // Sets the vertical domain of this table trace (in plot fraction).
        Domain& y(std::vector<std::string> f) {
            json["y"] = std::move(f);
            return *this;
        }

        // Advanced users may modify the JSON representation directly, at their own peril!
        nlohmann::json json{};
    };

    class Header {
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

        class Fill {
         public:

            // Sets the cell fill color. It accepts either a specific color or an array of colors or a 2D array of
            // colors.
            Fill& color(std::string f) {
                json["color"] = std::move(f);
                return *this;
            }
            Fill& color(std::vector<std::string> f) {
                json["color"] = std::move(f);
                return *this;
            }

            // Sets the source reference on Chart Studio Cloud for `color`.
            Fill& colorsrc(std::string f) {
                json["colorsrc"] = std::move(f);
                return *this;
            }

            // Advanced users may modify the JSON representation directly, at their own peril!
            nlohmann::json json{};
        };

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

        class Line {
         public:

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

        // Sets the horizontal alignment of the `text` within the box. Has an effect only if `text` spans two or more
        // lines (i.e. `text` contains one or more <br> HTML tags) or if an explicit width is set to override the text
        // width.
        // - Default: center
        Header& align(enum Align f) {
            json["align"] = to_string(f);
            return *this;
        }
        Header& align(const std::vector<enum Align>& f) {
            std::vector<std::string> stringified(f.size());
            std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e) { return to_string(e); });
            json["align"] = std::move(stringified);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `align`.
        Header& alignsrc(std::string f) {
            json["alignsrc"] = std::move(f);
            return *this;
        }

        Header& fill(class Fill f) {
            json["fill"] = std::move(f.json);
            return *this;
        }

        Header& font(class Font f) {
            json["font"] = std::move(f.json);
            return *this;
        }

        // Sets the cell value formatting rule using d3 formatting mini-languages which are very similar to those in
        // Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Header& format(std::vector<T> f) {
            json["format"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `format`.
        Header& formatsrc(std::string f) {
            json["formatsrc"] = std::move(f);
            return *this;
        }

        // The height of cells.
        Header& height(double f) {
            json["height"] = std::move(f);
            return *this;
        }

        Header& line(class Line f) {
            json["line"] = std::move(f.json);
            return *this;
        }

        // Prefix for cell values.
        Header& prefix(std::string f) {
            json["prefix"] = std::move(f);
            return *this;
        }
        Header& prefix(std::vector<std::string> f) {
            json["prefix"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `prefix`.
        Header& prefixsrc(std::string f) {
            json["prefixsrc"] = std::move(f);
            return *this;
        }

        // Suffix for cell values.
        Header& suffix(std::string f) {
            json["suffix"] = std::move(f);
            return *this;
        }
        Header& suffix(std::vector<std::string> f) {
            json["suffix"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `suffix`.
        Header& suffixsrc(std::string f) {
            json["suffixsrc"] = std::move(f);
            return *this;
        }

        // Header cell values. `values[m][n]` represents the value of the `n`th point in column `m`, therefore the
        // `values[m]` vector length for all columns must be the same (longer vectors will be truncated). Each value
        // must be a finite number or a string.
        template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
        Header& values(std::vector<T> f) {
            json["values"] = std::move(f);
            return *this;
        }

        // Sets the source reference on Chart Studio Cloud for `values`.
        Header& valuessrc(std::string f) {
            json["valuessrc"] = std::move(f);
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

    Table& cells(class Cells f) {
        json["cells"] = std::move(f.json);
        return *this;
    }

    // Specifies the rendered order of the data columns; for example, a value `2` at position `0` means that column
    // index `0` in the data will be rendered as the third column, as columns have an index base of zero.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Table& columnorder(std::vector<T> f) {
        json["columnorder"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `columnorder`.
    Table& columnordersrc(std::string f) {
        json["columnordersrc"] = std::move(f);
        return *this;
    }

    // The width of columns expressed as a ratio. Columns fill the available width in proportion of their specified
    // column widths.
    Table& columnwidth(double f) {
        json["columnwidth"] = std::move(f);
        return *this;
    }
    Table& columnwidth(std::vector<double> f) {
        json["columnwidth"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `columnwidth`.
    Table& columnwidthsrc(std::string f) {
        json["columnwidthsrc"] = std::move(f);
        return *this;
    }

    // Assigns extra data each datum. This may be useful when listening to hover, click and selection events. Note that,
    // *scatter* traces also appends customdata items in the markers DOM elements
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Table& customdata(std::vector<T> f) {
        json["customdata"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `customdata`.
    Table& customdatasrc(std::string f) {
        json["customdatasrc"] = std::move(f);
        return *this;
    }

    Table& domain(class Domain f) {
        json["domain"] = std::move(f.json);
        return *this;
    }

    Table& header(class Header f) {
        json["header"] = std::move(f.json);
        return *this;
    }

    // Determines which trace information appear on hover. If `none` or `skip` are set, no information is displayed upon
    // hovering. But, if `none` is set, click and hover events are still fired.
    // - Default: all
    // - Flags: ['x', 'y', 'z', 'text', 'name']
    // - Extras ['all', 'none', 'skip']
    Table& hoverinfo(std::string f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }
    Table& hoverinfo(std::vector<std::string> f) {
        json["hoverinfo"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `hoverinfo`.
    Table& hoverinfosrc(std::string f) {
        json["hoverinfosrc"] = std::move(f);
        return *this;
    }

    Table& hoverlabel(class Hoverlabel f) {
        json["hoverlabel"] = std::move(f.json);
        return *this;
    }

    // Assigns id labels to each datum. These ids for object constancy of data points during animation. Should be an
    // array of strings, not numbers or any other type.
    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    Table& ids(std::vector<T> f) {
        json["ids"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `ids`.
    Table& idssrc(std::string f) {
        json["idssrc"] = std::move(f);
        return *this;
    }

    // Sets the reference to a legend to show this trace in. References to these legends are *legend*, *legend2*,
    // *legend3*, etc. Settings for these legends are set in the layout, under `layout.legend`, `layout.legend2`, etc.
    Table& legend(std::string f) {
        json["legend"] = std::move(f);
        return *this;
    }

    Table& legendgrouptitle(class Legendgrouptitle f) {
        json["legendgrouptitle"] = std::move(f.json);
        return *this;
    }

    // Sets the legend rank for this trace. Items and groups with smaller ranks are presented on top/left side while
    // with *reversed* `legend.traceorder` they are on bottom/right side. The default legendrank is 1000, so that you
    // can use ranks less than 1000 to place certain items before all unranked items, and ranks greater than 1000 to go
    // after all unranked items. When having unranked or equal rank items shapes would be displayed after traces i.e.
    // according to their order in data and layout.
    Table& legendrank(double f) {
        json["legendrank"] = std::move(f);
        return *this;
    }

    // Sets the width (in px or fraction) of the legend for this trace.
    Table& legendwidth(double f) {
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
    Table& meta(T f) {
        json["meta"] = std::move(f);
        return *this;
    }
    template <typename T>
    Table& meta(std::vector<T> f) {
        json["meta"] = std::move(f);
        return *this;
    }

    // Sets the source reference on Chart Studio Cloud for `meta`.
    Table& metasrc(std::string f) {
        json["metasrc"] = std::move(f);
        return *this;
    }

    // Sets the trace name. The trace name appears as the legend item and on hover.
    Table& name(std::string f) {
        json["name"] = std::move(f);
        return *this;
    }

    Table& stream(class Stream f) {
        json["stream"] = std::move(f.json);
        return *this;
    }

    // Assign an id to this trace, Use this to provide object constancy between traces during animations and
    // transitions.
    Table& uid(std::string f) {
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
    Table& uirevision(T f) {
        json["uirevision"] = std::move(f);
        return *this;
    }

    // Determines whether or not this trace is visible. If *legendonly*, the trace is not drawn, but can appear as a
    // legend item (provided that the legend itself is visible).
    // - Default: True
    Table& visible(enum Visible f) {
        json["visible"] = to_string(f);
        return *this;
    }

    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};
} // namespace plotlypp
