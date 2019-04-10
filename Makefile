# Parameters to control Makefile operation
PROJECT=spellcheck
CC=g++
CFLAGS=-c -Wall -Werror -Wextra -std=c++17
LDFLAGS=
SRC_DIR=src
TEST_DIR=test
BUILD_DIR=build
SOURCES=$(SRC_DIR)/$(PROJECT)_main.cpp $(SRC_DIR)/$(PROJECT).cpp
OBJECTS=$(SOURCES:.cpp=.o)

# Default
all: main

# Make (link) an executable
main: $(SOURCES) $(PROJECT)

# Make (link) an executable
# Must have objects
$(PROJECT): $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@.out

# Make (compile) an object
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Remove object files and the executable
clean:
	rm -f $(SRC_DIR)/*.o $(BUILD_DIR)/$(PROJECT).out

# Run the executable
run:
	./$(BUILD_DIR)/$(PROJECT).out

# Don't display instructions while running
.SILENT:
	run