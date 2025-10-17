#include "NumberExpression.h"
#include "Context.h"
#include <iostream>
using namespace std;

// TERMINALEXPRESSION Implementation - NumberExpression

NumberExpression::NumberExpression(int num) : value(num) {
    cout << "[TerminalExpression] Number created: " << value << endl;
}

NumberExpression::~NumberExpression() {
}

// Interpret for NumberExpression
// Simply returns the stored value - no recursion!
int NumberExpression::interpret(Context& context) {
    cout << "[Number] Returning value: " << value << endl;
    return value;
}