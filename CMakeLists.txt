cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(grid-wars)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

file(GLOB SOURCES src/*.cpp)
add_executable(grid-wars ${SOURCES})
target_link_libraries(grid-wars ${SDL2_LIBRARIES})
