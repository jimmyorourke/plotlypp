// TODO: includes, copyright, etc

namespace plotlypp {

std::string Parcoords::to_string(Labelside e) {
    switch(e) {
        case Labelside::TOP: return "top";
        case Labelside::BOTTOM: return "bottom";
    }
}
std::string Parcoords::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}

template <typename T, typename>
Parcoords& Parcoords::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::dimensions(class Dimensions f) {
    json["dimensions"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::domain(class Domain f) {
    json["domain"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Parcoords& Parcoords::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::labelangle(double f) {
    json["labelangle"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::labelfont(class Labelfont f) {
    json["labelfont"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::labelside(enum Labelside f) {
    json["labelside"] = to_string(f);
    return *this;
}

Parcoords& Parcoords::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

template <typename T>
Parcoords& Parcoords::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Parcoords& Parcoords::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::rangefont(class Rangefont f) {
    json["rangefont"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Parcoords& Parcoords::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Parcoords& Parcoords::unselected(class Unselected f) {
    json["unselected"] = std::move(f.json);
    return *this;
}

Parcoords& Parcoords::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}


Parcoords::Dimensions& Parcoords::Dimensions::dimension(class Dimension f) {
    json["dimension"] = std::move(f.json);
    return *this;
}


Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::constraintrange(std::vector<std::string> f) {
    json["constraintrange"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::label(std::string f) {
    json["label"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::multiselect(bool f) {
    json["multiselect"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::range(std::vector<std::string> f) {
    json["range"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

template <typename T, typename>
Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::values(std::vector<T> f) {
    json["values"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::valuessrc(std::string f) {
    json["valuessrc"] = std::move(f);
    return *this;
}

Parcoords::Dimensions::Dimension& Parcoords::Dimensions::Dimension::visible(bool f) {
    json["visible"] = std::move(f);
    return *this;
}


Parcoords::Domain& Parcoords::Domain::column(int f) {
    json["column"] = std::move(f);
    return *this;
}

Parcoords::Domain& Parcoords::Domain::row(int f) {
    json["row"] = std::move(f);
    return *this;
}

Parcoords::Domain& Parcoords::Domain::x(std::vector<std::string> f) {
    json["x"] = std::move(f);
    return *this;
}

Parcoords::Domain& Parcoords::Domain::y(std::vector<std::string> f) {
    json["y"] = std::move(f);
    return *this;
}

std::string Parcoords::Labelfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Labelfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Labelfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Labelfont& Parcoords::Labelfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Labelfont& Parcoords::Labelfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Labelfont& Parcoords::Labelfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Parcoords::Legendgrouptitle& Parcoords::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Parcoords::Legendgrouptitle& Parcoords::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Parcoords::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Legendgrouptitle::Font& Parcoords::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Parcoords::Line& Parcoords::Line::autocolorscale(bool f) {
    json["autocolorscale"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::cauto(bool f) {
    json["cauto"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::cmax(double f) {
    json["cmax"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::cmid(double f) {
    json["cmid"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::cmin(double f) {
    json["cmin"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Line& Parcoords::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Line& Parcoords::Line::color(std::vector<std::string> f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Line& Parcoords::Line::color(std::vector<double> f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::coloraxis(std::string f) {
    json["coloraxis"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::colorbar(class Colorbar f) {
    json["colorbar"] = std::move(f.json);
    return *this;
}

Parcoords::Line& Parcoords::Line::colorscale(std::string f) {
    json["colorscale"] = std::move(f);
    return *this;
}
Parcoords::Line& Parcoords::Line::colorscale(std::vector<std::pair<double, std::string>> f) {
    json["colorscale"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::colorsrc(std::string f) {
    json["colorsrc"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::reversescale(bool f) {
    json["reversescale"] = std::move(f);
    return *this;
}

Parcoords::Line& Parcoords::Line::showscale(bool f) {
    json["showscale"] = std::move(f);
    return *this;
}

std::string Parcoords::Line::Colorbar::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Lenmode e) {
    switch(e) {
        case Lenmode::FRACTION: return "fraction";
        case Lenmode::PIXELS: return "pixels";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Orientation e) {
    switch(e) {
        case Orientation::H: return "h";
        case Orientation::V: return "v";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Thicknessmode e) {
    switch(e) {
        case Thicknessmode::FRACTION: return "fraction";
        case Thicknessmode::PIXELS: return "pixels";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Ticklabeloverflow e) {
    switch(e) {
        case Ticklabeloverflow::ALLOW: return "allow";
        case Ticklabeloverflow::HIDE_PAST_DIV: return "hide past div";
        case Ticklabeloverflow::HIDE_PAST_DOMAIN: return "hide past domain";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Ticklabelposition e) {
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
std::string Parcoords::Line::Colorbar::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Xanchor e) {
    switch(e) {
        case Xanchor::LEFT: return "left";
        case Xanchor::CENTER: return "center";
        case Xanchor::RIGHT: return "right";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Xref e) {
    switch(e) {
        case Xref::CONTAINER: return "container";
        case Xref::PAPER: return "paper";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Yanchor e) {
    switch(e) {
        case Yanchor::TOP: return "top";
        case Yanchor::MIDDLE: return "middle";
        case Yanchor::BOTTOM: return "bottom";
    }
}
std::string Parcoords::Line::Colorbar::to_string(Yref e) {
    switch(e) {
        case Yref::CONTAINER: return "container";
        case Yref::PAPER: return "paper";
    }
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

template <typename T>
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::len(double f) {
    json["len"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::lenmode(enum Lenmode f) {
    json["lenmode"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::orientation(enum Orientation f) {
    json["orientation"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::outlinecolor(std::string f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::outlinecolor(double f) {
    json["outlinecolor"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::outlinewidth(double f) {
    json["outlinewidth"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::thicknessmode(enum Thicknessmode f) {
    json["thicknessmode"] = to_string(f);
    return *this;
}

template <typename T>
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticklabeloverflow(enum Ticklabeloverflow f) {
    json["ticklabeloverflow"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticklabelposition(enum Ticklabelposition f) {
    json["ticklabelposition"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::x(double f) {
    json["x"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::xanchor(enum Xanchor f) {
    json["xanchor"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::xpad(double f) {
    json["xpad"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::xref(enum Xref f) {
    json["xref"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::y(double f) {
    json["y"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::yanchor(enum Yanchor f) {
    json["yanchor"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::ypad(double f) {
    json["ypad"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar& Parcoords::Line::Colorbar::yref(enum Yref f) {
    json["yref"] = to_string(f);
    return *this;
}

std::string Parcoords::Line::Colorbar::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Line::Colorbar::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Line::Colorbar::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickfont& Parcoords::Line::Colorbar::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Parcoords::Line::Colorbar::Tickformatstops& Parcoords::Line::Colorbar::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop& Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop& Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop& Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop& Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop& Parcoords::Line::Colorbar::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}

std::string Parcoords::Line::Colorbar::Title::to_string(Side e) {
    switch(e) {
        case Side::RIGHT: return "right";
        case Side::TOP: return "top";
        case Side::BOTTOM: return "bottom";
    }
}

Parcoords::Line::Colorbar::Title& Parcoords::Line::Colorbar::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Parcoords::Line::Colorbar::Title& Parcoords::Line::Colorbar::Title::side(enum Side f) {
    json["side"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Title& Parcoords::Line::Colorbar::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Parcoords::Line::Colorbar::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Line::Colorbar::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Line::Colorbar::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Line::Colorbar::Title::Font& Parcoords::Line::Colorbar::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}

std::string Parcoords::Rangefont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Rangefont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Rangefont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Rangefont& Parcoords::Rangefont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Rangefont& Parcoords::Rangefont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Rangefont& Parcoords::Rangefont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Parcoords::Stream& Parcoords::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Parcoords::Stream& Parcoords::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

std::string Parcoords::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Parcoords::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Parcoords::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Parcoords::Tickfont& Parcoords::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Tickfont& Parcoords::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Parcoords::Tickfont& Parcoords::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Parcoords::Unselected& Parcoords::Unselected::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}


Parcoords::Unselected::Line& Parcoords::Unselected::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Parcoords::Unselected::Line& Parcoords::Unselected::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Parcoords::Unselected::Line& Parcoords::Unselected::Line::opacity(double f) {
    json["opacity"] = std::move(f);
    return *this;
}

} // namespace plotlypp

