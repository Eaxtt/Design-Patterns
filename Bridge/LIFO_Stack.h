#ifndef LIFO_STACK_H
#define LIFO_STACK_H

#include "Stack.h"

class LIFO_Stack : public Stack {
public:
    LIFO_Stack(StackImplementor* impl);
    void push(int val) override;
    int pop() override;
};

#endif // LIFO_STACK_H