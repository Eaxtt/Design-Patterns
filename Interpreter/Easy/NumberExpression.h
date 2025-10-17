#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "Expression.h"

// TERMINALEXPRESSION - Represents a number (like 5, 42, 100)
// Terminal because it's a leaf node - no children
// Grammar: Number ::= digit+
class NumberExpression : public Expression {
private:
    int value;  // The actual numeric value

public:
    // Constructor takes the numeric value
    NumberExpression(int num);
    ~NumberExpression();
    
    // Interpret just returns the stored number
    // No recursion needed - it's a terminal!
    int interpret(Context& context) override;
};

#endif