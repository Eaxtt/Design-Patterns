#ifndef NONTERMINAL_EXPRESSION_H
#define NONTERMINAL_EXPRESSION_H

#include "Expression.h"

// Non-Terminal Expression - combines keywords into request types
class RequestExpression : public Expression {
private:
    Expression* department;
    Expression* action;
    
public:
    RequestExpression(Expression* dept, Expression* act);
    ~RequestExpression();
    std::string interpret(std::map<std::string, std::string>& context);
};

#endif