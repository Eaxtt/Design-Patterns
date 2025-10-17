#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "Expression.h"

// NONTERMINALEXPRESSION - Represents addition (left + right)
// Nonterminal because it has children (two operands)
// Grammar: Expression '+' Expression
class AddExpression : public Expression {
private:
    // Child expressions - this forms the tree structure
    Expression* left;
    Expression* right;

public:
    // Constructor takes two child expressions
    AddExpression(Expression* leftExpr, Expression* rightExpr);
    ~AddExpression();
    
    // Interpret recursively interprets both children and adds them
    int interpret(Context& context) override;
};

#endif