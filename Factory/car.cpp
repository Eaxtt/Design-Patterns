// ========== car.cpp ==========
#include "car.h"
#include <iostream>

Car::Car(const std::string& carColor, const std::string& carBrand) 
    : color(carColor), brand(carBrand) {
    // Constructor implementation - could do validation, logging, etc.
    std::cout << "Car constructor: Creating a " << color << " " << brand << std::endl;
}

void Car::start() {
    std::cout << "Car: Turning key in " << color << " " << brand << ", engine purring to life..." << std::endl;
}

void Car::stop() {
    std::cout << "Car: " << brand << " engine stopping, pressing brake..." << std::endl;
}

void Car::displayInfo() {
    std::cout << "This is a " << color << " " << brand << " Car - 4 wheels, comfortable seating, good for families" << std::endl;
}

std::string Car::getColor() const {
    return color;
}

std::string Car::getBrand() const {
    return brand;
}