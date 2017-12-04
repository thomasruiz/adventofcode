cmake_minimum_required(VERSION 3.9)
project(aoc)

file(COPY input DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc main.cpp day1.cpp day1.h day.h)
