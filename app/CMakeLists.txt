project(app)

# DEPENDENCIES

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

#GLU
pkg_search_module(GLU REQUIRED glu)

# library search path
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib/pkgconfig")
set(ENV{LD_LIBRARY_PATH} "ENV{LD_LIBRARY_PATH}:/usr/local/lib")

# build dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
# set(CMAKE_BINARY_DIR bin)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

# Include dirs
include_directories(
  ../dep/linmath
  ../dep/glad
  ../dep/klib
  ${GLFW_INCLUDE_DIRS}
  ${GLU_INCLUDE_DIRS})

set(SOURCE_FILES
  main.c
  scene_hexagons.c
  render_wire.c
  shader.c
  vbo.c)

add_executable(app ${SOURCE_FILES})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../dep/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(
  app
  graph
  glad
  ${GLFW_LIBRARIES}
  ${GLU_LIBRARIES}
  m)

