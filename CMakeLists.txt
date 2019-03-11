# 2.8.8 required to use PROTOBUF_IMPORT_DIRS
cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
set (CMAKE_CXX_FLAGS "-g -Wall -std=gnu++17")

include (FindPkgConfig)
pkg_check_modules(GAZEBO gazebo)
pkg_check_modules(SDF sdformat)

include_directories(
  ${GAZEBO_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}/msgs
  )
link_directories(${GAZEBO_LIBRARY_DIRS} ${CMAKE_CURRENT_BINARY_DIR}/msgs)

add_subdirectory(msgs)

add_library(StandalonePlugin SHARED plugin.cc )
target_link_libraries(StandalonePlugin ${GAZEBO_LIBRARIES} msgs)

add_executable(publish_vel publish_vel.cc msgs)
target_link_libraries(publish_vel ${GAZEBO_LIBRARIES} msgs)
