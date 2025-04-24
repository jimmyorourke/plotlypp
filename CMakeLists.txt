cmake_minimum_required(VERSION 3.13)
project(plotlypp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set(JSON_LIB nlohmann_json)
set(JSON_TARGET nlohmann_json::nlohmann_json)
if(PLOTLY_USE_EXTERNAL_JSON)
    find_package(${JSON_LIB} 3.11.3 REQUIRED)
else()
    include(FetchContent)

    set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party_fetch_content)
    FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
    FetchContent_MakeAvailable(json)
endif()

SET(LIB plotlypp)
add_library(${LIB} INTERFACE)
target_link_libraries(${LIB} INTERFACE ${JSON_TARGET})
target_include_directories(${LIB} INTERFACE generated ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${LIB} INTERFACE cxx_std_17)

# TODO: conditionally enable
add_executable(test test.cpp)
target_link_libraries(test
  PRIVATE
    ${LIB}
)


