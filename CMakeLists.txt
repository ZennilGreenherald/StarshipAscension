cmake_minimum_required(VERSION 3.13)
project(StarshipAscension)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "cc")
set(CMAKE_CXX_COMPILER "c++")

# Add the main executable
add_executable(starship)

# Enable testing
enable_testing()

# Add the additional modules
target_sources(starship PRIVATE
    main.cpp
    movement.cpp
    shields_manager.cpp
    station.cpp
    docking_module.cpp
    weapons_manager.cpp
    ship.cpp
)

# Set the language for each source file to C
set_source_files_properties(
    movement.cpp
    shields_manager.cpp
    station.cpp
    docking_module.cpp
    weapons_manager.cpp
    ship.cpp
    PROPERTIES LANGUAGE CXX
)

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})