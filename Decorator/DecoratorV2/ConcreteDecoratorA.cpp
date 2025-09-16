#include "ConcreteDecoratorA.h"

ConcreteDecoratorA::ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

void ConcreteDecoratorA::operation() {
    Decorator::operation();
    std::cout << " + Milk";
    addedBehaviour();
}

double ConcreteDecoratorA::getCost() {
    return Decorator::getCost() + 0.60;
}

std::string ConcreteDecoratorA::getDescription() {
    return Decorator::getDescription() + " + Milk";
}

void ConcreteDecoratorA::addedBehaviour() {
    std::cout << " (Steamed to perfection)";
}