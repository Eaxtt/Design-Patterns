#ifndef COMPOSITE_COMPONENTS_H
#define COMPOSITE_COMPONENTS_H

#include "BuildingComponent.h"
#include <vector>

// Concrete Composite - Room (contains walls, doors, windows, furniture)
class Room : public BuildingComponent {
private:
    std::string name;
    std::vector<BuildingComponent*> components;

public:
    Room(const std::string& roomName);
    ~Room();
    
    // Component interface implementation
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
    
    // Composite-specific operations
    void addComponent(BuildingComponent* component) override;
    void removeComponent(BuildingComponent* component) override;
};

// Concrete Composite - Floor (contains multiple rooms)
class Floor : public BuildingComponent {
private:
    int floorNumber;
    std::vector<BuildingComponent*> rooms;

public:
    Floor(int number);
    ~Floor();
    
    // Component interface implementation
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
    
    // Composite-specific operations
    void addComponent(BuildingComponent* component) override;
    void removeComponent(BuildingComponent* component) override;
};

// Concrete Composite - Building (contains multiple floors)
class Building : public BuildingComponent {
private:
    std::string name;
    std::string address;
    std::vector<BuildingComponent*> floors;

public:
    Building(const std::string& buildingName, const std::string& buildingAddress);
    ~Building();
    
    // Component interface implementation
    double getCost() const override;
    double getWeight() const override;
    std::string getDescription() const override;
    void showStructure(int indentLevel = 0) const override;
    
    // Composite-specific operations
    void addComponent(BuildingComponent* component) override;
    void removeComponent(BuildingComponent* component) override;
};

#endif // COMPOSITE_COMPONENTS_H