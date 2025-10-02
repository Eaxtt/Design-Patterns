// Builder
// Specifies an abstract interface for creating parts of the Product object.

#ifndef COMPUTERBUILDER_H
#define COMPUTERBUILDER_H

#include "Computer.h"

class ComputerBuilder {
public:
    virtual ~ComputerBuilder() {}
    
    // buildPart() - Methods for building individual parts of the product
    virtual void buildCPU() = 0;
    virtual void buildGPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildMotherboard() = 0;
    virtual void buildPowerSupply() = 0;
    virtual void buildCase() = 0;
    
    // getResult() - Provides an interface for retrieving the product
    virtual Computer* getComputer() = 0;
};

#endif