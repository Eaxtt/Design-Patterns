#ifndef NODE_H
#define NODE_H

class Node {
private:
    int value;
    Node* nextNode;

public:
    Node(int val, Node* next = nullptr);
    int getValue() const;
    Node* getNext() const;
    void setNext(Node* next);
};

#endif // NODE_H