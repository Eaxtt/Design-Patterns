// Topping.h
#ifndef TOPPING_H
#define TOPPING_H

#include "PizzaComponent.h"

// Leaf class - Individual toppings
class Topping : public PizzaComponent {
public:
    Topping(const std::string& name, double price);
    
    double getPrice() const override;
    void display() const override;
};

#endif