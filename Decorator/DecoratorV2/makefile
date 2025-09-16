# Makefile for Decorator Pattern Example

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = coffee_shop

# Source files
SOURCES = main.cpp ConcreteComponent.cpp Decorator.cpp ConcreteDecoratorA.cpp ConcreteDecoratorB.cpp

# Object files (generated from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = Component.h ConcreteComponent.h Decorator.h ConcreteDecoratorA.h ConcreteDecoratorB.h

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets (not files)
.PHONY: all clean run

# Run the program
run: $(TARGET)
	./$(TARGET)

# Display help
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  clean   - Remove object files and executable"
	@echo "  run     - Build and run the program"
	@echo "  help    - Display this help message"