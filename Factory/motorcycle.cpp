// ========== motorcycle.cpp ==========
#include "motorcycle.h"
#include <iostream>

void Motorcycle::start() {
    std::cout << "Motorcycle: Kick starting, engine roaring loudly!" << std::endl;
}

void Motorcycle::stop() {
    std::cout << "Motorcycle: Pulling brake lever, engine winding down..." << std::endl;
}

void Motorcycle::displayInfo() {
    std::cout << "This is a Motorcycle - 2 wheels, fast and agile, great for solo rides and has: " << numTires << " number of tires " << std::endl;
}

void Motorcycle::setNumTires(int x){
    numTires = x;
}

int Motorcycle::getNumTires(){
    return numTires;
}