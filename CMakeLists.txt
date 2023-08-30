cmake_minimum_required(VERSION 3.13)
project(StarshipAscension)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "cc")
set(CMAKE_CXX_COMPILER "c++")

# Add the main executable
add_executable(starship
    main.cpp
    movement.cpp
    shields_manager.cpp
    station.cpp
    docking_module.cpp
    weapons_manager.cpp
    ship.cpp
	game.h
    movement.h
    shields_manager.h
    station.h
    docking_module.h
    weapons_manager.h
    ship.h
)

# Enable testing
enable_testing()

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})