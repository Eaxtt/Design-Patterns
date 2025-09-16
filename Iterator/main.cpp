#include <iostream>
#include "Queue.h"
#include "CircularList.h"
#include "QueueIterator.h"

void test_queue_functionality() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTING QUEUE FUNCTIONALITY" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    Queue<int> queue;
    
    // Test basic queue operations
    std::cout << "\n1. Basic Queue Operations:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        queue.enqueue(i * 10);
        std::cout << "Enqueued: " << i * 10 << std::endl;
    }
    
    std::cout << "\nQueue size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;
    
    // Test enhanced iterator functionality
    std::cout << "\n2. Enhanced Iterator Features:" << std::endl;
    
    QueueIterator<int> it1 = queue.begin();
    QueueIterator<int> it2 = queue.begin();
    it2.advance(2);  // Move to position 2
    
    std::cout << "Iterator 1 points to: " << *it1 << std::endl;
    std::cout << "Iterator 2 points to: " << *it2 << std::endl;
    std::cout << "Distance from it1 to it2: " << it1.distance(it2) << std::endl;
    std::cout << "Iterator 1 before Iterator 2: " << (it1.before(it2) ? "Yes" : "No") << std::endl;
    
    // Test iterator advancement
    std::cout << "\n3. Iterator Advancement:" << std::endl;
    QueueIterator<int> adv_it = queue.begin();
    std::cout << "Original position: " << *adv_it << std::endl;
    adv_it.advance(3);
    std::cout << "After advancing 3 positions: " << *adv_it << std::endl;
    
    // Test backward iteration (inefficient for singly-linked, but demonstrates functionality)
    std::cout << "\n4. Backward Iteration (Note: Inefficient for Queue):" << std::endl;
    QueueIterator<int> back_it = queue.begin();
    back_it.advance(2);
    std::cout << "Starting at position: " << *back_it << std::endl;
    --back_it;
    std::cout << "After one step back: " << *back_it << std::endl;
    
    // Demonstrate FIFO nature
    std::cout << "\n5. FIFO Demonstration:" << std::endl;
    std::cout << "Dequeuing in FIFO order: ";
    while (!queue.empty()) {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl;
}

void test_circular_list_functionality() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTING CIRCULAR LIST FUNCTIONALITY" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    CircularList<int> clist;
    
    // Test basic circular list operations
    std::cout << "\n1. Basic Circular List Operations:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        clist.insert_back(i * 10);
        std::cout << "Inserted at back: " << i * 10 << std::endl;
    }
    
    std::cout << "\nList size: " << clist.size() << std::endl;
    std::cout << "Front element: " << clist.front() << std::endl;
    std::cout << "Back element: " << clist.back() << std::endl;
    
    // Demonstrate circular nature
    std::cout << "\n2. Circular Nature Demonstration:" << std::endl;
    std::cout << "Normal display: ";
    clist.display();
    std::cout << std::endl;
    
    std::cout << "Circular display (2 rotations): ";
    clist.display_circular(2);
    std::cout << std::endl;
    
    // Test insertions at different positions
    std::cout << "\n3. Insertion at Different Positions:" << std::endl;
    clist.insert_front(5);
    std::cout << "After inserting 5 at front: ";
    clist.display();
    std::cout << std::endl;
    
    clist.insert_at(3, 25);
    std::cout << "After inserting 25 at index 3: ";
    clist.display();
    std::cout << std::endl;
    
    // Test rotations
    std::cout << "\n4. Rotation Operations:" << std::endl;
    std::cout << "Before rotation: ";
    clist.display();
    std::cout << std::endl;
    
    clist.rotate_left(2);
    std::cout << "After rotating left 2 positions: ";
    clist.display();
    std::cout << std::endl;
    
    clist.rotate_right(1);
    std::cout << "After rotating right 1 position: ";
    clist.display();
    std::cout << std::endl;
    
    // Test search and removal
    std::cout << "\n5. Search and Removal:" << std::endl;
    std::cout << "Looking for value 30: " << (clist.contains(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Index of value 25: " << clist.find_index(25) << std::endl;
    
    clist.remove_value(25);
    std::cout << "After removing value 25: ";
    clist.display();
    std::cout << std::endl;
    
    // Test reversal
    std::cout << "\n6. List Reversal:" << std::endl;
    std::cout << "Before reversal: ";
    clist.display();
    std::cout << std::endl;
    
    clist.reverse();
    std::cout << "After reversal: ";
    clist.display();
    std::cout << std::endl;
}

void test_iterator_comparison() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "COMPARING ITERATORS: QUEUE vs CIRCULAR LIST" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    Queue<int> queue;
    CircularList<int> clist;
    
    // Populate both containers with same data
    for (int i = 1; i <= 4; i++) {
        queue.enqueue(i * 5);
        clist.insert_back(i * 5);
    }
    
    std::cout << "\n1. Same Iterator Class, Different Containers:" << std::endl;
    std::cout << "Queue iteration: ";
    for (QueueIterator<int> it = queue.begin(); it != queue.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Circular List iteration: ";
    for (QueueIterator<int> it = clist.begin(); it != clist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n2. Iterator Behavior Differences:" << std::endl;
    
    // Queue iterator behavior
    QueueIterator<int> q_it = queue.begin();
    q_it.advance(2);
    std::cout << "Queue iterator advanced 2 positions: " << *q_it << std::endl;
    
    // Circular list iterator behavior
    QueueIterator<int> c_it = clist.begin();
    c_it.advance(2);
    std::cout << "Circular list iterator advanced 2 positions: " << *c_it << std::endl;
    
    // Test advancing beyond end
    std::cout << "\n3. Advancing Beyond Container End:" << std::endl;
    QueueIterator<int> q_end = queue.begin();
    q_end.advance(10);  // Beyond queue size
    std::cout << "Queue iterator advanced beyond end - valid: " << (q_end.is_valid() ? "Yes" : "No") << std::endl;
    
    QueueIterator<int> c_end = clist.begin();
    c_end.advance(10);  // Beyond list size - should wrap around in circular
    std::cout << "Circular list iterator advanced 10 positions: ";
    if (c_end.is_valid()) {
        std::cout << *c_end << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }
}

void test_advanced_iterator_features() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTING ADVANCED ITERATOR FEATURES" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    CircularList<char> char_list;
    
    // Add some characters
    char_list.insert_back('A');
    char_list.insert_back('B');
    char_list.insert_back('C');
    char_list.insert_back('D');
    char_list.insert_back('E');
    
    std::cout << "\n1. Character Circular List:" << std::endl;
    std::cout << "List contents: ";
    char_list.display();
    std::cout << std::endl;
    
    // Test iterator distance calculation
    std::cout << "\n2. Iterator Distance Calculations:" << std::endl;
    QueueIterator<char> it1 = char_list.begin();
    QueueIterator<char> it2 = char_list.begin();
    it2.advance(3);
    
    std::cout << "Iterator 1 at: " << *it1 << std::endl;
    std::cout << "Iterator 2 at: " << *it2 << std::endl;
    std::cout << "Distance from it1 to it2: " << it1.distance(it2) << std::endl;
    
    // Test iterator reset
    std::cout << "\n3. Iterator Reset Functionality:" << std::endl;
    QueueIterator<char> reset_it = char_list.begin();
    reset_it.advance(3);
    std::cout << "Iterator before reset: " << *reset_it << std::endl;
    reset_it.reset_to_begin();
    std::cout << "Iterator after reset: " << *reset_it << std::endl;
    
    // Test range-based for loop
    std::cout << "\n4. Range-based For Loop:" << std::endl;
    std::cout << "Using range-based for: ";
    for (const auto& ch : char_list) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

void test_special_circular_iterator() {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "TESTING SPECIAL CIRCULAR ITERATOR" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    CircularList<int> small_list;
    small_list.insert_back(1);
    small_list.insert_back(2);
    small_list.insert_back(3);
    
    std::cout << "\n1. Small Circular List:" << std::endl;
    std::cout << "List contents: ";
    small_list.display();
    std::cout << std::endl;
    
    std::cout << "\n2. Infinite-like Iteration (showing circular nature):" << std::endl;
    std::cout << "Showing 2 complete rotations: ";
    
    // Manual iteration to show circular behavior
    QueueIterator<int> circular_it = small_list.begin();
    int max_elements = small_list.size() * 2; // Two complete rotations
    
    for (int i = 0; i < max_elements; ++i) {
        if (circular_it == small_list.end()) {
            circular_it = small_list.begin(); // Restart from beginning
        }
        std::cout << *circular_it << " ";
        ++circular_it;
    }
    std::cout << std::endl;
}

void demonstrate_iterator_pattern_benefits() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "DEMONSTRATING ITERATOR PATTERN BENEFITS" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    std::cout << "\n1. UNIFORM INTERFACE:" << std::endl;
    std::cout << "   - Same iterator class works with Queue and CircularList" << std::endl;
    std::cout << "   - Client code doesn't need to know container internals" << std::endl;
    std::cout << "   - Easy to switch between container types" << std::endl;
    
    std::cout << "\n2. ENCAPSULATION:" << std::endl;
    std::cout << "   - Internal structure (nodes, pointers) hidden from client" << std::endl;
    std::cout << "   - Only iterator methods exposed for traversal" << std::endl;
    std::cout << "   - Container can change implementation without affecting client" << std::endl;
    
    std::cout << "\n3. FLEXIBILITY:" << std::endl;
    std::cout << "   - Multiple iterators can traverse same container" << std::endl;
    std::cout << "   - Forward and backward iteration supported" << std::endl;
    std::cout << "   - Range-based for loops work automatically" << std::endl;
    
    std::cout << "\n4. EXTENSIBILITY:" << std::endl;
    std::cout << "   - Easy to add new iterator types (like CircularIterator)" << std::endl;
    std::cout << "   - Additional functionality (distance, reset, advance)" << std::endl;
    std::cout << "   - Container-specific optimizations possible" << std::endl;
}

int main() {
    std::cout << std::string(70, '*') << std::endl;
    std::cout << "ITERATOR DESIGN PATTERN COMPREHENSIVE DEMONSTRATION" << std::endl;
    std::cout << std::string(70, '*') << std::endl;
    
    try {
        // Test individual components
        test_queue_functionality();
        test_circular_list_functionality();
        test_iterator_comparison();
        test_advanced_iterator_features();
        test_special_circular_iterator();
        
        // Demonstrate pattern benefits
        demonstrate_iterator_pattern_benefits();
        
        std::cout << "\n" << std::string(70, '*') << std::endl;
        std::cout << "DEMONSTRATION COMPLETED SUCCESSFULLY!" << std::endl;
        std::cout << std::string(70, '*') << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "\nError during demonstration: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}