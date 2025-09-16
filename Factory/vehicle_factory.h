// ========== vehicle_factory.h ==========
#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include "vehicle.h"

// Abstract Factory class
class VehicleFactory {
public:
    virtual ~VehicleFactory() {}
    virtual Vehicle* createVehicle() = 0;
};

#endif