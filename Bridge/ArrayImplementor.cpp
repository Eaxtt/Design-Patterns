#include "ArrayImplementor.h"
#include <stdexcept>

ArrayImplementor::ArrayImplementor(int capacity) 
    : size(capacity), currentItem(-1) {
    itemList = new int[size];
}

ArrayImplementor::~ArrayImplementor() {
    delete[] itemList;
}

void ArrayImplementor::push(int val) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    itemList[++currentItem] = val;
}

int ArrayImplementor::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return itemList[currentItem--];
}

bool ArrayImplementor::isEmpty() const {
    return currentItem == -1;
}

bool ArrayImplementor::isFull() const {
    return currentItem == size - 1;
}