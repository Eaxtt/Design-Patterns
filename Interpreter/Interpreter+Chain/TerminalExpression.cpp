#include "TerminalExpression.h"

KeywordExpression::KeywordExpression(std::string kw) : keyword(kw) {}

std::string KeywordExpression::interpret(std::map<std::string, std::string>& context) {
    // Return the keyword - terminal expressions return their value
    return keyword;
}