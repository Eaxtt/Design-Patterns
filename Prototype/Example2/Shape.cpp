#include "Shape.h"

Shape::Shape() : length(0), width(0), colour("white"), positionX(0), positionY(0) {}

Shape::Shape(int l, int w, string c, int x, int y) 
    : length(l), width(w), colour(c), positionX(x), positionY(y) {}