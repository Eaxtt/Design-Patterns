#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "=== Coffee Shop Decorator Pattern Demo ===\n\n";
    
    // Basic coffee
    Component* coffee1 = new ConcreteComponent();
    std::cout << "Order 1: ";
    coffee1->operation();
    std::cout << "\nCost: $" << std::fixed << std::setprecision(2) << coffee1->getCost() << "\n\n";
    
    // Coffee with milk
    Component* coffee2 = new ConcreteDecoratorA(new ConcreteComponent());
    std::cout << "Order 2: ";
    coffee2->operation();
    std::cout << "\nCost: $" << std::fixed << std::setprecision(2) << coffee2->getCost() << "\n\n";
    
    // Coffee with sugar
    Component* coffee3 = new ConcreteDecoratorB(new ConcreteComponent());
    std::cout << "Order 3: ";
    coffee3->operation();
    std::cout << "\nCost: $" << std::fixed << std::setprecision(2) << coffee3->getCost() << "\n\n";
    
    // Coffee with both milk and sugar
    Component* coffee4 = new ConcreteDecoratorB(
        new ConcreteDecoratorA(new ConcreteComponent())
    );
    std::cout << "Order 4: ";
    coffee4->operation();
    std::cout << "\nCost: $" << std::fixed << std::setprecision(2) << coffee4->getCost() << "\n\n";
    
    // Multiple decorations - fancy coffee
    Component* coffee5 = new ConcreteDecoratorA(
        new ConcreteDecoratorB(
            new ConcreteDecoratorA(new ConcreteComponent())
        )
    );
    std::cout << "Order 5 (Fancy): ";
    coffee5->operation();
    std::cout << "\nCost: $" << std::fixed << std::setprecision(2) << coffee5->getCost() << "\n\n";
    
    // Clean up
    delete coffee1;
    delete coffee2;
    delete coffee3;
    delete coffee4;
    delete coffee5;
    
    return 0;
}