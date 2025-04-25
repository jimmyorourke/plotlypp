// TODO: includes, copyright, etc

namespace plotlypp {

std::string Indicator::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::CENTER: return "center";
        case Align::RIGHT: return "right";
    }
}
std::string Indicator::to_string(Visible e) {
    switch(e) {
        case Visible::TRUE: return "True";
        case Visible::FALSE: return "False";
        case Visible::LEGENDONLY: return "legendonly";
    }
}

Indicator& Indicator::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}

template <typename T, typename>
Indicator& Indicator::customdata(std::vector<T> f) {
    json["customdata"] = std::move(f);
    return *this;
}

Indicator& Indicator::customdatasrc(std::string f) {
    json["customdatasrc"] = std::move(f);
    return *this;
}

Indicator& Indicator::delta(class Delta f) {
    json["delta"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::domain(class Domain f) {
    json["domain"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::gauge(class Gauge f) {
    json["gauge"] = std::move(f.json);
    return *this;
}

template <typename T, typename>
Indicator& Indicator::ids(std::vector<T> f) {
    json["ids"] = std::move(f);
    return *this;
}

Indicator& Indicator::idssrc(std::string f) {
    json["idssrc"] = std::move(f);
    return *this;
}

Indicator& Indicator::legend(std::string f) {
    json["legend"] = std::move(f);
    return *this;
}

Indicator& Indicator::legendgrouptitle(class Legendgrouptitle f) {
    json["legendgrouptitle"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::legendrank(double f) {
    json["legendrank"] = std::move(f);
    return *this;
}

Indicator& Indicator::legendwidth(double f) {
    json["legendwidth"] = std::move(f);
    return *this;
}

template <typename T>
Indicator& Indicator::meta(T f) {
    json["meta"] = std::move(f);
    return *this;
}
template <typename T>
Indicator& Indicator::meta(std::vector<T> f) {
    json["meta"] = std::move(f);
    return *this;
}

Indicator& Indicator::metasrc(std::string f) {
    json["metasrc"] = std::move(f);
    return *this;
}

Indicator& Indicator::mode(std::string f) {
    json["mode"] = std::move(f);
    return *this;
}

Indicator& Indicator::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Indicator& Indicator::number(class Number f) {
    json["number"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::stream(class Stream f) {
    json["stream"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::title(class Title f) {
    json["title"] = std::move(f.json);
    return *this;
}

Indicator& Indicator::uid(std::string f) {
    json["uid"] = std::move(f);
    return *this;
}

template <typename T>
Indicator& Indicator::uirevision(T f) {
    json["uirevision"] = std::move(f);
    return *this;
}

Indicator& Indicator::value(double f) {
    json["value"] = std::move(f);
    return *this;
}

Indicator& Indicator::visible(enum Visible f) {
    json["visible"] = to_string(f);
    return *this;
}

std::string Indicator::Delta::to_string(Position e) {
    switch(e) {
        case Position::TOP: return "top";
        case Position::BOTTOM: return "bottom";
        case Position::LEFT: return "left";
        case Position::RIGHT: return "right";
    }
}

Indicator::Delta& Indicator::Delta::decreasing(class Decreasing f) {
    json["decreasing"] = std::move(f.json);
    return *this;
}

Indicator::Delta& Indicator::Delta::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Indicator::Delta& Indicator::Delta::increasing(class Increasing f) {
    json["increasing"] = std::move(f.json);
    return *this;
}

Indicator::Delta& Indicator::Delta::position(enum Position f) {
    json["position"] = to_string(f);
    return *this;
}

Indicator::Delta& Indicator::Delta::prefix(std::string f) {
    json["prefix"] = std::move(f);
    return *this;
}

Indicator::Delta& Indicator::Delta::reference(double f) {
    json["reference"] = std::move(f);
    return *this;
}

Indicator::Delta& Indicator::Delta::relative(bool f) {
    json["relative"] = std::move(f);
    return *this;
}

Indicator::Delta& Indicator::Delta::suffix(std::string f) {
    json["suffix"] = std::move(f);
    return *this;
}

Indicator::Delta& Indicator::Delta::valueformat(std::string f) {
    json["valueformat"] = std::move(f);
    return *this;
}


Indicator::Delta::Decreasing& Indicator::Delta::Decreasing::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Delta::Decreasing& Indicator::Delta::Decreasing::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Delta::Decreasing& Indicator::Delta::Decreasing::symbol(std::string f) {
    json["symbol"] = std::move(f);
    return *this;
}

std::string Indicator::Delta::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Indicator::Delta::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Indicator::Delta::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Indicator::Delta::Font& Indicator::Delta::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Delta::Font& Indicator::Delta::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Indicator::Delta::Font& Indicator::Delta::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Indicator::Delta::Increasing& Indicator::Delta::Increasing::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Delta::Increasing& Indicator::Delta::Increasing::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Delta::Increasing& Indicator::Delta::Increasing::symbol(std::string f) {
    json["symbol"] = std::move(f);
    return *this;
}


Indicator::Domain& Indicator::Domain::column(int f) {
    json["column"] = std::move(f);
    return *this;
}

Indicator::Domain& Indicator::Domain::row(int f) {
    json["row"] = std::move(f);
    return *this;
}

Indicator::Domain& Indicator::Domain::x(std::vector<std::string> f) {
    json["x"] = std::move(f);
    return *this;
}

Indicator::Domain& Indicator::Domain::y(std::vector<std::string> f) {
    json["y"] = std::move(f);
    return *this;
}

std::string Indicator::Gauge::to_string(Shape e) {
    switch(e) {
        case Shape::ANGULAR: return "angular";
        case Shape::BULLET: return "bullet";
    }
}

Indicator::Gauge& Indicator::Gauge::axis(class Axis f) {
    json["axis"] = std::move(f.json);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::bar(class Bar f) {
    json["bar"] = std::move(f.json);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::bgcolor(std::string f) {
    json["bgcolor"] = std::move(f);
    return *this;
}
Indicator::Gauge& Indicator::Gauge::bgcolor(double f) {
    json["bgcolor"] = std::move(f);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::bordercolor(std::string f) {
    json["bordercolor"] = std::move(f);
    return *this;
}
Indicator::Gauge& Indicator::Gauge::bordercolor(double f) {
    json["bordercolor"] = std::move(f);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::borderwidth(double f) {
    json["borderwidth"] = std::move(f);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::shape(enum Shape f) {
    json["shape"] = to_string(f);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::steps(class Steps f) {
    json["steps"] = std::move(f.json);
    return *this;
}

Indicator::Gauge& Indicator::Gauge::threshold(class Threshold f) {
    json["threshold"] = std::move(f.json);
    return *this;
}

std::string Indicator::Gauge::Axis::to_string(Exponentformat e) {
    switch(e) {
        case Exponentformat::NONE: return "none";
        case Exponentformat::E: return "E";
        case Exponentformat::POWER: return "power";
        case Exponentformat::SI: return "SI";
        case Exponentformat::B: return "B";
    }
}
std::string Indicator::Gauge::Axis::to_string(Showexponent e) {
    switch(e) {
        case Showexponent::ALL: return "all";
        case Showexponent::FIRST: return "first";
        case Showexponent::LAST: return "last";
        case Showexponent::NONE: return "none";
    }
}
std::string Indicator::Gauge::Axis::to_string(Showtickprefix e) {
    switch(e) {
        case Showtickprefix::ALL: return "all";
        case Showtickprefix::FIRST: return "first";
        case Showtickprefix::LAST: return "last";
        case Showtickprefix::NONE: return "none";
    }
}
std::string Indicator::Gauge::Axis::to_string(Showticksuffix e) {
    switch(e) {
        case Showticksuffix::ALL: return "all";
        case Showticksuffix::FIRST: return "first";
        case Showticksuffix::LAST: return "last";
        case Showticksuffix::NONE: return "none";
    }
}
std::string Indicator::Gauge::Axis::to_string(Tickmode e) {
    switch(e) {
        case Tickmode::AUTO: return "auto";
        case Tickmode::LINEAR: return "linear";
        case Tickmode::ARRAY: return "array";
    }
}
std::string Indicator::Gauge::Axis::to_string(Ticks e) {
    switch(e) {
        case Ticks::OUTSIDE: return "outside";
        case Ticks::INSIDE: return "inside";
        case Ticks::EMPTY: return "";
    }
}

template <typename T>
Indicator::Gauge::Axis& Indicator::Gauge::Axis::dtick(T f) {
    json["dtick"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::exponentformat(enum Exponentformat f) {
    json["exponentformat"] = to_string(f);
    return *this;
}

template <typename T>
Indicator::Gauge::Axis& Indicator::Gauge::Axis::labelalias(T f) {
    json["labelalias"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::minexponent(double f) {
    json["minexponent"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::nticks(int f) {
    json["nticks"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::range(std::vector<std::string> f) {
    json["range"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::separatethousands(bool f) {
    json["separatethousands"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::showexponent(enum Showexponent f) {
    json["showexponent"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::showticklabels(bool f) {
    json["showticklabels"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::showtickprefix(enum Showtickprefix f) {
    json["showtickprefix"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::showticksuffix(enum Showticksuffix f) {
    json["showticksuffix"] = to_string(f);
    return *this;
}

template <typename T>
Indicator::Gauge::Axis& Indicator::Gauge::Axis::tick0(T f) {
    json["tick0"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickangle(double f) {
    json["tickangle"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickcolor(std::string f) {
    json["tickcolor"] = std::move(f);
    return *this;
}
Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickcolor(double f) {
    json["tickcolor"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickfont(class Tickfont f) {
    json["tickfont"] = std::move(f.json);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickformat(std::string f) {
    json["tickformat"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickformatstops(class Tickformatstops f) {
    json["tickformatstops"] = std::move(f.json);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticklabelstep(int f) {
    json["ticklabelstep"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticklen(double f) {
    json["ticklen"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickmode(enum Tickmode f) {
    json["tickmode"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickprefix(std::string f) {
    json["tickprefix"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticks(enum Ticks f) {
    json["ticks"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticksuffix(std::string f) {
    json["ticksuffix"] = std::move(f);
    return *this;
}

template <typename T, typename>
Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticktext(std::vector<T> f) {
    json["ticktext"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::ticktextsrc(std::string f) {
    json["ticktextsrc"] = std::move(f);
    return *this;
}

template <typename T, typename>
Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickvals(std::vector<T> f) {
    json["tickvals"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickvalssrc(std::string f) {
    json["tickvalssrc"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::tickwidth(double f) {
    json["tickwidth"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis& Indicator::Gauge::Axis::visible(bool f) {
    json["visible"] = std::move(f);
    return *this;
}

std::string Indicator::Gauge::Axis::Tickfont::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Indicator::Gauge::Axis::Tickfont::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Indicator::Gauge::Axis::Tickfont::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Indicator::Gauge::Axis::Tickfont& Indicator::Gauge::Axis::Tickfont::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Indicator::Gauge::Axis::Tickformatstops& Indicator::Gauge::Axis::Tickformatstops::tickformatstop(class Tickformatstop f) {
    json["tickformatstop"] = std::move(f.json);
    return *this;
}


Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& Indicator::Gauge::Axis::Tickformatstops::Tickformatstop::dtickrange(std::vector<std::string> f) {
    json["dtickrange"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& Indicator::Gauge::Axis::Tickformatstops::Tickformatstop::enabled(bool f) {
    json["enabled"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& Indicator::Gauge::Axis::Tickformatstops::Tickformatstop::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& Indicator::Gauge::Axis::Tickformatstops::Tickformatstop::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Indicator::Gauge::Axis::Tickformatstops::Tickformatstop& Indicator::Gauge::Axis::Tickformatstops::Tickformatstop::value(std::string f) {
    json["value"] = std::move(f);
    return *this;
}


Indicator::Gauge::Bar& Indicator::Gauge::Bar::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Bar& Indicator::Gauge::Bar::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Bar& Indicator::Gauge::Bar::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Indicator::Gauge::Bar& Indicator::Gauge::Bar::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}


Indicator::Gauge::Bar::Line& Indicator::Gauge::Bar::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Bar::Line& Indicator::Gauge::Bar::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Bar::Line& Indicator::Gauge::Bar::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}


Indicator::Gauge::Steps& Indicator::Gauge::Steps::step(class Step f) {
    json["step"] = std::move(f.json);
    return *this;
}


Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::name(std::string f) {
    json["name"] = std::move(f);
    return *this;
}

Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::range(std::vector<std::string> f) {
    json["range"] = std::move(f);
    return *this;
}

Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::templateitemname(std::string f) {
    json["templateitemname"] = std::move(f);
    return *this;
}

Indicator::Gauge::Steps::Step& Indicator::Gauge::Steps::Step::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}


Indicator::Gauge::Steps::Step::Line& Indicator::Gauge::Steps::Step::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Steps::Step::Line& Indicator::Gauge::Steps::Step::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Steps::Step::Line& Indicator::Gauge::Steps::Step::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}


Indicator::Gauge::Threshold& Indicator::Gauge::Threshold::line(class Line f) {
    json["line"] = std::move(f.json);
    return *this;
}

Indicator::Gauge::Threshold& Indicator::Gauge::Threshold::thickness(double f) {
    json["thickness"] = std::move(f);
    return *this;
}

Indicator::Gauge::Threshold& Indicator::Gauge::Threshold::value(double f) {
    json["value"] = std::move(f);
    return *this;
}


Indicator::Gauge::Threshold::Line& Indicator::Gauge::Threshold::Line::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Gauge::Threshold::Line& Indicator::Gauge::Threshold::Line::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Gauge::Threshold::Line& Indicator::Gauge::Threshold::Line::width(double f) {
    json["width"] = std::move(f);
    return *this;
}


Indicator::Legendgrouptitle& Indicator::Legendgrouptitle::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Indicator::Legendgrouptitle& Indicator::Legendgrouptitle::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Indicator::Legendgrouptitle::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Indicator::Legendgrouptitle::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Indicator::Legendgrouptitle::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Indicator::Legendgrouptitle::Font& Indicator::Legendgrouptitle::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Indicator::Number& Indicator::Number::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Indicator::Number& Indicator::Number::prefix(std::string f) {
    json["prefix"] = std::move(f);
    return *this;
}

Indicator::Number& Indicator::Number::suffix(std::string f) {
    json["suffix"] = std::move(f);
    return *this;
}

Indicator::Number& Indicator::Number::valueformat(std::string f) {
    json["valueformat"] = std::move(f);
    return *this;
}

std::string Indicator::Number::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Indicator::Number::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Indicator::Number::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Indicator::Number::Font& Indicator::Number::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Number::Font& Indicator::Number::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Indicator::Number::Font& Indicator::Number::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}


Indicator::Stream& Indicator::Stream::maxpoints(double f) {
    json["maxpoints"] = std::move(f);
    return *this;
}

Indicator::Stream& Indicator::Stream::token(std::string f) {
    json["token"] = std::move(f);
    return *this;
}

std::string Indicator::Title::to_string(Align e) {
    switch(e) {
        case Align::LEFT: return "left";
        case Align::CENTER: return "center";
        case Align::RIGHT: return "right";
    }
}

Indicator::Title& Indicator::Title::align(enum Align f) {
    json["align"] = to_string(f);
    return *this;
}

Indicator::Title& Indicator::Title::font(class Font f) {
    json["font"] = std::move(f.json);
    return *this;
}

Indicator::Title& Indicator::Title::text(std::string f) {
    json["text"] = std::move(f);
    return *this;
}

std::string Indicator::Title::Font::to_string(Style e) {
    switch(e) {
        case Style::NORMAL: return "normal";
        case Style::ITALIC: return "italic";
    }
}
std::string Indicator::Title::Font::to_string(Textcase e) {
    switch(e) {
        case Textcase::NORMAL: return "normal";
        case Textcase::WORD_CAPS: return "word caps";
        case Textcase::UPPER: return "upper";
        case Textcase::LOWER: return "lower";
    }
}
std::string Indicator::Title::Font::to_string(Variant e) {
    switch(e) {
        case Variant::NORMAL: return "normal";
        case Variant::SMALL_CAPS: return "small-caps";
        case Variant::ALL_SMALL_CAPS: return "all-small-caps";
        case Variant::ALL_PETITE_CAPS: return "all-petite-caps";
        case Variant::PETITE_CAPS: return "petite-caps";
        case Variant::UNICASE: return "unicase";
    }
}

Indicator::Title::Font& Indicator::Title::Font::color(std::string f) {
    json["color"] = std::move(f);
    return *this;
}
Indicator::Title::Font& Indicator::Title::Font::color(double f) {
    json["color"] = std::move(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::family(std::string f) {
    json["family"] = std::move(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::lineposition(std::string f) {
    json["lineposition"] = std::move(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::shadow(std::string f) {
    json["shadow"] = std::move(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::size(double f) {
    json["size"] = std::move(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::style(enum Style f) {
    json["style"] = to_string(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::textcase(enum Textcase f) {
    json["textcase"] = to_string(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::variant(enum Variant f) {
    json["variant"] = to_string(f);
    return *this;
}

Indicator::Title::Font& Indicator::Title::Font::weight(int f) {
    json["weight"] = std::move(f);
    return *this;
}

} // namespace plotlypp

