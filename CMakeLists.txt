cmake_minimum_required(VERSION 3.17)
project(solving_interpolation_problems)

set(CMAKE_CXX_STANDARD 14)

add_executable(solving_interpolation_problems
        main.cpp main.h
        print_slae.cpp
        tests.cpp
        interpolation/interpolation_with_Lagrangian_polynomial.cpp
        interpolation/interpolation.h
        interpolation/mesh_creation.cpp
        interpolation/table_creation.cpp
        interpolation/file_creation.cpp
        interpolation/interpolation_with_natural_cubic_spline.cpp
        sweep_method/sweep_method.h
        sweep_method/sweep_method.cpp)