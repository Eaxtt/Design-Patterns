# Makefile for Spreadsheet Observer Pattern Demo

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Target executable
TARGET = spreadsheet_demo

# Source files
SOURCES = main.cpp Subject.cpp Observer.cpp Spreadsheet.cpp SumCalculator.cpp AverageCalculator.cpp StatisticsDisplay.cpp CellLinker.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = Subject.h Observer.h Spreadsheet.h SumCalculator.h AverageCalculator.h StatisticsDisplay.h CellLinker.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Force rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug target
debug: CXXFLAGS += -DDEBUG
debug: $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the executable (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags"
	@echo "  help     - Show this help message"

.PHONY: all clean rebuild run debug help