# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

# Target executable
TARGET = calculator

# Automatically find all .cpp files
SOURCES = $(wildcard *.cpp)

# Generate object file names
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild
rebuild: clean all

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run