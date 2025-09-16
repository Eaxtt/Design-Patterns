#ifndef CONCRETECOMPONENT_H
#define CONCRETECOMPONENT_H

#include "Component.h"
#include <iostream>

class ConcreteComponent : public Component {
public:
    void operation() override;
    double getCost() override;
    std::string getDescription() override;
};

#endif // CONCRETECOMPONENT_H