# Makefile for Command Pattern Database System
# No external libraries needed - using only standard C++ and vectors as requested

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Target executable
TARGET = database_system

# Object files
OBJS = main.o Database.o ConcreteCommands.o TransactionManager.o

# Header files (for dependency tracking)
HEADERS = Command.h Database.h ConcreteCommands.h TransactionManager.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files to object files
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

Database.o: Database.cpp Database.h
	$(CXX) $(CXXFLAGS) -c Database.cpp

ConcreteCommands.o: ConcreteCommands.cpp ConcreteCommands.h Command.h Database.h
	$(CXX) $(CXXFLAGS) -c ConcreteCommands.cpp

TransactionManager.o: TransactionManager.cpp TransactionManager.h Command.h
	$(CXX) $(CXXFLAGS) -c TransactionManager.cpp

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean complete!"

# Phony targets (not actual files)
.PHONY: all clean

# Additional useful targets
debug: CXXFLAGS += -DDEBUG
debug: $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all    - Build the program (default)"
	@echo "  clean  - Remove object files and executable"
	@echo "  debug  - Build with debug symbols"
	@echo "  run    - Build and run the program"
	@echo "  help   - Show this help message"