#include "CompositeComponents.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Room implementation
Room::Room(const std::string& roomName) : name(roomName) {
}

Room::~Room() {
    // Clean up all components owned by this room
    for (BuildingComponent* component : components) {
        delete component;
    }
    components.clear();
}

double Room::getCost() const {
    double totalCost = 0.0;
    for (const BuildingComponent* component : components) {
        totalCost += component->getCost();
    }
    return totalCost;
}

double Room::getWeight() const {
    double totalWeight = 0.0;
    for (const BuildingComponent* component : components) {
        totalWeight += component->getWeight();
    }
    return totalWeight;
}

std::string Room::getDescription() const {
    std::stringstream ss;
    ss << name << " (Cost: $" << getCost() << ", Weight: " << getWeight() << "kg)";
    return ss.str();
}

void Room::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "+ " << getDescription() << std::endl;
    for (const BuildingComponent* component : components) {
        component->showStructure(indentLevel + 1);
    }
}

void Room::addComponent(BuildingComponent* component) {
    components.push_back(component);
}

void Room::removeComponent(BuildingComponent* component) {
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end()) {
        components.erase(it);
    }
}

// Floor implementation
Floor::Floor(int number) : floorNumber(number) {
}

Floor::~Floor() {
    // Clean up all rooms owned by this floor
    for (BuildingComponent* room : rooms) {
        delete room;
    }
    rooms.clear();
}

double Floor::getCost() const {
    double totalCost = 0.0;
    for (const BuildingComponent* room : rooms) {
        totalCost += room->getCost();
    }
    return totalCost;
}

double Floor::getWeight() const {
    double totalWeight = 0.0;
    for (const BuildingComponent* room : rooms) {
        totalWeight += room->getWeight();
    }
    return totalWeight;
}

std::string Floor::getDescription() const {
    std::stringstream ss;
    ss << "Floor " << floorNumber << " (Cost: $" << getCost() 
       << ", Weight: " << getWeight() << "kg, Rooms: " << rooms.size() << ")";
    return ss.str();
}

void Floor::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "++ " << getDescription() << std::endl;
    for (const BuildingComponent* room : rooms) {
        room->showStructure(indentLevel + 1);
    }
}

void Floor::addComponent(BuildingComponent* component) {
    rooms.push_back(component);
}

void Floor::removeComponent(BuildingComponent* component) {
    auto it = std::find(rooms.begin(), rooms.end(), component);
    if (it != rooms.end()) {
        rooms.erase(it);
    }
}

// Building implementation
Building::Building(const std::string& buildingName, const std::string& buildingAddress) 
    : name(buildingName), address(buildingAddress) {
}

Building::~Building() {
    // Clean up all floors owned by this building
    for (BuildingComponent* floor : floors) {
        delete floor;
    }
    floors.clear();
}

double Building::getCost() const {
    double totalCost = 0.0;
    for (const BuildingComponent* floor : floors) {
        totalCost += floor->getCost();
    }
    return totalCost;
}

double Building::getWeight() const {
    double totalWeight = 0.0;
    for (const BuildingComponent* floor : floors) {
        totalWeight += floor->getWeight();
    }
    return totalWeight;
}

std::string Building::getDescription() const {
    std::stringstream ss;
    ss << name << " (" << address << ") - Total Cost: $" << getCost() 
       << ", Total Weight: " << getWeight() << "kg, Floors: " << floors.size();
    return ss.str();
}

void Building::showStructure(int indentLevel) const {
    std::cout << getIndent(indentLevel) << "+++ " << getDescription() << std::endl;
    for (const BuildingComponent* floor : floors) {
        floor->showStructure(indentLevel + 1);
    }
}

void Building::addComponent(BuildingComponent* component) {
    floors.push_back(component);
}

void Building::removeComponent(BuildingComponent* component) {
    auto it = std::find(floors.begin(), floors.end(), component);
    if (it != floors.end()) {
        floors.erase(it);
    }
}