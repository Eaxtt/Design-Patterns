# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target
TARGET = main

# Sources
SOURCES = main.cpp \
          Expression.cpp \
          NumberExpression.cpp \
          AddExpression.cpp \
          SubtractExpression.cpp \
          Context.cpp

# Objects
OBJECTS = $(SOURCES:.cpp=.o)

# Headers
HEADERS = Expression.h \
          NumberExpression.h \
          AddExpression.h \
          SubtractExpression.h \
          Context.h

# Default
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run