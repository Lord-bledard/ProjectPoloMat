cmake_minimum_required(VERSION 3.5)

project(r-type)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

Set(SOURCE_FILES_COMMON

        Common/include/Message.h
        Common/src/Message.cpp
        )

set(SOURCE_FILES_SERVER

        Server/include/Game.h
        Server/include/Server.h


        Server/src/Game.cpp
        Server/src/Server.cpp

        Server/src/main.cpp
        Server/src/GameManager.cpp)

set(SOURCE_FILES_CLIENT
        Client/include/client.h

        Client/src/client.cpp
        Server/include/GameManager.h Client/include/Menu.h Client/src/Menu.cpp)

add_executable(r-type_server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_COMMON})
add_executable(r-type_client ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_COMMON})

target_link_libraries(r-type_server ${CONAN_LIBS})
target_link_libraries(r-type_client ${CONAN_LIBS})

target_include_directories(
        r-type_server PUBLIC

        Server/include
        Server/src

        Common/include
        Common/src
)

target_include_directories(
        r-type_client PUBLIC

        Client/include
        Client/src

        Common/include
        Common/src
)

set_property(TARGET r-type_server PROPERTY CXX_STANDARD 11)
set_property(TARGET r-type_client PROPERTY CXX_STANDARD 11)