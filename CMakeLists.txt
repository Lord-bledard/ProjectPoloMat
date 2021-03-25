cmake_minimum_required(VERSION 3.5)

project(r-type)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCE_FILES_SERVER Server/src/server.cpp)
set(SOURCE_FILES_CLIENT Client/src/client.cpp)

add_executable(r-type_server ${SOURCE_FILES_SERVER})
add_executable(r-type_client ${SOURCE_FILES_CLIENT})

target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

