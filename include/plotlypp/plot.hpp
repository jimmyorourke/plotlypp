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

    void toHtml(std::ostream& os) {
        os << "<meta charset=\"utf-8\">\n";
        os << "<head>\n";
        // Try to load plotly JS from CDN. If that fails, try to load a local copy from common pre-defined locations.
        os << "    <script src=\"https://cdn.plot.ly/plotly-3.0.1.min.js1\"></script>\n";
        os << "    <script>\n";
        os << "        if (typeof Plotly === 'undefined') {\n";
        os << "            document.write('<script src=\"./plotly.min.js\">\\x3C/script>')\n";
        os << "            document.write('<script src=\"./js/plotly.min.js\">\\x3C/script>')\n";
        os << "        }\n";
        os << "    </script>\n";
        os << "</head>\n";
        os << "<body>\n";
        os << "    <div id=\"plot\"></div>\n";
        os << "    <script>\n";
        os << "        function resizeDiv() {\n";
        os << "            const div = document.getElementById('plot');\n";
        os << "            div.style.width = window.innerWidth;\n";
        os << "            div.style.height = window.innerHeight;\n";
        os << "            data = JSON.parse('" << serialize(_json) << "')\n";
        os << "            Plotly.newPlot('plot', data);\n";
        os << "        }\n";
        os << "        // Call resizeDiv initially to set the size on page load.\n";
        os << "        resizeDiv();\n";
        os << "        // Add an event listener to the window's resize event.\n";
        os << "        window.addEventListener('resize', resizeDiv);\n";
        os << "    </script>\n";
        os << "</body>\n";
    }

    std::string toHtml() {
        std::ostringstream html;
        toHtml(html);
        return html.str();
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

    Json _json;
    inline static int _showCount = 0;
};

} // namespace plotlypp
