// TODO: includes, copyright, etc

namespace plotlypp {

std::string Box::to_string(Boxmean e) {
    switch(e) {
        case Boxmean::TRUE: return "True";
        case Boxmean::SD: return "sd";
        case Boxmean::FALSE: return "False";
    }
}
std::string Box::to_string(Boxpoints e) {
    switch(e) {
        case Boxpoints::ALL: return "all";
        case Boxpoints::OUTLIERS: return "outliers";
        case Boxpoints::SUSPECTEDOUTLIERS: return "suspectedoutliers";
        case Boxpoints::FALSE: return "False";
    }
}
std::string Box::to_string(Orientation e) {
    switch(e) {
        case Orientation::V: return "v";
        case Orientation::H: return "h";
    }
}
std::string Box::to_string(Quartilemethod e) {
    switch(e) {
        case Quartilemethod::LINEAR: return "linear";
        case Quartilemethod::EXCLUSIVE: return "exclusive";
        case Quartilemethod::INCLUSIVE: return "inclusive";
    }
}
std::string Box::to_string(Sizemode e) {
    switch(e) {
        case Sizemode::QUARTILES: return "quartiles";
        case Sizemode::SD: return "sd";
    }
}
std::string Box::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}
std::string Box::to_string(Xcalendar e) {
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
std::string Box::to_string(Xperiodalignment e) {
    switch(e) {
        case Xperiodalignment::START: return "start";
        case Xperiodalignment::MIDDLE: return "middle";
        case Xperiodalignment::END: return "end";
    }
}
std::string Box::to_string(Ycalendar e) {
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
std::string Box::to_string(Yperiodalignment e) {
    switch(e) {
        case Yperiodalignment::START: return "start";
        case Yperiodalignment::MIDDLE: return "middle";
        case Yperiodalignment::END: return "end";
    }
}

Box& Box::alignmentgroup(std::string f) {
    json["alignmentgroup"] = std::move(f);
    return *this;
}

Box& Box::boxmean(enum Boxmean f) {
    json["boxmean"] = to_string(f);
    return *this;
}

Box& Box::boxpoints(enum Boxpoints f) {
    json["boxpoints"] = to_string(f);
    return *this;
}

template <typename T, typename>
Box& Box::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Box& Box::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Box& Box::dx(double f) {
    json["dx"] = std::move(f);
    return *this;
}

Box& Box::dy(double f) {
    json["dy"] = std::move(f);
    return *this;
}

Box& Box::fillcolor(std::string f) {
    json["fillcolor"] = std::move(f);
    return *this;
}
Box& Box::fillcolor(double f) {
    json["fillcolor"] = std::move(f);
    return *this;
}

Box& Box::hoverinfo(std::string f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}
Box& Box::hoverinfo(std::vector<std::string> f) {
    json["hoverinfo"] = std::move(f);
    return *this;
}

Box& Box::hoverinfosrc(std::string f) {
    json["hoverinfosrc"] = std::move(f);
    return *this;
}

Box& Box::hoverlabel(class Hoverlabel f) {
    json["hoverlabel"] = std::move(f.json);
    return *this;
}

Box& Box::hoveron(std::string f) {
    json["hoveron"] = std::move(f);
    return *this;
}

Box& Box::hovertemplate(std::string f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}
Box& Box::hovertemplate(std::vector<std::string> f) {
    json["hovertemplate"] = std::move(f);
    return *this;
}

Box& Box::hovertemplatesrc(std::string f) {
    json["hovertemplatesrc"] = std::move(f);
    return *this;
}

Box& Box::hovertext(std::string f) {
    json["hovertext"] = std::move(f);
    return *this;
}
Box& Box::hovertext(std::vector<std::string> f) {
    json["hovertext"] = std::move(f);
    return *this;
}

Box& Box::hovertextsrc(std::string f) {
    json["hovertextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Box& Box::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Box& Box::jitter(double f) {
    json["jitter"] = std::move(f);
    return *this;
}

Box& Box::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Box& Box::legendgroup(std::string f) {
    json["legendgroup"] = std::move(f);
    return *this;
}

Box& Box::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Box& Box::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Box& Box::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

Box& Box::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Box& Box::lowerfence(std::vector<T> f) {
    json["lowerfence"] = std::move(f);
    return *this;
}

Box& Box::lowerfencesrc(std::string f) {
    json["lowerfencesrc"] = std::move(f);
    return *this;
}

Box& Box::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Box& Box::mean(std::vector<T> f) {
    json["mean"] = std::move(f);
    return *this;
}

Box& Box::meansrc(std::string f) {
    json["meansrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::median(std::vector<T> f) {
    json["median"] = std::move(f);
    return *this;
}

Box& Box::mediansrc(std::string f) {
    json["mediansrc"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Box& Box::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Box& Box::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Box& Box::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Box& Box::notched(bool f) {
    json["notched"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::notchspan(std::vector<T> f) {
    json["notchspan"] = std::move(f);
    return *this;
}

Box& Box::notchspansrc(std::string f) {
    json["notchspansrc"] = std::move(f);
    return *this;
}

Box& Box::notchwidth(double f) {
    json["notchwidth"] = std::move(f);
    return *this;
}

Box& Box::offsetgroup(std::string f) {
    json["offsetgroup"] = std::move(f);
    return *this;
}

Box& Box::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Box& Box::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Box& Box::pointpos(double f) {
    json["pointpos"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::q1(std::vector<T> f) {
    json["q1"] = std::move(f);
    return *this;
}

Box& Box::q1src(std::string f) {
    json["q1src"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::q3(std::vector<T> f) {
    json["q3"] = std::move(f);
    return *this;
}

Box& Box::q3src(std::string f) {
    json["q3src"] = std::move(f);
    return *this;
}

Box& Box::quartilemethod(enum Quartilemethod f) {
    json["quartilemethod"] = to_string(f);
    return *this;
}

template <typename T, typename>
Box& Box::sd(std::vector<T> f) {
    json["sd"] = std::move(f);
    return *this;
}

Box& Box::sdmultiple(double f) {
    json["sdmultiple"] = std::move(f);
    return *this;
}

Box& Box::sdsrc(std::string f) {
    json["sdsrc"] = std::move(f);
    return *this;
}

Box& Box::selected(class Selected f) {
    json["selected"] = std::move(f.json);
    return *this;
}

template <typename T>
Box& Box::selectedpoints(T f) {
    json["selectedpoints"] = std::move(f);
    return *this;
}

Box& Box::showlegend(bool f) {
    json["showlegend"] = std::move(f);
    return *this;
}

Box& Box::showwhiskers(bool f) {
    json["showwhiskers"] = std::move(f);
    return *this;
}

Box& Box::sizemode(enum Sizemode f) {
    json["sizemode"] = to_string(f);
    return *this;
}

Box& Box::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Box& Box::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}
Box& Box::text(std::vector<std::string> f) {
    json["text"] = std::move(f);
    return *this;
}

Box& Box::textsrc(std::string f) {
    json["textsrc"] = std::move(f);
    return *this;
}

Box& Box::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Box& Box::unselected(class Unselected f) {
    json["unselected"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Box& Box::upperfence(std::vector<T> f) {
    json["upperfence"] = std::move(f);
    return *this;
}

Box& Box::upperfencesrc(std::string f) {
    json["upperfencesrc"] = std::move(f);
    return *this;
}

Box& Box::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

Box& Box::whiskerwidth(double f) {
    json["whiskerwidth"] = std::move(f);
    return *this;
}

Box& Box::width(double f) {
    json["width"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::x(std::vector<T> f) {
    json["x"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::x0(T f) {
    json["x0"] = std::move(f);
    return *this;
}

Box& Box::xaxis(std::string f) {
    json["xaxis"] = std::move(f);
    return *this;
}

Box& Box::xcalendar(enum Xcalendar f) {
    json["xcalendar"] = to_string(f);
    return *this;
}

Box& Box::xhoverformat(std::string f) {
    json["xhoverformat"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::xperiod(T f) {
    json["xperiod"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::xperiod0(T f) {
    json["xperiod0"] = std::move(f);
    return *this;
}

Box& Box::xperiodalignment(enum Xperiodalignment f) {
    json["xperiodalignment"] = to_string(f);
    return *this;
}

Box& Box::xsrc(std::string f) {
    json["xsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Box& Box::y(std::vector<T> f) {
    json["y"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::y0(T f) {
    json["y0"] = std::move(f);
    return *this;
}

Box& Box::yaxis(std::string f) {
    json["yaxis"] = std::move(f);
    return *this;
}

Box& Box::ycalendar(enum Ycalendar f) {
    json["ycalendar"] = to_string(f);
    return *this;
}

Box& Box::yhoverformat(std::string f) {
    json["yhoverformat"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::yperiod(T f) {
    json["yperiod"] = std::move(f);
    return *this;
}

template <typename T>
Box& Box::yperiod0(T f) {
    json["yperiod0"] = std::move(f);
    return *this;
}

Box& Box::yperiodalignment(enum Yperiodalignment f) {
    json["yperiodalignment"] = to_string(f);
    return *this;
}

Box& Box::ysrc(std::string f) {
    json["ysrc"] = std::move(f);
    return *this;
}

Box& Box::zorder(int f) {
    json["zorder"] = std::move(f);
    return *this;
}

std::string Box::Hoverlabel::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::RIGHT: return "right";
        case Align::AUTO: return "auto";
    }
}

Box::Hoverlabel& Box::Hoverlabel::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::align(const std::vector<enum Align>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["align"] = std::move(stringified);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::alignsrc(std::string f) {
    json["alignsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bgcolor(std::vector<std::string> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bgcolor(std::vector<double> f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::bgcolorsrc(std::string f) {
    json["bgcolorsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bordercolor(std::vector<std::string> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::bordercolor(std::vector<double> f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::bordercolorsrc(std::string f) {
    json["bordercolorsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::namelength(int f) {
    json["namelength"] = std::move(f);
    return *this;
}
Box::Hoverlabel& Box::Hoverlabel::namelength(std::vector<int> f) {
    json["namelength"] = std::move(f);
    return *this;
}

Box::Hoverlabel& Box::Hoverlabel::namelengthsrc(std::string f) {
    json["namelengthsrc"] = std::move(f);
    return *this;
}

std::string Box::Hoverlabel::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Box::Hoverlabel::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Box::Hoverlabel::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::family(std::vector<std::string> f) {
    json["family"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::familysrc(std::string f) {
    json["familysrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::lineposition(std::vector<std::string> f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::linepositionsrc(std::string f) {
    json["linepositionsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::shadow(std::vector<std::string> f) {
    json["shadow"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::shadowsrc(std::string f) {
    json["shadowsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::size(std::vector<double> f) {
    json["size"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::sizesrc(std::string f) {
    json["sizesrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::style(const std::vector<enum Style>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["style"] = std::move(stringified);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::stylesrc(std::string f) {
    json["stylesrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::textcase(const std::vector<enum Textcase>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["textcase"] = std::move(stringified);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::textcasesrc(std::string f) {
    json["textcasesrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::variant(const std::vector<enum Variant>& f) {
    std::vector<std::string> stringified(f.size());
    std::transform(f.begin(), f.end(), stringified.begin(), [this](const auto& e){return to_string(e);});
    json["variant"] = std::move(stringified);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::variantsrc(std::string f) {
    json["variantsrc"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}
Box::Hoverlabel::Font& Box::Hoverlabel::Font::weight(std::vector<int> f) {
    json["weight"] = std::move(f);
    return *this;
}

Box::Hoverlabel::Font& Box::Hoverlabel::Font::weightsrc(std::string f) {
    json["weightsrc"] = std::move(f);
    return *this;
}


Box::Legendgrouptitle& Box::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Box::Legendgrouptitle& Box::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Box::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Box::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Box::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Box::Legendgrouptitle::Font& Box::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Box::Line& Box::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Line& Box::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Line& Box::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}

std::string Box::Marker::to_string(Symbol e) {
    switch(e) {
        case Symbol::NUM_0: return "0";
        case Symbol::CIRCLE: return "circle";
        case Symbol::NUM_100: return "100";
        case Symbol::CIRCLE_OPEN: return "circle-open";
        case Symbol::NUM_200: return "200";
        case Symbol::CIRCLE_DOT: return "circle-dot";
        case Symbol::NUM_300: return "300";
        case Symbol::CIRCLE_OPEN_DOT: return "circle-open-dot";
        case Symbol::NUM_1: return "1";
        case Symbol::SQUARE: return "square";
        case Symbol::NUM_101: return "101";
        case Symbol::SQUARE_OPEN: return "square-open";
        case Symbol::NUM_201: return "201";
        case Symbol::SQUARE_DOT: return "square-dot";
        case Symbol::NUM_301: return "301";
        case Symbol::SQUARE_OPEN_DOT: return "square-open-dot";
        case Symbol::NUM_2: return "2";
        case Symbol::DIAMOND: return "diamond";
        case Symbol::NUM_102: return "102";
        case Symbol::DIAMOND_OPEN: return "diamond-open";
        case Symbol::NUM_202: return "202";
        case Symbol::DIAMOND_DOT: return "diamond-dot";
        case Symbol::NUM_302: return "302";
        case Symbol::DIAMOND_OPEN_DOT: return "diamond-open-dot";
        case Symbol::NUM_3: return "3";
        case Symbol::CROSS: return "cross";
        case Symbol::NUM_103: return "103";
        case Symbol::CROSS_OPEN: return "cross-open";
        case Symbol::NUM_203: return "203";
        case Symbol::CROSS_DOT: return "cross-dot";
        case Symbol::NUM_303: return "303";
        case Symbol::CROSS_OPEN_DOT: return "cross-open-dot";
        case Symbol::NUM_4: return "4";
        case Symbol::X: return "x";
        case Symbol::NUM_104: return "104";
        case Symbol::X_OPEN: return "x-open";
        case Symbol::NUM_204: return "204";
        case Symbol::X_DOT: return "x-dot";
        case Symbol::NUM_304: return "304";
        case Symbol::X_OPEN_DOT: return "x-open-dot";
        case Symbol::NUM_5: return "5";
        case Symbol::TRIANGLE_UP: return "triangle-up";
        case Symbol::NUM_105: return "105";
        case Symbol::TRIANGLE_UP_OPEN: return "triangle-up-open";
        case Symbol::NUM_205: return "205";
        case Symbol::TRIANGLE_UP_DOT: return "triangle-up-dot";
        case Symbol::NUM_305: return "305";
        case Symbol::TRIANGLE_UP_OPEN_DOT: return "triangle-up-open-dot";
        case Symbol::NUM_6: return "6";
        case Symbol::TRIANGLE_DOWN: return "triangle-down";
        case Symbol::NUM_106: return "106";
        case Symbol::TRIANGLE_DOWN_OPEN: return "triangle-down-open";
        case Symbol::NUM_206: return "206";
        case Symbol::TRIANGLE_DOWN_DOT: return "triangle-down-dot";
        case Symbol::NUM_306: return "306";
        case Symbol::TRIANGLE_DOWN_OPEN_DOT: return "triangle-down-open-dot";
        case Symbol::NUM_7: return "7";
        case Symbol::TRIANGLE_LEFT: return "triangle-left";
        case Symbol::NUM_107: return "107";
        case Symbol::TRIANGLE_LEFT_OPEN: return "triangle-left-open";
        case Symbol::NUM_207: return "207";
        case Symbol::TRIANGLE_LEFT_DOT: return "triangle-left-dot";
        case Symbol::NUM_307: return "307";
        case Symbol::TRIANGLE_LEFT_OPEN_DOT: return "triangle-left-open-dot";
        case Symbol::NUM_8: return "8";
        case Symbol::TRIANGLE_RIGHT: return "triangle-right";
        case Symbol::NUM_108: return "108";
        case Symbol::TRIANGLE_RIGHT_OPEN: return "triangle-right-open";
        case Symbol::NUM_208: return "208";
        case Symbol::TRIANGLE_RIGHT_DOT: return "triangle-right-dot";
        case Symbol::NUM_308: return "308";
        case Symbol::TRIANGLE_RIGHT_OPEN_DOT: return "triangle-right-open-dot";
        case Symbol::NUM_9: return "9";
        case Symbol::TRIANGLE_NE: return "triangle-ne";
        case Symbol::NUM_109: return "109";
        case Symbol::TRIANGLE_NE_OPEN: return "triangle-ne-open";
        case Symbol::NUM_209: return "209";
        case Symbol::TRIANGLE_NE_DOT: return "triangle-ne-dot";
        case Symbol::NUM_309: return "309";
        case Symbol::TRIANGLE_NE_OPEN_DOT: return "triangle-ne-open-dot";
        case Symbol::NUM_10: return "10";
        case Symbol::TRIANGLE_SE: return "triangle-se";
        case Symbol::NUM_110: return "110";
        case Symbol::TRIANGLE_SE_OPEN: return "triangle-se-open";
        case Symbol::NUM_210: return "210";
        case Symbol::TRIANGLE_SE_DOT: return "triangle-se-dot";
        case Symbol::NUM_310: return "310";
        case Symbol::TRIANGLE_SE_OPEN_DOT: return "triangle-se-open-dot";
        case Symbol::NUM_11: return "11";
        case Symbol::TRIANGLE_SW: return "triangle-sw";
        case Symbol::NUM_111: return "111";
        case Symbol::TRIANGLE_SW_OPEN: return "triangle-sw-open";
        case Symbol::NUM_211: return "211";
        case Symbol::TRIANGLE_SW_DOT: return "triangle-sw-dot";
        case Symbol::NUM_311: return "311";
        case Symbol::TRIANGLE_SW_OPEN_DOT: return "triangle-sw-open-dot";
        case Symbol::NUM_12: return "12";
        case Symbol::TRIANGLE_NW: return "triangle-nw";
        case Symbol::NUM_112: return "112";
        case Symbol::TRIANGLE_NW_OPEN: return "triangle-nw-open";
        case Symbol::NUM_212: return "212";
        case Symbol::TRIANGLE_NW_DOT: return "triangle-nw-dot";
        case Symbol::NUM_312: return "312";
        case Symbol::TRIANGLE_NW_OPEN_DOT: return "triangle-nw-open-dot";
        case Symbol::NUM_13: return "13";
        case Symbol::PENTAGON: return "pentagon";
        case Symbol::NUM_113: return "113";
        case Symbol::PENTAGON_OPEN: return "pentagon-open";
        case Symbol::NUM_213: return "213";
        case Symbol::PENTAGON_DOT: return "pentagon-dot";
        case Symbol::NUM_313: return "313";
        case Symbol::PENTAGON_OPEN_DOT: return "pentagon-open-dot";
        case Symbol::NUM_14: return "14";
        case Symbol::HEXAGON: return "hexagon";
        case Symbol::NUM_114: return "114";
        case Symbol::HEXAGON_OPEN: return "hexagon-open";
        case Symbol::NUM_214: return "214";
        case Symbol::HEXAGON_DOT: return "hexagon-dot";
        case Symbol::NUM_314: return "314";
        case Symbol::HEXAGON_OPEN_DOT: return "hexagon-open-dot";
        case Symbol::NUM_15: return "15";
        case Symbol::HEXAGON2: return "hexagon2";
        case Symbol::NUM_115: return "115";
        case Symbol::HEXAGON2_OPEN: return "hexagon2-open";
        case Symbol::NUM_215: return "215";
        case Symbol::HEXAGON2_DOT: return "hexagon2-dot";
        case Symbol::NUM_315: return "315";
        case Symbol::HEXAGON2_OPEN_DOT: return "hexagon2-open-dot";
        case Symbol::NUM_16: return "16";
        case Symbol::OCTAGON: return "octagon";
        case Symbol::NUM_116: return "116";
        case Symbol::OCTAGON_OPEN: return "octagon-open";
        case Symbol::NUM_216: return "216";
        case Symbol::OCTAGON_DOT: return "octagon-dot";
        case Symbol::NUM_316: return "316";
        case Symbol::OCTAGON_OPEN_DOT: return "octagon-open-dot";
        case Symbol::NUM_17: return "17";
        case Symbol::STAR: return "star";
        case Symbol::NUM_117: return "117";
        case Symbol::STAR_OPEN: return "star-open";
        case Symbol::NUM_217: return "217";
        case Symbol::STAR_DOT: return "star-dot";
        case Symbol::NUM_317: return "317";
        case Symbol::STAR_OPEN_DOT: return "star-open-dot";
        case Symbol::NUM_18: return "18";
        case Symbol::HEXAGRAM: return "hexagram";
        case Symbol::NUM_118: return "118";
        case Symbol::HEXAGRAM_OPEN: return "hexagram-open";
        case Symbol::NUM_218: return "218";
        case Symbol::HEXAGRAM_DOT: return "hexagram-dot";
        case Symbol::NUM_318: return "318";
        case Symbol::HEXAGRAM_OPEN_DOT: return "hexagram-open-dot";
        case Symbol::NUM_19: return "19";
        case Symbol::STAR_TRIANGLE_UP: return "star-triangle-up";
        case Symbol::NUM_119: return "119";
        case Symbol::STAR_TRIANGLE_UP_OPEN: return "star-triangle-up-open";
        case Symbol::NUM_219: return "219";
        case Symbol::STAR_TRIANGLE_UP_DOT: return "star-triangle-up-dot";
        case Symbol::NUM_319: return "319";
        case Symbol::STAR_TRIANGLE_UP_OPEN_DOT: return "star-triangle-up-open-dot";
        case Symbol::NUM_20: return "20";
        case Symbol::STAR_TRIANGLE_DOWN: return "star-triangle-down";
        case Symbol::NUM_120: return "120";
        case Symbol::STAR_TRIANGLE_DOWN_OPEN: return "star-triangle-down-open";
        case Symbol::NUM_220: return "220";
        case Symbol::STAR_TRIANGLE_DOWN_DOT: return "star-triangle-down-dot";
        case Symbol::NUM_320: return "320";
        case Symbol::STAR_TRIANGLE_DOWN_OPEN_DOT: return "star-triangle-down-open-dot";
        case Symbol::NUM_21: return "21";
        case Symbol::STAR_SQUARE: return "star-square";
        case Symbol::NUM_121: return "121";
        case Symbol::STAR_SQUARE_OPEN: return "star-square-open";
        case Symbol::NUM_221: return "221";
        case Symbol::STAR_SQUARE_DOT: return "star-square-dot";
        case Symbol::NUM_321: return "321";
        case Symbol::STAR_SQUARE_OPEN_DOT: return "star-square-open-dot";
        case Symbol::NUM_22: return "22";
        case Symbol::STAR_DIAMOND: return "star-diamond";
        case Symbol::NUM_122: return "122";
        case Symbol::STAR_DIAMOND_OPEN: return "star-diamond-open";
        case Symbol::NUM_222: return "222";
        case Symbol::STAR_DIAMOND_DOT: return "star-diamond-dot";
        case Symbol::NUM_322: return "322";
        case Symbol::STAR_DIAMOND_OPEN_DOT: return "star-diamond-open-dot";
        case Symbol::NUM_23: return "23";
        case Symbol::DIAMOND_TALL: return "diamond-tall";
        case Symbol::NUM_123: return "123";
        case Symbol::DIAMOND_TALL_OPEN: return "diamond-tall-open";
        case Symbol::NUM_223: return "223";
        case Symbol::DIAMOND_TALL_DOT: return "diamond-tall-dot";
        case Symbol::NUM_323: return "323";
        case Symbol::DIAMOND_TALL_OPEN_DOT: return "diamond-tall-open-dot";
        case Symbol::NUM_24: return "24";
        case Symbol::DIAMOND_WIDE: return "diamond-wide";
        case Symbol::NUM_124: return "124";
        case Symbol::DIAMOND_WIDE_OPEN: return "diamond-wide-open";
        case Symbol::NUM_224: return "224";
        case Symbol::DIAMOND_WIDE_DOT: return "diamond-wide-dot";
        case Symbol::NUM_324: return "324";
        case Symbol::DIAMOND_WIDE_OPEN_DOT: return "diamond-wide-open-dot";
        case Symbol::NUM_25: return "25";
        case Symbol::HOURGLASS: return "hourglass";
        case Symbol::NUM_125: return "125";
        case Symbol::HOURGLASS_OPEN: return "hourglass-open";
        case Symbol::NUM_26: return "26";
        case Symbol::BOWTIE: return "bowtie";
        case Symbol::NUM_126: return "126";
        case Symbol::BOWTIE_OPEN: return "bowtie-open";
        case Symbol::NUM_27: return "27";
        case Symbol::CIRCLE_CROSS: return "circle-cross";
        case Symbol::NUM_127: return "127";
        case Symbol::CIRCLE_CROSS_OPEN: return "circle-cross-open";
        case Symbol::NUM_28: return "28";
        case Symbol::CIRCLE_X: return "circle-x";
        case Symbol::NUM_128: return "128";
        case Symbol::CIRCLE_X_OPEN: return "circle-x-open";
        case Symbol::NUM_29: return "29";
        case Symbol::SQUARE_CROSS: return "square-cross";
        case Symbol::NUM_129: return "129";
        case Symbol::SQUARE_CROSS_OPEN: return "square-cross-open";
        case Symbol::NUM_30: return "30";
        case Symbol::SQUARE_X: return "square-x";
        case Symbol::NUM_130: return "130";
        case Symbol::SQUARE_X_OPEN: return "square-x-open";
        case Symbol::NUM_31: return "31";
        case Symbol::DIAMOND_CROSS: return "diamond-cross";
        case Symbol::NUM_131: return "131";
        case Symbol::DIAMOND_CROSS_OPEN: return "diamond-cross-open";
        case Symbol::NUM_32: return "32";
        case Symbol::DIAMOND_X: return "diamond-x";
        case Symbol::NUM_132: return "132";
        case Symbol::DIAMOND_X_OPEN: return "diamond-x-open";
        case Symbol::NUM_33: return "33";
        case Symbol::CROSS_THIN: return "cross-thin";
        case Symbol::NUM_133: return "133";
        case Symbol::CROSS_THIN_OPEN: return "cross-thin-open";
        case Symbol::NUM_34: return "34";
        case Symbol::X_THIN: return "x-thin";
        case Symbol::NUM_134: return "134";
        case Symbol::X_THIN_OPEN: return "x-thin-open";
        case Symbol::NUM_35: return "35";
        case Symbol::ASTERISK: return "asterisk";
        case Symbol::NUM_135: return "135";
        case Symbol::ASTERISK_OPEN: return "asterisk-open";
        case Symbol::NUM_36: return "36";
        case Symbol::HASH: return "hash";
        case Symbol::NUM_136: return "136";
        case Symbol::HASH_OPEN: return "hash-open";
        case Symbol::NUM_236: return "236";
        case Symbol::HASH_DOT: return "hash-dot";
        case Symbol::NUM_336: return "336";
        case Symbol::HASH_OPEN_DOT: return "hash-open-dot";
        case Symbol::NUM_37: return "37";
        case Symbol::Y_UP: return "y-up";
        case Symbol::NUM_137: return "137";
        case Symbol::Y_UP_OPEN: return "y-up-open";
        case Symbol::NUM_38: return "38";
        case Symbol::Y_DOWN: return "y-down";
        case Symbol::NUM_138: return "138";
        case Symbol::Y_DOWN_OPEN: return "y-down-open";
        case Symbol::NUM_39: return "39";
        case Symbol::Y_LEFT: return "y-left";
        case Symbol::NUM_139: return "139";
        case Symbol::Y_LEFT_OPEN: return "y-left-open";
        case Symbol::NUM_40: return "40";
        case Symbol::Y_RIGHT: return "y-right";
        case Symbol::NUM_140: return "140";
        case Symbol::Y_RIGHT_OPEN: return "y-right-open";
        case Symbol::NUM_41: return "41";
        case Symbol::LINE_EW: return "line-ew";
        case Symbol::NUM_141: return "141";
        case Symbol::LINE_EW_OPEN: return "line-ew-open";
        case Symbol::NUM_42: return "42";
        case Symbol::LINE_NS: return "line-ns";
        case Symbol::NUM_142: return "142";
        case Symbol::LINE_NS_OPEN: return "line-ns-open";
        case Symbol::NUM_43: return "43";
        case Symbol::LINE_NE: return "line-ne";
        case Symbol::NUM_143: return "143";
        case Symbol::LINE_NE_OPEN: return "line-ne-open";
        case Symbol::NUM_44: return "44";
        case Symbol::LINE_NW: return "line-nw";
        case Symbol::NUM_144: return "144";
        case Symbol::LINE_NW_OPEN: return "line-nw-open";
        case Symbol::NUM_45: return "45";
        case Symbol::ARROW_UP: return "arrow-up";
        case Symbol::NUM_145: return "145";
        case Symbol::ARROW_UP_OPEN: return "arrow-up-open";
        case Symbol::NUM_46: return "46";
        case Symbol::ARROW_DOWN: return "arrow-down";
        case Symbol::NUM_146: return "146";
        case Symbol::ARROW_DOWN_OPEN: return "arrow-down-open";
        case Symbol::NUM_47: return "47";
        case Symbol::ARROW_LEFT: return "arrow-left";
        case Symbol::NUM_147: return "147";
        case Symbol::ARROW_LEFT_OPEN: return "arrow-left-open";
        case Symbol::NUM_48: return "48";
        case Symbol::ARROW_RIGHT: return "arrow-right";
        case Symbol::NUM_148: return "148";
        case Symbol::ARROW_RIGHT_OPEN: return "arrow-right-open";
        case Symbol::NUM_49: return "49";
        case Symbol::ARROW_BAR_UP: return "arrow-bar-up";
        case Symbol::NUM_149: return "149";
        case Symbol::ARROW_BAR_UP_OPEN: return "arrow-bar-up-open";
        case Symbol::NUM_50: return "50";
        case Symbol::ARROW_BAR_DOWN: return "arrow-bar-down";
        case Symbol::NUM_150: return "150";
        case Symbol::ARROW_BAR_DOWN_OPEN: return "arrow-bar-down-open";
        case Symbol::NUM_51: return "51";
        case Symbol::ARROW_BAR_LEFT: return "arrow-bar-left";
        case Symbol::NUM_151: return "151";
        case Symbol::ARROW_BAR_LEFT_OPEN: return "arrow-bar-left-open";
        case Symbol::NUM_52: return "52";
        case Symbol::ARROW_BAR_RIGHT: return "arrow-bar-right";
        case Symbol::NUM_152: return "152";
        case Symbol::ARROW_BAR_RIGHT_OPEN: return "arrow-bar-right-open";
        case Symbol::NUM_53: return "53";
        case Symbol::ARROW: return "arrow";
        case Symbol::NUM_153: return "153";
        case Symbol::ARROW_OPEN: return "arrow-open";
        case Symbol::NUM_54: return "54";
        case Symbol::ARROW_WIDE: return "arrow-wide";
        case Symbol::NUM_154: return "154";
        case Symbol::ARROW_WIDE_OPEN: return "arrow-wide-open";
    }
}

Box::Marker& Box::Marker::angle(double f) {
    json["angle"] = std::move(f);
    return *this;
}

Box::Marker& Box::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Marker& Box::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Marker& Box::Marker::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Box::Marker& Box::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Box::Marker& Box::Marker::outliercolor(std::string f) {
    json["outliercolor"] = std::move(f);
    return *this;
}
Box::Marker& Box::Marker::outliercolor(double f) {
    json["outliercolor"] = std::move(f);
    return *this;
}

Box::Marker& Box::Marker::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Box::Marker& Box::Marker::symbol(enum Symbol f) {
    json["symbol"] = to_string(f);
    return *this;
}


Box::Marker::Line& Box::Marker::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Marker::Line& Box::Marker::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Marker::Line& Box::Marker::Line::outliercolor(std::string f) {
    json["outliercolor"] = std::move(f);
    return *this;
}
Box::Marker::Line& Box::Marker::Line::outliercolor(double f) {
    json["outliercolor"] = std::move(f);
    return *this;
}

Box::Marker::Line& Box::Marker::Line::outlierwidth(double f) {
    json["outlierwidth"] = std::move(f);
    return *this;
}

Box::Marker::Line& Box::Marker::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}


Box::Selected& Box::Selected::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}


Box::Selected::Marker& Box::Selected::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Selected::Marker& Box::Selected::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Selected::Marker& Box::Selected::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Box::Selected::Marker& Box::Selected::Marker::size(double f) {
    json["size"] = std::move(f);
    return *this;
}


Box::Stream& Box::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Box::Stream& Box::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}


Box::Unselected& Box::Unselected::marker(class Marker f) {
    json["marker"] = std::move(f.json);
    return *this;
}


Box::Unselected::Marker& Box::Unselected::Marker::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Box::Unselected::Marker& Box::Unselected::Marker::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Box::Unselected::Marker& Box::Unselected::Marker::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

Box::Unselected::Marker& Box::Unselected::Marker::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

} // namespace plotlypp

