#ifndef DIVIDE_EXPRESSION_H
#define DIVIDE_EXPRESSION_H

#include "Expression.h"

// Non-Terminal Expression - represents division
class DivideExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    DivideExpression(Expression* l, Expression* r);
    ~DivideExpression();
    int interpret();
};

#endif