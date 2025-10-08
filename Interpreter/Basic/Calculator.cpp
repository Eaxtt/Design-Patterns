#include "Calculator.h"
#include "NumberExpression.h"
#include "AddExpression.h"
#include "SubtractExpression.h"
#include "MultiplyExpression.h"
#include "DivideExpression.h"
#include <iostream>

Calculator::Calculator() {}

Calculator::~Calculator() {}

int Calculator::evaluate(std::string expression) {
    // Step 1: Tokenize the string
    std::vector<std::string> tokens = tokenize(expression);
    
    std::cout << "Tokens: ";
    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << "[" << tokens[i] << "] ";
    }
    std::cout << "\n";
    
    // Step 2: Parse tokens into expression tree
    Expression* tree = parse(tokens);
    
    // Step 3: Interpret the tree
    int result = tree->interpret();
    
    // Step 4: Clean up
    delete tree;
    
    return result;
}

std::vector<std::string> Calculator::tokenize(std::string expr) {
    std::vector<std::string> tokens;
    std::string currentToken = "";
    
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        // Skip whitespace
        if (c == ' ') {
            if (currentToken.length() > 0) {
                tokens.push_back(currentToken);
                currentToken = "";
            }
            continue;
        }
        
        // If operator, save current token and add operator
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (currentToken.length() > 0) {
                tokens.push_back(currentToken);
                currentToken = "";
            }
            std::string op = "";
            op = op + c;
            tokens.push_back(op);
        }
        // If digit, add to current token
        else if (c >= '0' && c <= '9') {
            currentToken = currentToken + c;
        }
    }
    
    // Don't forget the last token
    if (currentToken.length() > 0) {
        tokens.push_back(currentToken);
    }
    
    return tokens;
}

Expression* Calculator::parse(std::vector<std::string>& tokens) {
    int index = 0;
    return parseAddSubtract(tokens, index);
}

// Parse addition and subtraction (lowest precedence)
Expression* Calculator::parseAddSubtract(std::vector<std::string>& tokens, int& index) {
    Expression* left = parseMultiplyDivide(tokens, index);
    
    while (index < (int)tokens.size()) {
        std::string op = tokens[index];
        
        if (op == "+") {
            index++; // consume operator
            Expression* right = parseMultiplyDivide(tokens, index);
            left = new AddExpression(left, right);
        }
        else if (op == "-") {
            index++; // consume operator
            Expression* right = parseMultiplyDivide(tokens, index);
            left = new SubtractExpression(left, right);
        }
        else {
            break; // not our operator
        }
    }
    
    return left;
}

// Parse multiplication and division (higher precedence)
Expression* Calculator::parseMultiplyDivide(std::vector<std::string>& tokens, int& index) {
    Expression* left = parseNumber(tokens, index);
    
    while (index < (int)tokens.size()) {
        std::string op = tokens[index];
        
        if (op == "*") {
            index++; // consume operator
            Expression* right = parseNumber(tokens, index);
            left = new MultiplyExpression(left, right);
        }
        else if (op == "/") {
            index++; // consume operator
            Expression* right = parseNumber(tokens, index);
            left = new DivideExpression(left, right);
        }
        else {
            break; // not our operator
        }
    }
    
    return left;
}

// Parse a number (highest precedence - actual values)
Expression* Calculator::parseNumber(std::vector<std::string>& tokens, int& index) {
    if (index >= (int)tokens.size()) {
        return new NumberExpression(0);
    }
    
    std::string token = tokens[index];
    index++; // consume token
    
    if (isNumber(token)) {
        return new NumberExpression(toNumber(token));
    }
    
    return new NumberExpression(0);
}

bool Calculator::isNumber(std::string token) {
    if (token.length() == 0) return false;
    
    for (size_t i = 0; i < token.length(); i++) {
        if (token[i] < '0' || token[i] > '9') {
            return false;
        }
    }
    return true;
}

bool Calculator::isOperator(std::string token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int Calculator::toNumber(std::string token) {
    int result = 0;
    for (size_t i = 0; i < token.length(); i++) {
        result = result * 10 + (token[i] - '0');
    }
    return result;
}