#include "ConcreteComponent.h"

void ConcreteComponent::operation() {
    std::cout << "Basic Black Coffee";
}

double ConcreteComponent::getCost() {
    return 2.50;
}

std::string ConcreteComponent::getDescription() {
    return "Basic Black Coffee";
}