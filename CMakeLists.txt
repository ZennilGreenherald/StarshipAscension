cmake_minimum_required(VERSION 3.21)
project(StarshipAscension)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)

# Add the main executable
add_executable(starship main.cpp)

# Add the additional modules
target_sources(starship PRIVATE
    movement.cpp
    shields_manager.cpp
    station.cpp
    docking_module.cpp
    weapons_manager.cpp
    ship.cpp
)

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})