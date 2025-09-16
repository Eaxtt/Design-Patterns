// ExtraCheese.cpp
#include "ExtraCheese.h"

ExtraCheese::ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza) {}

double ExtraCheese::getPrice() const {
    return pizza->getPrice() + 1.50; // Add $1.50 for extra cheese
}

std::string ExtraCheese::getName() const {
    return pizza->getName() + " with Extra Cheese";
}