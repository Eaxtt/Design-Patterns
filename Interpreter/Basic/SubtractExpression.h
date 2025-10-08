#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H

#include "Expression.h"

// Non-Terminal Expression - represents subtraction
class SubtractExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    SubtractExpression(Expression* l, Expression* r);
    ~SubtractExpression();
    int interpret();
};

#endif