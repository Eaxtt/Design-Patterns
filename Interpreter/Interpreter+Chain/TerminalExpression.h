#ifndef TERMINAL_EXPRESSION_H
#define TERMINAL_EXPRESSION_H

#include "Expression.h"

// Terminal Expression - represents keywords in customer requests
class KeywordExpression : public Expression {
private:
    std::string keyword;
    
public:
    KeywordExpression(std::string kw);
    std::string interpret(std::map<std::string, std::string>& context);
};

#endif