cmake_minimum_required(VERSION 3.2)

project(bcrypt)

set(CMAKE_CXX_STANDARD 11)

add_library(bcrypt src/bcrypt.cpp src/blowfish.cpp)
target_include_directories(bcrypt PRIVATE src/)
target_include_directories(bcrypt PUBLIC include/)

add_executable(test test/main.cpp)
target_link_libraries(test PRIVATE bcrypt)