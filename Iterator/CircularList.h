#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "QueueIterator.h"

template<typename T>
class CircularList {
    // Friend class declaration
    friend class QueueIterator<T>;
    
private:
    // Use the shared Node structure
    typedef QueueNode<T> Node;
    
    Node* head;
    int size_count;

public:
    // Type alias for iterator
    typedef QueueIterator<T> Iterator;
    
    // Constructor and Destructor
    CircularList();
    ~CircularList();
    
    // Copy constructor and assignment operator
    CircularList(const CircularList& other);
    CircularList& operator=(const CircularList& other);
    
    // List operations
    void insert_front(const T& item);
    void insert_back(const T& item);
    void insert_at(int index, const T& item);
    bool remove_front();
    bool remove_back();
    bool remove_at(int index);
    bool remove_value(const T& value);
    
    // Access operations
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T& at(int index);
    const T& at(int index) const;
    
    // Query operations
    bool empty() const;
    int size() const;
    bool contains(const T& value) const;
    int find_index(const T& value) const;
    
    // Iterator support
    Iterator begin();
    Iterator end();
    Iterator circular_begin();  // Special iterator that can loop infinitely
    
    // Utility operations
    void reverse();
    void rotate_left(int positions = 1);
    void rotate_right(int positions = 1);
    void clear();
    
    // Display
    void display() const;
    void display_circular(int rotations = 2) const;  // Show circular nature
    
private:
    void copy_from(const CircularList& other);
    Node* get_node_at(int index) const;
    Node* get_tail() const;
};

// Special circular iterator that can loop infinitely
template<typename T>
class CircularIterator {
private:
    QueueNode<T>* current;
    QueueNode<T>* start;
    int loop_count;
    int max_loops;
    
public:
    CircularIterator(QueueNode<T>* node, int max_loop = 1);
    
    T& operator*();
    const T& operator*() const;
    CircularIterator& operator++();
    CircularIterator operator++(int);
    bool operator!=(const CircularIterator& other) const;
    bool has_more_loops() const;
    int current_loop() const;
};

#endif // CIRCULAR_LIST_H