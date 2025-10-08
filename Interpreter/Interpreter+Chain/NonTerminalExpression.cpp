#include "NonTerminalExpression.h"

RequestExpression::RequestExpression(Expression* dept, Expression* act) 
    : department(dept), action(act) {}

RequestExpression::~RequestExpression() {
    delete department;
    delete action;
}

std::string RequestExpression::interpret(std::map<std::string, std::string>& context) {
    // Interpret both parts and combine into a request type
    std::string dept = department->interpret(context);
    std::string act = action->interpret(context);
    
    // Store in context for Chain of Responsibility
    context["department"] = dept;
    context["action"] = act;
    
    // Return formatted request
    return dept + ":" + act;
}