cmake_minimum_required(VERSION 3.12)

add_executable(HotelManager main.cpp)

add_subdirectory(core)

target_link_libraries(HotelManager
    PRIVATE
        core
)
