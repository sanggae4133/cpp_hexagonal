# src/core/CMakeLists.txt

file(GLOB_RECURSE HPP_LIST "*.hpp")
file(GLOB_RECURSE CPP_LIST "*.cpp")

add_library(core
    STATIC
        ${HPP_LIST}
        ${CPP_LIST}
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(core PROPERTIES CXX_STANDARD 17)