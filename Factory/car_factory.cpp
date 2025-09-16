// ========== car_factory.cpp ==========
#include "car_factory.h"
#include "car.h"
#include <iostream>

CarFactory::CarFactory(const std::string& color, const std::string& brand) 
    : defaultColor(color), defaultBrand(brand) {
    std::cout << "CarFactory: Initialized with defaults - " << defaultColor << " " << defaultBrand << std::endl;
}

Vehicle* CarFactory::createVehicle() {
    std::cout << "CarFactory: Creating car with default settings..." << std::endl;
    return new Car(defaultColor, defaultBrand);
}

Vehicle* CarFactory::createVehicle(const std::string& color, const std::string& brand) {
    std::cout << "CarFactory: Creating custom car..." << std::endl;
    return new Car(color, brand);
}

void CarFactory::setDefaultColor(const std::string& color) {
    defaultColor = color;
    std::cout << "CarFactory: Default color changed to " << color << std::endl;
}

void CarFactory::setDefaultBrand(const std::string& brand) {
    defaultBrand = brand;
    std::cout << "CarFactory: Default brand changed to " << brand << std::endl;
}