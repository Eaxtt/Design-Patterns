#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Expression.h"
#include <string>
#include <vector>

// Client - builds the expression tree and evaluates it
class Calculator {
public:
    Calculator();
    ~Calculator();
    
    int evaluate(std::string expression);
    
private:
    // Tokenize the input string
    std::vector<std::string> tokenize(std::string expr);
    
    // Parse tokens into expression tree
    Expression* parse(std::vector<std::string>& tokens);
    
    // Parse with operator precedence
    Expression* parseAddSubtract(std::vector<std::string>& tokens, int& index);
    Expression* parseMultiplyDivide(std::vector<std::string>& tokens, int& index);
    Expression* parseNumber(std::vector<std::string>& tokens, int& index);
    
    // Helper functions
    bool isNumber(std::string token);
    bool isOperator(std::string token);
    int toNumber(std::string token);
};

#endif