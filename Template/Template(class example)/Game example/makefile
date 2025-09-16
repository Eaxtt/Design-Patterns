CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = game_demo

all: $(TARGET)

$(TARGET): main.cpp Game.h
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean