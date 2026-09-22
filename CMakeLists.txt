cmake_minimum_required(VERSION 3.1)

project(Task1)

set(CMAKE_CXX_STANDARD 17)

add_library(func_shared SHARED include/func.cpp)
add_executable(improved_task src/main.cpp)
target_link_libraries (func_shared PUBLIC include)