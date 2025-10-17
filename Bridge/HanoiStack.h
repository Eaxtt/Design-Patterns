#ifndef HANOI_STACK_H
#define HANOI_STACK_H

#include "Stack.h"

class HanoiStack : public Stack {
public:
    HanoiStack(StackImplementor* impl);
    void push(int val) override;
    int pop() override;
    int peek() const;
};

#endif // HANOI_STACK_H