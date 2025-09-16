// ToppingGroup.h
#ifndef TOPPING_GROUP_H
#define TOPPING_GROUP_H

#include "PizzaComponent.h"
#include <vector>

// Composite class - Groups of toppings
class ToppingGroup : public PizzaComponent {
private:
    std::vector<PizzaComponent*> toppings;

public:
    ToppingGroup(const std::string& name);
    ~ToppingGroup();
    
    void add(PizzaComponent* component) override;
    void remove(PizzaComponent* component) override;
    double getPrice() const override;
    void display() const override;
};

#endif