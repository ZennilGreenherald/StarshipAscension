@echo off
REM Debugging script for space_game using GDB

REM Executable Path
set TARGET=build\space_game.exe

REM Launch GDB
echo Starting debugger for %TARGET%...
gdb %TARGET%
pause
