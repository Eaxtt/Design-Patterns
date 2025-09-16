// ========== car_factory.h ==========
#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

#include "vehicle_factory.h"
#include <string>

// Concrete Factory 1
class CarFactory : public VehicleFactory {
private:
    std::string defaultColor;
    std::string defaultBrand;
    
public:
    // Constructor to set default values
    CarFactory(const std::string& color = "Red", const std::string& brand = "Toyota");
    
    // Override from base class
    Vehicle* createVehicle();
    
    // Additional method for creating cars with specific parameters
    Vehicle* createVehicle(const std::string& color, const std::string& brand);
    
    // Methods to change defaults
    void setDefaultColor(const std::string& color);
    void setDefaultBrand(const std::string& brand);
};

#endif