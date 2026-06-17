set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.14)

project(cpp_start CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

fetchcontent_declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

fetchcontent_makeavailable(raylib)

add_library(simulation src/core/simulation/simulation.cpp)
add_library(solar src/entities/planet_collection/planet_collection.cpp src/entities/planet/planet.cpp src/utils/coordinates/coordinate.cpp)
add_library(helpers src/helpers/raylib/raylib_helper.cpp)

target_include_directories(solar PUBLIC ${CMAKE_SOURCE_DIR}/src/core/solar_system)

target_link_libraries(solar PUBLIC raylib)
target_link_libraries(simulation PUBLIC raylib)
target_link_libraries(helpers PUBLIC raylib solar)

# Executable
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE simulation helpers)
