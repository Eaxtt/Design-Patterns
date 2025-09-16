#include "ConcreteStrategies.h"

// Add implementation
int Add::execute(int a, int b) {
    return a + b;
}

// Multiply implementation
int Multiply::execute(int a, int b) {
    return a * b;
}

// Subtract implementation
int Subtract::execute(int a, int b) {
    return a - b;
}