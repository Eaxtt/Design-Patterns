// ========== truck.cpp ==========
using namespace std;
#include "truck.h"
#include <iostream>

void Truck::start() {
    std::cout << "Truck: Diesel engine starting with a deep rumble..." << std::endl;
}

void Truck::stop() {
    std::cout << "Truck: Air brakes hissing, heavy engine shutting down..." << std::endl;
}

void Truck::displayInfo() {
    std::cout << "This is a Truck - Large wheels, heavy duty, built for cargo transport" << std::endl;
}

void Truck::foo(){
    cout << "this is the foo" << endl;
}