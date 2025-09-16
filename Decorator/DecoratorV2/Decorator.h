#ifndef DECORATOR_H
#define DECORATOR_H

#include "Component.h"

class Decorator : public Component {
protected:
    Component* component;
    
public:
    Decorator(Component* comp);
    virtual ~Decorator();
    
    void operation() override;
    double getCost() override;
    std::string getDescription() override;
    
    virtual void addedBehaviour() = 0;
};

#endif // DECORATOR_H