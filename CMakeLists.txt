add_library(Unity STATIC
        submodules/external/unity_cmake/Unity/src/unity.c
)

target_include_directories(Unity PUBLIC
        submodules/external/unity_cmake/Unity/src
)

cmake_minimum_required(VERSION 3.31)
project(algosi C)

set(CMAKE_C_STANDARD 11)

add_executable(algosi main.c
        linked_list.c
        utils.h
        utils.c)
