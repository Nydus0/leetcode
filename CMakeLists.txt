cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 23)

add_executable(tests
main.cpp
output.cpp

solutions/solution.cpp
solutions/CsolArraysHashing.cpp
solutions/CsolTwoPointers.cpp
)

