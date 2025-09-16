// ========== factory.h ==========
#ifndef FACTORY_H
#define FACTORY_H

#include "vehicle.h"

enum VehicleType {
    CAR,
    MOTORCYCLE,
    TRUCK
};

// Abstract Factory class
class VehicleFactory {
public:
    virtual ~VehicleFactory() {}
    virtual Vehicle* createVehicle(VehicleType type) = 0;
};

#endif