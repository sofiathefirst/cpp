cmake_minimum_required(VERSION 2.8.3)
project(myroscpp)
# check c++11 / c++0x
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

#find_package(pthread )
find_package(Boost REQUIRED COMPONENTS system)
message('boost &&&:')

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "-std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "-std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler. Suggested solution: update the pkg build-essential ")
endif()


aux_source_directory(. DIR_SRCS)
add_subdirectory("boost_learn") 

add_subdirectory("cartographer_learn") 


add_executable(hello1 src/fork/hello.cpp)

target_link_libraries (hello1 ${CMAKE_THREAD_LIBS_INIT})


#add_executable(boost_rar1 src/boost_rar1.cpp)
#target_link_libraries (boost_rar1 boost_iostreams boost_locale)


#add_executable(boost_rar src/boost_rar.cpp)
#target_link_libraries (boost_rar boost_iostreams boost_locale)

add_executable(exep src/fork/exep.cpp)
target_link_libraries (exep ${CMAKE_THREAD_LIBS_INIT})

add_executable(myfork src/fork/myfork.cpp)
target_link_libraries (myfork ${CMAKE_THREAD_LIBS_INIT})

add_executable(kill src/fork/kill.cpp)
target_link_libraries (kill ${CMAKE_THREAD_LIBS_INIT})

add_executable(hypot src/hypot.c)
target_link_libraries(hypot m)

add_library(dutility SHARED  include/utilities_impl.cpp)
add_library(sutility   include/utilities_impl.cpp)

include_directories(include)
add_executable(fixUsbId src/getUSBid.cpp)
add_executable(complex src/complex.cpp)
add_executable(vector src/vector.cpp)
add_executable(fileop src/fileop.cpp)
add_executable(getEnv src/getEnv.cpp)
add_executable(outOfRange src/exceptOutofRange.cpp)
add_executable(time src/time.cpp)
add_executable(atox src/atox.cpp)
add_executable(listsort src/listsort.cpp)
add_executable(vectorsort src/vectorsort.cpp)
add_executable(boostbind src/boostbind.cpp)
add_executable(boostmoment src/boostmoment.cpp)
add_executable(test src/utilities_test.cpp)
target_link_libraries(test sutility)

add_executable(map src/map.cpp)
add_executable(enum src/enum.cpp)
add_executable(typeinfo src/typeinfo.cpp)
#add_executable(LINE src/LINE.cpp)
add_executable(assert src/assert.cpp)
add_executable(math1 src/math.cpp)

add_executable(checknum src/checknum.cpp)

#target_link_libraries(math m)

add_executable(mythread src/mythread.cpp)
target_link_libraries(mythread pthread)

add_executable(classthread src/myclassthread.cpp)
target_link_libraries(classthread pthread)
#add_executable(math src/math.cpp)

add_executable(vector_emplace src/vector_emplace.cpp)
add_executable(nth_element src/nth_element.cpp)

add_executable(example src/example.cpp)
target_link_libraries(example pthread)

add_executable(ftrexample src/future_example.cpp)
target_link_libraries(ftrexample pthread)

