cmake_minimum_required(VERSION 3.5)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED system)
include_directories( ${Boost_INCLUDE_DIRS} )

set(SOURCE_FILES src/server.cpp)

add_executable(hello ${SOURCE_FILES})

set_target_properties(hello PROPERTIES LINKER_LANGUAGE C)
