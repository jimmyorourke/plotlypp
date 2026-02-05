// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "3d_charts.hpp"

#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <vector>

#if __cplusplus >= 202002L
#include <version>
// If std::mdspan is available (typically requires C++23), include support for it.
#if defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L
#include <mdspan>
#define PLOTLY_PP_MDSPAN
#endif
#endif

// For this specific example set we are also going to demonstrate using Eigen.
// This means we need to explicitly also pull in the Eigen support header.
#include <Eigen/Core>
#include <plotlypp/contrib/eigen_support.hpp>

#include <math_utils.hpp>
#include <plotlypp/figure.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/isosurface.hpp>
#include <plotlypp/traces/mesh3d.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/surface.hpp>
#include <plotlypp/traces/volume.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/3d-surface-plots/

Figure multiple3DSurfacePlots() {
#ifdef PLOTLY_PP_MDSPAN
    constexpr size_t rows = 15;
    constexpr size_t cols = 6;
    std::array<std::array<double, cols>, rows> z1_data = {{{8.83, 8.89, 8.81, 8.87, 8.9, 8.87},
                                                           {8.89, 8.94, 8.85, 8.94, 8.96, 8.92},
                                                           {8.84, 8.9, 8.82, 8.92, 8.93, 8.91},
                                                           {8.79, 8.85, 8.79, 8.9, 8.94, 8.92},
                                                           {8.79, 8.88, 8.81, 8.9, 8.95, 8.92},
                                                           {8.8, 8.82, 8.78, 8.91, 8.94, 8.92},
                                                           {8.75, 8.78, 8.77, 8.91, 8.95, 8.92},
                                                           {8.8, 8.8, 8.77, 8.91, 8.95, 8.94},
                                                           {8.74, 8.81, 8.76, 8.93, 8.98, 8.99},
                                                           {8.89, 8.99, 8.92, 9.1, 9.13, 9.11},
                                                           {8.97, 8.97, 8.91, 9.09, 9.11, 9.11},
                                                           {9.04, 9.08, 9.05, 9.25, 9.28, 9.27},
                                                           {9, 9.01, 9, 9.2, 9.23, 9.2},
                                                           {8.99, 8.99, 8.98, 9.18, 9.2, 9.19},
                                                           {8.93, 8.97, 8.97, 9.18, 9.2, 9.18}}};
    // We can create an mdspan view directly from the contiguous memory from array of arrays.
    // mdspan's default layout_right matches std::array<std::array<...>>.
    std::mdspan<const double, std::dextents<size_t, 2>> z1(&z1_data[0][0], rows, cols);
    // For simplicity of example, just use one mdspan, and use nested vectors for z2 and z3.
#else
    // Without mdspan support, use nested vectors.
    std::vector<std::vector<double>> z1 = {{8.83, 8.89, 8.81, 8.87, 8.9, 8.87},  {8.89, 8.94, 8.85, 8.94, 8.96, 8.92},
                                           {8.84, 8.9, 8.82, 8.92, 8.93, 8.91},  {8.79, 8.85, 8.79, 8.9, 8.94, 8.92},
                                           {8.79, 8.88, 8.81, 8.9, 8.95, 8.92},  {8.8, 8.82, 8.78, 8.91, 8.94, 8.92},
                                           {8.75, 8.78, 8.77, 8.91, 8.95, 8.92}, {8.8, 8.8, 8.77, 8.91, 8.95, 8.94},
                                           {8.74, 8.81, 8.76, 8.93, 8.98, 8.99}, {8.89, 8.99, 8.92, 9.1, 9.13, 9.11},
                                           {8.97, 8.97, 8.91, 9.09, 9.11, 9.11}, {9.04, 9.08, 9.05, 9.25, 9.28, 9.27},
                                           {9, 9.01, 9, 9.2, 9.23, 9.2},         {8.99, 8.99, 8.98, 9.18, 9.2, 9.19},
                                           {8.93, 8.97, 8.97, 9.18, 9.2, 9.18}};
    // To keep the iteration below consistent, just for this example, make a copy so the same name is available.
    auto z1_data = z1;
#endif

    std::vector<std::vector<double>> z2;
    for (const auto& row : z1_data) {
        std::vector<double> z2_row;
        for (double v : row) {
            z2_row.push_back(v + 1);
        }
        z2.push_back(std::move(z2_row));
    }

    std::vector<std::vector<double>> z3;
    for (const auto& row : z1_data) {
        std::vector<double> z3_row;
        for (double v : row) {
            z3_row.push_back(v - 1);
        }
        z3.push_back(std::move(z3_row));
    }

    auto trace1 = Surface().z(z1);
    auto trace2 = Surface().z(z2).showscale(false).opacity(0.9);
    auto trace3 = Surface().z(z3).showscale(false).opacity(0.9);
    return Figure().addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)});
}

Figure gen3dSurfaceContours() {
    std::vector x = {1, 2, 3, 4, 5};
    std::vector y = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> z = {
        {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0},
    };
    auto xContours = Surface::Contours::X().show(true).start(1.5).end(2).size(0.04).color("white");
    auto zContours = Surface::Contours::Z().show(true).start(0.5).end(0.8).size(0.05);
    auto surface = Surface().x(x).y(y).z(z).contours(Surface::Contours().x(xContours).z(zContours));
    return Figure().addTrace(std::move(surface));
}

Figure gen3dSurfaceTorus() {
    constexpr int kNumPoints = 50;
    auto u_vec = math_utils::linspace(0, 2 * /*pi=*/std::acos(-1.0), kNumPoints);
    auto v_vec = u_vec;
    auto [ugrid, vgrid] = math_utils::meshgrid(u_vec, v_vec);

    // This example demonstrates using Eigen matrices as trace inputs. While the nested loops are still suboptimal (due
    // to the meshgrid implementation using nested vectors), Eigen is still leveraged for the vectorized trigonometric
    // operations.

    Eigen::MatrixXd u(kNumPoints, kNumPoints);
    Eigen::MatrixXd v(kNumPoints, kNumPoints);
    for (auto i = 0u; i < kNumPoints; ++i) {
        for (auto j = 0u; j < kNumPoints; ++j) {
            u(i, j) = ugrid[i][j];
            v(i, j) = vgrid[i][j];
        }
    }

    Eigen::MatrixXd x(kNumPoints, kNumPoints);
    Eigen::MatrixXd y(kNumPoints, kNumPoints);
    Eigen::MatrixXd z(kNumPoints, kNumPoints);

    x = (5 + 2 * v.array().cos()) * u.array().cos();
    y = (5 + 2 * v.array().cos()) * u.array().sin();
    z = 2 * v.array().sin();

    return Figure().addTrace(Surface().x(x).y(y).z(z));
}

// Based on examples from https://plotly.com/javascript/3d-mesh/ and https://plotly.com/python/3d-mesh/

Figure meshCube() {
    std::vector<std::pair<double, std::string>> colorscale = {{0, "gold"}, {0.5, "mediumturquoise"}, {1, "magenta"}};
    auto trace = Mesh3D()
                     // 8 vertices of a cube.
                     .x(std::vector{0, 0, 1, 1, 0, 0, 1, 1})
                     .y(std::vector{0, 1, 1, 0, 0, 1, 1, 0})
                     .z(std::vector{0, 0, 0, 0, 1, 1, 1, 1})
                     // i, j and k give the vertices of triangles.
                     .i(std::vector{7, 0, 0, 0, 4, 4, 6, 6, 4, 0, 3, 2})
                     .j(std::vector{3, 4, 1, 2, 5, 6, 5, 2, 0, 1, 6, 3})
                     .k(std::vector{0, 7, 2, 3, 6, 7, 1, 1, 5, 5, 7, 6})
                     // Intensity of each vertex, which will be interpolated and color-coded.
                     .intensity(std::vector<double>{0, 0.14285714285714285, 0.2857142857142857, 0.42857142857142855,
                                                    0.5714285714285714, 0.7142857142857143, 0.8571428571428571, 1})
                     .colorscale(std::move(colorscale));
    return Figure().addTrace(std::move(trace));
}

// Based on examples from https://plotly.com/javascript/3d-line-plots/

Figure gen3dLineSpiral() {
    int point_count = 3142;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> c;
    for (int i = 0; i < point_count; i++) {
        double r = i * (point_count - i);
        x.push_back(r * std::cos(i / 30.0));
        y.push_back(r * std::sin(i / 30.0));
        z.push_back(i);
        c.push_back(i);
    }
    return Figure().addTrace(Scatter3D()
                                 .x(x)
                                 .y(y)
                                 .z(z)
                                 .mode({Scatter3D::Mode::Lines})
                                 .opacity(0.7)
                                 .line(Scatter3D::Line().width(10).color(std::move(c)).colorscale("Viridis")));
}

// Based on examples from https://plotly.com/python/3d-scatter-plots/

Figure gen3dScatterWithColorscalingAndMarkerStyling() {
    // Helix equation.
    auto t = math_utils::linspace(0, 20, 100);
    std::vector<double> x;
    std::vector<double> y;
    for (auto t_val : t) {
        x.push_back(std::cos(t_val));
        y.push_back(std::sin(t_val));
    }

    return Figure()
        .addTrace(Scatter3D()
                      .x(x)
                      .y(y)
                      .z(t)
                      .mode({Scatter3D::Mode::Markers})
                      .marker(Scatter3D::Marker().size(12).color(t).colorscale("Viridis").opacity(0.8)))
        .setLayout(Layout().margin(Layout::Margin().l(0).r(0).b(0).t(0)));
}

// Based on examples from https://plotly.com/python/3d-volume-plots/

Figure simpleVolumePlot() {

    constexpr int kNumPointsPerDim = 40;
    const auto x_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);
    const auto y_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);
    const auto z_coords = math_utils::linspace(-8, 8, kNumPointsPerDim);

    const int total_points = kNumPointsPerDim * kNumPointsPerDim * kNumPointsPerDim;
    std::vector<double> x_flat;
    std::vector<double> y_flat;
    std::vector<double> z_flat;
    std::vector<double> values_flat;
    x_flat.reserve(total_points);
    y_flat.reserve(total_points);
    z_flat.reserve(total_points);
    values_flat.reserve(total_points);

    for (double x : x_coords) {
        for (double y : y_coords) {
            for (double z : z_coords) {
                x_flat.push_back(x);
                y_flat.push_back(y);
                z_flat.push_back(z);
                const double product = x * y * z;
                // sinc(t) = sin(t)/t; for t=0, sinc(0)=1.
                values_flat.push_back(product == 0.0 ? 1.0 : std::sin(product) / product);
            }
        }
    }

    return Figure().addTrace(Volume()
                                 .x(x_flat)
                                 .y(y_flat)
                                 .z(z_flat)
                                 .value(std::move(values_flat))
                                 .isomin(0.1)
                                 .isomax(0.8)
                                 .opacity(0.1)
                                 .colorscale("Jet")
                                 .surface(Volume::Surface().count(17)));
}

// Based on examples from https://plotly.com/python/3d-isosurface-plots/

Figure multiple3dIsosurfaces() {
    constexpr int kNumPointsPerDim = 40;
    const auto x_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);
    const auto y_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);
    const auto z_coords = math_utils::linspace(-5, 5, kNumPointsPerDim);

    const int total_points = kNumPointsPerDim * kNumPointsPerDim * kNumPointsPerDim;
    std::vector<double> x_flat;
    std::vector<double> y_flat;
    std::vector<double> z_flat;
    std::vector<double> values_flat;
    x_flat.reserve(total_points);
    y_flat.reserve(total_points);
    z_flat.reserve(total_points);
    values_flat.reserve(total_points);

    for (double x : x_coords) {
        for (double y : y_coords) {
            for (double z : z_coords) {
                x_flat.push_back(x);
                y_flat.push_back(y);
                z_flat.push_back(z);
                // ellipsoid
                values_flat.push_back(x * x * 0.5 + y * y + z * z * 2);
            }
        }
    }

    return Figure().addTrace(
        Isosurface()
            .x(x_flat)
            .y(y_flat)
            .z(z_flat)
            .value(std::move(values_flat))
            .isomin(10)
            .isomax(50)
            .surface(Isosurface::Surface().count(5))    // number of isosurfaces, 2 by default: only min and max
            .colorbar(Isosurface::Colorbar().nticks(5)) // colorbar ticks correspond to isosurface values
            .caps(Isosurface::Caps().x(Isosurface::Caps::X().show(false)).y([](auto& c) { c.show(false); }))
            .colorscale("Blackbody"));
}

// Based on examples from https://plotly.com/python/3d-bubble-charts/

plotlypp::Figure bubbleChartSizedByVariable() {
    std::vector<std::string> planets = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                                        "Saturn",  "Uranus", "Neptune", "Pluto"};
    std::vector distanceFromSun = {57.9, 108.2, 149.6, 227.9, 778.6, 1433.5, 2872.5, 4495.1, 5906.4};
    std::vector density = {5427, 5243, 5514, 3933, 1326, 687, 1271, 1638, 2095};
    std::vector gravity = {3.7, 8.9, 9.8, 3.7, 23.1, 9.0, 8.7, 11.0, 0.7};
    std::vector<double> planetDiameter = {4879, 12104, 12756, 6792, 142984, 120536, 51118, 49528, 2370};
    std::vector<std::string> planetColors = {"rgb(135, 135, 125)", "rgb(210, 50, 0)",    "rgb(50, 90, 255)",
                                             "rgb(178, 0, 0)",     "rgb(235, 235, 210)", "rgb(235, 205, 130)",
                                             "rgb(55, 255, 217)",  "rgb(38, 0, 171)",    "rgb(255, 255, 255)"};

    return Figure()
        .addTrace(Scatter3D()
                      .x(distanceFromSun)
                      .y(density)
                      .z(gravity)
                      .text(std::move(planets))
                      .mode({Scatter3D::Mode::Markers})
                      .marker(Scatter3D::Marker()
                                  .sizemode(Scatter3D::Marker::Sizemode::Diameter)
                                  .sizeref(750)
                                  .size(std::move(planetDiameter))
                                  .color(std::move(planetColors))))
        .setLayout(Layout()
                       .width(800)
                       .height(800)
                       .title([](auto& t) { t.text("Planets!"); })
                       .scene(Layout::Scene()
                                  .xaxis(Layout::Scene::Xaxis().title([](auto& t) {
                                      t.text("Distance from Sun");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .yaxis(Layout::Scene::Yaxis().title([](auto& t) {
                                      t.text("Density");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .zaxis(Layout::Scene::Zaxis().title([](auto& t) {
                                      t.text("Gravity");
                                      t.font([](auto& f) { f.color("white"); });
                                  }))
                                  .bgcolor("rgb(20, 24, 54)")));
}

} // namespace plotlypp
