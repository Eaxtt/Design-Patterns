# Default target
all: building_demo

# Link object files to create executable
building_demo: main.o LeafComponents.o CompositeComponents.o
	g++ main.o LeafComponents.o CompositeComponents.o -o building_demo

# Compile main.cpp
main.o: main.cpp BuildingComponent.h LeafComponents.h CompositeComponents.h
	g++ -std=c++11 -Wall -Wextra -c main.cpp

# Compile LeafComponents.cpp
LeafComponents.o: LeafComponents.cpp LeafComponents.h BuildingComponent.h
	g++ -std=c++11 -Wall -Wextra -c LeafComponents.cpp

# Compile CompositeComponents.cpp
CompositeComponents.o: CompositeComponents.cpp CompositeComponents.h BuildingComponent.h
	g++ -std=c++11 -Wall -Wextra -c CompositeComponents.cpp

# Clean up generated files
clean:
	rm -f main.o LeafComponents.o CompositeComponents.o building_demo

# Run the program
run: building_demo
	./building_demo

# Run with valgrind to check for memory leaks
valgrind: building_demo
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./building_demo