#include <sstream>
#include <string>

#include <nlohmann/json.hpp>


namespace plotlypp {


class Figure {
public:
    // TODO: constrain
    template <typename T>
    Figure& addTrace(T trace) {
        _json["data"].push_back(std::move(trace.json));
        return *this;
    }

    std::string toHtml() {
        std::ostringstream html;
        html << "<head>\n"
                "   <script src=\"https://cdn.plot.ly/plotly-2.31.1.min.js\"></script>\n"
                "</head>\n"
                "<body>\n"
                "   <div id=\"plot\"></div>\n"
                "   <script>\n"
                "       data = JSON.parse('" << _json.dump() << "')\n"
                "       Plotly.newPlot('plot', data);\n"
                "   </script>\n"
                "</body>\n";
        return html.str();
    }




private:

    nlohmann::json _json;

};


}
