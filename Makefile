# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/space_game.exe

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS)
    @mkdir -p $(BUILDDIR)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
    @mkdir -p $(BUILDDIR)
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build directory
clean:
    rm -rf $(BUILDDIR)

.PHONY: all clean
