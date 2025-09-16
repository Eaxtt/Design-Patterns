#ifndef CONTEXT_H
#define CONTEXT_H

#include "Calculator.h"

// Context class that uses the strategy
class Context {
private:
    Calculator* strategy;  // Pointer to strategy (owned by Context)

public:
    // Constructor - takes a pointer to a Calculator strategy
    Context(Calculator* calc);
    
    // Destructor - deletes the owned strategy
    ~Context();
    
    // Method to change strategy at runtime (deletes old strategy)
    void setStrategy(Calculator* calc);
    
    // Method that delegates calculation to the strategy
    int calculate(int a, int b);
};

#endif // CONTEXT_H