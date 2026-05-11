cmake_minimum_required(VERSION 3.10)
project(cpp_start)


add_library(simulation src/core/simulation/simulation.cpp)
add_library(solar src/core/solar_system/solar_system.cpp src/core/planet/planet.cpp)

target_include_directories(
    solar PUBLIC
    ${CMAKE_SOURCE_DIR}/src/core/solar_system)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE simulation solar)
