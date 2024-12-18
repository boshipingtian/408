cmake_minimum_required(VERSION 3.30)
project(demo C)

set(CMAKE_C_STANDARD 11)

add_library(demo SHARED
        main.c
        line/ArrayList.c
        line/LinkedList.c)
