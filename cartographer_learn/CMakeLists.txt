find_package(Boost REQUIRED COMPONENTS system thread iostreams)

message('boost &&&:' ${Boost_LIBRARIES})

add_executable(vector_g vector.cpp )
#target_link_libraries(tt ${Boost_LIBRARIES})

add_executable(file_tream file_tream.cpp )
target_link_libraries(file_tream ${Boost_LIBRARIES})

add_executable(boost_zip boost_zip.cpp )
target_link_libraries(boost_zip ${Boost_LIBRARIES})