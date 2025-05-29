# src/infrastructure/CMakeLists.txt

file(GLOB_RECURSE HPP_LIST "*.hpp")
file(GLOB_RECURSE CPP_LIST "*.cpp")

add_library(infrastructure
    INTERFACE
        ${HPP_LIST}
        ${CPP_LIST}
)

target_link_libraries(infrastructure
    INTERFACE
        adapters
        core
)

target_include_directories(infrastructure
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)