// TODO: blah bla blah

#pragma once

#include <type_traits>
#include <vector>

namespace plotlypp {

// A data array is either a vector of arithmetic types, or a nested vector (depth currently unbounded) of arithmetic types.

template <typename T>
struct is_data_array_element: std::is_arithmetic<T>{};

template <typename T>
struct is_data_array_element<std::vector<T>> {
    static constexpr bool value = is_data_array_element<T>::value;
};

template<typename T>
inline constexpr bool is_data_array_element_v = is_data_array_element<T>::value;

}
