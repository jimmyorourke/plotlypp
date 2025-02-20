#pragma once

#include <sstream>
#include <string>
#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

namespace plotlypp {

class Figure {
 public:
    template <typename T, typename=std::enable_if_t<std::is_base_of_v<Trace, T>>>
    Figure& addTrace(T trace) {
        _json["data"].push_back(std::move(trace.json));
        return *this;
    }

    void toHtml(std::ostream& os) {
        // clang-format off
        os << "<meta charset=\"utf-8\">\n";
        os << "<head>\n";
        os << "    <script src=\"https://cdn.plot.ly/plotly-2.31.1.min.js\"></script>\n";
        os << "</head>\n";
        os << "<body>\n";
        os << "    <div id=\"plot\"></div>\n";
        os << "    <script>\n";
        os << "        function resizeDiv() {\n";
        os << "            const div = document.getElementById('plot');\n";
        os << "            div.style.width = window.innerWidth;\n";
        os << "            div.style.height = window.innerHeight;\n";
        os << "            data = JSON.parse('" << _json.dump() << "')\n";
        os << "            Plotly.newPlot('plot', data);\n";
        os << "        }";
        os << "        // Call resizeDiv initially to set the size on page load.\n";
        os << "        resizeDiv();\n";
        os << "        // Add an event listener to the window's resize event.\n";
        os << "        window.addEventListener('resize', resizeDiv);\n";
        os << "    </script>\n";
        os << "</body>\n";
        // clang-format on
    }

    std::string toHtml() {
        std::ostringstream html;
        toHtml(html);
        return html.str();
    }

    void show() {
      const auto temp_file = std::filesystem::temp_directory_path() / "plotlypp_plot.html";
      std::ofstream outputFile(temp_file);
      toHtml(outputFile);
      showInBrowser(temp_file.string());
    }

 private:
    void showInBrowser(const std::string& plot_file) {
      #ifdef _WIN32
        system(("cmd /C start " + plot_file).c_str());
      #elif __APPLE__
        system(("open " + plot_file).c_str());
      #elif __linux__
        system(("xdg-open " + plot_file).c_str());
      #else
        // Force a linker error, only if this function is actually called.
        unimplementedPlatorm();
      #endif
    }
    void unimplementedPlatorm();

    nlohmann::json _json;
};

} // namespace plotlypp
