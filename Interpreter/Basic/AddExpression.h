#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "Expression.h"

// Non-Terminal Expression - represents addition
class AddExpression : public Expression {
private:
    Expression* left;
    Expression* right;
    
public:
    AddExpression(Expression* l, Expression* r);
    ~AddExpression();
    int interpret();
};

#endif