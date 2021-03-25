cmake_minimum_required(VERSION 3.5)

project(rtype)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED system)
include_directories( ${Boost_INCLUDE_DIRS} )
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES src/server.cpp)


add_executable(rtype ${SOURCE_FILES})

target_link_libraries(rtype ${CONAN_LIBS})
