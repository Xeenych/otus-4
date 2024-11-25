#pragma once
#include <cstdlib>  // for size_t
#include <iostream>
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

// Рекурсивная Печать содержимого tuple
template <std::size_t I = 0, typename... Tp>
typename std::enable_if_t<I == sizeof...(Tp) - 1, void> print(std::tuple<Tp...>& t) {
    std::cout << std::get<I>(t) << std::endl;
}

// Рекурсивная Печать содержимого tuple
template <std::size_t I = 0, typename... Tp>
    typename std::enable_if_t < I<sizeof...(Tp) - 1, void> print(std::tuple<Tp...>& t) {
    std::cout << std::get<I>(t) << '.';
    print<I + 1, Tp...>(t);
}

// Функция работает, только для std::tuple с одинаковыми аргументами
template <typename... Args, typename = std::enable_if_t<check<std::tuple<Args...>>::value>>
void print_tuple(std::tuple<Args...> c) {
    print(c);
}
