// Director
// Constructs an object using the Builder interface.

#include "TechnicianAssembler.h"
#include <iostream>

TechnicianAssembler::TechnicianAssembler(ComputerBuilder* builder) {
    this->builder = builder;
}

void TechnicianAssembler::setBuilder(ComputerBuilder* builder) {
    this->builder = builder;
}

// construct() - Orchestrates the construction process
// Calls the builder's methods in the proper sequence to build the product
void TechnicianAssembler::constructComputer() {
    std::cout << "Starting computer assembly..." << std::endl;
    builder->buildMotherboard();
    builder->buildCPU();
    builder->buildRAM();
    builder->buildGPU();
    builder->buildStorage();
    builder->buildPowerSupply();
    builder->buildCase();
    std::cout << "Computer assembly complete!" << std::endl;
}