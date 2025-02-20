#include <scatter.hpp>
#include <scatter3d.hpp>
#include <surface.hpp>
#include <plot.hpp>

#include <iostream>


// x_data = [1, 2, 3, 4, 5]
// y_data = [3, 6, 4, 7, 5]
// x_error = [0.2, 0.3, 0.1, 0.4, 0.2]
// y_error = [0.5, 0.8, 0.3, 0.6, 0.4]

// # Create the scatter plot with error bars
// data2 = go.Scatter(
//     x=x_data,
//     y=y_data,
//     mode='markers',
//     error_x=dict(type='data', array=x_error, visible=True),
//     error_y=dict(type='data', array=y_error, visible=True)
// )


std::vector<double> linspace(double start, double stop, int points) {
    auto step = (stop - start) / points;
    std::vector<double> out(points);
    for (int i = 0; i < points; ++i) {
        out[i] = start + step * i;
    }
    return out;
}

plotlypp::Figure gensurface() {
    using namespace plotlypp;

    std::vector<std::vector<double>> z;
    z.push_back({8.83,8.89,8.81,8.87,8.9,8.87});
    z.push_back({8.89,8.94,8.85,8.94,8.96,8.92});
    z.push_back({8.84,8.9,8.82,8.92,8.93,8.91});
    z.push_back({8.79,8.85,8.79,8.9,8.94,8.92});
    z.push_back({8.79,8.88,8.81,8.9,8.95,8.92});
    z.push_back({8.8,8.82,.78,8.91,8.94,8.92});
    z.push_back({8.75,8.78,8.77,8.91,8.95,8.92});
    z.push_back({8.8,8.8,8.77,8.91,8.95,8.94});
    z.push_back({8.74,8.81,8.76,8.93,8.98,8.99});
    z.push_back({8.89,8.99,8.92,9.1,9.13,9.11});
    z.push_back({8.97,8.97,8.91,9.09,9.11,9.11});
    z.push_back({9.04,9.08,9.05,9.25,9.28,9.27});
    z.push_back({9,9.01,9,9.2,9.23,9.2});
    z.push_back({8.99,8.99,8.98,9.18,9.2,9.19});
    z.push_back({8.93,8.97,8.97,9.18,9.2,9.1});

    std::vector<std::vector<double>> z2;
    std::vector<std::vector<double>> z3;
    for (const auto& r : z) {
        std::vector<double> r2;
        std::vector<double> r3;
        for (auto e : r) {
            r2.push_back(e+1);
            r3.push_back(e-1);
        }
        z2.push_back(std::move(r2));
        z3.push_back(std::move(r3));
    }

    auto surface1 = Surface().z(std::move(z));
    auto surface2 = Surface().z(std::move(z2)).showscale(false).opacity(0.9);
    auto surface3 = Surface().z(std::move(z3)).showscale(false).opacity(0.9);

    auto fig = Figure().addTrace(std::move(surface1)).addTrace(std::move(surface2)).addTrace(std::move(surface3));
    return fig;

}

int main() {
    using namespace plotlypp;

    auto scatter = plotlypp::Scatter().x(std::vector{1, 2, 3, 4, 5}).y(std::vector{2, 4, 1, 3, 5}).mode("markers").name("Markers plt");
    auto error_x = plotlypp::Scatter::Error_x().visible(true).array(std::vector{0.2, 0.3, 0.1, 0.4, 0.2});
    auto error_y = plotlypp::Scatter::Error_y().visible(true).array(std::vector{0.5, 0.8, 0.3, 0.6, 0.4});
    auto scatter2 = plotlypp::Scatter().x(std::vector{1, 2, 3, 4, 5}).y(std::vector{3, 6, 4, 7, 5}).error_x(std::move(error_x)).error_y(std::move(error_y));
    std::cout << scatter.json << "\n";
    auto fig = plotlypp::Figure().addTrace(std::move(scatter)).addTrace(std::move(scatter2));
    std::cout << fig.toHtml();

    auto t = linspace(0, 10, 50);
    std::vector<double> x;
    std::vector<double> y;
    for (auto t_val : t) {
        x.push_back(std::cos(t_val));
        y.push_back(std::sin(t_val));
    }

    std::cout << Figure().addTrace(Scatter3d().x(x).y(y).z(t).mode("markers")).toHtml();
    Figure().addTrace(Scatter3d().x(x).y(y).z(t).mode("markers")).show();

    gensurface().show();
    //system("open ../sample.html");
    std::cout << "Done" << "\n";

}
