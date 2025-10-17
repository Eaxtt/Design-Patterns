#include "Node.h"

Node::Node(int val, Node* next) : value(val), nextNode(next) {}

int Node::getValue() const {
    return value;
}

Node* Node::getNext() const {
    return nextNode;
}

void Node::setNext(Node* next) {
    nextNode = next;
}