#include "ShapeFactory.h"

// RectangleFactory implementation
Shape* RectangleFactory::createShape() {
    return new Rectangle();
}

string RectangleFactory::toString() {
    return "Rectangle Factory";
}

// SquareFactory implementation
Shape* SquareFactory::createShape() {
    return new Square();
}

string SquareFactory::toString() {
    return "Square Factory";
}

// TextboxFactory implementation
Shape* TextboxFactory::createShape() {
    return new Textbox();
}

string TextboxFactory::toString() {
    return "Textbox Factory";
}