// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

module;

#include <plotlypp/figure.hpp>
#include <plotlypp/json.hpp>
#include <plotlypp/plotly_min_js.hpp>
#include <plotlypp/trace.hpp>
#include <plotlypp/traits.hpp>
#include <plotlypp/layout/layout.hpp>
#include <plotlypp/traces/bar.hpp>
#include <plotlypp/traces/barpolar.hpp>
#include <plotlypp/traces/box.hpp>
#include <plotlypp/traces/candlestick.hpp>
#include <plotlypp/traces/carpet.hpp>
#include <plotlypp/traces/choropleth.hpp>
#include <plotlypp/traces/choroplethmap.hpp>
#include <plotlypp/traces/choroplethmapbox.hpp>
#include <plotlypp/traces/cone.hpp>
#include <plotlypp/traces/contour.hpp>
#include <plotlypp/traces/contourcarpet.hpp>
#include <plotlypp/traces/densitymap.hpp>
#include <plotlypp/traces/densitymapbox.hpp>
#include <plotlypp/traces/funnel.hpp>
#include <plotlypp/traces/funnelarea.hpp>
#include <plotlypp/traces/heatmap.hpp>
#include <plotlypp/traces/histogram.hpp>
#include <plotlypp/traces/histogram2d.hpp>
#include <plotlypp/traces/histogram2dcontour.hpp>
#include <plotlypp/traces/icicle.hpp>
#include <plotlypp/traces/image.hpp>
#include <plotlypp/traces/indicator.hpp>
#include <plotlypp/traces/isosurface.hpp>
#include <plotlypp/traces/mesh3d.hpp>
#include <plotlypp/traces/ohlc.hpp>
#include <plotlypp/traces/parcats.hpp>
#include <plotlypp/traces/parcoords.hpp>
#include <plotlypp/traces/pie.hpp>
#include <plotlypp/traces/sankey.hpp>
#include <plotlypp/traces/scatter.hpp>
#include <plotlypp/traces/scatter3d.hpp>
#include <plotlypp/traces/scattercarpet.hpp>
#include <plotlypp/traces/scattergeo.hpp>
#include <plotlypp/traces/scattergl.hpp>
#include <plotlypp/traces/scattermap.hpp>
#include <plotlypp/traces/scattermapbox.hpp>
#include <plotlypp/traces/scatterpolar.hpp>
#include <plotlypp/traces/scatterpolargl.hpp>
#include <plotlypp/traces/scattersmith.hpp>
#include <plotlypp/traces/scatterternary.hpp>
#include <plotlypp/traces/splom.hpp>
#include <plotlypp/traces/streamtube.hpp>
#include <plotlypp/traces/sunburst.hpp>
#include <plotlypp/traces/surface.hpp>
#include <plotlypp/traces/table.hpp>
#include <plotlypp/traces/treemap.hpp>
#include <plotlypp/traces/violin.hpp>
#include <plotlypp/traces/volume.hpp>
#include <plotlypp/traces/waterfall.hpp>

export module plotlypp;

export namespace plotlypp {
    using plotlypp::Figure;
    using plotlypp::Json;
    using plotlypp::Trace;
    using plotlypp::Bar;
    using plotlypp::Barpolar;
    using plotlypp::Box;
    using plotlypp::Candlestick;
    using plotlypp::Carpet;
    using plotlypp::Choropleth;
    using plotlypp::Choroplethmap;
    using plotlypp::Choroplethmapbox;
    using plotlypp::Cone;
    using plotlypp::Contour;
    using plotlypp::Contourcarpet;
    using plotlypp::Densitymap;
    using plotlypp::Densitymapbox;
    using plotlypp::Funnel;
    using plotlypp::Funnelarea;
    using plotlypp::Heatmap;
    using plotlypp::Histogram;
    using plotlypp::Histogram2D;
    using plotlypp::Histogram2Dcontour;
    using plotlypp::Icicle;
    using plotlypp::Image;
    using plotlypp::Indicator;
    using plotlypp::Isosurface;
    using plotlypp::Mesh3D;
    using plotlypp::Ohlc;
    using plotlypp::Parcats;
    using plotlypp::Parcoords;
    using plotlypp::Pie;
    using plotlypp::Sankey;
    using plotlypp::Scatter;
    using plotlypp::Scatter3D;
    using plotlypp::Scattercarpet;
    using plotlypp::Scattergeo;
    using plotlypp::Scattergl;
    using plotlypp::Scattermap;
    using plotlypp::Scattermapbox;
    using plotlypp::Scatterpolar;
    using plotlypp::Scatterpolargl;
    using plotlypp::Scattersmith;
    using plotlypp::Scatterternary;
    using plotlypp::Splom;
    using plotlypp::Streamtube;
    using plotlypp::Sunburst;
    using plotlypp::Surface;
    using plotlypp::Table;
    using plotlypp::Treemap;
    using plotlypp::Violin;
    using plotlypp::Volume;
    using plotlypp::Waterfall;

    using plotlypp::serialize;
    using plotlypp::parse;

    using plotlypp::is_plotly_data_array_extension;
    using plotlypp::range_element_type;
    using plotlypp::range_element_type_t;
    using plotlypp::is_data_array_element;
    using plotlypp::is_data_array_element_v;
    using plotlypp::is_data_array;
    using plotlypp::is_data_array_v;

    using plotlypp::plotlyJS;
}
