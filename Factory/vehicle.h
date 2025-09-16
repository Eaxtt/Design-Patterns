
// ========== vehicle.h ==========
#ifndef VEHICLE_H
#define VEHICLE_H

// Abstract Product class
class Vehicle {
public:
    virtual ~Vehicle() {}
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void displayInfo() = 0;

    // Add these virtual methods
    virtual void setNumTires(int tires) { numTires = tires; }
    virtual int getNumTires() const { return numTires; }

protected:
    int numTires;
};

#endif