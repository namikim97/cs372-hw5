cmake_minimum_required(VERSION 3.13)
project(hw5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw5
    compound.cpp
    compound.h
    cps.cpp
    page.cpp
    page.h
    README.md
    shapes.cpp
    shapes.h)
