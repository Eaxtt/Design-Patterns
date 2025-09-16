# Default target
all: main

# Link object files to create executable
main: main.o Context.o ConcreteStrategies.o
	g++ main.o Context.o ConcreteStrategies.o -o main

# Compile main.cpp
main.o: main.cpp Calculator.h Context.h ConcreteStrategies.h
	g++ -std=c++11 -Wall -Wextra -c main.cpp

# Compile Context.cpp
Context.o: Context.cpp Context.h Calculator.h
	g++ -std=c++11 -Wall -Wextra -c Context.cpp

# Compile ConcreteStrategies.cpp
ConcreteStrategies.o: ConcreteStrategies.cpp ConcreteStrategies.h Calculator.h
	g++ -std=c++11 -Wall -Wextra -c ConcreteStrategies.cpp

# Clean up generated files
clean:
	rm -f main.o Context.o ConcreteStrategies.o main

# Run the program
run: main
	./main

# Run with valgrind to check for memory leaks
valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main