#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include <vector>
#include <iostream>

class Canvas {
private:
    vector<Shape*> shapes;

public:
    // Constructor
    Canvas();
    
    // Destructor
    ~Canvas();
    
    // Add shape created by factory
    void addShape(Shape* shape);
    
    // Clone an existing shape and add it (Prototype pattern usage)
    void duplicateShape(int index);
    
    // Display all shapes
    void displayAll() const;
    
    // Get shape count
    int getShapeCount() const;
    
    // Get shape at index
    Shape* getShape(int index) const;
    
    // Remove shape at index
    void removeShape(int index);
    
    // Clear all shapes
    void clear();

    std::string toString();
};

#endif