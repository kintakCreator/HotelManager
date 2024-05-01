cmake_minimum_required(VERSION 3.12)
project(HotelTest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR}/src)

add_executable(HotelTest 
    tester.cpp    
)

target_link_libraries(HotelTest core gtest gtest_main)
