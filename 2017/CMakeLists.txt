cmake_minimum_required(VERSION 3.9)
project(aoc)

file(COPY input DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc main.cpp day1.cpp day1.h day.h day2.cpp day2.h util.h day3.cpp day3.h day4.cpp day4.h)
