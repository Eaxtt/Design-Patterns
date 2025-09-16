#include "Square.h"

Square::Square() : Shape(8, 8, "red", 0, 0) {}

Square::Square(int size, string c, int x, int y) : Shape(size, size, c, x, y) {}

Square::Square(const Square& other) : Shape(other.length, other.width, other.colour, other.positionX, other.positionY) {}

Shape* Square::clone() {
    return new Square(*this);
}

void Square::display() const {
    cout << "Square: " << length << "x" << width 
         << ", Color: " << colour 
         << ", Position: (" << positionX << "," << positionY << ")" << endl;
}

string Square::getType() const {
    return "Square";
}