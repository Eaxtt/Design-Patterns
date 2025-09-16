#include <iostream>
#include "BuildingComponent.h"
#include "LeafComponents.h"
#include "CompositeComponents.h"

using namespace std;

void given(){
std::cout << "=== Building Construction - Composite Pattern Demo ===\n\n";
    
    // Create the main building
    Building* officeBuilding = new Building("TechCorp Tower", "123 Business Street");
    
    // Create first floor
    Floor* firstFloor = new Floor(1);
    
    // Create lobby room
    Room* lobby = new Room("Main Lobby");
    lobby->addComponent(new Wall("Marble", 10.0, 3.0, 200.0, 300.0)); // 10m x 3m marble wall
    lobby->addComponent(new Wall("Marble", 8.0, 3.0, 200.0, 300.0));  // 8m x 3m marble wall  
    lobby->addComponent(new Door("Glass", 1500.0, 80.0));              // Fancy glass door
    lobby->addComponent(new Window("Floor-to-ceiling", 800.0, 120.0)); // Large window
    lobby->addComponent(new Furniture("Reception Desk", 2000.0, 150.0)); // Reception desk
    lobby->addComponent(new Furniture("Leather Sofa", 1200.0, 80.0));   // Waiting area sofa
    
    // Create conference room
    Room* conferenceRoom = new Room("Conference Room A");
    conferenceRoom->addComponent(new Wall("Drywall", 6.0, 3.0, 50.0, 80.0)); // 6m x 3m drywall
    conferenceRoom->addComponent(new Wall("Drywall", 6.0, 3.0, 50.0, 80.0)); 
    conferenceRoom->addComponent(new Door("Wood", 600.0, 45.0));              // Standard door
    conferenceRoom->addComponent(new Window("Double-pane", 400.0, 50.0));     // Standard window
    conferenceRoom->addComponent(new Furniture("Conference Table", 1500.0, 120.0)); // Big table
    conferenceRoom->addComponent(new Furniture("Office Chair", 300.0, 25.0));       // Chair 1
    conferenceRoom->addComponent(new Furniture("Office Chair", 300.0, 25.0));       // Chair 2
    conferenceRoom->addComponent(new Furniture("Office Chair", 300.0, 25.0));       // Chair 3
    
    // Add rooms to first floor
    firstFloor->addComponent(lobby);
    firstFloor->addComponent(conferenceRoom);
    
    // Create second floor
    Floor* secondFloor = new Floor(2);
    
    // Create office room
    Room* office1 = new Room("CEO Office");
    office1->addComponent(new Wall("Wood Paneling", 5.0, 3.0, 150.0, 100.0)); // Fancy walls
    office1->addComponent(new Wall("Wood Paneling", 4.0, 3.0, 150.0, 100.0));
    office1->addComponent(new Door("Mahogany", 1200.0, 60.0));                 // Expensive door
    office1->addComponent(new Window("Panoramic", 1000.0, 100.0));             // Big window
    office1->addComponent(new Furniture("Executive Desk", 3000.0, 200.0));     // Fancy desk
    office1->addComponent(new Furniture("Executive Chair", 800.0, 35.0));      // Fancy chair
    office1->addComponent(new Furniture("Bookshelf", 600.0, 80.0));            // Storage
    
    // Create regular office
    Room* office2 = new Room("Regular Office");
    office2->addComponent(new Wall("Drywall", 4.0, 3.0, 50.0, 80.0));
    office2->addComponent(new Wall("Drywall", 3.0, 3.0, 50.0, 80.0));
    office2->addComponent(new Door("Wood", 500.0, 40.0));
    office2->addComponent(new Window("Standard", 300.0, 35.0));
    office2->addComponent(new Furniture("Desk", 400.0, 50.0));
    office2->addComponent(new Furniture("Office Chair", 200.0, 20.0));
    
    // Add rooms to second floor
    secondFloor->addComponent(office1);
    secondFloor->addComponent(office2);
    
    // Add floors to building
    officeBuilding->addComponent(firstFloor);
    officeBuilding->addComponent(secondFloor);
    
    // Display the complete building structure
    std::cout << "Complete Building Structure:\n";
    std::cout << "============================\n";
    officeBuilding->showStructure();
    
    std::cout << "\n=== Cost and Weight Summary ===\n";
    std::cout << "Total Building Cost: $" << officeBuilding->getCost() << std::endl;
    std::cout << "Total Building Weight: " << officeBuilding->getWeight() << "kg\n\n";
    
    // Demonstrate treating individual components uniformly
    std::cout << "=== Individual Component Details ===\n";
    std::cout << "Lobby details: " << lobby->getDescription() << std::endl;
    std::cout << "Conference Room details: " << conferenceRoom->getDescription() << std::endl;
    std::cout << "First Floor details: " << firstFloor->getDescription() << std::endl;
    
    std::cout << "\n=== Demo Complete ===\n";
    std::cout << "This demonstrates:\n";
    std::cout << "- Leaf components (walls, doors, windows, furniture) stored in Rooms\n";
    std::cout << "- Rooms stored in Floors (middle-men composites)\n";  
    std::cout << "- Floors stored in Building (top-level composite)\n";
    std::cout << "- All components treated uniformly through common interface\n";
    std::cout << "- Automatic cost/weight calculation up the hierarchy\n";
    
    // Cleanup - Building destructor will cascade delete everything
    delete officeBuilding;
}

void kyle(){
    Building* school = new Building("high school","123 street");
    Floor* f1 = new Floor(1);
    Room* MathsClassroom = new Room("maths class");
    MathsClassroom->addComponent(new Wall("dry wall",20,2,10,10));
    MathsClassroom->addComponent(new Wall("dry wall",20,2,10,10));
    MathsClassroom->addComponent(new Wall("dry wall",20,2,10,10));
    MathsClassroom->addComponent(new Wall("dry wall",20,2,10,10));
    MathsClassroom->addComponent(new Furniture("Chair",100,10));
    Room* EnglishClassroom = new Room("english calss");

    f1->addComponent(MathsClassroom);
    school->addComponent(f1);

    school->showStructure();
    
    
}

int main() {
    
    kyle();
    //given();
    return 0;
}