#pragma once
#include <cstdlib>  // for size_t
#include <tuple>

template <typename Tuple, size_t idx>
struct element_same_as_previous {
    using Cur = std::tuple_element<idx, Tuple>::type;
    using Prev = std::tuple_element<idx - 1, Tuple>::type;
    constexpr static bool value = std::is_same<Cur, Prev>::value && element_same_as_previous<Tuple, idx - 1>::value;
};

template <typename T>
struct element_same_as_previous<T, 0> {
    constexpr static bool value = true;
};

// Проверяет, что std::tuple содержит одинаковые элементы
template <typename T>
struct check {
    static constexpr bool value = element_same_as_previous<T, std::tuple_size<T>::value - 1>::value;
};
