#include "SubtractExpression.h"
#include "Context.h"
#include <iostream>
using namespace std;

// NONTERMINALEXPRESSION Implementation - SubtractExpression

SubtractExpression::SubtractExpression(Expression* leftExpr, Expression* rightExpr)
    : left(leftExpr), right(rightExpr) {
    cout << "[NonterminalExpression] SubtractExpression created" << endl;
}

SubtractExpression::~SubtractExpression() {
    // Clean up child expressions
    delete left;
    delete right;
}

// Interpret for SubtractExpression
// Recursively interprets both children and subtracts them
int SubtractExpression::interpret(Context& context) {
    cout << "[Subtract] Evaluating left operand..." << endl;
    int leftValue = left->interpret(context);
    
    cout << "[Subtract] Evaluating right operand..." << endl;
    int rightValue = right->interpret(context);
    
    int result = leftValue - rightValue;
    cout << "[Subtract] " << leftValue << " - " << rightValue << " = " << result << endl;
    
    return result;
}