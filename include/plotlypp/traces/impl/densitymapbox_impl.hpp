// TODO: includes, copyright, etc

namespace plotlypp {

std::string Densitymapbox::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}

Densitymapbox& Densitymapbox::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::below(std::string f) {
    json["below"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

Densitymapbox& Densitymapbox::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox& Densitymapbox::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Densitymapbox& Densitymapbox::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hovertext(std::string f) {
    json["hovertext"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::hovertext(std::vector<std::string> f) {
    json["hovertext"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::hovertextsrc(std::string f) {
    json["hovertextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox& Densitymapbox::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox& Densitymapbox::lat(std::vector<T> f) {
    json["lat"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::latsrc(std::string f) {
    json["latsrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::legendgroup(std::string f) {
    json["legendgroup"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Densitymapbox& Densitymapbox::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox& Densitymapbox::lon(std::vector<T> f) {
    json["lon"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::lonsrc(std::string f) {
    json["lonsrc"] = std::move(f);
    return *this;
}

template <typename T>
Densitymapbox& Densitymapbox::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Densitymapbox& Densitymapbox::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::radius(double f) {
    json["radius"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::radius(std::vector<double> f) {
    json["radius"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::radiussrc(std::string f) {
    json["radiussrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::showlegend(bool f) {
    json["showlegend"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Densitymapbox& Densitymapbox::subplot(std::string f) {
    json["subplot"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}
Densitymapbox& Densitymapbox::text(std::vector<std::string> f) {
    json["text"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::textsrc(std::string f) {
    json["textsrc"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Densitymapbox& Densitymapbox::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

template <typename T, typename>
Densitymapbox& Densitymapbox::z(std::vector<T> f) {
    json["z"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::zauto(bool f) {
    json["zauto"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::zmax(double f) {
    json["zmax"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::zmid(double f) {
    json["zmid"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::zmin(double f) {
    json["zmin"] = std::move(f);
    return *this;
}

Densitymapbox& Densitymapbox::zsrc(std::string f) {
    json["zsrc"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Densitymapbox::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Densitymapbox::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Densitymapbox::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Densitymapbox::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Densitymapbox::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Densitymapbox::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Densitymapbox::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Densitymapbox::Colorbar::to_string(Ticklabelposition e) {
    switch(e) {
        case Ticklabelposition::OUTSIDE: return "outside";
        case Ticklabelposition::INSIDE: return "inside";
        case Ticklabelposition::OUTSIDE_TOP: return "outside top";
        case Ticklabelposition::INSIDE_TOP: return "inside top";
        case Ticklabelposition::OUTSIDE_LEFT: return "outside left";
        case Ticklabelposition::INSIDE_LEFT: return "inside left";
        case Ticklabelposition::OUTSIDE_RIGHT: return "outside right";
        case Ticklabelposition::INSIDE_RIGHT: return "inside right";
        case Ticklabelposition::OUTSIDE_BOTTOM: return "outside bottom";
        case Ticklabelposition::INSIDE_BOTTOM: return "inside bottom";
    }
}
std::string Densitymapbox::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Densitymapbox::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Densitymapbox::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Densitymapbox::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Densitymapbox::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Densitymapbox::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar& Densitymapbox::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar& Densitymapbox::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Densitymapbox::Colorbar& Densitymapbox::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Densitymapbox::Colorbar& Densitymapbox::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar& Densitymapbox::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Densitymapbox::Colorbar& Densitymapbox::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar& Densitymapbox::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Densitymapbox::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Densitymapbox::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Densitymapbox::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Tickfont& Densitymapbox::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Densitymapbox::Colorbar::Tickformatstops& Densitymapbox::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Densitymapbox::Colorbar::Tickformatstops::Tickformatstop& Densitymapbox::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickformatstops::Tickformatstop& Densitymapbox::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickformatstops::Tickformatstop& Densitymapbox::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickformatstops::Tickformatstop& Densitymapbox::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Tickformatstops::Tickformatstop& Densitymapbox::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Densitymapbox::Colorbar::Title& Densitymapbox::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Densitymapbox::Colorbar::Title& Densitymapbox::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Title& Densitymapbox::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Densitymapbox::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Densitymapbox::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Densitymapbox::Colorbar::Title::Font& Densitymapbox::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel& Densitymapbox::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Densitymapbox::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Densitymapbox::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Densitymapbox::Hoverlabel::Font& Densitymapbox::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Densitymapbox::Legendgrouptitle& Densitymapbox::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Densitymapbox::Legendgrouptitle& Densitymapbox::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Densitymapbox::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Densitymapbox::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Densitymapbox::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Densitymapbox::Legendgrouptitle::Font& Densitymapbox::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Densitymapbox::Stream& Densitymapbox::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Densitymapbox::Stream& Densitymapbox::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

} // namespace plotlypp

