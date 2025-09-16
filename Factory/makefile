# Makefile for Factory Pattern Example

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable name
TARGET = main

# Source files
SOURCES = client.cpp car.cpp motorcycle.cpp truck.cpp car_factory.cpp motorcycle_factory.cpp truck_factory.cpp

# Object files (generated from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile individual source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Rebuild everything from scratch
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run the program with Valgrind
v: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all       - Build the factory demo (default)"
	@echo "  clean     - Remove generated files"
	@echo "  rebuild   - Clean and build"
	@echo "  run       - Run the program"
	@echo "  valgrind  - Run the program with Valgrind memory check"
	@echo "  help      - Show this help message"

# Declare phony targets (targets that don't create files)
.PHONY: all clean rebuild help run valgrind
