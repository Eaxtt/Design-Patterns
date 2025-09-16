#include <iostream>
#include "Context.h"
#include "ConcreteStrategies.h"

int main() {
    // Create context with initial strategy (new Add object)
    Context context(new Add());
    
    std::cout << "=== Strategy Pattern Demo ===\n\n";
    
    // Test with Add strategy
    std::cout << "Using Add strategy: ";
    std::cout << "5 + 3 = " << context.calculate(5, 3) << std::endl;
    
    // Change strategy to Multiply (new object)
    context.setStrategy(new Multiply());
    std::cout << "Using Multiply strategy: ";
    std::cout << "5 * 3 = " << context.calculate(5, 3) << std::endl;
    
    // Change strategy to Subtract (new object)
    context.setStrategy(new Subtract());
    std::cout << "Using Subtract strategy: ";
    std::cout << "5 - 3 = " << context.calculate(5, 3) << std::endl;
    
    // Demonstrate changing strategy again (new object)
    std::cout << "\nChanging back to Add strategy: ";
    context.setStrategy(new Add());
    std::cout << "10 + 7 = " << context.calculate(10, 7) << std::endl;
    
    std::cout << "\n=== Demo Complete ===\n";
    
    // Memory management is now handled automatically!
    // - When setStrategy() is called, it deletes the old strategy first
    // - When context goes out of scope, its destructor deletes the final strategy
    // - No memory leaks!
    
    return 0;
}