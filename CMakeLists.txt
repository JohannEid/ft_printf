cmake_minimum_required(VERSION 3.6)
project(printf_project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c misc.c misc.h my_struct.c my_struct.h)
add_executable(printf_project ${SOURCE_FILES})