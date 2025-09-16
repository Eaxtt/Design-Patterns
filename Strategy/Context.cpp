#include "Context.h"

// Constructor - initializes strategy pointer
Context::Context(Calculator* calc) : strategy(calc) {
    // Context now owns the Calculator object
}

// Destructor - deletes the owned strategy
Context::~Context() {
    delete strategy;  // Clean up the owned Calculator object
    strategy = nullptr;  // Good practice to avoid dangling pointers
}

// Set a new strategy (deletes the old one first)
void Context::setStrategy(Calculator* calc) {
    delete strategy;  // Delete the old strategy first
    strategy = calc;  // Set the new strategy
}

// Delegate calculation to the current strategy
int Context::calculate(int a, int b) {
    if (strategy != nullptr) {
        return strategy->execute(a, b);
    }
    // Handle null strategy case (in real code, you might throw an exception)
    return 0;
}