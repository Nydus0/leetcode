cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 23)

add_executable(
    ${CMAKE_PROJECT_NAME}
    main.cpp
    output.cpp
    solutions/Solution.cpp
    solutions/SolArraysHashing.cpp
    solutions/SolTwoPointers.cpp
    solutions/SolBinarySearch.cpp
)

