// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#include "subplots.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include <math_utils.hpp>
#include <plotlypp/figure.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traces/histogram.hpp>
#include <plotlypp/traces/scatter.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/scattergeo.hpp>
#include <plotlypp/traces/surface.hpp>

namespace plotlypp {

// Based on examples from https://plotly.com/javascript/subplots/

Figure subplotsGridLayout() {
    auto trace1 = Scatter().x(std::vector{1, 2, 3}).y(std::vector{4, 5, 6});
    auto trace2 = Scatter().x(std::vector{20, 30, 40}).y(std::vector{50, 60, 70}).xaxis("x2").yaxis("y2");

    auto gridLayout = Layout{}.grid(Layout::Grid().rows(1).columns(2).pattern(Layout::Grid::Pattern::Independent));
    return Figure().addTrace(std::move(trace1)).addTrace(std::move(trace2)).setLayout(std::move(gridLayout));
}

Figure subplotsDomainLayout() {
    auto trace1 = Scatter().x(std::vector{1, 2, 3}).y(std::vector{4, 5, 6});
    auto trace2 = Scatter().x(std::vector{20, 30, 40}).y(std::vector{50, 60, 70}).xaxis("x2").yaxis("y2");

    auto domanLayout = Layout{}
                           .xaxis(Layout::Xaxis().domain(std::vector{0, 0.7}))
                           .yaxis(2, Layout::Yaxis().anchor("x2"))
                           .xaxis(2, Layout::Xaxis().domain(std::vector{0.8, 1.0}));

    return Figure().addTrace(std::move(trace1)).addTrace(std::move(trace2)).setLayout(std::move(domanLayout));
}

Figure multipleSubplotsWithSharedAxes() {
    auto trace1 = Scatter().x(std::vector{1, 2, 3}).y(std::vector{2, 3, 4});
    auto trace2 = Scatter().x(std::vector{20, 30, 40}).y(std::vector{5, 5, 5}).xaxis("x2").yaxis("y");
    auto trace3 = Scatter().x(std::vector{2, 3, 4}).y(std::vector{600, 700, 800}).xaxis("x").yaxis("y3");
    auto trace4 = Scatter().x(std::vector{4000, 5000, 6000}).y(std::vector{7000, 8000, 9000}).xaxis("x4").yaxis("y4");

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4)})
        .setLayout(Layout().grid(Layout::Grid()
                                     .rows(2)
                                     .columns(2)
                                     .subplots({std::vector<std::string>{"xy", "x2y"}, {"xy3", "x4y4"}})
                                     .roworder(Layout::Grid::Roworder::BottomToTop)));
}

// Based on examples from https://plotly.com/python/3d-subplots/ and https://plotly.com/javascript/3d-subplots/

Figure gen3dSubplots() {
    auto x = math_utils::linspace(-5, 80, 10);
    auto y = math_utils::linspace(-5, 60, 10);

    auto [x_grid, y_grid] = math_utils::meshgrid(y, x);

    std::vector<std::vector<double>> z(x_grid.size(), std::vector<double>(x_grid[0].size()));

    for (auto i = 0u; i < x_grid.size(); ++i) {
        for (size_t j = 0; j < x_grid[0].size(); ++j) {
            double x_val = x_grid[i][j];
            double y_val = y_grid[i][j];

            z[i][j] = std::pow(x_val, 3) + std::pow(y_val, 3);
        }
    }

    auto trace1 = Surface().x(x).y(y).z(z).colorscale("Viridis").showscale(false).scene("scene1");
    auto trace2 = Surface().x(x).y(y).z(z).colorscale("RdBu").showscale(false).scene("scene2");
    auto trace3 = Surface().x(x).y(y).z(z).colorscale("YlOrRd").showscale(false).scene("scene3");
    auto trace4 = Surface().x(x).y(y).z(z).colorscale("YlGnBu").showscale(false).scene("scene4");

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3), std::move(trace4)})
        .setLayout(Layout()
                       .title([](auto& t) { t.text("3D subplots with different colorscales"); })
                       .height(800)
                       .width(800)
                       .scene(1, Layout::Scene().domain([](auto& d) {
                           d.x({0.0, 0.5});
                           d.y({0.5, 1.0});
                       }))
                       .scene(2, Layout::Scene().domain([](auto& d) {
                           d.x({0.5, 1.0});
                           d.y({0.5, 1.0});
                       }))
                       .scene(3, Layout::Scene().domain([](auto& d) {
                           d.x({0.0, 0.5});
                           d.y({0.0, 0.5});
                       }))
                       .scene(4, Layout::Scene().domain([](auto& d) {
                           d.x({0.5, 1.0});
                           d.y({0.0, 0.5});
                       })));
}

// Based on examples from https://plotly.com/javascript/insets/

Figure insetGraph() {
    auto trace1 = Scatter().x(std::vector{1, 2, 3}).y(std::vector{4, 3, 2});
    auto trace2 = Scatter().x(std::vector{20, 30, 40}).y(std::vector{30, 40, 50}).xaxis("x2").yaxis("y2");

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2)})
        .setLayout(Layout().yaxis(2, [](auto& ay) { ay.domain({0.6, 0.95}).anchor("x2"); }).xaxis(2, [](auto& ax) {
            ax.domain({0.6, 0.95}).anchor("y2");
        }));
}

// Data generation
struct VolcanoData {
    std::vector<std::string> status;
    std::vector<std::string> type;
    std::vector<double> elev;
    std::vector<std::string> country;
    std::vector<double> lon;
    std::vector<double> lat;
};

VolcanoData generate_data(int n) {
    VolcanoData data;
    std::mt19937 gen(1); // for reproducibility
    std::normal_distribution<> elev_dist(1000.0, 5000.0);
    std::uniform_real_distribution<> lon_dist(-180.0, 180.0);
    std::uniform_real_distribution<> lat_dist(-70.0, 80.0);
    std::uniform_int_distribution<unsigned int> status_dist(0, 1);
    std::uniform_int_distribution<unsigned int> type_dist(0, 3);
    std::uniform_int_distribution<unsigned int> country_dist(0, 5);

    std::vector<std::string> statuses = {"Historical", "Holocene"};
    std::vector<std::string> types = {"Stratovolcano", "Shield volcano", "Submarine volcano", "Caldera"};
    std::vector<std::string> countries = {"US", "Japan", "Indonesia", "Chile", "Italy", "Mexico"};

    for (int i = 0; i < n; ++i) {
        data.status.push_back(statuses[status_dist(gen)]);
        data.type.push_back(types[type_dist(gen)]);
        data.elev.push_back(std::round(elev_dist(gen)));
        data.country.push_back(countries[country_dist(gen)]);
        data.lon.push_back(lon_dist(gen));
        data.lat.push_back(lat_dist(gen));
    }
    return data;
}

// Based on examples from https://plotly.com/javascript/mixed-subplots/

Figure mixedSubplots() {
    VolcanoData rows = generate_data(500);

    auto trace1 =
        Scatter3D()
            .x(rows.status)
            .y(rows.type)
            .z(rows.elev)
            .marker([&](auto& m) {
                // m.size(2).color(rows.elev).colorscale("Reds").line([](auto& l) { l.color("transparent");
                // });
                m.size(2).color(rows.elev).colorscale("Reds").line([](auto& l) { l.color("rgba(0, 0, 0, 0)"); });
            })
            .mode({Scatter3D::Mode::Markers})
            .text(rows.country)
            .hoverinfo(
                {Scatter3D::Hoverinfo::X, Scatter3D::Hoverinfo::Y, Scatter3D::Hoverinfo::Z, Scatter3D::Hoverinfo::Text})
            .showlegend(false);

    auto trace2 = Histogram()
                      .x(rows.elev)
                      .hoverinfo({Histogram::Hoverinfo::X, Histogram::Hoverinfo::Y})
                      .showlegend(false)
                      .xaxis("x2")
                      .yaxis("y2")
                      .marker([](auto& m) { m.color("red"); });

    std::vector<std::string> elev_str(rows.elev.size());
    std::transform(rows.elev.begin(), rows.elev.end(), elev_str.begin(),
                   [](const auto& e) { return std::to_string(e); });
    auto trace3 = Scattergeo()
                      .geo("geo3") // Link trace to subplot "geo3" layout
                      .lon(rows.lon)
                      .lat(rows.lat)
                      .hoverinfo({Scattergeo::Hoverinfo::Text})
                      .text(elev_str)
                      .mode({Scattergeo::Mode::Markers})
                      .showlegend(false)
                      .marker([&](auto& m) {
                          m.size(4)
                              .color(rows.elev)
                              .colorscale("Reds")
                              .opacity(0.8)
                              .symbol(Scattergeo::Marker::Symbol::Circle)
                              .line([](auto& l) { l.width(1); });
                      });

    auto layout =
        Layout()
            .paper_bgcolor("black")
            .plot_bgcolor("black")
            .title([](auto& t) { t.text("Volcano Database: Elevation"); })
            .font([](auto& f) { f.color("white"); })
            .annotations(
                {Layout::Annotation().x(0).y(0).xref("paper").yref("paper").text("Source: Random").showarrow(false)})
            .geo(3,
                 [](auto& g) {
                     g.domain([](auto& d) { d.x({0, 0.45}).y({0.02, 0.98}); })
                         .scope(Layout::Geo::Scope::World)
                         .projection([](auto& p) { p.type(Layout::Geo::Projection::Type::Orthographic); })
                         .showland(true)
                         .showocean(true)
                         .showlakes(true)
                         .landcolor("rgb(250,250,250)")
                         .lakecolor("rgb(127,205,255)")
                         .oceancolor("rgb(6,66,115)")
                         .subunitcolor("rgb(217,217,217)")
                         .countrycolor("rgb(217,217,217)")
                         .countrywidth(0.5)
                         .subunitwidth(0.5)
                         .bgcolor("black");
                 })
            .scene([](auto& s) {
                s.domain([](auto& d) { d.x({0.55, 1}).y({0, 0.6}); })
                    .xaxis([](auto& ax) {
                        ax.title([](auto& t) { t.text("Status"); })
                            .showticklabels(false)
                            .showgrid(true)
                            .gridcolor("white");
                    })
                    .yaxis([](auto& ax) {
                        ax.title([](auto& t) { t.text("Type"); })
                            .showticklabels(false)
                            .showgrid(true)
                            .gridcolor("white");
                    })
                    .zaxis(
                        [](auto& ax) { ax.title([](auto& t) { t.text("Elev"); }).showgrid(true).gridcolor("white"); });
            })
            .yaxis(2, [](auto& ax) { ax.anchor("x2").domain({0.7, 1}).showgrid(false); })
            .xaxis(2, [](auto& ax) { ax.tickangle(45).anchor("y2").ticksuffix("m").domain({0.6, 1}); });

    return Figure()
        .addTraces(std::vector<Trace>{std::move(trace1), std::move(trace2), std::move(trace3)})
        .setLayout(std::move(layout));
}

} // namespace plotlypp
