#include "Canvas.h"
#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Square.h"
#include "Textbox.h"
#include <iostream>

using namespace std;

void demonstrateFactoryMethod(Canvas& canvas) {
    cout << "\n=== FACTORY METHOD PATTERN DEMO ===" << endl;
    
    // Create shapes using Factory Method pattern
    RectangleFactory rectFactory;
    SquareFactory squareFactory;
    TextboxFactory textFactory;
    
    cout << "\nCreating shapes using Factory Method:" << endl;
    
    // Create rectangle using factory
    Shape* rect1 = rectFactory.createShape();
    canvas.addShape(rect1);
    
    // Create square using factory
    Shape* square1 = squareFactory.createShape();
    canvas.addShape(square1);
    
    // Create textbox using factory
    Shape* textbox1 = textFactory.createShape();
    canvas.addShape(textbox1);
    
    canvas.displayAll();
}

void demonstratePrototypePattern(Canvas& canvas) {
    cout << "\n=== PROTOTYPE PATTERN DEMO ===" << endl;
    
    // Modify some properties of existing shapes
    cout << "\nModifying properties of existing shapes:" << endl;
    
    if (canvas.getShapeCount() > 0) {
        canvas.getShape(0)->setColour("green");
        canvas.getShape(0)->setPosition(5, 10);
        cout << "Modified rectangle color to green and position to (5,10)" << endl;
    }
    
    if (canvas.getShapeCount() > 1) {
        canvas.getShape(1)->setColour("purple");
        canvas.getShape(1)->setPosition(15, 20);
        cout << "Modified square color to purple and position to (15,20)" << endl;
    }
    
    if (canvas.getShapeCount() > 2) {
        Textbox* tb = dynamic_cast<Textbox*>(canvas.getShape(2));
        if (tb) {
            tb->setText("Hello Prototype!");
            tb->setColour("orange");
            tb->setPosition(25, 30);
            cout << "Modified textbox text, color, and position" << endl;
        }
    }
    
    cout << "\nShapes after modification:" << endl;
    canvas.displayAll();
    
    // Now use Prototype pattern to clone modified shapes
    cout << "\nCloning shapes using Prototype Pattern:" << endl;
    
    for (int i = 0; i < 3 && i < canvas.getShapeCount(); i++) {
        canvas.duplicateShape(i);
    }
    
    cout << "\nCanvas after cloning:" << endl;
    canvas.displayAll();
}

void demonstrateBothPatterns() {
    cout << "\n=== COMPARING BOTH PATTERNS ===" << endl;
    
    Canvas canvas2;
    
    // Factory Method: Create new rectangle from scratch
    cout << "\nFactory Method - Creating new Rectangle:" << endl;
    RectangleFactory factory;
    Shape* newRect = factory.createShape();
    newRect->setColour("blue");
    newRect->setPosition(0, 0);
    canvas2.addShape(newRect);
    newRect->display();
    
    // Prototype Pattern: Clone the existing rectangle
    cout << "\nPrototype Pattern - Cloning existing Rectangle:" << endl;
    Shape* clonedRect = newRect->clone();
    clonedRect->setPosition(10, 10); // Slightly different position
    canvas2.addShape(clonedRect);
    clonedRect->display();
    
    cout << "\nBoth rectangles:" << endl;
    canvas2.displayAll();
}

void givenMain(){
    cout << "=== DESIGN PATTERNS DEMONSTRATION ===" << endl;
    cout << "Demonstrating Factory Method and Prototype Patterns" << endl;
    
    Canvas canvas;
    
    // Demonstrate Factory Method Pattern
    demonstrateFactoryMethod(canvas);
    
    // Demonstrate Prototype Pattern
    demonstratePrototypePattern(canvas);
    
    // Show the comparison
    demonstrateBothPatterns();
    
    cout << "\n=== SUMMARY ===" << endl;
    cout << "Factory Method Pattern: Creates new objects from scratch using factories" << endl;
    cout << "Prototype Pattern: Creates new objects by cloning existing ones" << endl;
    cout << "Both patterns work together to provide flexible object creation!" << endl;
}


// void KyleMain(){
//     RectangleFactory rFact;
//     Shape* r = rFact.createShape();
//     cout << r->toString() << endl;
// }

void KyleMain(){
    ShapeFactory* s = new RectangleFactory;
    Shape* r = s->createShape();
    r->display();
}

int main() {
    KyleMain();
    //givenMain();
    
    return 0;
}