// PizzaComponent.cpp
#include "PizzaComponent.h"
#include <iostream>

PizzaComponent::PizzaComponent(const std::string& name, double price) 
    : name(name), price(price) {}

std::string PizzaComponent::getName() const {
    return name;
}

void PizzaComponent::add(PizzaComponent* /* component */) {
    std::cout << "Cannot add to individual topping\n";
}

void PizzaComponent::remove(PizzaComponent* /* component */) {
    std::cout << "Cannot remove from individual topping\n";
}