cmake_minimum_required(VERSION 3.10)

project(Task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(improved_task)
target_sources(improved_task 
    PRIVATE
    src/main.cpp
)

add_library(func_shared SHARED include/func.cpp include/func.h)
target_include_directories(func_shared PUBLIC include)
target_link_libraries (improved_task PUBLIC func_shared)