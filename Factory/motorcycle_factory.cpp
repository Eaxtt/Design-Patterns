// ========== motorcycle_factory.cpp ==========
#include "motorcycle_factory.h"
#include "motorcycle.h"
#include <iostream>

Vehicle* MotorcycleFactory::createVehicle() {
    std::cout << "MotorcycleFactory: Creating a new Motorcycle..." << std::endl;
    return new Motorcycle();
    } 

    // Additional method that returns specific type
    //we could use this in our main incase we ever want to access specific fucntions in motorcycle that arent in vehicle
    Motorcycle* MotorcycleFactory::createMotorcycle() {
    return new Motorcycle();
    }
