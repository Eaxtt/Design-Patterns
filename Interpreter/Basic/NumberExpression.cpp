#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) : number(value) {}

int NumberExpression::interpret() {
    // Terminal expression just returns its value
    return number;
}