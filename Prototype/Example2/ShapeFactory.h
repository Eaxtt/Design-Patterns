#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"

// Abstract Factory
class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    virtual Shape* createShape() = 0;
    virtual string toString() = 0;
};

// Concrete Factories
class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() override;
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() override;
};

class TextboxFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() override;
};

#endif