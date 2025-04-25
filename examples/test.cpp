#include <plotlypp/traces/mesh3d.hpp>
#include <plotlypp/plot.hpp>
#include <plotlypp/traces/scatter.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/surface.hpp>
#include <plotlypp/traces/scattermap.hpp>

#include <cmath>
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
    auto step = (stop + 1 - start) / points;
    std::vector<double> out(points);
    for (int i = 0; i < points; ++i) {
        out[i] = start + step * i;
    }
    return out;
}

// Eigen would probably simplify this a lot.
std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> meshgrid(const std::vector<double>& x,
                                                                                       const std::vector<double>& y) {
    std::vector<std::vector<double>> xgrid(y.size(), std::vector<double>(x.size()));
    std::vector<std::vector<double>> ygrid(y.size(), std::vector<double>(x.size()));

    for (size_t i = 0; i < y.size(); ++i) {
        for (size_t j = 0; j < x.size(); ++j) {
            xgrid[i][j] = x[j];
            ygrid[i][j] = y[i];
        }
    }
    return {std::move(xgrid), std::move(ygrid)};
}

plotlypp::Figure gen3dScatterHelix() {
    // with color scale and marker syling
    using namespace plotlypp;

    auto t = linspace(0, 20, 100);
    std::vector<double> x;
    std::vector<double> y;
    for (auto t_val : t) {
        x.push_back(std::cos(t_val));
        y.push_back(std::sin(t_val));
    }

    return Figure().addTrace(Scatter3D()
                                 .x(std::move(x))
                                 .y(std::move(y))
                                 .z(t)
                                 .mode("markers")
                                 .marker(Scatter3D::Marker().size(12).color(t).colorscale("Viridis").opacity(0.8)));
}

plotlypp::Figure gen3dScatterBubblePlanets() {
    using namespace plotlypp;
    // TODO: add layout stuff
    std::vector<std::string> planets = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                                        "Saturn",  "Uranus", "Neptune", "Pluto"};
    std::vector distanceFromSun = {57.9, 108.2, 149.6, 227.9, 778.6, 1433.5, 2872.5, 4495.1, 5906.4};
    std::vector density = {5427, 5243, 5514, 3933, 1326, 687, 1271, 1638, 2095};
    std::vector gravity = {3.7, 8.9, 9.8, 3.7, 23.1, 9.0, 8.7, 11.0, 0.7};
    std::vector<double> planetDiameter = {4879, 12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370};
    std::vector<std::string> planetColors = {"rgb(135, 135, 125)", "rgb(210, 50, 0)",    "rgb(50, 90, 255)",
                                             "rgb(178, 0, 0)",     "rgb(235, 235, 210)", "rgb(235, 205, 130)",
                                             "rgb(55, 255, 217)",  "rgb(38, 0, 171)",    "rgb(255, 255, 255)"};

    return Figure().addTrace(Scatter3D()
                                 .x(std::move(distanceFromSun))
                                 .y(std::move(density))
                                 .z(std::move(gravity))
                                 .text(std::move(planets))
                                 .mode("markers")
                                 .marker(Scatter3D::Marker()
                                             .sizemode(Scatter3D::Marker::Sizemode::DIAMETER)
                                             .sizeref(750)
                                             .size(std::move(planetDiameter))
                                             .color(std::move(planetColors))));
}

plotlypp::Figure gen3dSurfaces() {
    using namespace plotlypp;

    std::vector<std::vector<double>> z;
    z.push_back({8.83, 8.89, 8.81, 8.87, 8.9, 8.87});
    z.push_back({8.89, 8.94, 8.85, 8.94, 8.96, 8.92});
    z.push_back({8.84, 8.9, 8.82, 8.92, 8.93, 8.91});
    z.push_back({8.79, 8.85, 8.79, 8.9, 8.94, 8.92});
    z.push_back({8.79, 8.88, 8.81, 8.9, 8.95, 8.92});
    z.push_back({8.8, 8.82, 8.78, 8.91, 8.94, 8.92});
    z.push_back({8.75, 8.78, 8.77, 8.91, 8.95, 8.92});
    z.push_back({8.8, 8.8, 8.77, 8.91, 8.95, 8.94});
    z.push_back({8.74, 8.81, 8.76, 8.93, 8.98, 8.99});
    z.push_back({8.89, 8.99, 8.92, 9.1, 9.13, 9.11});
    z.push_back({8.97, 8.97, 8.91, 9.09, 9.11, 9.11});
    z.push_back({9.04, 9.08, 9.05, 9.25, 9.28, 9.27});
    z.push_back({9, 9.01, 9, 9.2, 9.23, 9.2});
    z.push_back({8.99, 8.99, 8.98, 9.18, 9.2, 9.19});
    z.push_back({8.93, 8.97, 8.97, 9.18, 9.2, 9.1});

    std::vector<std::vector<double>> z2;
    std::vector<std::vector<double>> z3;
    for (const auto& r : z) {
        std::vector<double> r2;
        std::vector<double> r3;
        for (auto e : r) {
            r2.push_back(e + 1);
            r3.push_back(e - 1);
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

plotlypp::Figure gen3dSurfaceContours() {
    using namespace plotlypp;
    std::vector x = {1, 2, 3, 4, 5};
    std::vector y = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> z = {
        {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0},
    };
    auto xContours = Surface::Contours::X().show(true).start(1.5).end(2).size(0.04).color("white");
    auto zContours = Surface::Contours::Z().show(true).start(0.5).end(0.8).size(0.05);
    auto surface = Surface()
                       .x(std::move(x))
                       .y(std::move(y))
                       .z(std::move(z))
                       .contours(Surface::Contours().x(std::move(xContours)).z(std::move(zContours)));
    return Figure().addTrace(std::move(surface));
}

// Torus
// using Plots; plotlyjs()

// Θ = ϕ = range(-π,π,300)
// X = [(2 + cos(v)) * cos(u) for u in Θ, v in ϕ]
// Y = [(2 + cos(v)) * sin(u) for u in Θ, v in ϕ]
// Z = [1.5*sin(v) for u in Θ, v in ϕ]
// surface(X, Y, Z, lims=(-3,3), size=(600,600), cbar=:none, legend=false, )

plotlypp::Figure gen3dSurfaceTorus() {
    using namespace plotlypp;
    auto u = linspace(0, 2 * M_PI, 50);
    auto v = u;
    auto [ugrid, vgrid] = meshgrid(u, v);

    // Eigen or something with vectorized ops would greatly simplify this.

    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> y;
    std::vector<std::vector<double>> z;
    for (auto r = 0; r < ugrid.size(); ++r) {
        std::vector<double> xr;
        std::vector<double> yr;
        std::vector<double> zr;
        for (auto c = 0; c < ugrid[0].size(); ++c) {
            xr.push_back((5 + 2 * std::cos(vgrid[r][c])) * std::cos(ugrid[r][c]));
            yr.push_back((5 + 2 * std::cos(vgrid[r][c])) * std::sin(ugrid[r][c]));
            zr.push_back(2 * std::sin(vgrid[r][c]));
        }
        x.push_back(std::move(xr));
        y.push_back(std::move(yr));
        z.push_back(std::move(zr));
    }
    return Figure().addTrace(Surface().x(std::move(x)).y(std::move(y)).z(std::move(z)));
}

plotlypp::Figure genMesh3dTetrahedron() {
    using namespace plotlypp;

    // Intensity of each vertex, which will be interpolated and color-coded.
    std::vector intensity = {0., 0.33, 0.66, 1.};
    // i, j and k give the vertices of triangles
    //  here we represent the 4 triangles of the tetrahedron surface
    std::vector i = {0, 0, 0, 1};
    std::vector j = {1, 2, 3, 2};
    std::vector k = {2, 3, 1, 3};

    using colorscale_t = std::vector<std::pair<double, std::string>>;

    auto mesh = Mesh3D()
                    .x(std::vector{0, 1, 2, 0})
                    .y(std::vector{0, 0, 1, 2})
                    .z(std::vector{0, 2, 0, 1})
                    .intensity(std::move(intensity))
                    .i(std::move(i))
                    .j(std::move(j))
                    .k(std::move(k))
                    .colorbar(Mesh3D::Colorbar().title(Mesh3D::Colorbar::Title().text("z")))
                    .colorscale(colorscale_t{{0, "gold"}, {0.5, "mediumturquoise"}, {1, "magenta"}})
                    .name("y")
                    .showscale(true);

    return Figure().addTrace(std::move(mesh));
}

// fig = go.Figure(go.Scattermap(
//     mode = "markers+text+lines",
//     lon = [-75, -80, -50], lat = [45, 20, -20],
//     marker = {'size': 20, 'symbol': ["bus", "harbor", "airport"]},
//     text = ["Bus", "Harbor", "airport"], textposition = "bottom right",
//     textfont = dict(size=18, color="black", family="Open Sans Bold")
//     ))

plotlypp::Figure genScatterMap() {
    using namespace plotlypp;
    // TODO layout stuff

    return Figure().addTrace(Scattermap()
                                 .mode("markers+text+lines")
                                 .lon(std::vector{-75, -80, -50})
                                 .lat(std::vector{45, 20, -20})
                                 .marker(Scattermap::Marker()
                                    .size(20)
                                    .symbol(std::vector<std::string>{"bus", "harbor", "airport"}))
                                 .text(std::vector<std::string>{"Bus", "Harbor", "Airport"})
                                 .textposition(Scattermap::Textposition::BOTTOM_RIGHT)
                                 .textfont(Scattermap::Textfont().size(18).color("black").family("Open Sans Bold")));
}



int main() {
    using namespace plotlypp;

    auto scatter = plotlypp::Scatter()
                       .x(std::vector{1, 2, 3, 4, 5})
                       .y(std::vector{2, 4, 1, 3, 5})
                       .mode("markers")
                       .name("Markers plt");
    auto error_x = plotlypp::Scatter::Error_X().visible(true).array(std::vector{0.2, 0.3, 0.1, 0.4, 0.2});
    auto error_y = plotlypp::Scatter::Error_Y().visible(true).array(std::vector{0.5, 0.8, 0.3, 0.6, 0.4});
    auto scatter2 = plotlypp::Scatter()
                        .x(std::vector{1, 2, 3, 4, 5})
                        .y(std::vector{3, 6, 4, 7, 5})
                        .error_x(std::move(error_x))
                        .error_y(std::move(error_y));
    std::cout << scatter.json << "\n";
    auto fig = plotlypp::Figure().addTrace(std::move(scatter)).addTrace(std::move(scatter2));
    std::cout << fig.toHtml();

    // std::cout << Figure().addTrace(Scatter3d().x(x).y(y).z(t).mode("markers")).toHtml();
    // Figure().addTrace(Scatter3d().x(x).y(y).z(t).mode("markers")).show();

    // gen3dSurfaces().show();
    // gen3dSurfaces().show(true);
    // gen3dScatterHelix().show();
    // gen3dSurfaceContours().show();
    // genMesh3dTetrahedron().show();
    //gen3dSurfaceTorus().show();
    //gen3dScatterBubblePlanets().show();
    genScatterMap().show();
    // system("open ../sample.html");
    std::cout << "Done" << "\n";
}
