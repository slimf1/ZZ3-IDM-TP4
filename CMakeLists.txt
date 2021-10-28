project(tp4)
cmake_minimum_required(VERSION 3.10.0)

include_directories(include/)

option(DEBUG "Enable debugging" OFF)

if (DEBUG)
    add_definitions(-DDEBUG)
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    if (DEBUG)
        add_compile_options(-g)
    else()
        add_compile_options(-O2)
    endif()

    add_compile_options(-Wall -Wextra -Werror -std=c11)
endif()

file(GLOB C_SOURCES src/*.c)
list(REMOVE_ITEM C_SOURCES "${CMAKE_SOURCE_DIR}/src/main.c")

add_executable( ${CMAKE_PROJECT_NAME}_main 
    ${C_SOURCES}
    src/main.c
)

add_executable( ${CMAKE_PROJECT_NAME}_test
    ${C_SOURCES}
    test/teZZt.c
    test/teZZt.h
    test/tests_main.c
)

set_target_properties(${CMAKE_PROJECT_NAME}_main PROPERTIES LINKER_LANGUAGE C)
set_target_properties(${CMAKE_PROJECT_NAME}_test PROPERTIES LINKER_LANGUAGE C)
