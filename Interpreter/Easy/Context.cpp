#include "Context.h"
#include <iostream>
using namespace std;

// CONTEXT Implementation

Context::Context(const string& expr) : input(expr), position(0) {
    cout << "[Context] Created with input: \"" << input << "\"" << endl;
}

Context::~Context() {
}

char Context::peek() const {
    if (position < input.length()) {
        return input[position];
    }
    return '\0';  // End of input
}

char Context::getNext() {
    if (position < input.length()) {
        return input[position++];
    }
    return '\0';
}

bool Context::hasMore() const {
    return position < input.length();
}

void Context::skipWhitespace() {
    while (hasMore() && (peek() == ' ' || peek() == '\t')) {
        position++;
    }
}

unsigned int Context::getPosition() const {
    return position;
}