# Copyright (c) 2025-2026 Jimmy O'Rourke
# Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
# Official repository: https://github.com/jimmyorourke/plotlypp

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${PLOTLYPP_FETCH_CONTENT_DIR})
FetchContent_Declare(
  eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
  URL_HASH SHA256=8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72
)
# Avoid trying to pull in a fortran compiler for the eigen tests. This fails on Windows.
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "Disable Eigen testing" FORCE)
set(EIGEN_BUILD_DOC OFF CACHE BOOL "Disable Eigen docs" FORCE)
set(EIGEN_LEAVE_TEST_IN_ALL_TARGET OFF CACHE BOOL "" FORCE)
set(CMAKE_Fortran_COMPILER "")
set(CMAKE_Fortran_COMPILER_WORKS 0)
FetchContent_MakeAvailable(eigen)

add_library(math_utils
    math_utils.cpp
)
target_include_directories(math_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(math_utils PUBLIC cxx_std_17)

include(Warnings.cmake)

add_executable(example
    example.cpp
    3d_charts.cpp
    basic_charts.cpp
    financial_charts.cpp
    maps.cpp
    scientific_charts.cpp
    statistical_charts.cpp
    subplots.cpp)

target_link_libraries(example
  PRIVATE
    plotlypp
    math_utils
    Eigen3::Eigen
)

target_include_directories(example SYSTEM PRIVATE
    $<TARGET_PROPERTY:Eigen3::Eigen,INTERFACE_INCLUDE_DIRECTORIES>
)

if(PLOTLYPP_BUILD_MODULES)
    add_executable(module_example module_example.cpp)
    target_link_libraries(module_example PRIVATE plotlypp)
    # Must use at least C++20 for modules
    target_compile_features(module_example PRIVATE cxx_std_20)
endif()

set_target_warnings(example)
target_compile_options(example PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
        # Clang complains with -Wpedantic. For external users we also have the PLOTLYPP_SYSTEM_INCLUDE CMake option
        # to treat all plotlypp headers as system headers.
    	-Wno-overlength-strings
    >
)
