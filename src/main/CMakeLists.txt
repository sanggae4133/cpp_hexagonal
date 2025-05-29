# /src/main/CMakeLists.txt

file(GLOB_RECURSE HPP_LIST "inc/*.hpp")
file(GLOB_RECURSE CPP_LIST "src/*.cpp")

add_executable(CppHexagonal main.cpp)

target_link_libraries(CppHexagonal
    PRIVATE
        adapters
        core
        infrastructure
)

target_link_directories(CppHexagonal
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(CppHexagonal
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)