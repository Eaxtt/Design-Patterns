#include <iostream>
#include "LIFO_Stack.h"
#include "HanoiStack.h"
#include "ArrayImplementor.h"
#include "ListImplementor.h"

using namespace std;

void testLIFOWithArray() {
    cout << "\n=== Testing LIFO Stack with Array Implementation ===" << endl;
    LIFO_Stack stack(new ArrayImplementor(5));
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Pushed: 10, 20, 30" << endl;
    cout << "Pop: " << stack.pop() << endl;  // 30
    cout << "Pop: " << stack.pop() << endl;  // 20
    
    stack.push(40);
    cout << "Pushed: 40" << endl;
    cout << "Pop: " << stack.pop() << endl;  // 40
    cout << "Pop: " << stack.pop() << endl;  // 10
}

void testLIFOWithList() {
    cout << "\n=== Testing LIFO Stack with List Implementation ===" << endl;
    LIFO_Stack stack(new ListImplementor());
    
    stack.push(100);
    stack.push(200);
    stack.push(300);
    
    cout << "Pushed: 100, 200, 300" << endl;
    cout << "Pop: " << stack.pop() << endl;  // 300
    cout << "Pop: " << stack.pop() << endl;  // 200
    cout << "Pop: " << stack.pop() << endl;  // 100
}

void testHanoiWithArray() {
    cout << "\n=== Testing Hanoi Stack with Array Implementation ===" << endl;
    HanoiStack stack(new ArrayImplementor(5));
    
    try {
        stack.push(3);
        stack.push(2);
        stack.push(1);
        cout << "Pushed: 3, 2, 1 (valid Hanoi sequence)" << endl;
        
        cout << "Pop: " << stack.pop() << endl;  // 1
        
        stack.push(4);  // This should fail - trying to put 4 on top of 2
        cout << "This line should not be reached!" << endl;
    } catch (const exception& e) {
        cout << "Caught expected error: " << e.what() << endl;
    }
}

void testHanoiWithList() {
    cout << "\n=== Testing Hanoi Stack with List Implementation ===" << endl;
    HanoiStack stack(new ListImplementor());
    
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    
    cout << "Pushed: 5, 4, 3, 2, 1 (valid Tower of Hanoi)" << endl;
    cout << "Pop: " << stack.pop() << endl;  // 1
    cout << "Pop: " << stack.pop() << endl;  // 2
    cout << "Pop: " << stack.pop() << endl;  // 3
}

void demonstrateBridgePattern() {
    cout << "\n=== Demonstrating Bridge Pattern Flexibility ===" << endl;
    cout << "You can combine any Stack type with any Implementation:" << endl;
    
    Stack* stacks[] = {
        new LIFO_Stack(new ArrayImplementor(5)),
        new LIFO_Stack(new ListImplementor()),
        new HanoiStack(new ArrayImplementor(5)),
        new HanoiStack(new ListImplementor())
    };
    
    cout << "\nCreated 4 different stack combinations:" << endl;
    cout << "1. LIFO + Array" << endl;
    cout << "2. LIFO + List" << endl;
    cout << "3. Hanoi + Array" << endl;
    cout << "4. Hanoi + List" << endl;
    
    for (int i = 0; i < 4; i++) {
        delete stacks[i];
    }
}

int main() {
    cout << "Bridge Design Pattern - Stack Implementation Example" << endl;
    cout << "=====================================================" << endl;
    
    testLIFOWithArray();
    testLIFOWithList();
    testHanoiWithArray();
    testHanoiWithList();
    demonstrateBridgePattern();
    
    cout << "\n=== All tests completed! ===" << endl;
    
    return 0;
}