cmake_minimum_required(VERSION 3.14)
project(SolveSquare C)

set(CMAKE_C_STANDARD 11)

add_executable(SolveSquare main.c)

target_link_libraries(SolveSquare m)