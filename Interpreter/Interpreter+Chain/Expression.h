#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <map>

// Abstract Expression (Interpreter Pattern participant)
class Expression {
public:
    virtual ~Expression() {}
    virtual std::string interpret(std::map<std::string, std::string>& context) = 0;
};

#endif