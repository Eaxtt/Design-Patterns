CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = sorting_demo

all: $(TARGET)

$(TARGET): main.cpp Sorter.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean