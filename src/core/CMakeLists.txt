add_library(core "")

add_subdirectory(systems)

target_link_libraries(core
    PRIVATE
        systems
)
