cmake_minimum_required(VERSION 3.13)
project(plotlypp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PLOTLY_USE_EXTERNAL_JSON)
    find_package(nlohmann_json 3.11.3 REQUIRED)
else()
    include(FetchContent)

    set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party_fetch_content)
    FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
    FetchContent_MakeAvailable(json)
endif()

add_library(plotlypp INTERFACE)
target_link_libraries(plotlypp INTERFACE nlohmann_json::nlohmann_json)
target_include_directories(plotlypp INTERFACE generated ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(test test.cpp)
target_link_libraries(test
  PRIVATE
    plotlypp
    nlohmann_json::nlohmann_json
)


