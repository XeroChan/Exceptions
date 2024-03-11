cmake_minimum_required(VERSION 3.27)
project(Exceptions)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror=return-type")

add_executable(Exceptions main.cpp)
