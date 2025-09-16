# Makefile for Pizza Decorator Pattern Example

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = pizza_decorator
SOURCES = main.cpp BasePizza.cpp PizzaDecorator.cpp ExtraCheese.cpp StuffedCrust.cpp
HEADERS = Pizza.h BasePizza.h PizzaDecorator.h ExtraCheese.h StuffedCrust.h
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile individual object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJECTS)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Rebuild everything
rebuild: clean all

.PHONY: all clean run rebuild