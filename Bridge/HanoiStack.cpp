#include "HanoiStack.h"
#include <stdexcept>

HanoiStack::HanoiStack(StackImplementor* impl) : Stack(impl) {}

void HanoiStack::push(int val) {
    // Hanoi rule: can only place smaller disk on top of larger disk
    if (!isEmpty()) {
        int topVal = peek();
        if (val > topVal) {
            throw std::invalid_argument("Cannot place larger disk on smaller disk");
        }
    }
    stackData->push(val);
}

int HanoiStack::pop() {
    return stackData->pop();
}

int HanoiStack::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    // Peek by popping and pushing back
    int val = const_cast<StackImplementor*>(stackData)->pop();
    const_cast<StackImplementor*>(stackData)->push(val);
    return val;
}