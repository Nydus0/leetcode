cmake_minimum_required(VERSION 3.25)
project(leetcode VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 23)

add_executable(
    ${CMAKE_PROJECT_NAME}

    #core sources
        main.cpp
        output.cpp

        solutions/sol_arrays_hashing.cpp
        solutions/sol_two_pointers.cpp
        solutions/sol_binary_search.cpp
        solutions/sol_trees.cpp

        tools/TimeMap.cpp

    #header only sources
    tools/node.hpp
        solutions/Solution.hpp
)

