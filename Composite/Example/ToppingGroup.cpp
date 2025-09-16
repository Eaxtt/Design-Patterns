// ToppingGroup.cpp
#include "ToppingGroup.h"
#include <iostream>

ToppingGroup::ToppingGroup(const std::string& name) 
    : PizzaComponent(name, 0.0) {}

ToppingGroup::~ToppingGroup() {
    for (auto* topping : toppings) {
        delete topping;
    }
}

void ToppingGroup::add(PizzaComponent* component) {
    toppings.push_back(component);
}

void ToppingGroup::remove(PizzaComponent* component) {
    for (auto it = toppings.begin(); it != toppings.end(); ++it) {
        if (*it == component) {
            delete *it;
            toppings.erase(it);
            break;
        }
    }
}

double ToppingGroup::getPrice() const {
    double totalPrice = 0.0;
    for (const auto* topping : toppings) {
        totalPrice += topping->getPrice();
    }
    return totalPrice;
}

void ToppingGroup::display() const {
    std::cout << name << " (Total: $" << getPrice() << ")" << std::endl;
    for (const auto* topping : toppings) {
        topping->display();
    }
}