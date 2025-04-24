#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace plotlypp {

using Json = nlohmann::json;

inline std::string serialize(const Json& json) { return json.dump(); }

} // namespace plotlypp
