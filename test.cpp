#include <scatter.hpp>
#include <scatter3d.hpp>
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



}
