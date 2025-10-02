// Director
// Constructs an object using the Builder interface.

#ifndef TECHNICIANASSEMBLER_H
#define TECHNICIANASSEMBLER_H

#include "ComputerBuilder.h"

class TechnicianAssembler {
private:
    ComputerBuilder* builder;
    
public:
    TechnicianAssembler(ComputerBuilder* builder);
    void setBuilder(ComputerBuilder* builder);
    
    // construct() - Orchestrates the construction process using the builder
    void constructComputer();
};

#endif