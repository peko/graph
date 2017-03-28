project(vec)

# http://stackoverflow.com/questions/7980784/cmake-add-sub-directory-which-is-not-sub-directory-on-real-directory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../dep/delaunay ${CMAKE_CURRENT_BINARY_DIR}/delaunay)
add_library(vec mesh.c)

target_link_libraries(vec delaunay)
