XX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

# Directories
SRC_DIR = .
BUILD_DIR = build

# Source files
# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/movement.cpp)
SRCS += $(wildcard $(SRC_DIR)/shields_manager.cpp)
SRCS += $(wildcard $(SRC_DIR)/station.cpp)
SRCS += $(wildcard $(SRC_DIR)/docking_module.cpp)
SRCS += $(wildcard $(SRC_DIR)/weapons_manager.cpp)
SRCS += $(wildcard $(SRC_DIR)/ship.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET = $(BUILD_DIR)/starship

# Build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Object file rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILD_DIR)