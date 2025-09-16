#include "QueueIterator.h"
#include <stdexcept>

// QueueIterator implementation
template<typename T>
QueueIterator<T>::QueueIterator() : current(nullptr), container_begin(nullptr) {
}

template<typename T>
QueueIterator<T>::QueueIterator(QueueNode<T>* node, QueueNode<T>* begin_node) 
    : current(node), container_begin(begin_node) {
}

template<typename T>
QueueIterator<T>::QueueIterator(const QueueIterator& other) 
    : current(other.current), container_begin(other.container_begin) {
}

template<typename T>
QueueIterator<T>& QueueIterator<T>::operator=(const QueueIterator& other) {
    if (this != &other) {
        current = other.current;
        container_begin = other.container_begin;
    }
    return *this;
}

template<typename T>
QueueIterator<T>::~QueueIterator() {
    // Iterator doesn't own the nodes, so no cleanup needed
}

template<typename T>
T& QueueIterator<T>::operator*() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return current->data;
}

template<typename T>
const T& QueueIterator<T>::operator*() const {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return current->data;
}

template<typename T>
T* QueueIterator<T>::operator->() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return &(current->data);
}

template<typename T>
const T* QueueIterator<T>::operator->() const {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return &(current->data);
}

template<typename T>
QueueIterator<T>& QueueIterator<T>::operator++() {
    if (current != nullptr) {
        current = current->next;
    }
    return *this;
}

template<typename T>
QueueIterator<T> QueueIterator<T>::operator++(int) {
    QueueIterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bool QueueIterator<T>::operator==(const QueueIterator& other) const {
    return current == other.current;
}

template<typename T>
bool QueueIterator<T>::operator!=(const QueueIterator& other) const {
    return current != other.current;
}

template<typename T>
bool QueueIterator<T>::is_valid() const {
    return current != nullptr;
}

// Additional iterator functionality
template<typename T>
QueueIterator<T>& QueueIterator<T>::operator--() {
    // For singly linked structures, decrement is not efficient
    // This is a basic implementation that searches from beginning
    if (current == nullptr || container_begin == nullptr) {
        return *this;
    }
    
    if (current == container_begin) {
        // Already at beginning, can't go back further
        return *this;
    }
    
    QueueNode<T>* prev = nullptr;
    QueueNode<T>* temp = container_begin;
    while (temp != nullptr && temp != current) {
        prev = temp;
        temp = temp->next;
    }
    
    current = prev;
    return *this;
}

template<typename T>
QueueIterator<T> QueueIterator<T>::operator--(int) {
    QueueIterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
QueueIterator<T>& QueueIterator<T>::advance(int n) {
    if (n > 0) {
        for (int i = 0; i < n && current != nullptr; ++i) {
            current = current->next;
        }
    } else if (n < 0) {
        for (int i = 0; i > n && current != nullptr; --i) {
            --(*this);
        }
    }
    return *this;
}

template<typename T>
int QueueIterator<T>::distance(const QueueIterator& other) const {
    if (container_begin == nullptr) return -1;
    
    int dist = 0;
    QueueNode<T>* temp = current;
    
    // Count forward to other
    while (temp != nullptr && temp != other.current) {
        temp = temp->next;
        dist++;
    }
    
    if (temp == other.current) {
        return dist;
    }
    
    // Try counting backward (reset and count to current, then to other)
    temp = container_begin;
    int pos1 = 0, pos2 = 0;
    
    while (temp != nullptr) {
        if (temp == current) break;
        temp = temp->next;
        pos1++;
    }
    
    temp = container_begin;
    while (temp != nullptr) {
        if (temp == other.current) break;
        temp = temp->next;
        pos2++;
    }
    
    return pos2 - pos1;
}

template<typename T>
void QueueIterator<T>::reset_to_begin() {
    current = container_begin;
}

template<typename T>
bool QueueIterator<T>::before(const QueueIterator& other) const {
    if (container_begin == nullptr) return false;
    
    QueueNode<T>* temp = current;
    while (temp != nullptr) {
        if (temp == other.current) return true;
        temp = temp->next;
    }
    return false;
}

// Explicit template instantiations (add more as needed)
template class QueueIterator<int>;
template class QueueIterator<double>;
template class QueueIterator<char>;
template class QueueIterator<const char*>;