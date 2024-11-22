#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_ip_(T v);

template <typename T>
void print_ip(T v) {
    print_ip_<T>(v);
    std::cout << std::endl;
}

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

// Этот вводит std::string
template <>
void print_ip_<std::string>(std::string v) {
    std::cout << v;
}

template <>
void print_ip_<std::vector<int>>(std::vector<int> v) {
    for (const auto& i : v) {
        print_ip_<int>(i);
    }
}
