cmake_minimum_required(VERSION 3.6)
project(AAL)

set(GTEST_DIR googletest/googletest)

add_library(gtest ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
target_include_directories(gtest PUBLIC ${GTEST_DIR} ${GTEST_DIR}/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp SkipList.cpp SkipList.h BaseSkipList.h OutTimerSkipList.cpp OutTimerSkipList.h Simulation.cpp Simulation.h BaseTimerSkipList.h TimerSkipList.cpp TimerSkipList.h)

add_executable(AAL ${SOURCE_FILES})

add_executable(Tests UnitTests.cpp ${SOURCE_FILES})
target_link_libraries(Tests gtest)
