cmake_minimum_required(VERSION 3.25)
project(leetcode)

set (CMAKE_CXX_STANDARD 26)

# enable and add subdirectory for tests
enable_testing()
add_subdirectory(tests)

# add solutions library
add_subdirectory(solutions)
target_include_directories(solutions PUBLIC ${CMAKE_SOURCE_DIR})

#[[add_executable(
        ${CMAKE_PROJECT_NAME}

        #core sources
        main.cpp
        output.cpp

        solutions/sol_arrays_hashing.cpp
        solutions/sol_two_pointers.cpp
        solutions/sol_binary_search.cpp
        solutions/sol_trees.cpp

        tools/TimeMap.cpp
        tests/tests.cpp
)]]

