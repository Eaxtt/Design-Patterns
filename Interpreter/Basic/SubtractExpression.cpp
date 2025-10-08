#include "SubtractExpression.h"

SubtractExpression::SubtractExpression(Expression* l, Expression* r) 
    : left(l), right(r) {}

SubtractExpression::~SubtractExpression() {
    delete left;
    delete right;
}

int SubtractExpression::interpret() {
    // Recursively interpret both sides and subtract
    return left->interpret() - right->interpret();
}