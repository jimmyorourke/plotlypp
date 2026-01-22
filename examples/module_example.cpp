#include <utility>
#include <vector>

import plotlypp;

int main() {
    using namespace plotlypp;

    std::vector x_data = {1, 2, 3, 4};
    std::vector y_data = {2, 4, 6, 8};

    // Plotly++ uses a fluent API.
    // Trace data (e.g. x, y, z, etc) can be provided as std::vector, std::array,
    // std::span (C++20+), or std::mdspan (C++23+). For custom types like Eigen, see the
    // "Supported Data Types" section of the README, below.
    // Plotly `flaglist` types are specfied with initializer lists. (mode setting is equivalent
    // to "markers+lines" in JavaScript or Python)
    auto scatter_and_lines =
        Scatter().x(x_data).y(y_data).mode({Scatter::Mode::Lines, Scatter::Mode::Markers}).name("Lines & Markers");

    // Nested types can get verbose, so a lambda-setter API is also available.
    // `title` uses the lambda API, `yaxis` uses the regular setter API, and `xaxis uses both.
    // Also note that adding a layout is optional.
    auto layout = Layout()
                      .title([](auto& t) { t.text("Title of the Graph"); })
                      .xaxis(Layout::Xaxis().title([](auto& t) { t.text("x-axis title"); }))
                      .yaxis(Layout::Yaxis().title(Layout::Yaxis::Title().text("y-axis title")));

    // `xaxis` could alternatively have used nested lambdas.
    layout.xaxis([](auto& x) { x.title([](auto& t) { t.text("New x-axis title"); }); });

    // If you think you really know what you're doing and want to give up type safety, a raw
    // JSON string API is also available.
    layout.yaxis({R"({"title": {"text": "New y-axis title"}})"});

    // The underlying nlohmann::json object can also be accessed and modified directly.
    layout.json["title"]["font"]["size"] = 24;

    auto figure = Figure().addTrace(std::move(scatter_and_lines)).setLayout(std::move(layout));

    // Open the plot in the default browser for interactive viewing.
    figure.show();

    // Save the plot to disk for interactive viewing at a later time.
    figure.writeHtml("line_plot_with_markers.html");

    return 0;
}
