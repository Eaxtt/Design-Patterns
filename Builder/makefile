# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = computer_builder

# Object files
OBJS = main.o Computer.o ConcreteBuilders.o TechnicianAssembler.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp
main.o: main.cpp Computer.h ComputerBuilder.h ConcreteBuilders.h TechnicianAssembler.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile Computer.cpp
Computer.o: Computer.cpp Computer.h
	$(CXX) $(CXXFLAGS) -c Computer.cpp

# Compile ConcreteBuilders.cpp
ConcreteBuilders.o: ConcreteBuilders.cpp ConcreteBuilders.h ComputerBuilder.h Computer.h
	$(CXX) $(CXXFLAGS) -c ConcreteBuilders.cpp

# Compile TechnicianAssembler.cpp
TechnicianAssembler.o: TechnicianAssembler.cpp TechnicianAssembler.h ComputerBuilder.h
	$(CXX) $(CXXFLAGS) -c TechnicianAssembler.cpp

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)