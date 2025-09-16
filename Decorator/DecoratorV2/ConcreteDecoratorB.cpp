#include "ConcreteDecoratorB.h"

ConcreteDecoratorB::ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

void ConcreteDecoratorB::operation() {
    Decorator::operation();
    std::cout << " + Sugar";
    addedBehaviour();
}

double ConcreteDecoratorB::getCost() {
    return Decorator::getCost() + 0.25;
}

std::string ConcreteDecoratorB::getDescription() {
    return Decorator::getDescription() + " + Sugar";
}

void ConcreteDecoratorB::addedBehaviour() {
    std::cout << " (Extra sweetness added)";
}