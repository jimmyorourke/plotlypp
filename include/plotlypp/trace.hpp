// TODO: includes, copyright, etc
#pragma once

#include <plotlypp/json.hpp>

namespace plotlypp {

class Trace {
 public:
    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp
