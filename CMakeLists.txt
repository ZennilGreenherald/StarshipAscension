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

file(GLOB_RECURSE HDRS "include/*.h")
file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(starship ${SRCS} ${HDRS})

# Enable testing
enable_testing()

# Include the project root directory
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/utils)