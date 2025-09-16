#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

// ConcretePrototype and ConcreteProduct
class Rectangle : public Shape {
public:
    // Default constructor
    Rectangle();
    
    // Parameterized constructor
    Rectangle(int l, int w, string c, int x, int y);
    
    // Copy constructor (needed for cloning)
    Rectangle(const Rectangle& other);
    
    // Prototype pattern: clone method
    Shape* clone() override;
    
    // Display method
    void display() const override;
    string getType() const override;

};

#endif