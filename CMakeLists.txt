cmake_minimum_required(VERSION 3.6)
project(rspbtest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(rspbtest ${SOURCE_FILES})
target_link_libraries(rspbtest -lserial -pthread)