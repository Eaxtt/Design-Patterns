#include "CircularList.h"
#include <stdexcept>
#include <iostream>

// CircularList implementation
template<typename T>
CircularList<T>::CircularList() : head(nullptr), size_count(0) {
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
}

template<typename T>
CircularList<T>::CircularList(const CircularList& other) : head(nullptr), size_count(0) {
    copy_from(other);
}

template<typename T>
CircularList<T>& CircularList<T>::operator=(const CircularList& other) {
    if (this != &other) {
        clear();
        copy_from(other);
    }
    return *this;
}

template<typename T>
void CircularList<T>::insert_front(const T& item) {
    Node* new_node = new Node(item);
    
    if (empty()) {
        head = new_node;
        new_node->next = new_node;  // Points to itself
    } else {
        Node* tail = get_tail();
        new_node->next = head;
        tail->next = new_node;
        head = new_node;
    }
    size_count++;
}

template<typename T>
void CircularList<T>::insert_back(const T& item) {
    if (empty()) {
        insert_front(item);
        return;
    }
    
    Node* new_node = new Node(item);
    Node* tail = get_tail();
    
    new_node->next = head;
    tail->next = new_node;
    size_count++;
}

template<typename T>
void CircularList<T>::insert_at(int index, const T& item) {
    if (index < 0 || index > size_count) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        insert_front(item);
        return;
    }
    
    if (index == size_count) {
        insert_back(item);
        return;
    }
    
    Node* new_node = new Node(item);
    Node* prev = get_node_at(index - 1);
    
    new_node->next = prev->next;
    prev->next = new_node;
    size_count++;
}

template<typename T>
bool CircularList<T>::remove_front() {
    if (empty()) return false;
    
    if (size_count == 1) {
        delete head;
        head = nullptr;
    } else {
        Node* tail = get_tail();
        Node* old_head = head;
        head = head->next;
        tail->next = head;
        delete old_head;
    }
    size_count--;
    return true;
}

template<typename T>
bool CircularList<T>::remove_back() {
    if (empty()) return false;
    
    if (size_count == 1) {
        return remove_front();
    }
    
    Node* prev = get_node_at(size_count - 2);
    Node* tail = prev->next;
    
    prev->next = head;
    delete tail;
    size_count--;
    return true;
}

template<typename T>
bool CircularList<T>::remove_at(int index) {
    if (index < 0 || index >= size_count) return false;
    
    if (index == 0) return remove_front();
    
    Node* prev = get_node_at(index - 1);
    Node* to_remove = prev->next;
    
    prev->next = to_remove->next;
    delete to_remove;
    size_count--;
    return true;
}

template<typename T>
bool CircularList<T>::remove_value(const T& value) {
    int index = find_index(value);
    return index >= 0 ? remove_at(index) : false;
}

template<typename T>
T& CircularList<T>::front() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
const T& CircularList<T>::front() const {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
T& CircularList<T>::back() {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return get_tail()->data;
}

template<typename T>
const T& CircularList<T>::back() const {
    if (empty()) {
        throw std::runtime_error("List is empty");
    }
    return get_tail()->data;
}

template<typename T>
T& CircularList<T>::at(int index) {
    if (index < 0 || index >= size_count) {
        throw std::out_of_range("Index out of range");
    }
    return get_node_at(index)->data;
}

template<typename T>
const T& CircularList<T>::at(int index) const {
    if (index < 0 || index >= size_count) {
        throw std::out_of_range("Index out of range");
    }
    return get_node_at(index)->data;
}

template<typename T>
bool CircularList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
int CircularList<T>::size() const {
    return size_count;
}

template<typename T>
bool CircularList<T>::contains(const T& value) const {
    return find_index(value) >= 0;
}

template<typename T>
int CircularList<T>::find_index(const T& value) const {
    if (empty()) return -1;
    
    Node* current = head;
    for (int i = 0; i < size_count; ++i) {
        if (current->data == value) return i;
        current = current->next;
    }
    return -1;
}

template<typename T>
typename CircularList<T>::Iterator CircularList<T>::begin() {
    return Iterator(head, head);
}

template<typename T>
typename CircularList<T>::Iterator CircularList<T>::end() {
    if (empty()) return Iterator(nullptr, nullptr);
    
    // For circular list, end is when we've completed one full cycle
    // We'll create a special end iterator
    Node* tail = get_tail();
    return Iterator(tail->next, head);  // Points to head again, marking end of cycle
}

template<typename T>
typename CircularList<T>::Iterator CircularList<T>::circular_begin() {
    return Iterator(head, head);
}

template<typename T>
void CircularList<T>::reverse() {
    if (size_count <= 1) return;
    
    Node* current = head;
    Node* prev = get_tail();
    Node* next = nullptr;
    
    for (int i = 0; i < size_count; ++i) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

template<typename T>
void CircularList<T>::rotate_left(int positions) {
    if (empty() || positions <= 0) return;
    
    positions = positions % size_count;
    for (int i = 0; i < positions; ++i) {
        head = head->next;
    }
}

template<typename T>
void CircularList<T>::rotate_right(int positions) {
    if (empty() || positions <= 0) return;
    
    positions = positions % size_count;
    rotate_left(size_count - positions);
}

template<typename T>
void CircularList<T>::clear() {
    if (empty()) return;
    
    Node* current = head;
    for (int i = 0; i < size_count; ++i) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    size_count = 0;
}

template<typename T>
void CircularList<T>::display() const {
    if (empty()) {
        std::cout << "Empty circular list";
        return;
    }
    
    Node* current = head;
    for (int i = 0; i < size_count; ++i) {
        std::cout << current->data;
        if (i < size_count - 1) std::cout << " -> ";
        current = current->next;
    }
    std::cout << " -> (back to " << head->data << ")";
}

template<typename T>
void CircularList<T>::display_circular(int rotations) const {
    if (empty()) {
        std::cout << "Empty circular list";
        return;
    }
    
    Node* current = head;
    int total_elements = size_count * rotations;
    
    for (int i = 0; i < total_elements; ++i) {
        std::cout << current->data;
        if (i < total_elements - 1) std::cout << " -> ";
        current = current->next;
    }
}

template<typename T>
void CircularList<T>::copy_from(const CircularList& other) {
    if (other.empty()) return;
    
    Node* other_current = other.head;
    for (int i = 0; i < other.size_count; ++i) {
        insert_back(other_current->data);
        other_current = other_current->next;
    }
}

template<typename T>
typename CircularList<T>::Node* CircularList<T>::get_node_at(int index) const {
    if (index < 0 || index >= size_count || empty()) {
        return nullptr;
    }
    
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

template<typename T>
typename CircularList<T>::Node* CircularList<T>::get_tail() const {
    if (empty()) return nullptr;
    return get_node_at(size_count - 1);
}

// CircularIterator implementation
template<typename T>
CircularIterator<T>::CircularIterator(QueueNode<T>* node, int max_loop) 
    : current(node), start(node), loop_count(0), max_loops(max_loop) {
}

template<typename T>
T& CircularIterator<T>::operator*() {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return current->data;
}

template<typename T>
const T& CircularIterator<T>::operator*() const {
    if (current == nullptr) {
        throw std::runtime_error("Iterator dereferencing null pointer");
    }
    return current->data;
}

template<typename T>
CircularIterator<T>& CircularIterator<T>::operator++() {
    if (current != nullptr) {
        current = current->next;
        if (current == start) {
            loop_count++;
        }
    }
    return *this;
}

template<typename T>
CircularIterator<T> CircularIterator<T>::operator++(int) {
    CircularIterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
bool CircularIterator<T>::operator!=(const CircularIterator& other) const {
    return current != other.current || loop_count < max_loops;
}

template<typename T>
bool CircularIterator<T>::has_more_loops() const {
    return loop_count < max_loops;
}

template<typename T>
int CircularIterator<T>::current_loop() const {
    return loop_count;
}

// Explicit template instantiations
template class CircularList<int>;
template class CircularList<double>;
template class CircularList<char>;
template class CircularList<const char*>;
template class CircularIterator<int>;
template class CircularIterator<double>;
template class CircularIterator<char>;
template class CircularIterator<const char*>;