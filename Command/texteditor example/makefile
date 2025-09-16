# Makefile for Command Pattern Text Editor Demo
# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable name
TARGET = text_editor

# Source files
SOURCES = main.cpp TextEditor.cpp TextCommands.cpp EditorInvoker.cpp

# Object files (automatically generated from sources)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Command.h TextEditor.h TextCommands.h EditorInvoker.h

# Default target - builds the executable
all: $(TARGET)

# Rule to build the executable from object files
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Rule to build object files from source files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Force rebuild everything
rebuild: clean all

# Run the program after building
run: $(TARGET)
	./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the executable (default)"
	@echo "  clean    - Remove compiled files" 
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  help     - Show this help message"

# Mark targets that don't create files
.PHONY: all clean rebuild run help