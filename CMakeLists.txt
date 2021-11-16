project(tp4)
cmake_minimum_required(VERSION 3.10.0)

include_directories(include/)

option(DEBUG "Enable debugging" OFF)


if (DEBUG)
    add_definitions(-DDEBUG)
    add_compile_options(-g)
else()
    add_compile_options(-O2)
endif()

add_compile_options(-Wall -Wextra -Werror -std=gnu11)

file(GLOB C_SOURCES src/*.c)
list(REMOVE_ITEM C_SOURCES "${CMAKE_SOURCE_DIR}/src/main_classes.c")
list(REMOVE_ITEM C_SOURCES "${CMAKE_SOURCE_DIR}/src/main_stack.c")

add_executable( ${CMAKE_PROJECT_NAME}_main 
    ${C_SOURCES}
    src/main_classes.c
)

add_executable( ${CMAKE_PROJECT_NAME}_test
    ${C_SOURCES}
    test/teZZt.c
    test/teZZt.h
    test/tests_main.c
)

add_executable( ${CMAKE_PROJECT_NAME}_stack
    src/main_stack.c
)

set_target_properties(${CMAKE_PROJECT_NAME}_main PROPERTIES LINKER_LANGUAGE C)
set_target_properties(${CMAKE_PROJECT_NAME}_test PROPERTIES LINKER_LANGUAGE C)
