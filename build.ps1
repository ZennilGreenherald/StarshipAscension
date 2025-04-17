# Directories
$SRC_DIR = "src"
$INCLUDE_DIR = "include"
$BUILD_DIR = "build"

# Compiler and Flags
$COMPILER = "g++"
$FLAGS = "-std=c++17 -Wall -Werror -Wextra -pedantic -Wpedantic -I$INCLUDE_DIR"

# Executable Name
$TARGET = "$BUILD_DIR\space_game.exe"

# Create build directory if it doesn't exist
if (-Not (Test-Path $BUILD_DIR)) {
    New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null
}

# Compile each source file into object files
Get-ChildItem "$SRC_DIR\*.cpp" | ForEach-Object {
    $SourceFile = $_.FullName
    $ObjectFile = "$BUILD_DIR\$($_.BaseName).o"
    Write-Host "Compiling $SourceFile..."
    Invoke-Expression "$COMPILER $FLAGS -c $SourceFile -o $ObjectFile"
}

# Gather all object files
$OBJECT_FILES = (Get-ChildItem "$BUILD_DIR\*.o").ForEach({ $_.FullName }) -join " "

# Link object files into the final executable
Write-Host "Linking files..."
Invoke-Expression "$COMPILER $FLAGS $OBJECT_FILES -o $TARGET"

# Print completion message
if (Test-Path $TARGET) {
    Write-Host "Build complete: $TARGET"
} else {
    Write-Host "Build failed: $TARGET"
}

Pause
