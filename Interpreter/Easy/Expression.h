#ifndef EXPRESSION_H
#define EXPRESSION_H

class Context;

// ABSTRACTEXPRESSION - Base class for all expression nodes
// Every node in the expression tree inherits from this
class Expression {
public:
    Expression();
    virtual ~Expression();
    
    // The interpret method - evaluates this expression and returns a number
    // Each subclass implements this differently
    virtual int interpret(Context& context) = 0;
};

#endif