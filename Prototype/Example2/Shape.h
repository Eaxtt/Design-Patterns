#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

// Abstract Shape class - participates in both Factory Method (Product) and Prototype (Prototype)
class Shape {
protected:
    int length;
    int width;
    string colour;
    int positionX;
    int positionY;

public:
    // Default constructor
    Shape();
    
    // Parameterized constructor
    Shape(int l, int w, string c, int x, int y);
    
    // Virtual destructor
    virtual ~Shape() = default;
    
    // Pure virtual clone method for Prototype pattern
    virtual Shape* clone() = 0;
    
    // Getters
    int getLength() const { return length; }
    int getWidth() const { return width; }
    string getColour() const { return colour; }
    int getPositionX() const { return positionX; }
    int getPositionY() const { return positionY; }
    
    // Setters
    void setLength(int l) { length = l; }
    void setWidth(int w) { width = w; }
    void setColour(const string& c) { colour = c; }
    void setPosition(int x, int y) { positionX = x; positionY = y; }
    
    // Display method
    virtual void display() const = 0;
    virtual string getType() const = 0;
};

#endif