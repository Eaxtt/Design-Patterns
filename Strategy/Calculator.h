#ifndef CALCULATOR_H
#define CALCULATOR_H

// Abstract Strategy - Calculator interface
class Calculator {
public:
    virtual ~Calculator() = default;
    virtual int execute(int a, int b) = 0;
};

#endif // CALCULATOR_H