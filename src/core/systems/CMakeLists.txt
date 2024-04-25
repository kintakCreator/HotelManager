cmake_minimum_required(VERSION 3.12)

add_library(systems "")

include_directories("${CMAKE_CURRENT_LIST_DIR}/base")

target_sources(systems
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/RoomMgr.cpp
        ${CMAKE_CURRENT_LIST_DIR}/HotelMgr.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/RoomMgr.hpp
        ${CMAKE_CURRENT_LIST_DIR}/HotelMgr.hpp
)


target_include_directories(systems
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
