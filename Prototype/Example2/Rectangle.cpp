#include "Rectangle.h"

Rectangle::Rectangle() : Shape(10, 5, "blue", 0, 0) {}

Rectangle::Rectangle(int l, int w, string c, int x, int y) : Shape(l, w, c, x, y) {}

Rectangle::Rectangle(const Rectangle& other) : Shape(other.length, other.width, other.colour, other.positionX, other.positionY) {}

Shape* Rectangle::clone() {
    return new Rectangle(*this);
}

void Rectangle::display() const {
    cout << "Rectangle: " << length << "x" << width 
         << ", Color: " << colour 
         << ", Position: (" << positionX << "," << positionY << ")" << endl;
}

string Rectangle::getType() const {
    return "Rectangle";
}
