#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>

// ConcretePrototype and ConcreteProduct
class Square : public Shape {
public:
    // Default constructor
    Square();
    
    // Parameterized constructor (size applies to both length and width)
    Square(int size, string c, int x, int y);
    
    // Copy constructor (needed for cloning)
    Square(const Square& other);
    
    // Prototype pattern: clone method
    Shape* clone() override;
    
    // Override setters to maintain square property
    void setLength(int l) { length = l; width = l; }
    void setWidth(int w) { length = w; width = w; }
    void setSize(int size) { length = size; width = size; }
    
    // Display method
    void display() const override;
    string getType() const override;
};

#endif