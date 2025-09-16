
// ========== motorcycle.h ==========
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

// Concrete Product 2
class Motorcycle : public Vehicle {
public:
    void start();
    void stop();
    void displayInfo();
    void setNumTires(int);
    int getNumTires();
};

#endif