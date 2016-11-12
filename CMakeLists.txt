cmake_minimum_required(VERSION 3.6)
project(AAL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp SkipList.cpp SkipList.h)
add_executable(AAL ${SOURCE_FILES})