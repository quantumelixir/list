project(list)

cmake_minimum_required(VERSION 2.6)

# libify
add_library(list SHARED list.c)

# make demo
add_executable(demo demo.c)
target_link_libraries(demo list)
