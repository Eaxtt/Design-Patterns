#include "RequestParser.h"
#include "TerminalExpression.h"
#include "NonTerminalExpression.h"
#include <algorithm>

RequestParser::RequestParser() {}

RequestParser::~RequestParser() {}

std::string RequestParser::toLowerCase(std::string str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + 32; // Convert to lowercase
        }
    }
    return result;
}

bool RequestParser::contains(std::string text, std::string keyword) {
    return text.find(keyword) != std::string::npos;
}

Expression* RequestParser::parse(std::string customerRequest) {
    std::string request = toLowerCase(customerRequest);
    
    Expression* department = 0;
    Expression* action = 0;
    
    // Determine department based on keywords
    if (contains(request, "phone") || contains(request, "laptop") || 
        contains(request, "computer") || contains(request, "electronics") ||
        contains(request, "tv") || contains(request, "gadget")) {
        department = new KeywordExpression("electronics");
        action = new KeywordExpression("product");
    }
    else if (contains(request, "shirt") || contains(request, "pants") || 
             contains(request, "dress") || contains(request, "clothes") ||
             contains(request, "clothing") || contains(request, "shoes")) {
        department = new KeywordExpression("clothing");
        action = new KeywordExpression("product");
    }
    else if (contains(request, "food") || contains(request, "bread") || 
             contains(request, "milk") || contains(request, "grocery") ||
             contains(request, "produce") || contains(request, "fruit")) {
        department = new KeywordExpression("food");
        action = new KeywordExpression("product");
    }
    else if (contains(request, "return") || contains(request, "refund") || 
             contains(request, "complaint") || contains(request, "manager") ||
             contains(request, "problem")) {
        department = new KeywordExpression("service");
        action = new KeywordExpression("complaint");
    }
    else {
        // Default to customer service
        department = new KeywordExpression("service");
        action = new KeywordExpression("inquiry");
    }
    
    // Build composite expression (NonTerminalExpression)
    return new RequestExpression(department, action);
}