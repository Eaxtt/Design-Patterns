// PizzaDecorator.h
#ifndef PIZZA_DECORATOR_H
#define PIZZA_DECORATOR_H

#include "Pizza.h"

// Abstract Decorator - base class for all decorators
class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;

public:
    PizzaDecorator(Pizza* pizza);
    virtual ~PizzaDecorator();
    
    double getPrice() const override;
    std::string getName() const override;
    void printPizza() const override;
};

#endif