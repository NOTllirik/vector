cmake_minimum_required(VERSION 3.23)
project(program C)

set(CMAKE_C_STANDARD 99)

add_executable(program main.c
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vector.h
        libs/data_structures/vector/test.h
        libs/data_structures/vector/test.c)



