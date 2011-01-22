project(list)

cmake_minimum_required(VERSION 2.6)

add_definitions("-Wall -ansi -pedantic -O2")

if(APPLE)
    include_directories(/usr/include/malloc/)
endif(APPLE)

# libify
add_library(list SHARED list.c)

# make demo
add_executable(demo demo.c)
target_link_libraries(demo list)
