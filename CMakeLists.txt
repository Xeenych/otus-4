cmake_minimum_required(VERSION 3.5)

project(otus-4)
#add_compile_options(-Werror)
#add_compile_options(-Wall)
#add_compile_options(-Wextra)
#add_compile_options(-Warray-bounds)
#add_compile_options(-Weffc++)

add_executable(print_ip src/main.cpp)
set_target_properties(print_ip PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

