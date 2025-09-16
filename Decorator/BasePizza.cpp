// BasePizza.cpp
#include "BasePizza.h"
#include <iostream>

BasePizza::BasePizza(const std::string& toppings) : toppings(toppings) {}

double BasePizza::getPrice() const {
    return 8.99; // Base price for any pizza
}

std::string BasePizza::getName() const {
    return toppings + " Pizza";
}

void BasePizza::printPizza() const {
    std::cout << getName() << " - $" << getPrice() << std::endl;
}