# Makefile for Pizza Composite Pattern Example

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = pizza
SOURCES = main.cpp PizzaComponent.cpp Topping.cpp ToppingGroup.cpp
HEADERS = PizzaComponent.h Topping.h ToppingGroup.h
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