#pragma once
#include "container_helper.hpp"
#include "integral_helper.hpp"
#include "tuple_helper.hpp"

#include <list>
#include <string>
#include <vector>

// Главный шаблон с двумя парамтерами, чтобы различать integral и std::string
template <typename T, typename enable = void>
void print_ip(T v);

// Для std::string
template <>
void print_ip<std::string>(std::string v) {
    std::cout << v << std::endl;
}

// Для вывода целых типов
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void print_ip(T v) {
    print_integral(v);
}

/*
//  Специализация для int8_t
template <>
void print_ip_<int8_t>(int8_t v) {
    std::cout << (v & 0xff);
}

//  Специализация для int16_t
template <>
void print_ip_<int16_t>(int16_t v) {
    print_ip_<int8_t>(v >> 8);
    std::cout << '.';
    print_ip_<int8_t>(v);
}

//  Специализация для int32_t
template <>
void print_ip_<int32_t>(int32_t v) {
    print_ip_<int16_t>(v >> 16);
    std::cout << '.';
    print_ip_<int16_t>(v);
}

//  Специализация для int64_t
template <>
void print_ip_<int64_t>(int64_t v) {
    print_ip_<int32_t>(v >> 32);
    std::cout << '.';
    print_ip_<int32_t>(v);
}
*/

// Шаблон с тремя параметрами
// Работает для любого контейнера, кроме std::string, потому что std::string захватывается боле узким шаблоном с одним
// параметром
template <template <typename, typename> typename Container, typename Type, typename Allocator = std::allocator<Type>,
          typename = std::enable_if_t<(std::is_same_v<Container<Type, Allocator>, std::vector<Type, Allocator>> ||
                                       std::is_same_v<Container<Type, Allocator>, std::list<Type, Allocator>>)>>
void print_ip(Container<Type, Allocator> c) {
    print_container(c);
}

// Шаблон с бесконечным числом парамтеров
// Включается только для std::tuple
template <template <typename> typename Tp, typename... Args,
          typename = std::enable_if_t<std::is_same_v<std::tuple<Args...>, Tp<Args...>>>>
void print_ip(Tp<Args...> c) {
    print_tuple(c);
}
