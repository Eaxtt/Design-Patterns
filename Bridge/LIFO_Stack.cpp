#include "LIFO_Stack.h"

LIFO_Stack::LIFO_Stack(StackImplementor* impl) : Stack(impl) {}

void LIFO_Stack::push(int val) {
    stackData->push(val);
}

int LIFO_Stack::pop() {
    return stackData->pop();
}