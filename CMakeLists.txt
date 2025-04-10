cmake_minimum_required(VERSION 3.10)

project(space_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(space_game ${SOURCES})
