#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calc;
    
    cout << "========================================\n";
    cout << "   SIMPLE CALCULATOR (Interpreter Pattern)\n";
    cout << "========================================\n\n";
    
    // Test 1: Simple addition
    cout << "Test 1: 3 + 5\n";
    cout << "Result: " << calc.evaluate("3 + 5") << "\n";
    cout << "Expected: 8\n\n";
    
    // Test 2: Subtraction
    cout << "Test 2: 10 - 4\n";
    cout << "Result: " << calc.evaluate("10 - 4") << "\n";
    cout << "Expected: 6\n\n";
    
    // Test 3: Multiplication
    cout << "Test 3: 4 * 5\n";
    cout << "Result: " << calc.evaluate("4 * 5") << "\n";
    cout << "Expected: 20\n\n";
    
    // Test 4: Division
    cout << "Test 4: 20 / 4\n";
    cout << "Result: " << calc.evaluate("20 / 4") << "\n";
    cout << "Expected: 5\n\n";
    
    // Test 5: Operator precedence (multiply before add)
    cout << "Test 5: 3 + 5 * 2\n";
    cout << "Result: " << calc.evaluate("3 + 5 * 2") << "\n";
    cout << "Expected: 13 (not 16!)\n\n";
    
    // Test 6: Complex expression
    cout << "Test 6: 10 + 20 * 3 - 5\n";
    cout << "Result: " << calc.evaluate("10 + 20 * 3 - 5") << "\n";
    cout << "Expected: 65\n\n";
    
    // Test 7: Multiple operations
    cout << "Test 7: 100 / 10 + 5 * 2\n";
    cout << "Result: " << calc.evaluate("100 / 10 + 5 * 2") << "\n";
    cout << "Expected: 20\n\n";
    
    // Test 8: Left to right evaluation with same precedence
    cout << "Test 8: 20 - 5 - 3\n";
    cout << "Result: " << calc.evaluate("20 - 5 - 3") << "\n";
    cout << "Expected: 12\n\n";
    
    cout << "========================================\n";
    
    return 0;
}