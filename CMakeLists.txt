cmake_minimum_required(VERSION 3.25)
project(leetcode VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 23)

add_executable(
    ${CMAKE_PROJECT_NAME}

    #core sources
    main.cc
    output.cc

    solutions/solution.cc
    solutions/sol_arrays_hashing.cc
    solutions/sol_two_pointers.cc
    solutions/sol_binary_search.cc

    tools/TimeMap.cc

    #header only sources
    tools/node.hpp
)

