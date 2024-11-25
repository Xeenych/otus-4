#pragma once
#include <iostream>

template <typename T>
void print_container(T c) {
    for (auto iter = std::begin(c); iter != std::end(c); ++iter) {
        if (iter != std::begin(c)) {
            std::cout << ".";
        }
        std::cout << *iter;
    }
    std::cout << std::endl;
}