// ConcreteBuilder
// Builds the product's internal representation and defines the process
// by which it is assembled.
// Defines and keeps track of the representation it creates.
// Provides an interface for retrieving the product.

#ifndef CONCRETEBUILDERS_H
#define CONCRETEBUILDERS_H

#include "ComputerBuilder.h"

class GamingPCBuilder : public ComputerBuilder {
private:
    Computer* computer;
    
public:
    GamingPCBuilder();
    ~GamingPCBuilder();
    
    // buildPart() - Methods for building individual parts of the product
    void buildCPU();
    void buildGPU();
    void buildRAM();
    void buildStorage();
    void buildMotherboard();
    void buildPowerSupply();
    void buildCase();
    
    // getResult() - Provides an interface for retrieving the product
    Computer* getComputer();
};

class OfficePCBuilder : public ComputerBuilder {
private:
    Computer* computer;
    
public:
    OfficePCBuilder();
    ~OfficePCBuilder();
    
    // buildPart() - Methods for building individual parts of the product
    void buildCPU();
    void buildGPU();
    void buildRAM();
    void buildStorage();
    void buildMotherboard();
    void buildPowerSupply();
    void buildCase();
    
    // getResult() - Provides an interface for retrieving the product
    Computer* getComputer();
};

class ServerBuilder : public ComputerBuilder {
private:
    Computer* computer;
    
public:
    ServerBuilder();
    ~ServerBuilder();
    
    // buildPart() - Methods for building individual parts of the product
    void buildCPU();
    void buildGPU();
    void buildRAM();
    void buildStorage();
    void buildMotherboard();
    void buildPowerSupply();
    void buildCase();
    
    // getResult() - Provides an interface for retrieving the product
    Computer* getComputer();
};

#endif