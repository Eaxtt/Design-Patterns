# Makefile for Iterator Design Pattern Demo

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
DEBUGFLAGS = -std=c++11 -Wall -Wextra -g -O0 -DDEBUG

# Target executable name
TARGET = iterator_demo

# Source files
SOURCES = main.cpp Queue.cpp QueueIterator.cpp CircularList.cpp
HEADERS = Queue.h QueueIterator.h CircularList.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug build
debug: CXXFLAGS = $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Clean and rebuild
rebuild: clean $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install (copy to /usr/local/bin - requires sudo)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  debug    - Build with debug symbols"
	@echo "  clean    - Remove build files"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  install  - Install to /usr/local/bin (requires sudo)"
	@echo "  uninstall- Remove from /usr/local/bin (requires sudo)"
	@echo "  help     - Show this help message"

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Generate assembly output
assembly: main.cpp Queue.cpp
	$(CXX) $(CXXFLAGS) -S main.cpp Queue.cpp

# Phony targets
.PHONY: all debug clean rebuild run install uninstall help memcheck assembly