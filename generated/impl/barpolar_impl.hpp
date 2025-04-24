// TODO: includes, copyright, etc

namespace plotlypp {

std::string Barpolar::to_string(Thetaunit e) {
    switch(e) {
        case Thetaunit::RADIANS: return "radians";
        case Thetaunit::DEGREES: return "degrees";
        case Thetaunit::GRADIANS: return "gradians";
    }
}
std::string Barpolar::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}

template <typename T>
Barpolar& Barpolar::base(T f) {
    json["base"] = std::move(f);
    return *this;
}
template <typename T>
Barpolar& Barpolar::base(std::vector<T> f) {
    json["base"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::basesrc(std::string f) {
    json["basesrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar& Barpolar::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::dr(double f) {
    json["dr"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::dtheta(double f) {
    json["dtheta"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Barpolar& Barpolar::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hovertext(std::string f) {
    json["hovertext"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::hovertext(std::vector<std::string> f) {
    json["hovertext"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::hovertextsrc(std::string f) {
    json["hovertextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar& Barpolar::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::legendgroup(std::string f) {
    json["legendgroup"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Barpolar& Barpolar::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

template <typename T>
Barpolar& Barpolar::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Barpolar& Barpolar::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::offset(double f) {
    json["offset"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::offset(std::vector<double> f) {
    json["offset"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::offsetsrc(std::string f) {
    json["offsetsrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar& Barpolar::r(std::vector<T> f) {
    json["r"] = std::move(f);
    return *this;
}

template <typename T>
Barpolar& Barpolar::r0(T f) {
    json["r0"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::rsrc(std::string f) {
    json["rsrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::selected(class Selected f) {
    json["selected"] = std::move(f.json);
    return *this;
}

template <typename T>
Barpolar& Barpolar::selectedpoints(T f) {
    json["selectedpoints"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::showlegend(bool f) {
    json["showlegend"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Barpolar& Barpolar::subplot(std::string f) {
    json["subplot"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::text(std::vector<std::string> f) {
    json["text"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::textsrc(std::string f) {
    json["textsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar& Barpolar::theta(std::vector<T> f) {
    json["theta"] = std::move(f);
    return *this;
}

template <typename T>
Barpolar& Barpolar::theta0(T f) {
    json["theta0"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::thetasrc(std::string f) {
    json["thetasrc"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::thetaunit(enum Thetaunit f) {
    json["thetaunit"] = to_string(f);
    return *this;
}

Barpolar& Barpolar::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Barpolar& Barpolar::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::unselected(class Unselected f) {
    json["unselected"] = std::move(f.json);
    return *this;
}

Barpolar& Barpolar::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

Barpolar& Barpolar::width(double f) {
    json["width"] = std::move(f);
    return *this;
}
Barpolar& Barpolar::width(std::vector<double> f) {
    json["width"] = std::move(f);
    return *this;
}

Barpolar& Barpolar::widthsrc(std::string f) {
    json["widthsrc"] = std::move(f);
    return *this;
}

std::string Barpolar::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel& Barpolar::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel& Barpolar::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Barpolar::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Barpolar::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Barpolar::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Barpolar::Hoverlabel::Font& Barpolar::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Barpolar::Legendgrouptitle& Barpolar::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Barpolar::Legendgrouptitle& Barpolar::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Barpolar::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Barpolar::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Barpolar::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Barpolar::Legendgrouptitle::Font& Barpolar::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Barpolar::Marker& Barpolar::Marker::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::cauto(bool f) {
    json["cauto"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::cmax(double f) {
    json["cmax"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::cmid(double f) {
    json["cmid"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::cmin(double f) {
    json["cmin"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker& Barpolar::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker& Barpolar::Marker::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker& Barpolar::Marker::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Barpolar::Marker& Barpolar::Marker::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}
Barpolar::Marker& Barpolar::Marker::opacity(std::vector<double> f) {
    json["opacity"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::opacitysrc(std::string f) {
    json["opacitysrc"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::pattern(class Pattern f) {
    json["pattern"] = std::move(f.json);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Barpolar::Marker& Barpolar::Marker::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

std::string Barpolar::Marker::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Ticklabelposition e) {
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
std::string Barpolar::Marker::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Barpolar::Marker::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar& Barpolar::Marker::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Barpolar::Marker::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Barpolar::Marker::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Barpolar::Marker::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickfont& Barpolar::Marker::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Barpolar::Marker::Colorbar::Tickformatstops& Barpolar::Marker::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop& Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop& Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop& Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop& Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop& Barpolar::Marker::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Barpolar::Marker::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Barpolar::Marker::Colorbar::Title& Barpolar::Marker::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Barpolar::Marker::Colorbar::Title& Barpolar::Marker::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title& Barpolar::Marker::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Barpolar::Marker::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Barpolar::Marker::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Barpolar::Marker::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Barpolar::Marker::Colorbar::Title::Font& Barpolar::Marker::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Barpolar::Marker::Line& Barpolar::Marker::Line::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::cauto(bool f) {
    json["cauto"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::cmax(double f) {
    json["cmax"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::cmid(double f) {
    json["cmid"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::cmin(double f) {
    json["cmin"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker::Line& Barpolar::Marker::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker::Line& Barpolar::Marker::Line::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Marker::Line& Barpolar::Marker::Line::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Barpolar::Marker::Line& Barpolar::Marker::Line::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}
Barpolar::Marker::Line& Barpolar::Marker::Line::width(std::vector<double> f) {
    json["width"] = std::move(f);
    return *this;
}

Barpolar::Marker::Line& Barpolar::Marker::Line::widthsrc(std::string f) {
    json["widthsrc"] = std::move(f);
    return *this;
}

std::string Barpolar::Marker::Pattern::to_string(Fillmode e) {
    switch(e) {
        case Fillmode::REPLACE: return "replace";
        case Fillmode::OVERLAY: return "overlay";
    }
}
std::string Barpolar::Marker::Pattern::to_string(Shape e) {
    switch(e) {
        case Shape::EMPTY: return "";
        case Shape::SLASH: return "/";
        case Shape::DOUBLEBACKSLASH: return "\\";
        case Shape::X: return "x";
        case Shape::HYPHEN: return "-";
        case Shape::OR: return "|";
        case Shape::PLUS: return "+";
        case Shape::DOT: return ".";
    }
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgcolor(std::string f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgcolor(double f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgcolor(std::vector<std::string> f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgcolor(std::vector<double> f) {
    json["fgcolor"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgcolorsrc(std::string f) {
    json["fgcolorsrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fgopacity(double f) {
    json["fgopacity"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::fillmode(enum Fillmode f) {
    json["fillmode"] = to_string(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::shape(enum Shape f) {
    json["shape"] = to_string(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::shape(const std::vector<enum Shape>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["shape"] = std::move(stringified);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::shapesrc(std::string f) {
    json["shapesrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::solidity(double f) {
    json["solidity"] = std::move(f);
    return *this;
}
Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::solidity(std::vector<double> f) {
    json["solidity"] = std::move(f);
    return *this;
}

Barpolar::Marker::Pattern& Barpolar::Marker::Pattern::soliditysrc(std::string f) {
    json["soliditysrc"] = std::move(f);
    return *this;
}


Barpolar::Selected& Barpolar::Selected::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

Barpolar::Selected& Barpolar::Selected::textfont(class Textfont f) {
    json["textfont"] = std::move(f.json);
    return *this;
}


Barpolar::Selected::Marker& Barpolar::Selected::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Selected::Marker& Barpolar::Selected::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Selected::Marker& Barpolar::Selected::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}


Barpolar::Selected::Textfont& Barpolar::Selected::Textfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Selected::Textfont& Barpolar::Selected::Textfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}


Barpolar::Stream& Barpolar::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Barpolar::Stream& Barpolar::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}


Barpolar::Unselected& Barpolar::Unselected::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

Barpolar::Unselected& Barpolar::Unselected::textfont(class Textfont f) {
    json["textfont"] = std::move(f.json);
    return *this;
}


Barpolar::Unselected::Marker& Barpolar::Unselected::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Unselected::Marker& Barpolar::Unselected::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Barpolar::Unselected::Marker& Barpolar::Unselected::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}


Barpolar::Unselected::Textfont& Barpolar::Unselected::Textfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Barpolar::Unselected::Textfont& Barpolar::Unselected::Textfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

} // namespace plotlypp

