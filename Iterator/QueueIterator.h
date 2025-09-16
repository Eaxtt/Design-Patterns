#ifndef QUEUE_ITERATOR_H
#define QUEUE_ITERATOR_H

template<typename T>
struct QueueNode {
    T data;
    QueueNode* next;
    
    QueueNode(const T& value) : data(value), next(nullptr) {}
};

template<typename T> class Queue;
template<typename T> class CircularList;

template<typename T>
class QueueIterator {
    friend class Queue<T>;
    friend class CircularList<T>;
    
private:
    QueueNode<T>* current;
    QueueNode<T>* container_begin;
    
    QueueIterator(QueueNode<T>* node, QueueNode<T>* begin_node = nullptr);
    
public:
    QueueIterator();
    QueueIterator(const QueueIterator& other);
    QueueIterator& operator=(const QueueIterator& other);
    ~QueueIterator();
    
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    
    QueueIterator& operator++();
    QueueIterator operator++(int);
    
    bool operator==(const QueueIterator& other) const;
    bool operator!=(const QueueIterator& other) const;
    
    bool is_valid() const;
    
    QueueIterator& operator--();
    QueueIterator operator--(int);
    
    QueueIterator& advance(int n);
    int distance(const QueueIterator& other) const;
    void reset_to_begin();
    bool before(const QueueIterator& other) const;
};

#endif