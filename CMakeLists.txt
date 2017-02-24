cmake_minimum_required(VERSION 2.8.3)
project(myroscpp)

aux_source_directory(. DIR_SRCS)


add_executable(fixUsbId src/getUSBid.cpp)

add_executable(complex src/complex.cpp)
