#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

#include "Expression.h"
#include <string>
#include <map>

// Client for Interpreter Pattern - builds abstract syntax tree
class RequestParser {
public:
    RequestParser();
    ~RequestParser();
    
    // Parse customer request and build expression tree
    Expression* parse(std::string customerRequest);
    
private:
    std::string toLowerCase(std::string str);
    bool contains(std::string text, std::string keyword);
};

#endif