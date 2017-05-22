

project(hellozym)
cmake_minimum_required(VERSION 2.8)
find_package(Protobuf REQUIRED) 
include(FindPkgConfig)

set(CMAKE_VERBOSE_MAKEFILE on)
add_subdirectory(src)
add_subdirectory(proto)