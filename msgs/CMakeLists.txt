cmake_minimum_required(VERSION 3.0)
find_package(Protobuf REQUIRED)

pkg_check_modules(GAZEBO gazebo)

set (msgs
  velocity.proto
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})

add_library(msgs SHARED ${PROTO_SRCS})
target_link_libraries(msgs ${PROTOBUF_LIBRARY})
