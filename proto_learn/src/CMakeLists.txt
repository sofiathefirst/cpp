
include_directories(${PROJECT_BINARY_DIR}/proto)
#include_directories("/usr/local/protobuf-2.4.1/include/")
#link_directories("/usr/local/protobuf-2.4.1/lib/")
set(TARGET helloworldzym)
set(SRCFILES main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(${TARGET} ${SRCFILES})
target_link_libraries(${TARGET} proto protobuf)

include_directories(${PROJECT_BINARY_DIR}/proto)
include_directories("/usr/local/protobuf-2.4.1/include/")
link_directories("/usr/local/protobuf-2.4.1/lib/")
set(TARGET helloworld)
set(SRCFILES main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(${TARGET} ${SRCFILES})
target_link_libraries(${TARGET} proto protobuf)