cmake_minimum_required(VERSION 3.20)
project(Practica3_CC232 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Programa principal (lee de stdin, formato CSES)
add_executable(pc3_main src/main.cpp)

# Demo ilustrativo con el ejemplo del enunciado
add_executable(demo_sliding_window_first demos/demo_sliding_window_first.cpp)
