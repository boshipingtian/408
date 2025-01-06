cmake_minimum_required(VERSION 3.30)
project(408 C)

set(CMAKE_C_STANDARD 11)

add_executable(408
    line/LinkedList.c
    line/SequenceTable.c
    main.c)
