cmake_minimum_required(VERSION 3.12)

add_library(core "")

add_subdirectory(systems)

target_link_libraries(core
    PRIVATE
        systems
)
