#ifndef PROTOTYPE_MANAGER_H
#define PROTOTYPE_MANAGER_H

#include "Prototype.h"
#include <string>

// Simple map implementation using arrays
struct PrototypeEntry {
    std::string key;
    Prototype* prototype;
    bool isActive;
    
    PrototypeEntry() : key(""), prototype(nullptr), isActive(false) {}
};

class PrototypeManager {
private:
    // prototypeStore - stores the master prototype instances
    static const int MAX_PROTOTYPES = 50;
    PrototypeEntry prototypeStore[MAX_PROTOTYPES];
    int prototypeCount;

public:
    PrototypeManager();
    ~PrototypeManager();
    
    // Add a prototype to the registry
    void addPrototype(const std::string& key, Prototype* prototype);
    
    // Remove a prototype from the registry
    void removePrototype(const std::string& key);
    
    // Get a prototype by key (returns nullptr if not found)
    Prototype* getPrototype(const std::string& key) const;
    
    // Utility method to list all available prototypes
    void listPrototypes() const;
    
    // Clear all prototypes
    void clearPrototypes();
    
    // Get number of stored prototypes
    int getPrototypeCount() const;
};

#endif // PROTOTYPE_MANAGER_H