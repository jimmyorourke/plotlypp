// TODO: includes, copyright, etc

namespace plotlypp {

std::string Mesh3D::to_string(Delaunayaxis e) {
    switch(e) {
        case Delaunayaxis::X: return "x";
        case Delaunayaxis::Y: return "y";
        case Delaunayaxis::Z: return "z";
    }
}
std::string Mesh3D::to_string(Intensitymode e) {
    switch(e) {
        case Intensitymode::VERTEX: return "vertex";
        case Intensitymode::CELL: return "cell";
    }
}
std::string Mesh3D::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}
std::string Mesh3D::to_string(Xcalendar e) {
    switch(e) {
        case Xcalendar::CHINESE: return "chinese";
        case Xcalendar::COPTIC: return "coptic";
        case Xcalendar::DISCWORLD: return "discworld";
        case Xcalendar::ETHIOPIAN: return "ethiopian";
        case Xcalendar::GREGORIAN: return "gregorian";
        case Xcalendar::HEBREW: return "hebrew";
        case Xcalendar::ISLAMIC: return "islamic";
        case Xcalendar::JALALI: return "jalali";
        case Xcalendar::JULIAN: return "julian";
        case Xcalendar::MAYAN: return "mayan";
        case Xcalendar::NANAKSHAHI: return "nanakshahi";
        case Xcalendar::NEPALI: return "nepali";
        case Xcalendar::PERSIAN: return "persian";
        case Xcalendar::TAIWAN: return "taiwan";
        case Xcalendar::THAI: return "thai";
        case Xcalendar::UMMALQURA: return "ummalqura";
    }
}
std::string Mesh3D::to_string(Ycalendar e) {
    switch(e) {
        case Ycalendar::CHINESE: return "chinese";
        case Ycalendar::COPTIC: return "coptic";
        case Ycalendar::DISCWORLD: return "discworld";
        case Ycalendar::ETHIOPIAN: return "ethiopian";
        case Ycalendar::GREGORIAN: return "gregorian";
        case Ycalendar::HEBREW: return "hebrew";
        case Ycalendar::ISLAMIC: return "islamic";
        case Ycalendar::JALALI: return "jalali";
        case Ycalendar::JULIAN: return "julian";
        case Ycalendar::MAYAN: return "mayan";
        case Ycalendar::NANAKSHAHI: return "nanakshahi";
        case Ycalendar::NEPALI: return "nepali";
        case Ycalendar::PERSIAN: return "persian";
        case Ycalendar::TAIWAN: return "taiwan";
        case Ycalendar::THAI: return "thai";
        case Ycalendar::UMMALQURA: return "ummalqura";
    }
}
std::string Mesh3D::to_string(Zcalendar e) {
    switch(e) {
        case Zcalendar::CHINESE: return "chinese";
        case Zcalendar::COPTIC: return "coptic";
        case Zcalendar::DISCWORLD: return "discworld";
        case Zcalendar::ETHIOPIAN: return "ethiopian";
        case Zcalendar::GREGORIAN: return "gregorian";
        case Zcalendar::HEBREW: return "hebrew";
        case Zcalendar::ISLAMIC: return "islamic";
        case Zcalendar::JALALI: return "jalali";
        case Zcalendar::JULIAN: return "julian";
        case Zcalendar::MAYAN: return "mayan";
        case Zcalendar::NANAKSHAHI: return "nanakshahi";
        case Zcalendar::NEPALI: return "nepali";
        case Zcalendar::PERSIAN: return "persian";
        case Zcalendar::TAIWAN: return "taiwan";
        case Zcalendar::THAI: return "thai";
        case Zcalendar::UMMALQURA: return "ummalqura";
    }
}

Mesh3D& Mesh3D::alphahull(double f) {
    json["alphahull"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::cauto(bool f) {
    json["cauto"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::cmax(double f) {
    json["cmax"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::cmid(double f) {
    json["cmid"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::cmin(double f) {
    json["cmin"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

Mesh3D& Mesh3D::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::contour(class Contour f) {
    json["contour"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::delaunayaxis(enum Delaunayaxis f) {
    json["delaunayaxis"] = to_string(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::facecolor(std::vector<T> f) {
    json["facecolor"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::facecolorsrc(std::string f) {
    json["facecolorsrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::flatshading(bool f) {
    json["flatshading"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Mesh3D& Mesh3D::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hovertext(std::string f) {
    json["hovertext"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::hovertext(std::vector<std::string> f) {
    json["hovertext"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::hovertextsrc(std::string f) {
    json["hovertextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::i(std::vector<T> f) {
    json["i"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::intensity(std::vector<T> f) {
    json["intensity"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::intensitymode(enum Intensitymode f) {
    json["intensitymode"] = to_string(f);
    return *this;
}

Mesh3D& Mesh3D::intensitysrc(std::string f) {
    json["intensitysrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::isrc(std::string f) {
    json["isrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::j(std::vector<T> f) {
    json["j"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::jsrc(std::string f) {
    json["jsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::k(std::vector<T> f) {
    json["k"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::ksrc(std::string f) {
    json["ksrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::legendgroup(std::string f) {
    json["legendgroup"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Mesh3D& Mesh3D::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::lighting(class Lighting f) {
    json["lighting"] = std::move(f.json);
    return *this;
}

Mesh3D& Mesh3D::lightposition(class Lightposition f) {
    json["lightposition"] = std::move(f.json);
    return *this;
}

template <typename T>
Mesh3D& Mesh3D::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Mesh3D& Mesh3D::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::scene(std::string f) {
    json["scene"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::showlegend(bool f) {
    json["showlegend"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Mesh3D& Mesh3D::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}
Mesh3D& Mesh3D::text(std::vector<std::string> f) {
    json["text"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::textsrc(std::string f) {
    json["textsrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Mesh3D& Mesh3D::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::vertexcolor(std::vector<T> f) {
    json["vertexcolor"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::vertexcolorsrc(std::string f) {
    json["vertexcolorsrc"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::x(std::vector<T> f) {
    json["x"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::xcalendar(enum Xcalendar f) {
    json["xcalendar"] = to_string(f);
    return *this;
}

Mesh3D& Mesh3D::xhoverformat(std::string f) {
    json["xhoverformat"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::xsrc(std::string f) {
    json["xsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::y(std::vector<T> f) {
    json["y"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::ycalendar(enum Ycalendar f) {
    json["ycalendar"] = to_string(f);
    return *this;
}

Mesh3D& Mesh3D::yhoverformat(std::string f) {
    json["yhoverformat"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::ysrc(std::string f) {
    json["ysrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D& Mesh3D::z(std::vector<T> f) {
    json["z"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::zcalendar(enum Zcalendar f) {
    json["zcalendar"] = to_string(f);
    return *this;
}

Mesh3D& Mesh3D::zhoverformat(std::string f) {
    json["zhoverformat"] = std::move(f);
    return *this;
}

Mesh3D& Mesh3D::zsrc(std::string f) {
    json["zsrc"] = std::move(f);
    return *this;
}

std::string Mesh3D::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Mesh3D::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Mesh3D::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Mesh3D::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Mesh3D::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Mesh3D::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Mesh3D::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Mesh3D::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Mesh3D::Colorbar::to_string(Ticklabelposition e) {
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
std::string Mesh3D::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Mesh3D::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Mesh3D::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Mesh3D::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Mesh3D::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Mesh3D::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Mesh3D::Colorbar& Mesh3D::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar& Mesh3D::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar& Mesh3D::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Mesh3D::Colorbar& Mesh3D::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Mesh3D::Colorbar& Mesh3D::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar& Mesh3D::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Mesh3D::Colorbar& Mesh3D::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar& Mesh3D::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D::Colorbar& Mesh3D::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Mesh3D::Colorbar& Mesh3D::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar& Mesh3D::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Mesh3D::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Mesh3D::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Mesh3D::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Tickfont& Mesh3D::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Mesh3D::Colorbar::Tickformatstops& Mesh3D::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Mesh3D::Colorbar::Tickformatstops::Tickformatstop& Mesh3D::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickformatstops::Tickformatstop& Mesh3D::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickformatstops::Tickformatstop& Mesh3D::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickformatstops::Tickformatstop& Mesh3D::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Tickformatstops::Tickformatstop& Mesh3D::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Mesh3D::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Mesh3D::Colorbar::Title& Mesh3D::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Mesh3D::Colorbar::Title& Mesh3D::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Title& Mesh3D::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Mesh3D::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Mesh3D::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Mesh3D::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Mesh3D::Colorbar::Title::Font& Mesh3D::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Mesh3D::Contour& Mesh3D::Contour::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Contour& Mesh3D::Contour::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D::Contour& Mesh3D::Contour::show(bool f) {
    json["show"] = std::move(f);
    return *this;
}

Mesh3D::Contour& Mesh3D::Contour::width(double f) {
    json["width"] = std::move(f);
    return *this;
}

std::string Mesh3D::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel& Mesh3D::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Mesh3D::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Mesh3D::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Mesh3D::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Mesh3D::Hoverlabel::Font& Mesh3D::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Mesh3D::Legendgrouptitle& Mesh3D::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Mesh3D::Legendgrouptitle& Mesh3D::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Mesh3D::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Mesh3D::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Mesh3D::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Mesh3D::Legendgrouptitle::Font& Mesh3D::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Mesh3D::Lighting& Mesh3D::Lighting::ambient(double f) {
    json["ambient"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::diffuse(double f) {
    json["diffuse"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::facenormalsepsilon(double f) {
    json["facenormalsepsilon"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::fresnel(double f) {
    json["fresnel"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::roughness(double f) {
    json["roughness"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::specular(double f) {
    json["specular"] = std::move(f);
    return *this;
}

Mesh3D::Lighting& Mesh3D::Lighting::vertexnormalsepsilon(double f) {
    json["vertexnormalsepsilon"] = std::move(f);
    return *this;
}


Mesh3D::Lightposition& Mesh3D::Lightposition::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Mesh3D::Lightposition& Mesh3D::Lightposition::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Mesh3D::Lightposition& Mesh3D::Lightposition::z(double f) {
    json["z"] = std::move(f);
    return *this;
}


Mesh3D::Stream& Mesh3D::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Mesh3D::Stream& Mesh3D::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

} // namespace plotlypp

