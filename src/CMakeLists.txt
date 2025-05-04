cmake_minimum_required(VERSION 3.28)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_library(gui STATIC Application.cpp Ball.cpp)
target_compile_features(gui PRIVATE cxx_std_17)

target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}   ${CMAKE_BINARY_DIR}/_deps/sfml-src/include)

message("Global include directories: ${CMAKE_INCLUDE_PATH}")
get_target_property(includes gui INCLUDE_DIRECTORIES)
message("Include directories for GUI: ${includes}")

