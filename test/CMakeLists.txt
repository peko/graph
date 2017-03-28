project(tests)

# test vec
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../vec ${CMAKE_CURRENT_BINARY_DIR}/vec)
include_directories(../vec)
add_executable(test_vec test_vec.c)

target_link_libraries(test_vec vec m)

