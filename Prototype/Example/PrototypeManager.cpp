#include "PrototypeManager.h"
#include <iostream>

PrototypeManager::PrototypeManager() : prototypeCount(0) {
    // Initialize all entries as inactive
    for (int i = 0; i < MAX_PROTOTYPES; i++) {
        prototypeStore[i].isActive = false;
    }
}

PrototypeManager::~PrototypeManager() {
    clearPrototypes();
}

void PrototypeManager::addPrototype(const std::string& key, Prototype* prototype) {
    if (prototype && prototypeCount < MAX_PROTOTYPES) {
        // Find first inactive slot
        for (int i = 0; i < MAX_PROTOTYPES; i++) {
            if (!prototypeStore[i].isActive) {
                prototypeStore[i].key = key;
                prototypeStore[i].prototype = prototype;
                prototypeStore[i].isActive = true;
                prototypeCount++;
                std::cout << "Adding prototype '" << key << "' of type: " << prototype->getType() << std::endl;
                return;
            }
        }
    }
    std::cout << "Failed to add prototype '" << key << "'" << std::endl;
}

void PrototypeManager::removePrototype(const std::string& key) {
    for (int i = 0; i < MAX_PROTOTYPES; i++) {
        if (prototypeStore[i].isActive && prototypeStore[i].key == key) {
            std::cout << "Removing prototype '" << key << "'" << std::endl;
            delete prototypeStore[i].prototype;
            prototypeStore[i].isActive = false;
            prototypeStore[i].prototype = nullptr;
            prototypeStore[i].key = "";
            prototypeCount--;
            return;
        }
    }
    std::cout << "Prototype '" << key << "' not found for removal" << std::endl;
}

Prototype* PrototypeManager::getPrototype(const std::string& key) const {
    for (int i = 0; i < MAX_PROTOTYPES; i++) {
        if (prototypeStore[i].isActive && prototypeStore[i].key == key) {
            std::cout << "Retrieved prototype '" << key << "'" << std::endl;
            return prototypeStore[i].prototype;
        }
    }
    std::cout << "Prototype '" << key << "' not found" << std::endl;
    return nullptr;
}

void PrototypeManager::listPrototypes() const {
    std::cout << "\n=== AVAILABLE PROTOTYPES ===" << std::endl;
    if (prototypeCount == 0) {
        std::cout << "No prototypes registered" << std::endl;
    } else {
        for (int i = 0; i < MAX_PROTOTYPES; i++) {
            if (prototypeStore[i].isActive) {
                std::cout << "Key: '" << prototypeStore[i].key << "' -> Type: " 
                          << prototypeStore[i].prototype->getType() << std::endl;
            }
        }
    }
    std::cout << "=============================" << std::endl << std::endl;
}

void PrototypeManager::clearPrototypes() {
    std::cout << "Clearing all prototypes" << std::endl;
    for (int i = 0; i < MAX_PROTOTYPES; i++) {
        if (prototypeStore[i].isActive) {
            delete prototypeStore[i].prototype;
            prototypeStore[i].isActive = false;
            prototypeStore[i].prototype = nullptr;
            prototypeStore[i].key = "";
        }
    }
    prototypeCount = 0;
}

int PrototypeManager::getPrototypeCount() const {
    return prototypeCount;
}