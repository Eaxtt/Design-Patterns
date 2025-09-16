#ifndef CONCRETE_PROTOTYPES_H
#define CONCRETE_PROTOTYPES_H

#include "Prototype.h"

// Concrete Prototype 1: Orc Enemy
class OrcEnemy : public Prototype {
private:
    std::string name;
    int health;
    int damage;
    std::string weapon;
    int level;

public:
    OrcEnemy(const std::string& n = "Orc", int h = 100, int d = 25, 
             const std::string& w = "Club", int l = 1);
    
    // Copy constructor for proper cloning
    OrcEnemy(const OrcEnemy& other);
    
    // Clone method - creates a copy of this object
    Prototype* clone() const override;
    
    void display() const override;
    std::string getType() const override;
    
    // Setters for customization
    void setLevel(int l) { level = l; }
    void setHealth(int h) { health = h; }
    void setName(const std::string& n) { name = n; }
};

// Concrete Prototype 2: Dragon Enemy
class DragonEnemy : public Prototype {
private:
    std::string name;
    int health;
    int damage;
    std::string element;
    bool canFly;
    int treasureValue;

public:
    DragonEnemy(const std::string& n = "Dragon", int h = 500, int d = 75,
                const std::string& e = "Fire", bool fly = true, int treasure = 1000);
    
    // Copy constructor for proper cloning
    DragonEnemy(const DragonEnemy& other);
    
    // Clone method - creates a copy of this object
    Prototype* clone() const override;
    
    void display() const override;
    std::string getType() const override;
    
    // Setters for customization
    void setElement(const std::string& e) { element = e; }
    void setTreasureValue(int t) { treasureValue = t; }
    void setName(const std::string& n) { name = n; }
};

// Concrete Prototype 3: Skeleton Enemy
class SkeletonEnemy : public Prototype {
private:
    std::string name;
    int health;
    int damage;
    bool hasShield;
    std::string boneType;

public:
    SkeletonEnemy(const std::string& n = "Skeleton", int h = 60, int d = 20,
                  bool shield = false, const std::string& bone = "Normal");
    
    // Copy constructor for proper cloning
    SkeletonEnemy(const SkeletonEnemy& other);
    
    // Clone method - creates a copy of this object
    Prototype* clone() const override;
    
    void display() const override;
    std::string getType() const override;
    
    // Setters for customization
    void setHasShield(bool shield) { hasShield = shield; }
    void setBoneType(const std::string& bone) { boneType = bone; }
    void setName(const std::string& n) { name = n; }
};

#endif // CONCRETE_PROTOTYPES_H