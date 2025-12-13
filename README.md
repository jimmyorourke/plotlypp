# Pʟᴏᴛʟʏ++

Plotly++ is a header-only C++ graphing library for creating interactive plots and charts, with rendering powered by [Plotly.js](https://plotly.com/javascript). Plots are generated as HTML, providing interactive visualizations that can be viewed in a web browser.

This makes Plotly++ extremely simple and lightweight for C++ applications; no graphics or rendering libraries or frameworks are required! Plotly++'s only additional dependency is a JSON library.

The more than 40 chart types supported by Plotly.js are supported by Plotly++.

Plotly++ is largely auto-generated from offical Plotly.js sources.

## Examples

TODO

### Building and running the examples

```
mkdir build && cd build
cmake -G <your favourite generator> ..
cmake --build .
./examples/example
```

## Additional Documentation

Since much of Plotly++ is auto-generated from Plotly.js sources, the official [Plotly.js documentation](https://plotly.com/javascript/) is the best source for additional documentation about trace and chart types and parameters and layout options.

## Dependencies

* C++17
* [nlohmann JSON](https://github.com/nlohmann/json)

The CMakeLists will attempt to use `find_package` to find `nlohmann_json` when Plotly++ is built as part of a larger project. When Plotly++ is the main project (eg for just building the examples), CMake will use `FetchContent` to download `nlohmann_json` to a project-local directory.

While not directly supported at present, nlohmann JSON could be swapped out for another JSON library will minimal work. Libraries with similar APIs such as Boost JSON could easily be swapped in by updating the alias type in [json.hpp](include/plotlypp/json.hpp). For less similar libraries a stronger abstraction would be required.

If regenerating Plotly++ headers, Python3.6+ is required.

## Offline Rendering

The HTML emitted by Plotly++ requires the Plotly.js Javascript library in order to render in a web browser. Plotly++ prefers offline rendering when possible, so the HTML output instructs the web browser to first try to load Plotly.js from a local file in a `js` subdirectory of the HTML file's directory. Plotly++ emits the required file as `js/plotly.min.js` when `Figure.writeHtmlFigure()` is called with parameter `includeJsResources` set to true (the default). If the local Plotly.js file is not found, the Plotly++ HTML will try to acquire and use Plotly.js from the official CDN, requiring an internet connection unless your browser already has it cached.
