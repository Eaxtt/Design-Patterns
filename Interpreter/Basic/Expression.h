#ifndef EXPRESSION_H
#define EXPRESSION_H

// Abstract Expression
class Expression {
public:
    virtual ~Expression() {}
    virtual int interpret() = 0;
};

#endif