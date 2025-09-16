#ifndef CONCRETE_STRATEGIES_H
#define CONCRETE_STRATEGIES_H

#include "Calculator.h"

// Concrete Strategy - Add
class Add : public Calculator {
public:
    int execute(int a, int b) override;
};

// Concrete Strategy - Multiply
class Multiply : public Calculator {
public:
    int execute(int a, int b) override;
};

// Concrete Strategy - Subtract
class Subtract : public Calculator {
public:
    int execute(int a, int b) override;
};

#endif // CONCRETE_STRATEGIES_H