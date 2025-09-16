// StuffedCrust.cpp
#include "StuffedCrust.h"

StuffedCrust::StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza) {}

double StuffedCrust::getPrice() const {
    return pizza->getPrice() + 2.25; // Add $2.25 for stuffed crust
}

std::string StuffedCrust::getName() const {
    return pizza->getName() + " with Stuffed Crust";
}