#include "ConcretePrototypes.h"

// ========== OrcEnemy Implementation ==========
OrcEnemy::OrcEnemy(const std::string& n, int h, int d, const std::string& w, int l)
    : name(n), health(h), damage(d), weapon(w), level(l) {
    std::cout << "Creating OrcEnemy: " << name << std::endl;
}

OrcEnemy::OrcEnemy(const OrcEnemy& other)
    : name(other.name), health(other.health), damage(other.damage), 
      weapon(other.weapon), level(other.level) {
    std::cout << "Cloning OrcEnemy: " << name << std::endl;
}

Prototype* OrcEnemy::clone() const {
    return new OrcEnemy(*this);
}

void OrcEnemy::display() const {
    std::cout << "=== ORC ENEMY ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Weapon: " << weapon << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "=================" << std::endl;
}

std::string OrcEnemy::getType() const {
    return "OrcEnemy";
}

// ========== DragonEnemy Implementation ==========
DragonEnemy::DragonEnemy(const std::string& n, int h, int d, const std::string& e, bool fly, int treasure)
    : name(n), health(h), damage(d), element(e), canFly(fly), treasureValue(treasure) {
    std::cout << "Creating DragonEnemy: " << name << std::endl;
}

DragonEnemy::DragonEnemy(const DragonEnemy& other)
    : name(other.name), health(other.health), damage(other.damage),
      element(other.element), canFly(other.canFly), treasureValue(other.treasureValue) {
    std::cout << "Cloning DragonEnemy: " << name << std::endl;
}

Prototype* DragonEnemy::clone() const {
    return new DragonEnemy(*this);
}

void DragonEnemy::display() const {
    std::cout << "=== DRAGON ENEMY ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Element: " << element << std::endl;
    std::cout << "Can Fly: " << (canFly ? "Yes" : "No") << std::endl;
    std::cout << "Treasure Value: " << treasureValue << std::endl;
    std::cout << "===================" << std::endl;
}

std::string DragonEnemy::getType() const {
    return "DragonEnemy";
}

// ========== SkeletonEnemy Implementation ==========
SkeletonEnemy::SkeletonEnemy(const std::string& n, int h, int d, bool shield, const std::string& bone)
    : name(n), health(h), damage(d), hasShield(shield), boneType(bone) {
    std::cout << "Creating SkeletonEnemy: " << name << std::endl;
}

SkeletonEnemy::SkeletonEnemy(const SkeletonEnemy& other)
    : name(other.name), health(other.health), damage(other.damage),
      hasShield(other.hasShield), boneType(other.boneType) {
    std::cout << "Cloning SkeletonEnemy: " << name << std::endl;
}

Prototype* SkeletonEnemy::clone() const {
    return new SkeletonEnemy(*this);
}

void SkeletonEnemy::display() const {
    std::cout << "=== SKELETON ENEMY ===" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Has Shield: " << (hasShield ? "Yes" : "No") << std::endl;
    std::cout << "Bone Type: " << boneType << std::endl;
    std::cout << "=====================" << std::endl;
}

std::string SkeletonEnemy::getType() const {
    return "SkeletonEnemy";
}