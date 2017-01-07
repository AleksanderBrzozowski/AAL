cmake_minimum_required(VERSION 3.6)
project(AAL)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp SkipList.cpp SkipList.h)

add_executable(AAL ${SOURCE_FILES} BaseSkipList.h TimerSkipList.cpp TimerSkipList.h Simulation.cpp Simulation.h)
add_library(src ${SOURCE_FILES})

add_executable(Tests UnitTests.cpp)
target_link_libraries(Tests gtest gtest_main)
target_link_libraries(Tests src)
