#include "LeafComponents.h"
#include <iostream>
#include <sstream>

// Window implementation
Window::Window(const std::string& windowType, double windowCost, double windowWeight)
    : type(windowType), cost(windowCost), weight(windowWeight) {
}

double Window::getCost() const {
    return cost;
}

double Window::getWeight() const {
    return weight;
}

std::string Window::getDescription() const {
    std::stringstream ss;
    ss << type << " Window ($" << cost << ", " << weight << "kg)";
    return ss.str();
}

void Window::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "- " << getDescription() << std::endl;
}

// Door implementation
Door::Door(const std::string& doorMaterial, double doorCost, double doorWeight)
    : material(doorMaterial), cost(doorCost), weight(doorWeight) {
}

double Door::getCost() const {
    return cost;
}

double Door::getWeight() const {
    return weight;
}

std::string Door::getDescription() const {
    std::stringstream ss;
    ss << material << " Door ($" << cost << ", " << weight << "kg)";
    return ss.str();
}

void Door::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "- " << getDescription() << std::endl;
}

// Wall implementation
Wall::Wall(const std::string& wallMaterial, double wallLength, double wallHeight, 
           double costPerSqm, double weightPerSqm)
    : material(wallMaterial), length(wallLength), height(wallHeight), 
      costPerSquareMeter(costPerSqm), weightPerSquareMeter(weightPerSqm) {
}

double Wall::getCost() const {
    double area = length * height;
    return area * costPerSquareMeter;
}

double Wall::getWeight() const {
    double area = length * height;
    return area * weightPerSquareMeter;
}

std::string Wall::getDescription() const {
    std::stringstream ss;
    ss << material << " Wall " << length << "m x " << height << "m ($" 
       << getCost() << ", " << getWeight() << "kg)";
    return ss.str();
}

void Wall::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "- " << getDescription() << std::endl;
}

// Furniture implementation
Furniture::Furniture(const std::string& furnitureType, double furnitureCost, double furnitureWeight)
    : type(furnitureType), cost(furnitureCost), weight(furnitureWeight) {
}

double Furniture::getCost() const {
    return cost;
}

double Furniture::getWeight() const {
    return weight;
}

std::string Furniture::getDescription() const {
    std::stringstream ss;
    ss << type << " ($" << cost << ", " << weight << "kg)";
    return ss.str();
}

void Furniture::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "- " << getDescription() << std::endl;
}