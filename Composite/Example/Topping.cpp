// Topping.cpp
#include "Topping.h"
#include <iostream>

Topping::Topping(const std::string& name, double price) 
    : PizzaComponent(name, price) {}

double Topping::getPrice() const {
    return price;
}

void Topping::display() const {
    std::cout << "  " << name << ": $" << price << std::endl;
}