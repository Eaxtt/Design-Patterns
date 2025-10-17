#ifndef STACK_H
#define STACK_H

#include "StackImplementor.h"

// Abstract Stack class (Abstraction in Bridge Pattern)
class Stack {
protected:
    StackImplementor* stackData;

public:
    Stack(StackImplementor* impl);
    virtual ~Stack();
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() const;
    virtual bool isFull() const;
};

#endif // STACK_H