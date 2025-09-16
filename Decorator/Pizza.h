// Pizza.h
#ifndef PIZZA_H
#define PIZZA_H

#include <string>

// Abstract Component - defines interface for objects that can be decorated
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual void printPizza() const = 0;
};

#endif