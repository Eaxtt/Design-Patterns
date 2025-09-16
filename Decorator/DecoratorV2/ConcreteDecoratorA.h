#ifndef CONCRETEDECORATORA_H
#define CONCRETEDECORATORA_H

#include "Decorator.h"
#include <iostream>

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp);
    
    void operation() override;
    double getCost() override;
    std::string getDescription() override;
    void addedBehaviour() override;
};

#endif // CONCRETEDECORATORA_H