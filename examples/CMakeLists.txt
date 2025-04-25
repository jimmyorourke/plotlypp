# Copyright (c) 2025 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

add_executable(test test.cpp)
target_link_libraries(test
  PRIVATE
    plotlypp
)
