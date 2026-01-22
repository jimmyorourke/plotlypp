# Pʟᴏᴛʟʏ++
[![CI MacOS Clang](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-macos-clang.yml/badge.svg)](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-macos-clang.yml) [![CI Ubuntu GCC](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-ubuntu-gcc.yml/badge.svg)](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-ubuntu-gcc.yml) [![CI Ubuntu Clang](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-ubuntu-clang.yml/badge.svg)](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-ubuntu-clang.yml) [![CI Windows MSVC](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-windows-msvc.yml/badge.svg)](https://github.com/jimmyorourke/plotlypp/actions/workflows/ci-windows-msvc.yml)

Plotly++ is a header-only C++ graphing library for creating interactive plots and charts, with rendering powered by [Plotly.js](https://plotly.com/javascript). Plots are generated as HTML, providing interactive visualizations that can be viewed in any modern web browser.

This makes Plotly++ extremely simple and lightweight for C++ applications; no graphics or rendering libraries or frameworks are required! Plotly++'s only additional dependency is a JSON library.

The Plotly++ API provides strong compile-time type safety, enabling active IDE auto-complete and suggestions.

The more than 40 chart types supported by Plotly.js are supported by Plotly++.

Plotly++ is largely auto-generated from the official Plotly.js schema.

<details>
<summary><b>Table of Contents</b></summary>

- [Examples](#examples)
- [Additional Documentation](#additional-documentation)
- [Dependencies](#dependencies)
- [Supported Data Types](#supported-data-types)
- [Offline Rendering](#offline-rendering)
- [Usage in Web Applications](#usage-in-web-applications)

</details>

## Examples

A comprehensive set of examples demonstrating various chart types can be found in the [`examples/`](./examples) directory and the generated interactive plots can be viewed live: **[View Live Examples](https://jimmyorourke.github.io/plotlypp/examples/output/)**

### Gallery

Each of the thumbnails below is chart from the the [`examples/`](./examples) directory. Click the thumbnail to open the interactive HTML version.

<table width="100%" cellspacing="0" cellpadding="0" style="border-collapse: collapse;">
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/area_polar_chart.html"><img src="./examples/output/png_exports/area_polar_chart.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/asymmetric_error_bars.html"><img src="./examples/output/png_exports/asymmetric_error_bars.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/basic_funnel.html"><img src="./examples/output/png_exports/basic_funnel.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/basic_horizontal_violin_plot.html"><img src="./examples/output/png_exports/basic_horizontal_violin_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/basic_overlaid_area.html"><img src="./examples/output/png_exports/basic_overlaid_area.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/basic_pie.html"><img src="./examples/output/png_exports/basic_pie.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/bubble_chart_sized_by_variable.html"><img src="./examples/output/png_exports/bubble_chart_sized_by_variable.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/bubble_with_marker_size_and_color.html"><img src="./examples/output/png_exports/bubble_with_marker_size_and_color.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/carpet_with_scatter_trace.html"><img src="./examples/output/png_exports/carpet_with_scatter_trace.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/categorical_dot_plot.html"><img src="./examples/output/png_exports/categorical_dot_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/colored_and_styled_histograms.html"><img src="./examples/output/png_exports/colored_and_styled_histograms.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/colored_box_plot.html"><img src="./examples/output/png_exports/colored_box_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/colorscale_for_contour_plot.html"><img src="./examples/output/png_exports/colorscale_for_contour_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/continuous_filled_error_bars.html"><img src="./examples/output/png_exports/continuous_filled_error_bars.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/data_labels_on_plot.html"><img src="./examples/output/png_exports/data_labels_on_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/donut.html"><img src="./examples/output/png_exports/donut.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen2d_histogram_bivariate_normal.html"><img src="./examples/output/png_exports/gen2d_histogram_bivariate_normal.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen2d_histogram_contour.html"><img src="./examples/output/png_exports/gen2d_histogram_contour.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen3d_line_spiral.html"><img src="./examples/output/png_exports/gen3d_line_spiral.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen3d_scatter_with_colorscaling_and_marker_styling.html"><img src="./examples/output/png_exports/gen3d_scatter_with_colorscaling_and_marker_styling.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen3d_subplots.html"><img src="./examples/output/png_exports/gen3d_subplots.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen3d_surface_contours.html"><img src="./examples/output/png_exports/gen3d_surface_contours.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/gen3d_surface_torus.html"><img src="./examples/output/png_exports/gen3d_surface_torus.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/grouped_bar.html"><img src="./examples/output/png_exports/grouped_bar.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/grouped_scatter.html"><img src="./examples/output/png_exports/grouped_scatter.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/horizontal_bar.html"><img src="./examples/output/png_exports/horizontal_bar.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/indicator.html"><img src="./examples/output/png_exports/indicator.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/inset_graph.html"><img src="./examples/output/png_exports/inset_graph.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/light_tile.html"><img src="./examples/output/png_exports/light_tile.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/line_and_scatter_with_names_axes_title.html"><img src="./examples/output/png_exports/line_and_scatter_with_names_axes_title.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/line_dashes.html"><img src="./examples/output/png_exports/line_dashes.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/lines_on_maps.html"><img src="./examples/output/png_exports/lines_on_maps.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/mesh_cube.html"><img src="./examples/output/png_exports/mesh_cube.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/mixed_subplots.html"><img src="./examples/output/png_exports/mixed_subplots.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/multiple_3d_isosurfaces.html"><img src="./examples/output/png_exports/multiple_3d_isosurfaces.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/multiple_3d_surface_plots.html"><img src="./examples/output/png_exports/multiple_3d_surface_plots.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/multiple_subplots_with_shared_axes.html"><img src="./examples/output/png_exports/multiple_subplots_with_shared_axes.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/multiple_trace_radar_chart.html"><img src="./examples/output/png_exports/multiple_trace_radar_chart.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/outline_map_locations.html"><img src="./examples/output/png_exports/outline_map_locations.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/scatter_tile_maps.html"><img src="./examples/output/png_exports/scatter_tile_maps.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
  <tr>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/scatter_with_color_dimension.html"><img src="./examples/output/png_exports/scatter_with_color_dimension.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/simple_volume_plot.html"><img src="./examples/output/png_exports/simple_volume_plot.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/smith_chart_subplots_with_stlying.html"><img src="./examples/output/png_exports/smith_chart_subplots_with_stlying.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/subplots_domain_layout.html"><img src="./examples/output/png_exports/subplots_domain_layout.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
    <td align="center" width="20%" valign="top" style="padding: 0px;">
      <a href="https://jimmyorourke.github.io/plotlypp/examples/output/subplots_grid_layout.html"><img src="./examples/output/png_exports/subplots_grid_layout.png" width="100%" style="border-radius: 0px; border: 1px solid #d0d7de;" /></a>
    </td>
  </tr>
</table>

### Creating a simple plot

```cpp
#include <plotlypp/figure.hpp>
#include <plotlypp/traces/scatter.hpp>

void linePlotWithMarkers() {
  using namespace plotlypp;

  std::vector x_data = {1, 2, 3, 4};
  std::vector y_data = {2, 4, 6, 8};

  // Plotly++ uses a fluent API.
  // Trace data (e.g. x, y, z, etc) can be provided as std::vector, std::array,
  // std::span (C++20+), or std::mdspan (C++23+). For custom types like Eigen, see the
  // "Supported Data Types" section of the README, below.
  // Plotly `flaglist` types are specfied with initializer lists. (mode setting is equivalent
  // to "markers+lines" in JavaScript or Python)
  auto scatter_and_lines = Scatter()
                             .x(x_data)
                             .y(y_data)
                             .mode({Scatter::Mode::Lines, Scatter::Mode::Markers})
                             .name("Lines & Markers");

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

  auto figure = Figure()
                  .addTrace(std::move(scatter_and_lines))
                  .setLayout(std::move(layout));

  // Open the plot in the default browser for interactive viewing.
  figure.show();

  // Save the plot to disk for interactive viewing at a later time.
  figure.writeHtml("line_plot_with_markers.html");
}
```

### Building and running the examples

```
cmake -S . -B build -G <your favourite generator>
cmake --build build
./build/examples/example
```

When included as part of a larger CMake project, the example target will not be built, unless `PLOTLYPP_BUILD_EXAMPLES` is set.

## Additional Documentation

Since much of Plotly++ is auto-generated from the Plotly.js schema, the official [Plotly.js documentation](https://plotly.com/javascript/) is the best source for additional documentation about trace and chart types and parameters and layout options.

IDE auto-complete and suggestion features are also highly beneficial when working with Plotly++.

## Dependencies

* C++17 or newer
* [nlohmann JSON](https://github.com/nlohmann/json)

The CMakeLists will attempt to use `find_package` to find `nlohmann_json` when Plotly++ is built as part of a larger project. When Plotly++ is the main project (eg for just building the examples), or if `find_package` fails to locate an existing installation, CMake will use `FetchContent` to download `nlohmann_json` to a project-local directory.

While not directly supported at present, nlohmann JSON could be swapped out for another JSON library will minimal work. Libraries with similar APIs such as Boost JSON could be substituted by updating the alias type in [json.hpp](include/plotlypp/json.hpp). For less similar libraries, and consistent [custom data type support](#supported-data-types), a stronger abstraction would be required.

If regenerating Plotly++ headers, Python3.6+ is required.

## Supported Data Types

Plotly++ accepts trace data (e.g., for `x`, `y`, `z` coordinates) in various container types holding arithmetic values or strings:

*   **1D Data**: `std::vector<T>`, `std::array<T,N>`, and (in C++20+) `std::span<T>`.
*   **2D Data**: `std::vector<std::vector<T>>`, and (in C++23+) `std::mdspan`.
*   **Custom Types**: You can extend Plotly++ to support other array-like types by specializing [`plotlypp::is_plotly_data_array_extension`](./include/plotlypp/traits.hpp). Any custom type passed to Plotly++ must additionally be serializable by nlohmann JSON into an appropriate JSON array format. See [nlohmann JSON's documentation](https://json.nlohmann.me/features/arbitrary_types/) for details on providing serialization support.
    The [`plotlypp/contrib/`](./include/plotlypp/contrib/) directory offers opt-in support providing these specializations for libraries not included as core Plotly++ dependencies. For example, to use [Eigen](https://libeigen.gitlab.io/) matrices/vectors as trace data, include [`contrib/eigen_support.hpp`](./include/plotlypp/contrib/eigen_support.hpp) and add Eigen as a dependency to your own build target; Plotly++ itself does not depend on Eigen.

Note: [examples/3d_charts.cpp](./examples/3d_charts.cpp) includes an example using Eigen (as well as std::mdspan), and as such the examples target depends on Eigen. CMake will use `FetchContent` to download Eigen to a project-local directory when the examples target is included to be built.

## Offline Rendering

The HTML emitted by Plotly++ requires the Plotly.js Javascript library in order to render in a web browser. Plotly++ prefers offline rendering when possible, so the HTML output instructs the web browser to first try to load Plotly.js from a local file in a `js` subdirectory of the HTML file's directory. Plotly++ emits the required file as `js/plotly.min.js` when `Figure.writeHtml()` is called with parameter `includeJsResources` set to true (the default). If the local Plotly.js file is not found, the Plotly++ HTML will try to acquire and use Plotly.js from the official CDN, requiring an internet connection unless your browser already has it cached.

## Usage in Web Applications

In addition to viewing and exporting local HTML plot files, Plotly++ can be used in C++ web server applications to dynamically generate plots for web clients. There are two possible approaches:

### 1. Generating full HTML

The server can generate a full, self-contained HTML page containing the plot and all necessary JavaScript, which the browser can render directly (the same page produced by `Figure.show()` and `Figure.writeHtml`). The `Figure.html()` method returns the plot as an HTML string, which can be sent in an HTTP response body with a `Content-Type: text/html` header.

### 2. Generating Plotly JSON Payload for Client-Side Rendering

Alternatively, the server can act as a JSON API endpoint and generate just the JSON required for the client to render with Plotly.js. The `Figure.json()` method returns the figure's JSON representation following the Plotly.js figure spec. The figure JSON can be serialized to string and sent in an HTTP response. The client-side page is required to load the Plotly.js library (eg from a CDN), fetch plot data from the server, and use `Plotly.newPlot()` to render the plot in the browser.

```cpp
// Server-side C++ pseudo-code for /api/plot-data endpoint:
auto figure = plotlypp::Figure().addTrace(plotlypp::Scatter().y(std::array{2,4,6}));
std::string json_content = figure.json().dump();
// send json_content as HTTP response...
```

```javascript
// Client-side JavaScript pseudo-code:
// Assumes Plotly.js is loaded and an element with id="plot-div" exists.
fetch('/api/plot-data')
    .then(response => response.json())
    .then(plotData => {
        Plotly.newPlot('plot-div', plotData.data, plotData.layout);
    });
```
