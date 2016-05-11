cmake_minimum_required(VERSION 3.3)
project(Vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector/Vector.cpp Vector/Vector.h)
add_executable(Vector ${SOURCE_FILES})