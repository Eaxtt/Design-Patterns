#ifndef QUEUE_H
#define QUEUE_H

#include "QueueIterator.h"

template<typename T>
class Queue {
    // Friend class declaration
    friend class QueueIterator<T>;
    
private:
    // Use the shared Node structure
    typedef QueueNode<T> Node;
    
    Node* front_node;
    Node* rear_node;
    int size_count;

public:
    // Type alias for iterator
    typedef QueueIterator<T> Iterator;
    
    // Constructor and Destructor
    Queue();
    ~Queue();
    
    // Copy constructor and assignment operator
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    
    // Queue operations
    void enqueue(const T& item);
    T dequeue();
    T& front();
    const T& front() const;
    bool empty() const;
    int size() const;
    
    // Iterator support
    Iterator begin();
    Iterator end();
    
private:
    void clear();
    void copy_from(const Queue& other);
};

#endif // QUEUE_H