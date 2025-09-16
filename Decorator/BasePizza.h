// BasePizza.h
#ifndef BASE_PIZZA_H
#define BASE_PIZZA_H

#include "Pizza.h"

// Concrete Component - the base pizza that can be decorated
class BasePizza : public Pizza {
private:
    std::string toppings;

public:
    BasePizza(const std::string& toppings);
    
    double getPrice() const override;
    std::string getName() const override;
    void printPizza() const override;
};

#endif