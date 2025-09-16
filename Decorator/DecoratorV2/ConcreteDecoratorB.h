#ifndef CONCRETEDECORATORB_H
#define CONCRETEDECORATORB_H

#include "Decorator.h"
#include <iostream>

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp);
    
    void operation() override;
    double getCost() override;
    std::string getDescription() override;
    void addedBehaviour() override;
};

#endif // CONCRETEDECORATORB_H