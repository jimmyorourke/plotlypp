// Copyright (c) 2025 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace plotlypp {

using Json = nlohmann::json;

inline std::string serialize(const Json& json) { return json.dump(); }

inline Json parse(std::string content) { return Json::parse(std::move(content)); }

} // namespace plotlypp
