#include "Stack.h"

Stack::Stack(StackImplementor* impl) : stackData(impl) {}

Stack::~Stack() {
    delete stackData;
}

bool Stack::isEmpty() const {
    return stackData->isEmpty();
}

bool Stack::isFull() const {
    return stackData->isFull();
}