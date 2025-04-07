cmake_minimum_required(VERSION 3.13)
project(StarshipAscension
        VERSION 1.0.0
        DESCRIPTION "A game about space exploration and combat"
        HOMEPAGE_URL "https://github.com/gbowne1/StarshipAscension"
        LANGUAGES CXX C)

include(CTest)

# Set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-specific configurations
if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)
    set(CMAKE_C_LINKER "ld")
    set(CMAKE_CXX_LINKER "ld")
    set(CMAKE_EXE_LINKER_FLAGS "-g -s")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
    set(CMAKE_C_FLAGS "-g -Wall")
    set(CMAKE_C_FLAGS_DEBUG "-g")
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
        # MSVC-specific settings
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /EHsc /Zi /DEBUG /MDd")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Zi /DEBUG /MDd")
        set(CMAKE_EXE_LINKER_FLAGS "/DEBUG /INCREMENTAL:NO")
        set(CMAKE_BUILD_TYPE Debug)
    else()
        # MinGW/MSYS2 settings
        set(CMAKE_C_COMPILER "gcc.exe")
        set(CMAKE_CXX_COMPILER "g++.exe")
        set(CMAKE_LINKER "ld.exe")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
        set(CMAKE_C_FLAGS_DEBUG "-g")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall")
    endif()
endif()

# Project directories
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Glob source and header files
file(GLOB_RECURSE HDRS "include/*.h")
file(GLOB_RECURSE SRCS "src/*.cpp")

# Add executable
add_executable(starship ${SRCS} ${HDRS})

# Include directories
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
target_include_directories(starship PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/utils)

# Enable testing
enable_testing()

# Add testing targets (example)
# add_test(NAME TestName COMMAND starship --test)
# add_test(NAME AnotherTestName COMMAND starship --another-test)
# add_test(NAME YetAnotherTestName COMMAND starship --yet-another-test)	