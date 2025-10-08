#include "ConcreteStaffHandlers.h"
#include <iostream>

// Electronics Staff
ElectronicsStaff::ElectronicsStaff() : StaffHandler("electronics") {}

void ElectronicsStaff::processRequest(std::string details) {
    std::cout << "\n=== ELECTRONICS DEPARTMENT ===\n";
    std::cout << "Electronics specialist: I'll help you with " << details << "\n";
    std::cout << "Let me show you our latest gadgets and tech!\n";
    std::cout << "==============================\n\n";
}

// Clothing Staff
ClothingStaff::ClothingStaff() : StaffHandler("clothing") {}

void ClothingStaff::processRequest(std::string details) {
    std::cout << "\n=== CLOTHING DEPARTMENT ===\n";
    std::cout << "Fashion consultant: I'll assist you with " << details << "\n";
    std::cout << "Let me find the perfect outfit for you!\n";
    std::cout << "===========================\n\n";
}

// Food Staff
FoodStaff::FoodStaff() : StaffHandler("food") {}

void FoodStaff::processRequest(std::string details) {
    std::cout << "\n=== FOOD DEPARTMENT ===\n";
    std::cout << "Food specialist: I can help with " << details << "\n";
    std::cout << "Let me show you our fresh produce and gourmet items!\n";
    std::cout << "=======================\n\n";
}

// Customer Service Staff
CustomerServiceStaff::CustomerServiceStaff() : StaffHandler("service") {}

void CustomerServiceStaff::processRequest(std::string details) {
    std::cout << "\n=== CUSTOMER SERVICE ===\n";
    std::cout << "Customer service rep: I'll handle " << details << "\n";
    std::cout << "How can I make your shopping experience better?\n";
    std::cout << "========================\n\n";
}