#include "AddExpression.h"

AddExpression::AddExpression(Expression* l, Expression* r) 
    : left(l), right(r) {}

AddExpression::~AddExpression() {
    delete left;
    delete right;
}

int AddExpression::interpret() {
    // Recursively interpret both sides and add them
    return left->interpret() + right->interpret();
}