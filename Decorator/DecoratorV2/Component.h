#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
public:
    virtual ~Component() = default;
    virtual void operation() = 0;
    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;
};

#endif // COMPONENT_H