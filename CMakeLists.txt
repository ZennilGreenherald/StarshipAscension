cmake_minimum_required(VERSION 3.13)
project(StarshipAscension
        VERSION 1.0.0
        DESCRIPTION "A game about space exploration and combat"
        HOMEPAGE_URL "https://github.com/gbowne1/StarshipAscension"
        LANGUAGES CXX C)

		include(CTest)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
	set(CMAKE_C_COMPILER /usr/bin/gcc)
	set(CMAKE_C_LINKER "ld")
	set(CMAKE_CXX_LINKER "ld")
	set(CMAKE_EXE_LINKER_FLAGS "-g -s")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
	set(CMAKE_CXX_FLAGS "-g -Wall")
	set(CMAKE_C_FLAGS "-g -Wall")
	set(CMAKE_C_FLAGS_DEBUG "-g")
	set(CMAKE_BUILD_TYPE Debug)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
	set(CMAKE_CXX_COMPILER /usr/bin/g++)
endif ()

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
# set_target_properties(starship PROPERTIES LINK_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    # set build targets for Windows
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    # set build targets for Linux
elseif(CMAKE_SYSTEM_NAME MATCHES "UNIX")
    # set build targets for macOS
endif()


# Add the main executable
add_executable(starship
    include/data_models/Health.h
    include/data_models/Inventory.h
    include/data_models/Moon.h
    include/data_models/Navigation.h
    include/data_models/Planet.h
    include/data_models/Player.h
    include/data_models/Position.h
    include/data_models/Score.h
    include/data_models/Shields.h
    include/game_logic/Engine.h
    include/game_logic/Game.h
    include/game_logic/Movement.h
    include/game_logic/Missions.h
    include/game_logic/Player.h
    include/game_logic/ShieldsManager.h
    include/game_logic/Spaceship.h
    include/game_logic/Starbase.h
    include/game_logic/StarshipAscension.h
    include/game_logic/WeaponsManager.h
    include/ui/Display.h
    include/ui/Menu.h
    include/ui/PlayingField.h
    include/utils/Serializer.h
    include/utils/Vector2D.h
    src/data_models/Health.cpp
    src/data_models/Inventory.cpp
    src/data_models/Moon.cpp
    src/data_models/Navigation.cpp
    src/data_models/Planet.cpp
    src/data_models/Player.cpp
    src/data_models/Position.cpp
    src/data_models/Score.cpp
    src/data_models/Shields.cpp
    src/game_logic/Engine.cpp
    src/game_logic/Game.cpp
    src/game_logic/Movement.cpp
    src/game_logic/Missions.cpp
    src/game_logic/Player.cpp
    src/game_logic/ShieldsManager.cpp
    src/game_logic/Spaceship.cpp
    src/game_logic/Starbase.cpp
    src/game_logic/StarshipAscension.cpp
    src/game_logic/WeaponsManager.cpp
    src/ui/Display.cpp
    src/ui/Menu.cpp
    src/ui/PlayingField.cpp
    src/utils/Serializer.cpp
    src/utils/Vector2D.cpp
)

# Enable testing
enable_testing()

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/utils)