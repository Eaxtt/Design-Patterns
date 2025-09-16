# Makefile for Shape Factory and Prototype Pattern Demo

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = demo

# Source files
SOURCES = main.cpp Shape.cpp Rectangle.cpp Square.cpp Textbox.cpp ShapeFactory.cpp Canvas.cpp

# Object files (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Shape.h Rectangle.h Square.h Textbox.h ShapeFactory.h Canvas.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build complete! Run with: make run"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete"

# Rebuild everything
rebuild: clean all

# Debug build with extra debugging info
debug: CXXFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build with optimizations
release: CXXFLAGS += -O3 -DNDEBUG
release: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  run      - Build and run the program"  
	@echo "  clean    - Remove build files"
	@echo "  rebuild  - Clean and build"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with optimizations"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all run clean rebuild debug release help