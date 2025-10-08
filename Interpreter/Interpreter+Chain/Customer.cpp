#include "Customer.h"
#include "Expression.h"
#include <iostream>
#include <map>

Customer::Customer(std::string customerName) : name(customerName) {}

void Customer::askForHelp(std::string request, StaffHandler* firstStaff) {
    std::cout << "\n" << name << " says: \"" << request << "\"\n";
    std::cout << "----------------------------------------\n";
    
    // INTERPRETER PATTERN: Parse the natural language request
    Expression* requestExpr = parser.parse(request);
    
    // Create context (as per Interpreter pattern)
    std::map<std::string, std::string> context;
    
    // Interpret the expression
    std::string interpretedRequest = requestExpr->interpret(context);
    
    std::cout << "Interpreted as: " << interpretedRequest << "\n";
    std::cout << "----------------------------------------\n";
    
    // CHAIN OF RESPONSIBILITY PATTERN: Route to appropriate staff
    firstStaff->handleRequest(interpretedRequest, request);
    
    // Clean up expression tree
    delete requestExpr;
}