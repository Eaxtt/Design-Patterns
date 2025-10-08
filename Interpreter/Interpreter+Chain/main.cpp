#include <iostream>
#include "Customer.h"
#include "ConcreteStaffHandlers.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "   WELCOME TO THE DEPARTMENT STORE\n";
    std::cout << "========================================\n\n";
    
    // Set up Chain of Responsibility
    ElectronicsStaff* electronicsStaff = new ElectronicsStaff();
    ClothingStaff* clothingStaff = new ClothingStaff();
    FoodStaff* foodStaff = new FoodStaff();
    CustomerServiceStaff* serviceStaff = new CustomerServiceStaff();
    
    // Build the chain
    electronicsStaff->setSuccessor(clothingStaff);
    clothingStaff->setSuccessor(foodStaff);
    foodStaff->setSuccessor(serviceStaff);
    
    // Create customers
    Customer alice("Alice");
    Customer bob("Bob");
    Customer charlie("Charlie");
    Customer diana("Diana");
    
    // Scenario 1: Electronics request
    alice.askForHelp("I need help finding a new laptop", electronicsStaff);
    
    // Scenario 2: Clothing request
    bob.askForHelp("Where can I find a nice shirt?", electronicsStaff);
    
    // Scenario 3: Food request
    charlie.askForHelp("I'm looking for fresh bread and milk", electronicsStaff);
    
    // Scenario 4: Customer service request
    diana.askForHelp("I need to return this item, it's broken", electronicsStaff);
    
    // Scenario 5: Ambiguous request (defaults to customer service)
    alice.askForHelp("Can you help me find something?", electronicsStaff);
    
    std::cout << "\n========================================\n";
    std::cout << "   THANK YOU FOR SHOPPING WITH US!\n";
    std::cout << "========================================\n";
    
    // Clean up chain
    delete electronicsStaff;
    delete clothingStaff;
    delete foodStaff;
    delete serviceStaff;
    
    return 0;
}