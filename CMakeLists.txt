cmake_minimum_required(VERSION 3.8)
project(DataStructures)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp btree.cpp btree.h)
add_executable(DataStructures ${SOURCE_FILES})