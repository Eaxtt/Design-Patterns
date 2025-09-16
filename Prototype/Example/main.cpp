#include "PrototypeManager.h"
#include "ConcretePrototypes.h"
#include <iostream>

// Simple dynamic array to store enemies
class EnemyList {
private:
    static const int MAX_ENEMIES = 100;
    Prototype* enemies[MAX_ENEMIES];
    int count;

public:
    EnemyList() : count(0) {}
    
    ~EnemyList() {
        for (int i = 0; i < count; i++) {
            delete enemies[i];
        }
    }
    
    void add(Prototype* enemy) {
        if (count < MAX_ENEMIES) {
            enemies[count++] = enemy;
        }
    }
    
    int size() const { return count; }
    
    Prototype* get(int index) const {
        if (index >= 0 && index < count) {
            return enemies[index];
        }
        return nullptr;
    }
};

int main() {
    std::cout << "=== PROTOTYPE PATTERN DEMO ===" << std::endl << std::endl;
    
    // Create the Prototype Manager
    PrototypeManager manager;
    
    std::cout << "1. Creating and registering prototype templates..." << std::endl;
    
    // Create prototype instances (these are our "templates")
    OrcEnemy* basicOrc = new OrcEnemy("Basic Orc", 80, 20, "Wooden Club", 1);
    OrcEnemy* eliteOrc = new OrcEnemy("Elite Orc", 150, 35, "Steel Mace", 5);
    
    DragonEnemy* fireDragon = new DragonEnemy("Fire Dragon", 400, 60, "Fire", true, 800);
    DragonEnemy* iceDragon = new DragonEnemy("Ice Dragon", 450, 55, "Ice", true, 1200);
    
    SkeletonEnemy* normalSkeleton = new SkeletonEnemy("Skeleton Warrior", 50, 15, false, "Normal");
    SkeletonEnemy* armoredSkeleton = new SkeletonEnemy("Armored Skeleton", 90, 25, true, "Reinforced");
    
    // Register prototypes with the manager
    manager.addPrototype("basicOrc", basicOrc);
    manager.addPrototype("eliteOrc", eliteOrc);
    manager.addPrototype("fireDragon", fireDragon);
    manager.addPrototype("iceDragon", iceDragon);
    manager.addPrototype("skeleton", normalSkeleton);
    manager.addPrototype("armoredSkeleton", armoredSkeleton);
    
    std::cout << std::endl;
    manager.listPrototypes();
    
    std::cout << "2. Creating enemies by cloning prototypes..." << std::endl << std::endl;
    
    // Client code - spawn enemies by cloning prototypes
    EnemyList enemies;
    
    // Spawn some basic orcs
    for (int i = 0; i < 3; ++i) {
        Prototype* orcProto = manager.getPrototype("basicOrc");
        if (orcProto) {
            Prototype* newOrc = orcProto->clone();
            // Could customize the cloned enemy here if needed
            enemies.add(newOrc);
        }
    }
    
    //for gabi, this is how it is done in the slides ive called the getPrototype which finds that specific concrete prototype in its list and then calls its clone function
    

        Prototype* eliteEnemy = (manager.getPrototype("eliteOrc"))->clone();
        enemies.add(eliteEnemy);
    
    
    // Spawn a dragon
    Prototype* dragonProto = manager.getPrototype("fireDragon");
    if (dragonProto) {
        Prototype* dragon = dragonProto->clone();
        enemies.add(dragon);
    }
    
    // Spawn some skeletons
    Prototype* skeletonProto = manager.getPrototype("skeleton");
    if (skeletonProto) {
        Prototype* skeleton1 = skeletonProto->clone();
        Prototype* skeleton2 = skeletonProto->clone();
        enemies.add(skeleton1);
        enemies.add(skeleton2);
    }
    
    std::cout << "\n3. Displaying all spawned enemies..." << std::endl << std::endl;
    
    // Display all created enemies
    for (int i = 0; i < enemies.size(); ++i) {
        std::cout << "Enemy #" << (i + 1) << ":" << std::endl;
        enemies.get(i)->display();
        std::cout << std::endl;
    }
    
    std::cout << "4. Testing prototype removal..." << std::endl;
    manager.removePrototype("basicOrc");
    manager.listPrototypes();
    
    // Try to get removed prototype
    std::cout << "5. Trying to get removed prototype..." << std::endl;
    Prototype* removedProto = manager.getPrototype("basicOrc");
    if (!removedProto) {
        std::cout << "Correctly returned nullptr for removed prototype." << std::endl;
    }
    
    std::cout << "\n=== DEMO COMPLETE ===" << std::endl;
    
    return 0;
}