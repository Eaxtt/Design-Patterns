#include "Queue.h"
#include <stdexcept>

// Queue implementation
template<typename T>
Queue<T>::Queue() : front_node(nullptr), rear_node(nullptr), size_count(0) {
}

template<typename T>
Queue<T>::~Queue() {
    clear();
}

template<typename T>
Queue<T>::Queue(const Queue& other) : front_node(nullptr), rear_node(nullptr), size_count(0) {
    copy_from(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}

template<typename T>
void Queue<T>::enqueue(const T& item) {
    Node* new_node = new Node(item);
    
    if (empty()) {
        front_node = rear_node = new_node;
    } else {
        rear_node->next = new_node;
        rear_node = new_node;
    }
    size_count++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    
    Node* temp = front_node;
    T data = temp->data;
    
    front_node = front_node->next;
    if (front_node == nullptr) {
        rear_node = nullptr;
    }
    
    delete temp;
    size_count--;
    return data;
}

template<typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front_node->data;
}

template<typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front_node->data;
}

template<typename T>
bool Queue<T>::empty() const {
    return front_node == nullptr;
}

template<typename T>
int Queue<T>::size() const {
    return size_count;
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(front_node);
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(nullptr);
}

template<typename T>
void Queue<T>::clear() {
    while (!empty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::copy_from(const Queue& other) {
    Node* current = other.front_node;
    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }
}

// Explicit template instantiations (add more as needed)
template class Queue<int>;
template class Queue<double>;
template class Queue<char>;
template class Queue<const char*>;