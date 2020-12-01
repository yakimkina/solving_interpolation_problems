cmake_minimum_required(VERSION 3.17)
project(solving_interpolation_problems)

set(CMAKE_CXX_STANDARD 14)

add_executable(solving_interpolation_problems
        main.cpp main.h
        print_slae.cpp
        interpolation/interpolation_with_Lagrangian_polynomial.cpp
        interpolation/math_functions.cpp interpolation/math_functions.h interpolation/interpolation.h)