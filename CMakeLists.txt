cmake_minimum_required(VERSION 3.13)
project(StarshipAscension
        VERSION 1.0.0
        DESCRIPTION "A game about space exploration and combat"
        HOMEPAGE_URL "https://github.com/gbowne1/StarshipAscension"
        LANGUAGES CXX)

		include(CTest)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_LINKER ld)
set(CMAKE_EXE_LINKER_FLAGS "-g -s")
set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -e")
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_C_FLAGS "-g -Wall -m32")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_GDB_COMMAND gdb)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_ASM_COMPILER nasm)
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --32")
set(CMAKE_ASM_NASM_OBJECT_FORMAT bin)
set(CMAKE_SYSTEM_PROCESSOR i386)
set(CMAKE_SYSTEM_NAME None)
set(CMAKE_ASM_NASM_COMPILER nasm)
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
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)