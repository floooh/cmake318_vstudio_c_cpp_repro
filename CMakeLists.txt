cmake_minimum_required(VERSION 3.1)
project(bug)

set(CMAKE_CXX_FLAGS "/TP")
set(CMAKE_C_FLAGS "/TC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "Generic C++ Compiler Flags" FORCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "Generic C Compiler Flags" FORCE)

add_executable(bug main.c lib_cpp.cpp)