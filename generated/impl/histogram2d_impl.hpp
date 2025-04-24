// TODO: includes, copyright, etc

namespace plotlypp {

std::string Histogram2D::to_string(Histfunc e) {
    switch(e) {
        case Histfunc::COUNT: return "count";
        case Histfunc::SUM: return "sum";
        case Histfunc::AVG: return "avg";
        case Histfunc::MIN: return "min";
        case Histfunc::MAX: return "max";
    }
}
std::string Histogram2D::to_string(Histnorm e) {
    switch(e) {
        case Histnorm::EMPTY: return "";
        case Histnorm::PERCENT: return "percent";
        case Histnorm::PROBABILITY: return "probability";
        case Histnorm::DENSITY: return "density";
        case Histnorm::PROBABILITY_DENSITY: return "probability density";
    }
}
std::string Histogram2D::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}
std::string Histogram2D::to_string(Xcalendar e) {
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
std::string Histogram2D::to_string(Ycalendar e) {
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
std::string Histogram2D::to_string(Zsmooth e) {
    switch(e) {
        case Zsmooth::FAST: return "fast";
        case Zsmooth::BEST: return "best";
        case Zsmooth::FALSE: return "False";
    }
}

Histogram2D& Histogram2D::autobinx(bool f) {
    json["autobinx"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::autobiny(bool f) {
    json["autobiny"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::bingroup(std::string f) {
    json["bingroup"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Histogram2D& Histogram2D::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D& Histogram2D::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::histfunc(enum Histfunc f) {
    json["histfunc"] = to_string(f);
    return *this;
}

Histogram2D& Histogram2D::histnorm(enum Histnorm f) {
    json["histnorm"] = to_string(f);
    return *this;
}

Histogram2D& Histogram2D::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Histogram2D& Histogram2D::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Histogram2D& Histogram2D::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D& Histogram2D::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::legendgroup(std::string f) {
    json["legendgroup"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

template <typename T>
Histogram2D& Histogram2D::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Histogram2D& Histogram2D::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::nbinsx(int f) {
    json["nbinsx"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::nbinsy(int f) {
    json["nbinsy"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::showlegend(bool f) {
    json["showlegend"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::textfont(class Textfont f) {
    json["textfont"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::texttemplate(std::string f) {
    json["texttemplate"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D& Histogram2D::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

template <typename T, typename>
Histogram2D& Histogram2D::x(std::vector<T> f) {
    json["x"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::xaxis(std::string f) {
    json["xaxis"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::xbingroup(std::string f) {
    json["xbingroup"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::xbins(class Xbins f) {
    json["xbins"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::xcalendar(enum Xcalendar f) {
    json["xcalendar"] = to_string(f);
    return *this;
}

Histogram2D& Histogram2D::xgap(double f) {
    json["xgap"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::xhoverformat(std::string f) {
    json["xhoverformat"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::xsrc(std::string f) {
    json["xsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D& Histogram2D::y(std::vector<T> f) {
    json["y"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::yaxis(std::string f) {
    json["yaxis"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::ybingroup(std::string f) {
    json["ybingroup"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::ybins(class Ybins f) {
    json["ybins"] = std::move(f.json);
    return *this;
}

Histogram2D& Histogram2D::ycalendar(enum Ycalendar f) {
    json["ycalendar"] = to_string(f);
    return *this;
}

Histogram2D& Histogram2D::ygap(double f) {
    json["ygap"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::yhoverformat(std::string f) {
    json["yhoverformat"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::ysrc(std::string f) {
    json["ysrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D& Histogram2D::z(std::vector<T> f) {
    json["z"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zauto(bool f) {
    json["zauto"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zhoverformat(std::string f) {
    json["zhoverformat"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zmax(double f) {
    json["zmax"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zmid(double f) {
    json["zmid"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zmin(double f) {
    json["zmin"] = std::move(f);
    return *this;
}

Histogram2D& Histogram2D::zsmooth(enum Zsmooth f) {
    json["zsmooth"] = to_string(f);
    return *this;
}

Histogram2D& Histogram2D::zsrc(std::string f) {
    json["zsrc"] = std::move(f);
    return *this;
}

std::string Histogram2D::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Histogram2D::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Histogram2D::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Histogram2D::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Histogram2D::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Histogram2D::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Histogram2D::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Histogram2D::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Histogram2D::Colorbar::to_string(Ticklabelposition e) {
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
std::string Histogram2D::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Histogram2D::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Histogram2D::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Histogram2D::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Histogram2D::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Histogram2D::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Histogram2D::Colorbar& Histogram2D::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar& Histogram2D::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar& Histogram2D::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D::Colorbar& Histogram2D::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Histogram2D::Colorbar& Histogram2D::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar& Histogram2D::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Histogram2D::Colorbar& Histogram2D::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar& Histogram2D::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D::Colorbar& Histogram2D::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Histogram2D::Colorbar& Histogram2D::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar& Histogram2D::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Histogram2D::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Histogram2D::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Histogram2D::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Tickfont& Histogram2D::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Histogram2D::Colorbar::Tickformatstops& Histogram2D::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Histogram2D::Colorbar::Tickformatstops::Tickformatstop& Histogram2D::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickformatstops::Tickformatstop& Histogram2D::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickformatstops::Tickformatstop& Histogram2D::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickformatstops::Tickformatstop& Histogram2D::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Tickformatstops::Tickformatstop& Histogram2D::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Histogram2D::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Histogram2D::Colorbar::Title& Histogram2D::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Histogram2D::Colorbar::Title& Histogram2D::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Title& Histogram2D::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Histogram2D::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Histogram2D::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Histogram2D::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Histogram2D::Colorbar::Title::Font& Histogram2D::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}

std::string Histogram2D::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel& Histogram2D::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Histogram2D::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Histogram2D::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Histogram2D::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Histogram2D::Hoverlabel::Font& Histogram2D::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Histogram2D::Legendgrouptitle& Histogram2D::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Histogram2D::Legendgrouptitle& Histogram2D::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Histogram2D::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Histogram2D::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Histogram2D::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Histogram2D::Legendgrouptitle::Font& Histogram2D::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


template <typename T, typename>
Histogram2D::Marker& Histogram2D::Marker::color(std::vector<T> f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Marker& Histogram2D::Marker::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}


Histogram2D::Stream& Histogram2D::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Histogram2D::Stream& Histogram2D::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

std::string Histogram2D::Textfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Histogram2D::Textfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Histogram2D::Textfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Histogram2D::Textfont& Histogram2D::Textfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Histogram2D::Textfont& Histogram2D::Textfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Histogram2D::Textfont& Histogram2D::Textfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


template <typename T>
Histogram2D::Xbins& Histogram2D::Xbins::end(T f) {
    json["end"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D::Xbins& Histogram2D::Xbins::size(T f) {
    json["size"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D::Xbins& Histogram2D::Xbins::start(T f) {
    json["start"] = std::move(f);
    return *this;
}


template <typename T>
Histogram2D::Ybins& Histogram2D::Ybins::end(T f) {
    json["end"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D::Ybins& Histogram2D::Ybins::size(T f) {
    json["size"] = std::move(f);
    return *this;
}

template <typename T>
Histogram2D::Ybins& Histogram2D::Ybins::start(T f) {
    json["start"] = std::move(f);
    return *this;
}

} // namespace plotlypp

