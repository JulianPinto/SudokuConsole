cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(sudoku VERSION 1.0 DESCRIPTION "Console sudoku")

file(GLOB_RECURSE SRC_FLIES src/*.cpp)
add_executable(sudoku ${SRC_FLIES})
target_include_directories(sudoku PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)