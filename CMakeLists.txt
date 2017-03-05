cmake_minimum_required(VERSION 3.6)
project(printf_project_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        dynamic_array.c
        dynamic_array.h
        main.c
        misc.c
        misc.h
        services.c
        services.h)

add_executable(printf_project_ ${SOURCE_FILES})