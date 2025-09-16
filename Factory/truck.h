// ========== truck.h ==========
#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

// Concrete Product 3
class Truck : public Vehicle {
public:
    void start();
    void stop();
    void displayInfo();
    void foo();
};

#endif