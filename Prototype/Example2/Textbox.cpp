#include "Textbox.h"

Textbox::Textbox() : Shape(15, 3, "yellow", 0, 0), text("Default Text") {}

Textbox::Textbox(int l, int w, string c, int x, int y, string txt) 
    : Shape(l, w, c, x, y), text(txt) {}

Textbox::Textbox(const Textbox& other) 
    : Shape(other.length, other.width, other.colour, other.positionX, other.positionY), text(other.text) {}

Shape* Textbox::clone() {
    return new Textbox(*this);
}

void Textbox::display() const {
    cout << "Textbox: " << length << "x" << width 
         << ", Color: " << colour 
         << ", Position: (" << positionX << "," << positionY << ")"
         << ", Text: \"" << text << "\"" << endl;
}

string Textbox::getType() const {
    return "Textbox";
}