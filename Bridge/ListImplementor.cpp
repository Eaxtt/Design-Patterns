#include "ListImplementor.h"
#include <stdexcept>

ListImplementor::ListImplementor() : head(nullptr) {}

ListImplementor::~ListImplementor() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void ListImplementor::push(int val) {
    Node* newNode = new Node(val, head);
    head = newNode;
}

int ListImplementor::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    Node* temp = head;
    int value = temp->getValue();
    head = head->getNext();
    delete temp;
    return value;
}

bool ListImplementor::isEmpty() const {
    return head == nullptr;
}

bool ListImplementor::isFull() const {
    // Linked list is never full (until memory exhaustion)
    return false;
}