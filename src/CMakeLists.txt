cmake_minimum_required(VERSION 3.12)

add_executable(HotelManager main.cpp)

include_directories(${CMAKE_BINARY_DIR}/dep/spdlog/include)
include_directories(${CMAKE_BINARY_DIR}/src/core)

add_subdirectory(core)

target_link_libraries(HotelManager
    PRIVATE
        core
        spdlog
)
