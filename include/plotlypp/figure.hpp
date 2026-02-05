// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include <plotlypp/json.hpp>
#include <plotlypp/layout/layout.hpp>
#include <plotlypp/plotly_min_js.hpp>
#include <plotlypp/trace.hpp>

namespace plotlypp {

class Figure {
 public:
    template <typename T, typename = std::enable_if_t<std::is_base_of_v<Trace, T>>>
    Figure& addTrace(T trace) {
        _json["data"].push_back(std::move(trace.json));
        return *this;
    }

    template <typename T, typename = std::enable_if_t<std::is_base_of_v<Trace, T>>>
    Figure& addTraces(std::vector<T> traces) {
        for (auto& trace : traces) {
            _json["data"].push_back(std::move(trace.json));
        }
        return *this;
    }

    Figure& setLayout(Layout layout) {
        _json["layout"] = std::move(layout.json);
        return *this;
    }

    template <typename C, typename = std::enable_if_t<std::is_invocable_v<C, Layout&>>>
    Figure& setLayout(C&& c) {
        Layout layout{};
        std::forward<C>(c)(layout);
        return setLayout(std::move(layout));
    }

    void toHtml(std::ostream& os) const {
        // Serialize and sanitize for HTML embedding.
        // This escapes '<' to '\u003c' so the browser never confuses JSON data for HTML tags.
        auto html_safe_serialize = [](const auto& json) {
            std::string s = serialize(json);
            // Escape '<' to '\u003c' so the browser never confuses JSON data for HTML tags.
            size_t pos = 0;
            while ((pos = s.find('<', pos)) != std::string::npos) {
                s.replace(pos, 1, "\\u003c");
                pos += 6;
            }
            return s;
        };

        // Embed the JSON directly as javascript objects. This more efficient than JSON parsing at render time, and
        // avoids issues with quote escaping in the C++ serialized JSON. We just have to be concerned with escaping
        // HTML tags to ensure none of our blocks get closed.

        // clang-format off
        os << R"(
            <!doctype html>
            <html lang="en">
            <head>
                <meta charset="utf-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Plotly++ Plot</title>
                <style>
                    #plot { width: 100vw; height: 100vh; }
                </style>
                <!--  Try to load plotly JS from a local pre-defined location. If that fails, try an alternate local -->
                <!-- location and fallback to a CDN. -->
                <script src="./js/plotly.min.js"></script>
                <script>
                    if (typeof Plotly === 'undefined') {
                        document.write('<script src="./plotly.min.js"><\/script>');
                        document.write('<script src="https://cdn.plot.ly/plotly-3.0.1.min.js"><\/script>');
                    }
                </script>
            </head>
            <body>
                <div id="plot"></div>
                <script>
                    const data = )" << html_safe_serialize(_json["data"]) << R"(;
                    const layout = )" << html_safe_serialize(_json["layout"]) << R"(;
                    const plotDiv = document.getElementById('plot');
                    Plotly.newPlot(plotDiv, data, layout);
                    // Throttle redrawing to occur no more faster than the browser can repaint.
                    let resizing = false;
                    window.addEventListener('resize', () => {
                        if (!resizing) {
                            resizing = true;
                            window.requestAnimationFrame(() => {
                                // Drawing a new plot appears more responsize than Plotly.Plots.resize() or
    Plotly.relayout
                                // The size already known/fixed by the #plot style.
                                Plotly.newPlot(plotDiv, data, layout);
                                resizing = false;
                            });
                        }
                    });
                </script>
            </body>
            </html>)";
        // clang-format on
    }

    static void writePlotlyJsResourceFile(const std::filesystem::path& outputDir) {
        std::filesystem::create_directories(outputDir / "js");
        std::ofstream jsFile(outputDir / "js" / "plotly.min.js");
        jsFile << plotlyJS;
    }

    void writeHtml(const std::filesystem::path& outputFilePath, bool includeJsResources = true) const {
        if (includeJsResources) {
            writePlotlyJsResourceFile(outputFilePath.parent_path());
        }
        std::ofstream outputFile(outputFilePath);
        toHtml(outputFile);
    }

    void show() const {
        const auto tempFile =
            std::filesystem::temp_directory_path() / ("plotlypp_plot_" + std::to_string(_showCount++) + ".html");
        writeHtml(tempFile);
        showInBrowser(tempFile.string());
    }

    const Json& json() const& { return _json; }
    Json json() && { return std::move(_json); }

    std::string html() const {
        std::stringstream ss;
        toHtml(ss);
        return ss.str();
    }

 private:
    void showInBrowser(const std::string& plotFile) const {
        std::cout << "opening " << plotFile << "\n";
#ifdef _WIN32
        system(("cmd /C start " + plotFile).c_str());
#elif __APPLE__
        system(("open " + plotFile).c_str());
#elif __linux__
        // On some systems, using `system` opens a text editor rather than a web browser, for unknown reasons.
        if (auto* pipe = popen(("xdg-open " + plotFile).c_str(), "r"); pipe) {
            pclose(pipe);
        }
#else
        // Force a linker error, only if this function is actually called.
        unimplementedPlatorm();
#endif
    }
    void unimplementedPlatorm();

    Json _json{{"data", {}}, {"layout", {}}};
    inline static int _showCount = 0;
};

} // namespace plotlypp
