// StuffedCrust.h
#ifndef STUFFED_CRUST_H
#define STUFFED_CRUST_H

#include "PizzaDecorator.h"

// Concrete Decorator - adds stuffed crust functionality
class StuffedCrust : public PizzaDecorator {
public:
    StuffedCrust(Pizza* pizza);
    
    double getPrice() const override;
    std::string getName() const override;
};

#endif