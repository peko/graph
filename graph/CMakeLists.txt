cmake_minimum_required(VERSION 3.0)

include_directories(../dep/klib)

add_library(graph graph.c)
target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_graph test_graph.c)
target_link_libraries(test_graph graph)