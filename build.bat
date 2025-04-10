@echo off
REM Enable delayed variable expansion
setlocal enabledelayedexpansion

REM Directories
set SRC_DIR=src
set INCLUDE_DIR=include
set BUILD_DIR=build

REM Compiler and Flags
set COMPILER=g++
set FLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -Wpedantic -I%INCLUDE_DIR%

REM Executable Name
set TARGET=%BUILD_DIR%\space_game.exe

REM Create build directory
if not exist %BUILD_DIR% mkdir %BUILD_DIR%

REM Compile each source file into object files
for %%f in (%SRC_DIR%\*.cpp) do (
    echo Compiling %%f...
    %COMPILER% %FLAGS% -c %%f -o %BUILD_DIR%\%%~nf.o
)

REM Gather all object files
set OBJECT_FILES=
for %%f in (%BUILD_DIR%\*.o) do (
    set OBJECT_FILES=!OBJECT_FILES! %%f
)

REM Link object files into the final executable
echo Linking files...
%COMPILER% %FLAGS% !OBJECT_FILES! -o %TARGET%

REM Print completion message
if exist %TARGET% (
    echo Build complete: %TARGET%
) else (
    echo Build failed: %TARGET%
)

pause
