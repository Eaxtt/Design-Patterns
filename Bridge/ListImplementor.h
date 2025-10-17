#ifndef LIST_IMPLEMENTOR_H
#define LIST_IMPLEMENTOR_H

#include "StackImplementor.h"
#include "Node.h"

class ListImplementor : public StackImplementor {
private:
    Node* head;

public:
    ListImplementor();
    ~ListImplementor();
    void push(int val) override;
    int pop() override;
    bool isEmpty() const override;
    bool isFull() const override;
};

#endif // LIST_IMPLEMENTOR_H