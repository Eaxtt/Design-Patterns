#include "Canvas.h"

Canvas::Canvas() {}

Canvas::~Canvas() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void Canvas::addShape(Shape* shape) {
    if (shape != nullptr) {
        shapes.push_back(shape);
        cout << "Added " << shape->getType() << " to canvas." << endl;
    }
}

void Canvas::duplicateShape(int index) {
    if (index >= 0 && index < shapes.size()) {
        Shape* cloned = shapes[index]->clone();
        // Offset the position slightly so it's visible as a copy
        cloned->setPosition(cloned->getPositionX() + 2, cloned->getPositionY() + 2);
        shapes.push_back(cloned);
        cout << "Cloned " << shapes[index]->getType() << " using Prototype pattern." << endl;
    } else {
        cout << "Invalid index for duplication." << endl;
    }
}

void Canvas::displayAll() const {
    cout << "\n=== Canvas Contents ===" << endl;
    if (shapes.empty()) {
        cout << "Canvas is empty." << endl;
    } else {
        for (int i = 0; i < shapes.size(); i++) {
            cout << "[" << i << "] ";
            shapes[i]->display();
        }
    }
    cout << "======================" << endl;
}

int Canvas::getShapeCount() const {
    return shapes.size();
}

Shape* Canvas::getShape(int index) const {
    if (index >= 0 && index < shapes.size()) {
        return shapes[index];
    }
    return nullptr;
}

void Canvas::removeShape(int index) {
    if (index >= 0 && index < shapes.size()) {
        delete shapes[index];
        shapes.erase(shapes.begin() + index);
        cout << "Removed shape at index " << index << endl;
    }
}

void Canvas::clear() {
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
    cout << "Canvas cleared." << endl;
}