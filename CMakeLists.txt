cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 23)

add_executable(
    ${CMAKE_PROJECT_NAME}
    main.cpp
    output.cpp
    solutions/solution.cpp
    solutions/sol_arrays_hashing.cpp
    solutions/sol_two_pointers.cpp
    solutions/sol_binary_search.cpp
)

