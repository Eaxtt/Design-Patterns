CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = mediator_demo
OBJS = main.o User.o ChatRoom.o ChatUser.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
main.o: main.cpp ChatRoom.h ChatUser.h
	$(CXX) $(CXXFLAGS) -c main.cpp

User.o: User.cpp User.h Mediator.h
	$(CXX) $(CXXFLAGS) -c User.cpp

ChatRoom.o: ChatRoom.cpp ChatRoom.h Mediator.h User.h
	$(CXX) $(CXXFLAGS) -c ChatRoom.cpp

ChatUser.o: ChatUser.cpp ChatUser.h User.h Mediator.h
	$(CXX) $(CXXFLAGS) -c ChatUser.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Declare phony targets
.PHONY: all clean run