# Compiler options
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
DOCS_DIR = docs

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(SRCS))) \
       $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(SRCS)))

# Executable file name
TARGET = $(BIN_DIR)/lab-01.elf

# Main target
all: directories $(TARGET)

# Create directories
directories:
	mkdir -p $(BUILD_DIR) $(BIN_DIR) $(DOCS_DIR)

# Compile executable file
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Compile .c files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .cpp files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate documentation with Doxygen
docs:
	doxygen docs/Doxyfile
	make -C $(DOCS_DIR)/latex
	mv $(DOCS_DIR)/latex/refman.pdf $(DOCS_DIR)/lab-01.pdf
	rm -rf $(DOCS_DIR)/html $(DOCS_DIR)/latex

# Clean build
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/* $(DOCS_DIR)/html $(DOCS_DIR)/latex

# Target for running the program
run: all
	$(TARGET)

.PHONY: all directories clean docs run
