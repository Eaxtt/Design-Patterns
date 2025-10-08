#ifndef CONCRETE_STAFF_HANDLERS_H
#define CONCRETE_STAFF_HANDLERS_H

#include "StaffHandler.h"

// Concrete Handler 1 - Electronics Department
class ElectronicsStaff : public StaffHandler {
public:
    ElectronicsStaff();
    
protected:
    void processRequest(std::string details);
};

// Concrete Handler 2 - Clothing Department
class ClothingStaff : public StaffHandler {
public:
    ClothingStaff();
    
protected:
    void processRequest(std::string details);
};

// Concrete Handler 3 - Food Department
class FoodStaff : public StaffHandler {
public:
    FoodStaff();
    
protected:
    void processRequest(std::string details);
};

// Concrete Handler 4 - Customer Service
class CustomerServiceStaff : public StaffHandler {
public:
    CustomerServiceStaff();
    
protected:
    void processRequest(std::string details);
};

#endif