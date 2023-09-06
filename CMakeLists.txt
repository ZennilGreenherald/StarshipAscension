cmake_minimum_required(VERSION 3.13)
project(StarshipAscension
        VERSION 1.0.0
        DESCRIPTION "A game about space exploration and combat"
        HOMEPAGE_URL "https://github.com/gbowne1/StarshipAscension"
        LANGUAGES CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "cc")
set(CMAKE_CXX_COMPILER "c++")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

target_compile_options(starship PRIVATE -Wall -Wextra)

# Enable testing
enable_testing()

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})