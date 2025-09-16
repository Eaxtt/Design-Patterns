#ifndef LEAF_COMPONENTS_H
#define LEAF_COMPONENTS_H

#include "BuildingComponent.h"

// Concrete Leaf - Window
class Window : public BuildingComponent {
private:
    std::string type;
    double cost;
    double weight;

public:
    Window(const std::string& windowType, double windowCost, double windowWeight);
    
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
};

// Concrete Leaf - Door
class Door : public BuildingComponent {
private:
    std::string material;
    double cost;
    double weight;

public:
    Door(const std::string& doorMaterial, double doorCost, double doorWeight);
    
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
};

// Concrete Leaf - Wall
class Wall : public BuildingComponent {
private:
    std::string material;
    double length;
    double height;
    double costPerSquareMeter;
    double weightPerSquareMeter;

public:
    Wall(const std::string& wallMaterial, double wallLength, double wallHeight, 
         double costPerSqm, double weightPerSqm);
    
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
};

// Concrete Leaf - Furniture
class Furniture : public BuildingComponent {
private:
    std::string type;
    double cost;
    double weight;

public:
    Furniture(const std::string& furnitureType, double furnitureCost, double furnitureWeight);
    
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
};

#endif // LEAF_COMPONENTS_H