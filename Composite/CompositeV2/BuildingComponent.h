#ifndef BUILDING_COMPONENT_H
#define BUILDING_COMPONENT_H

#include <string>

// Abstract Component - Base class for all building components
class BuildingComponent {
public:
    virtual ~BuildingComponent() = default;
    
    // Core operations that all components must support
    virtual double getCost() const = 0;
    virtual double getWeight() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void showStructure(int indentLevel = 0) const = 0;
    
    // Default implementations for composite operations
    // Leaf components will not override these
    virtual void addComponent(BuildingComponent* component) {
        // Default: do nothing (leaves can't add components)
    }
    
    virtual void removeComponent(BuildingComponent* component) {
        // Default: do nothing (leaves can't remove components)
    }
    
protected:
    // Helper method to create indentation for structure display
    std::string getIndent(int level) const {
        return std::string(level * 2, ' ');
    }
};

#endif // BUILDING_COMPONENT_H