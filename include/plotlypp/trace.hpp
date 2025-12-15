// Copyright (c) 2025 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#include <string>

#include <plotlypp/json.hpp>

namespace plotlypp {

class Trace {
 public:
    Trace() = default;

    explicit Trace(std::string jsonStr)
    : json(parse(std::move(jsonStr))) {}

    // Advanced users may modify the JSON representation directly, at their own peril!
    Json json{};
};

} // namespace plotlypp
