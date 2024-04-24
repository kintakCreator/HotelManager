add_executable(HotelManager main.cpp)

add_subdirectory(core)

target_link_libraries(HotelManager
    PRIVATE
        core
)
