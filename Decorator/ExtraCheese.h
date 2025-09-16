// ExtraCheese.h
#ifndef EXTRA_CHEESE_H
#define EXTRA_CHEESE_H

#include "PizzaDecorator.h"

// Concrete Decorator - adds extra cheese functionality
class ExtraCheese : public PizzaDecorator {
public:
    ExtraCheese(Pizza* pizza);
    
    double getPrice() const override;
    std::string getName() const override;
};

#endif