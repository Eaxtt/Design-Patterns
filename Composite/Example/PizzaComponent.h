// PizzaComponent.h
#ifndef PIZZA_COMPONENT_H
#define PIZZA_COMPONENT_H

#include <string>

// Abstract base class - Component
class PizzaComponent {
protected:
    std::string name;
    double price;

public:
    PizzaComponent(const std::string& name, double price);
    virtual ~PizzaComponent() = default;
    
    virtual std::string getName() const;
    virtual double getPrice() const = 0;
    virtual void display() const = 0;
    
    // Default implementations for composite operations
    virtual void add(PizzaComponent* component);
    virtual void remove(PizzaComponent* component);
};

#endif