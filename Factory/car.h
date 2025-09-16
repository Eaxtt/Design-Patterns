// ========== car.h ==========
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
#include <string>

// Concrete Product 1
class Car : public Vehicle {
private:
    std::string color;
    std::string brand;
    
public:
    // Constructor that takes parameters
    Car(const std::string& carColor, const std::string& carBrand);
    
    void start();
    void stop();
    void displayInfo();
    
    // Getters for the new properties
    std::string getColor() const;
    std::string getBrand() const;
};

#endif