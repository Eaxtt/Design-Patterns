#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H

#include "Expression.h"

// NONTERMINALEXPRESSION - Represents subtraction (left - right)
// Nonterminal because it has children (two operands)
// Grammar: Expression '-' Expression
class SubtractExpression : public Expression {
private:
    // Child expressions
    Expression* left;
    Expression* right;

public:
    // Constructor takes two child expressions
    SubtractExpression(Expression* leftExpr, Expression* rightExpr);
    ~SubtractExpression();
    
    // Interpret recursively interprets both children and subtracts them
    int interpret(Context& context) override;
};

#endif