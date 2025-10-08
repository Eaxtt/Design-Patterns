#include "DivideExpression.h"

DivideExpression::DivideExpression(Expression* l, Expression* r) 
    : left(l), right(r) {}

DivideExpression::~DivideExpression() {
    delete left;
    delete right;
}

int DivideExpression::interpret() {
    // Recursively interpret both sides and divide
    int rightValue = right->interpret();
    if (rightValue == 0) {
        return 0; // Avoid division by zero
    }
    return left->interpret() / rightValue;
}