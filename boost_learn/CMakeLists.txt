find_package(Boost REQUIRED COMPONENTS system thread )
find_package(PkgConfig)
#find_package(Eigen3 REQUIRED) 
#add_definitions(${EIGEN3_DEFINITIONS}) 
 
message('boost &&&:' ${Boost_LIBRARIES})

add_executable(tt tt.cpp )
target_link_libraries(tt ${Boost_LIBRARIES})