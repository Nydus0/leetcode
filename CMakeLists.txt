cmake_minimum_required(VERSION 3.25)
project(leetcode)

set (CMAKE_CXX_STANDARD 26)

# enable and add subdirectory for tests
enable_testing()
add_subdirectory(tests)

# add tools subdirectory for tests
add_subdirectory(tools)
target_include_directories(tools PUBLIC ${CMAKE_SOURCE_DIR})

# add solutions library
add_subdirectory(solutions)
target_include_directories(solutions PUBLIC ${CMAKE_SOURCE_DIR})

