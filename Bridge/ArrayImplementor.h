#ifndef ARRAY_IMPLEMENTOR_H
#define ARRAY_IMPLEMENTOR_H

#include "StackImplementor.h"

class ArrayImplementor : public StackImplementor {
private:
    int* itemList;
    int currentItem;
    int size;

public:
    ArrayImplementor(int capacity = 10);
    ~ArrayImplementor();
    void push(int val) override;
    int pop() override;
    bool isEmpty() const override;
    bool isFull() const override;
};

#endif // ARRAY_IMPLEMENTOR_H