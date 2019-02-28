cmake_minimum_required(VERSION 3.12)
project(data_structure C)

set(CMAKE_C_STANDARD 99)

add_library(data_structure src/include/array_list.h src/include/linked_list.h src/array_list.c src/linked_list.c src/include/common.h)