// ========== truck_factory.cpp ==========
#include "truck_factory.h"
// #include "truck.h"
#include <iostream>

Vehicle* TruckFactory::createVehicle() {
    std::cout << "TruckFactory: Creating a new Truck..." << std::endl;
    return new Truck();
}

Truck* TruckFactory::createTruck(){
    return new Truck();
}