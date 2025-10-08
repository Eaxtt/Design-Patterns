#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "Expression.h"

// Terminal Expression - represents a number
class NumberExpression : public Expression {
private:
    int number;
    
public:
    NumberExpression(int value);
    int interpret();
};

#endif