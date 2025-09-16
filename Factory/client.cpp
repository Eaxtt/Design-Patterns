// ========== client.cpp ==========
#include "car_factory.h"
#include "motorcycle_factory.h"
#include "truck_factory.h"
#include "motorcycle.h"
//#include "factory.h"
#include <iostream>
//#include "truck.h"


void givenMain(){
   std::cout << "=== Vehicle Factory Demo (With Car Properties) ===" << std::endl << std::endl;
    
    // Create factories with different default settings
    CarFactory toyotaFactory("Blue", "Toyota");
    CarFactory bmwFactory("Black", "BMW");
    MotorcycleFactory motorcycleFactory;
    TruckFactory truckFactory;
    
    // Create cars using default factory settings
    std::cout << "Client: Creating cars with factory defaults..." << std::endl;
    Vehicle* toyotaCar = toyotaFactory.createVehicle();
    if (toyotaCar) {
        toyotaCar->displayInfo();
        toyotaCar->start();
        delete toyotaCar;
    }
    
    std::cout << std::endl;
    Vehicle* bmwCar = bmwFactory.createVehicle();
    if (bmwCar) {
        bmwCar->displayInfo();
        bmwCar->start();
        delete bmwCar;
    }
    
    // Create cars with custom specifications
    std::cout << std::endl << "Client: Creating cars with custom specifications..." << std::endl;
    Vehicle* customCar1 = toyotaFactory.createVehicle("Green", "Honda");
    if (customCar1) {
        customCar1->displayInfo();
        delete customCar1;
    }
    
    Vehicle* customCar2 = bmwFactory.createVehicle("White", "Mercedes");
    if (customCar2) {
        customCar2->displayInfo();
        delete customCar2;
    }
    
    // Change factory defaults and create another car
    std::cout << std::endl << "Client: Changing factory defaults..." << std::endl;
    toyotaFactory.setDefaultColor("Silver");
    toyotaFactory.setDefaultBrand("Lexus");
    
    Vehicle* updatedCar = toyotaFactory.createVehicle();
    if (updatedCar) {
        updatedCar->displayInfo();
        delete updatedCar;
    }
    
    // Still create other vehicles normally
    std::cout << std::endl << "Client: Creating other vehicles..." << std::endl;
    Vehicle* motorcycle = motorcycleFactory.createVehicle();
    if (motorcycle) {
        motorcycle->displayInfo();
        delete motorcycle;
    }
    
    Vehicle* truck = truckFactory.createVehicle();
    if (truck) {
        truck->displayInfo();
        delete truck;
    }
    
    std::cout << std::endl << "=== Demo Complete ===" << std::endl;
}

void test(){
factory* f = new MotorcycleFactory();
Vehicle* motorcycle = f.createVehicle();
    motorcycle->setNumTires(2);
    if (motorcycle) {
        motorcycle->displayInfo();
        delete motorcycle;
    }
delete f;

}

void KyleMain(){
    // Create factories
    

    MotorcycleFactory a;
    Vehicle* motorcycle = a.createVehicle();
    motorcycle->setNumTires(2);
    if (motorcycle) {
        motorcycle->displayInfo();
        delete motorcycle;
    }

    //otherwise we can now interface with motorcycle as follows (but keep in mind you need to include motorcycle.h):
    Motorcycle* m = a.createMotorcycle();
    m->displayInfo();

    TruckFactory b ;
    Truck* truck = b.createTruck();
    truck->start();
    truck->foo();

    //Truck* truckPtr = dynamic_cast<Truck*>(truck); //cannot do this because we have not included "truck.h"
    //if (truckPtr) {
    //     truckPtr->foo();  // Now you can call foo()
    //     std::cout << "Successfully called truck-specific method!" << std::endl;
    // } else {
    //     std::cout << "Cast failed - not a truck!" << std::endl;
    // }

    delete m;
    delete truck;   
}


int main() {
 
    KyleMain();
    //test();
    return 0;
}