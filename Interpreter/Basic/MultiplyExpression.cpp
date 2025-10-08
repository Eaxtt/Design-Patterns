#include "MultiplyExpression.h"

MultiplyExpression::MultiplyExpression(Expression* l, Expression* r) 
    : left(l), right(r) {}

MultiplyExpression::~MultiplyExpression() {
    delete left;
    delete right;
}

int MultiplyExpression::interpret() {
    // Recursively interpret both sides and multiply
    return left->interpret() * right->interpret();
}