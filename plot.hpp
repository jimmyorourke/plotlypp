#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <json.hpp>

#include "plotly_min_js.h"

namespace plotlypp {

class Figure {
 public:
    template <typename T, typename = std::enable_if_t<std::is_base_of_v<Trace, T>>>
    Figure& addTrace(T trace) {
        _json["data"].push_back(std::move(trace.json));
        return *this;
    }

    void toHtml(std::ostream& os, bool renderOffline = false) {
        os << "<meta charset=\"utf-8\">\n";
        os << "<head>\n";
        if (renderOffline) {
            os << "    <script>\n";
            os << plotlyJS << "\n";
            os << "    </script>\n";
        } else {
            // TODO: check versions;
            os << "    <script src=\"https://cdn.plot.ly/plotly-3.0.1.min.js\"></script>\n";
        }
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
        os << "        }";
        os << "        // Call resizeDiv initially to set the size on page load.\n";
        os << "        resizeDiv();\n";
        os << "        // Add an event listener to the window's resize event.\n";
        os << "        window.addEventListener('resize', resizeDiv);\n";
        os << "    </script>\n";
        os << "</body>\n";
    }

    std::string toHtml(bool renderOffline = false) {
        std::ostringstream html;
        toHtml(html, renderOffline);
        return html.str();
    }

    void show(bool renderOffline = false) {
        const auto tempFile =
            std::filesystem::temp_directory_path() / ("plotlypp_plot_" + std::to_string(_showCount++) + ".html");
        std::cout << "creating " << tempFile << "\n";
        std::ofstream outputFile(tempFile);
        toHtml(outputFile, renderOffline);
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
        system(("xdg-open " + plotFile).c_str());
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
