#include "Decorator.h"

Decorator::Decorator(Component* comp) : component(comp) {}

Decorator::~Decorator() {
    delete component;
}

void Decorator::operation() {
    if (component) {
        component->operation();
    }
}

double Decorator::getCost() {
    if (component) {
        return component->getCost();
    }
    return 0.0;
}

std::string Decorator::getDescription() {
    if (component) {
        return component->getDescription();
    }
    return "";
}