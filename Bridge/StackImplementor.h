#ifndef STACK_IMPLEMENTOR_H
#define STACK_IMPLEMENTOR_H

// Abstract interface for stack implementations
class StackImplementor {
public:
    virtual ~StackImplementor() {}
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif // STACK_IMPLEMENTOR_H