cmake_minimum_required(VERSION 3.13)
project(StarshipAscension
        VERSION 1.0.0
        DESCRIPTION "A game about space exploration and combat"
        HOMEPAGE_URL "https://github.com/gbowne1/StarshipAscension"
        LANGUAGES CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the main executable
add_executable(starship
    main.cpp
	game.cpp
    movement.cpp
    shields_manager.cpp
    station.cpp
    docking_module.cpp
    weapons_manager.cpp
    ship.cpp
	menu.cpp
	movement.cpp
	player.cpp
	playing_field.cpp
	vector2d.cpp
	vector2d.h
	playing_field.h
	player.h
	movement.h
	menu.h
	main.h
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