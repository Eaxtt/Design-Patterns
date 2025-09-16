// ========== truck_factory.h ==========
#ifndef TRUCK_FACTORY_H
#define TRUCK_FACTORY_H

#include "vehicle_factory.h"
#include "truck.h"

// Concrete Factory 3
class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle();
    Truck* createTruck();
};



#endif