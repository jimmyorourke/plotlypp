# Copyright (c) 2025-2026 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

cmake_minimum_required(VERSION 3.28)
project(plotlypp VERSION 0.1.0 LANGUAGES CXX)

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()

option(PLOTLYPP_BUILD_EXAMPLES "Build the examples" ${MAIN_PROJECT})
option(PLOTLYPP_BUILD_MODULES "Build Plotly++ as a C++ module" OFF)

if(MAIN_PROJECT)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set(PLOTLYPP_FETCH_CONTENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party_fetch_content)

# When part of a larger project, nlohmann_json may be made available by the greater project, but may or may not be
# discoverable by find_package. Try to avoid imposing requirements on how projects procure their dependencies. If not
# discoverable, no pre-defined target found, or when just building plotlypp (eg the examples), use FetchContent.
if(NOT TARGET nlohmann_json::nlohmann_json)
    find_package(nlohmann_json QUIET)
    if(nlohmann_json_FOUND)
        message(STATUS "Found system nlohmann_json")
    else()
        message(STATUS "nlohmann_json not found, fetching...")
        # Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24+:
        if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
            cmake_policy(SET CMP0135 NEW)
        endif()
        include(FetchContent)

        set(FETCHCONTENT_BASE_DIR ${PLOTLYPP_FETCH_CONTENT_DIR})
        # Enable nlohmann::json install targets. Otherwise the plotlypp install targets complain the "local" dependency
        # is not being exported.
        set(JSON_Install ON)
        FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
        FetchContent_MakeAvailable(json)
    endif()
else()
    message(STATUS "Found pre-existing nlohmann_json::nlohmann_json target definition.")
endif()
set(JSON_TARGET nlohmann_json::nlohmann_json)

if(PLOTLYPP_BUILD_MODULES)
    # Build as C++20 module
    add_library(plotlypp STATIC)
    target_sources(plotlypp PUBLIC
        FILE_SET CXX_MODULES FILES modules/plotlypp.cppm
    )
    # Require at least C++2o for modules. Depending executables can override with a newer version.
    target_compile_features(plotlypp PUBLIC cxx_std_20)

    set(SCOPE PUBLIC)
    set(INSTALL_MODULE_ARGS FILE_SET CXX_MODULES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/modules)
else()
    # Build as header-only interface library
    add_library(plotlypp INTERFACE)
    # Require at least C++17. Depending executables can override with a newer version.
    target_compile_features(plotlypp INTERFACE cxx_std_17)

    set(SCOPE INTERFACE)
    set(INSTALL_MODULE_ARGS "")
endif()

target_link_libraries(plotlypp ${SCOPE} ${JSON_TARGET})
target_include_directories(plotlypp ${SCOPE}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add a namespaced alias for in-tree users.
add_library(plotlypp::plotlypp ALIAS plotlypp)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Install headers.
install(DIRECTORY include/plotlypp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Register the target with the export set.
install(TARGETS plotlypp
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ${INSTALL_MODULE_ARGS}
)

# Install/generate the cmake file for rebuilding the export set targets.
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

# Write the find package config file.
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
"include(CMakeFindDependencyMacro)
find_dependency(nlohmann_json)
include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Targets.cmake\")"
)

# Write the find package version file.
write_basic_package_version_file(
    ${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Install find package config files.
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

if(PLOTLYPP_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
