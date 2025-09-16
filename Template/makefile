# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

# Target executable
TARGET = boardgames

# Source files
SOURCES = main.cpp BoardGame.cpp Chess.cpp Checkers.cpp

# Object files (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files for dependencies
HEADERS = BoardGame.h Chess.h Checkers.h

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Generic rule for compiling .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies (headers)
BoardGame.o: BoardGame.cpp BoardGame.h
Chess.o: Chess.cpp Chess.h BoardGame.h
Checkers.o: Checkers.cpp Checkers.h BoardGame.h
main.o: main.cpp Chess.h Checkers.h BoardGame.h

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install (optional - copies to /usr/local/bin)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Debug build with debug symbols and no optimization
debug: CXXFLAGS = -Wall -Wextra -std=c++11 -g -DDEBUG
debug: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the executable (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug symbols"
	@echo "  install  - Install to /usr/local/bin"
	@echo "  help     - Show this help message"

# Declare phony targets (targets that don't create files)
.PHONY: all clean rebuild run install debug help