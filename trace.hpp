// TODO: includes, copyright, etc
#pragma once

#include <nlohmann/json.hpp>

namespace plotlypp {

class Trace {
public:
    // Advanced users may modify the JSON representation directly, at their own peril!
    nlohmann::json json{};
};

}
