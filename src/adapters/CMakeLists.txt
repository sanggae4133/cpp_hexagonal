# src/adapters/CMakeLists.txt

file(GLOB_RECURSE HPP_LIST "*.hpp")
file(GLOB_RECURSE CPP_LIST "*.cpp")

add_library(adapters
    STATIC
        ${HPP_LIST}
        ${CPP_LIST}
)

target_link_libraries(adapters
    PUBLIC
        core
)

target_include_directories(adapters
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)