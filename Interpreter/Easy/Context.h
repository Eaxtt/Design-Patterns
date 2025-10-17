#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
using namespace std;

// CONTEXT - Holds the input string being parsed and current position
// In this simple interpreter, Context tracks where we are in the input
class Context {
private:
    string input;           // The expression string (e.g., "5 + 3")
    unsigned int position;  // Current position in the string

public:
    Context(const string& expr);
    ~Context();
    
    // Get the current character without consuming it
    char peek() const;
    
    // Get current character and advance position
    char getNext();
    
    // Check if we've reached the end
    bool hasMore() const;
    
    // Skip whitespace
    void skipWhitespace();
    
    // Get current position (for debugging)
    unsigned int getPosition() const;
};

#endif