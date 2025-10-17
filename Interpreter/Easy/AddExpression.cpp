#include "AddExpression.h"
#include "Context.h"
#include <iostream>
using namespace std;

// NONTERMINALEXPRESSION Implementation - AddExpression

AddExpression::AddExpression(Expression* leftExpr, Expression* rightExpr)
    : left(leftExpr), right(rightExpr) {
    cout << "[NonterminalExpression] AddExpression created" << endl;
}

AddExpression::~AddExpression() {
    // Clean up child expressions
    delete left;
    delete right;
}

// Interpret for AddExpression
// Recursively interprets both children and adds the results
int AddExpression::interpret(Context& context) {
    cout << "[Add] Evaluating left operand..." << endl;
    int leftValue = left->interpret(context);
    
    cout << "[Add] Evaluating right operand..." << endl;
    int rightValue = right->interpret(context);
    
    int result = leftValue + rightValue;
    cout << "[Add] " << leftValue << " + " << rightValue << " = " << result << endl;
    
    return result;
}