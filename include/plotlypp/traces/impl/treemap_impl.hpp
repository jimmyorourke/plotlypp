// TODO: includes, copyright, etc

namespace plotlypp {

std::string Treemap::to_string(Branchvalues e) {
    switch(e) {
        case Branchvalues::REMAINDER: return "remainder";
        case Branchvalues::TOTAL: return "total";
    }
}
std::string Treemap::to_string(Textposition e) {
    switch(e) {
        case Textposition::TOP_LEFT: return "top left";
        case Textposition::TOP_CENTER: return "top center";
        case Textposition::TOP_RIGHT: return "top right";
        case Textposition::MIDDLE_LEFT: return "middle left";
        case Textposition::MIDDLE_CENTER: return "middle center";
        case Textposition::MIDDLE_RIGHT: return "middle right";
        case Textposition::BOTTOM_LEFT: return "bottom left";
        case Textposition::BOTTOM_CENTER: return "bottom center";
        case Textposition::BOTTOM_RIGHT: return "bottom right";
    }
}
std::string Treemap::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}

Treemap& Treemap::branchvalues(enum Branchvalues f) {
    json["branchvalues"] = to_string(f);
    return *this;
}

Treemap& Treemap::count(std::string f) {
    json["count"] = std::move(f);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Treemap& Treemap::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::domain(class Domain f) {
    json["domain"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Treemap& Treemap::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Treemap& Treemap::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Treemap& Treemap::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Treemap& Treemap::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::hovertext(std::string f) {
    json["hovertext"] = std::move(f);
    return *this;
}
Treemap& Treemap::hovertext(std::vector<std::string> f) {
    json["hovertext"] = std::move(f);
    return *this;
}

Treemap& Treemap::hovertextsrc(std::string f) {
    json["hovertextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Treemap& Treemap::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::insidetextfont(class Insidetextfont f) {
    json["insidetextfont"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::labels(std::vector<T> f) {
    json["labels"] = std::move(f);
    return *this;
}

Treemap& Treemap::labelssrc(std::string f) {
    json["labelssrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Treemap& Treemap::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Treemap& Treemap::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

template <typename T>
Treemap& Treemap::level(T f) {
    json["level"] = std::move(f);
    return *this;
}

Treemap& Treemap::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::maxdepth(int f) {
    json["maxdepth"] = std::move(f);
    return *this;
}

template <typename T>
Treemap& Treemap::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Treemap& Treemap::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Treemap& Treemap::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Treemap& Treemap::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Treemap& Treemap::outsidetextfont(class Outsidetextfont f) {
    json["outsidetextfont"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::parents(std::vector<T> f) {
    json["parents"] = std::move(f);
    return *this;
}

Treemap& Treemap::parentssrc(std::string f) {
    json["parentssrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::pathbar(class Pathbar f) {
    json["pathbar"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::root(class Root f) {
    json["root"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::sort(bool f) {
    json["sort"] = std::move(f);
    return *this;
}

Treemap& Treemap::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::text(std::vector<T> f) {
    json["text"] = std::move(f);
    return *this;
}

Treemap& Treemap::textfont(class Textfont f) {
    json["textfont"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::textinfo(std::string f) {
    json["textinfo"] = std::move(f);
    return *this;
}

Treemap& Treemap::textposition(enum Textposition f) {
    json["textposition"] = to_string(f);
    return *this;
}

Treemap& Treemap::textsrc(std::string f) {
    json["textsrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::texttemplate(std::string f) {
    json["texttemplate"] = std::move(f);
    return *this;
}
Treemap& Treemap::texttemplate(std::vector<std::string> f) {
    json["texttemplate"] = std::move(f);
    return *this;
}

Treemap& Treemap::texttemplatesrc(std::string f) {
    json["texttemplatesrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::tiling(class Tiling f) {
    json["tiling"] = std::move(f.json);
    return *this;
}

Treemap& Treemap::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Treemap& Treemap::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

template <typename T, typename>
Treemap& Treemap::values(std::vector<T> f) {
    json["values"] = std::move(f);
    return *this;
}

Treemap& Treemap::valuessrc(std::string f) {
    json["valuessrc"] = std::move(f);
    return *this;
}

Treemap& Treemap::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}


Treemap::Domain& Treemap::Domain::column(int f) {
    json["column"] = std::move(f);
    return *this;
}

Treemap::Domain& Treemap::Domain::row(int f) {
    json["row"] = std::move(f);
    return *this;
}

Treemap::Domain& Treemap::Domain::x(std::vector<std::string> f) {
    json["x"] = std::move(f);
    return *this;
}

Treemap::Domain& Treemap::Domain::y(std::vector<std::string> f) {
    json["y"] = std::move(f);
    return *this;
}

std::string Treemap::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Treemap::Hoverlabel& Treemap::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel& Treemap::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel& Treemap::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Treemap::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Treemap::Hoverlabel::Font& Treemap::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}

std::string Treemap::Insidetextfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Insidetextfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Insidetextfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Insidetextfont& Treemap::Insidetextfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Treemap::Insidetextfont& Treemap::Insidetextfont::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Treemap::Insidetextfont& Treemap::Insidetextfont::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Treemap::Legendgrouptitle& Treemap::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Treemap::Legendgrouptitle& Treemap::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Treemap::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Treemap::Legendgrouptitle::Font& Treemap::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}

std::string Treemap::Marker::to_string(Depthfade e) {
    switch(e) {
        case Depthfade::TRUE: return "True";
        case Depthfade::FALSE: return "False";
        case Depthfade::REVERSED: return "reversed";
    }
}

Treemap::Marker& Treemap::Marker::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::cauto(bool f) {
    json["cauto"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::cmax(double f) {
    json["cmax"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::cmid(double f) {
    json["cmid"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::cmin(double f) {
    json["cmin"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Treemap::Marker& Treemap::Marker::colors(std::vector<T> f) {
    json["colors"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Treemap::Marker& Treemap::Marker::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::colorssrc(std::string f) {
    json["colorssrc"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::cornerradius(double f) {
    json["cornerradius"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::depthfade(enum Depthfade f) {
    json["depthfade"] = to_string(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Treemap::Marker& Treemap::Marker::pad(class Pad f) {
    json["pad"] = std::move(f.json);
    return *this;
}

Treemap::Marker& Treemap::Marker::pattern(class Pattern f) {
    json["pattern"] = std::move(f.json);
    return *this;
}

Treemap::Marker& Treemap::Marker::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Treemap::Marker& Treemap::Marker::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

std::string Treemap::Marker::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Ticklabelposition e) {
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
std::string Treemap::Marker::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Treemap::Marker::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar& Treemap::Marker::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Treemap::Marker::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Marker::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Marker::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickfont& Treemap::Marker::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Treemap::Marker::Colorbar::Tickformatstops& Treemap::Marker::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop& Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop& Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop& Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop& Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop& Treemap::Marker::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Treemap::Marker::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Treemap::Marker::Colorbar::Title& Treemap::Marker::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Treemap::Marker::Colorbar::Title& Treemap::Marker::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Title& Treemap::Marker::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Treemap::Marker::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Marker::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Marker::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Treemap::Marker::Colorbar::Title::Font& Treemap::Marker::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Treemap::Marker::Line& Treemap::Marker::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Marker::Line& Treemap::Marker::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Marker::Line& Treemap::Marker::Line::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Marker::Line& Treemap::Marker::Line::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Marker::Line& Treemap::Marker::Line::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Line& Treemap::Marker::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}
Treemap::Marker::Line& Treemap::Marker::Line::width(std::vector<double> f) {
    json["width"] = std::move(f);
    return *this;
}

Treemap::Marker::Line& Treemap::Marker::Line::widthsrc(std::string f) {
    json["widthsrc"] = std::move(f);
    return *this;
}


Treemap::Marker::Pad& Treemap::Marker::Pad::b(double f) {
    json["b"] = std::move(f);
    return *this;
}

Treemap::Marker::Pad& Treemap::Marker::Pad::l(double f) {
    json["l"] = std::move(f);
    return *this;
}

Treemap::Marker::Pad& Treemap::Marker::Pad::r(double f) {
    json["r"] = std::move(f);
    return *this;
}

Treemap::Marker::Pad& Treemap::Marker::Pad::t(double f) {
    json["t"] = std::move(f);
    return *this;
}

std::string Treemap::Marker::Pattern::to_string(Fillmode e) {
    switch(e) {
        case Fillmode::REPLACE: return "replace";
        case Fillmode::OVERLAY: return "overlay";
    }
}
std::string Treemap::Marker::Pattern::to_string(Shape e) {
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

Treemap::Marker::Pattern& Treemap::Marker::Pattern::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgcolor(std::string f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgcolor(double f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgcolor(std::vector<std::string> f) {
    json["fgcolor"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgcolor(std::vector<double> f) {
    json["fgcolor"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgcolorsrc(std::string f) {
    json["fgcolorsrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::fgopacity(double f) {
    json["fgopacity"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::fillmode(enum Fillmode f) {
    json["fillmode"] = to_string(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::shape(enum Shape f) {
    json["shape"] = to_string(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::shape(const std::vector<enum Shape>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["shape"] = std::move(stringified);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::shapesrc(std::string f) {
    json["shapesrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::solidity(double f) {
    json["solidity"] = std::move(f);
    return *this;
}
Treemap::Marker::Pattern& Treemap::Marker::Pattern::solidity(std::vector<double> f) {
    json["solidity"] = std::move(f);
    return *this;
}

Treemap::Marker::Pattern& Treemap::Marker::Pattern::soliditysrc(std::string f) {
    json["soliditysrc"] = std::move(f);
    return *this;
}

std::string Treemap::Outsidetextfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Outsidetextfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Outsidetextfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Treemap::Outsidetextfont& Treemap::Outsidetextfont::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Treemap::Outsidetextfont& Treemap::Outsidetextfont::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}

std::string Treemap::Pathbar::to_string(Edgeshape e) {
    switch(e) {
        case Edgeshape::GT: return ">";
        case Edgeshape::LT: return "<";
        case Edgeshape::OR: return "|";
        case Edgeshape::SLASH: return "/";
        case Edgeshape::DOUBLEBACKSLASH: return "\\";
    }
}
std::string Treemap::Pathbar::to_string(Side e) {
    switch(e) {
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Treemap::Pathbar& Treemap::Pathbar::edgeshape(enum Edgeshape f) {
    json["edgeshape"] = to_string(f);
    return *this;
}

Treemap::Pathbar& Treemap::Pathbar::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Treemap::Pathbar& Treemap::Pathbar::textfont(class Textfont f) {
    json["textfont"] = std::move(f.json);
    return *this;
}

Treemap::Pathbar& Treemap::Pathbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Treemap::Pathbar& Treemap::Pathbar::visible(bool f) {
    json["visible"] = std::move(f);
    return *this;
}

std::string Treemap::Pathbar::Textfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Pathbar::Textfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Pathbar::Textfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Treemap::Pathbar::Textfont& Treemap::Pathbar::Textfont::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Treemap::Root& Treemap::Root::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Root& Treemap::Root::color(double f) {
    json["color"] = std::move(f);
    return *this;
}


Treemap::Stream& Treemap::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Treemap::Stream& Treemap::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

std::string Treemap::Textfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Treemap::Textfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Treemap::Textfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Treemap::Textfont& Treemap::Textfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Treemap::Textfont& Treemap::Textfont::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Treemap::Textfont& Treemap::Textfont::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}

std::string Treemap::Tiling::to_string(Packing e) {
    switch(e) {
        case Packing::SQUARIFY: return "squarify";
        case Packing::BINARY: return "binary";
        case Packing::DICE: return "dice";
        case Packing::SLICE: return "slice";
        case Packing::SLICE_DICE: return "slice-dice";
        case Packing::DICE_SLICE: return "dice-slice";
    }
}

Treemap::Tiling& Treemap::Tiling::flip(std::string f) {
    json["flip"] = std::move(f);
    return *this;
}

Treemap::Tiling& Treemap::Tiling::packing(enum Packing f) {
    json["packing"] = to_string(f);
    return *this;
}

Treemap::Tiling& Treemap::Tiling::pad(double f) {
    json["pad"] = std::move(f);
    return *this;
}

Treemap::Tiling& Treemap::Tiling::squarifyratio(double f) {
    json["squarifyratio"] = std::move(f);
    return *this;
}

} // namespace plotlypp

