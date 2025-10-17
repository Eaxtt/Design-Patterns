# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = main

# Source files
SOURCES = main.cpp \
          Node.cpp \
          Stack.cpp \
          LIFO_Stack.cpp \
          HanoiStack.cpp \
          ArrayImplementor.cpp \
          ListImplementor.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Node.h \
          StackImplementor.h \
          ArrayImplementor.h \
          ListImplementor.h \
          Stack.h \
          LIFO_Stack.h \
          HanoiStack.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run