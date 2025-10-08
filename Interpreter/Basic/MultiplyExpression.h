#ifndef MULTIPLY_EXPRESSION_H
#define MULTIPLY_EXPRESSION_H

#include "Expression.h"

// Non-Terminal Expression - represents multiplication
class MultiplyExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    MultiplyExpression(Expression* l, Expression* r);
    ~MultiplyExpression();
    int interpret();
};

#endif