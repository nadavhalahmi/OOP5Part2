cmake_minimum_required(VERSION 3.7)
project(Part2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Part2Examples.cpp Stream.h)
add_executable(Part2 ${SOURCE_FILES})