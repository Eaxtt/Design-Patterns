#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <iostream>

// ConcretePrototype and ConcreteProduct
class Textbox : public Shape {
private:
    string text;
    
public:
    // Default constructor
    Textbox();
    
    // Parameterized constructor
    Textbox(int l, int w, string c, int x, int y, string txt);
    
    // Copy constructor (needed for cloning)
    Textbox(const Textbox& other);
    
    // Prototype pattern: clone method
    Shape* clone() override;
    
    // Text specific methods
    void setText(const string& newText) { text = newText; }
    string getText() const { return text; }
    
    // Display method
    void display() const override;
    string getType() const override;
};

#endif