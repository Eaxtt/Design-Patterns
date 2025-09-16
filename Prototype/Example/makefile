# Simple Makefile for Prototype Pattern Example

CXX = g++
CXXFLAGS = -std=c++14 -Wall
TARGET = prototype_demo

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp ConcretePrototypes.cpp PrototypeManager.cpp

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run