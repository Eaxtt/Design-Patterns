// ========== motorcycle_factory.h ==========
#ifndef MOTORCYCLE_FACTORY_H
#define MOTORCYCLE_FACTORY_H

#include "vehicle_factory.h"
#include "motorcycle.h"

// Concrete Factory 2
class MotorcycleFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() ;
    Motorcycle* createMotorcycle();
};

#endif