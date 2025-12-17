// Copyright (c) 2025 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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

    void toHtml(std::ostream& os) {
        // clang-format off
        os << "<meta charset=\"utf-8\">\n"
              "<head>\n"
              // Try to load plotly JS from a local pre-defined location. If that fails, try an alternate local
              // location and fallback to a CDN.
              "    <script src=\"./js/plotly.min.js\"></script>\n"
              "    <script>\n"
              "        if (typeof Plotly === 'undefined') {\n"
              "            document.write('<script src=\"./plotly.min.js\">\\x3C/script>')\n"
              "            document.write('<script src=\"https://cdn.plot.ly/plotly-3.0.1.min.js\">\\x3C/script>')\n"
              "        }\n"
              "    </script>\n"
              "</head>\n"
              "<body>\n"
              "    <div id=\"plot\"></div>\n"
              "    <script>\n"
              "        function resizeDiv() {\n"
              "            const div = document.getElementById('plot');\n"
              "            div.style.width = window.innerWidth;\n"
              "            div.style.height = window.innerHeight;\n"
              "            data = JSON.parse('" << serialize(_json["data"]) << "')\n"
              "            layout = JSON.parse('" << serialize(_json["layout"]) << "')\n"
              "            Plotly.newPlot('plot', data, layout);\n"
              "        }\n"
              "        // Call resizeDiv initially to set the size on page load.\n"
              "        resizeDiv();\n"
              "        // Add an event listener to the window's resize event.\n"
              "        window.addEventListener('resize', resizeDiv);\n"
              "    </script>\n"
              "</body>\n";
        // clang-format on
    }

    void writePlotlyJsResourceFile(const std::filesystem::path& outputDir) {
        std::filesystem::create_directories(outputDir / "js");
        std::ofstream jsFile(outputDir / "js" / "plotly.min.js");
        jsFile << plotlyJS;
    }

    void writeHtmlFigure(const std::filesystem::path& outputFilePath, bool includeJsResources = true) {
        if (includeJsResources) {
            writePlotlyJsResourceFile(outputFilePath.parent_path());
        }
        std::ofstream outputFile(outputFilePath);
        toHtml(outputFile);
    }

    void show() {
        const auto tempFile =
            std::filesystem::temp_directory_path() / ("plotlypp_plot_" + std::to_string(_showCount++) + ".html");
        writeHtmlFigure(tempFile);
        showInBrowser(tempFile.string());
    }

 private:
    void showInBrowser(const std::string& plotFile) {
        std::cout << "opening " << plotFile << "\n";
#ifdef _WIN32
        system(("cmd /C start " + plotFile).c_str());
#elif __APPLE__
        system(("open " + plotFile).c_str());
#elif __linux__
        // On some systems, using `system` opens a text editor rather than a web browser, for unknown reasons.
        popen(("xdg-open " + plotFile).c_str(), "r");
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
