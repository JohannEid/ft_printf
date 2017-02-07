cmake_minimum_required(VERSION 3.6)
project(printf_project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c misc.c misc.h dynamic_array.c dynamic_array.h node.c node.h)
add_executable(printf_project ${SOURCE_FILES} dynamic_array.c dynamic_array.h)