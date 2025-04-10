#!/bin/bash

# Create build directory
mkdir -p build
cd build

# Run CMake and build
cmake ..
make

# Return to the root directory
cd ..
