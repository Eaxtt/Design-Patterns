#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>
#include <iostream>

// Abstract Prototype class
class Prototype {
public:
    virtual ~Prototype() = default;
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
    virtual std::string getType() const = 0;
};

#endif // PROTOTYPE_H