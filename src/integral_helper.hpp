#pragma once
#include <iostream>
#include <limits>
#include <span>

template <typename T>
void print_integral(T v) {
    size_t size = sizeof(T);
    unsigned val = 0;
    while (size > 1) {
        val = v >> (size - 1) * 8;
        std::cout << (val & 0xff) << '.';
        size--;
    }
    val = v >> (size - 1) * 8;
    std::cout << (val & 0xff) << std::endl;
}