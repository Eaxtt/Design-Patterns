// ConcreteBuilder
// Builds the product's internal representation and defines the process
// by which it is assembled.
// Defines and keeps track of the representation it creates.
// Provides an interface for retrieving the product.

#include "ConcreteBuilders.h"

// GamingPCBuilder Implementation
GamingPCBuilder::GamingPCBuilder() {
    computer = new Computer();
}

GamingPCBuilder::~GamingPCBuilder() {
    delete computer;
}

// buildPart() - Build individual parts with gaming-specific specifications
void GamingPCBuilder::buildCPU() {
    computer->setCPU("Intel Core i9-13900K (24 cores, 5.8GHz)");
}

void GamingPCBuilder::buildGPU() {
    computer->setGPU("NVIDIA RTX 4090 24GB");
}

void GamingPCBuilder::buildRAM() {
    computer->setRAM("64GB DDR5 6000MHz");
}

void GamingPCBuilder::buildStorage() {
    computer->setStorage("2TB NVMe SSD + 4TB HDD");
}

void GamingPCBuilder::buildMotherboard() {
    computer->setMotherboard("ASUS ROG Maximus Z790");
}

void GamingPCBuilder::buildPowerSupply() {
    computer->setPowerSupply("1000W 80+ Platinum Modular");
}

void GamingPCBuilder::buildCase() {
    computer->setCaseType("Lian Li O11 Dynamic RGB");
}

// getResult() - Returns the constructed product
Computer* GamingPCBuilder::getComputer() {
    return computer;
}

// OfficePCBuilder Implementation
OfficePCBuilder::OfficePCBuilder() {
    computer = new Computer();
}

OfficePCBuilder::~OfficePCBuilder() {
    delete computer;
}

// buildPart() - Build individual parts with office-specific specifications
void OfficePCBuilder::buildCPU() {
    computer->setCPU("Intel Core i5-12400 (6 cores, 4.4GHz)");
}

void OfficePCBuilder::buildGPU() {
    computer->setGPU("Integrated Intel UHD Graphics 730");
}

void OfficePCBuilder::buildRAM() {
    computer->setRAM("16GB DDR4 3200MHz");
}

void OfficePCBuilder::buildStorage() {
    computer->setStorage("512GB NVMe SSD");
}

void OfficePCBuilder::buildMotherboard() {
    computer->setMotherboard("MSI B660M Pro");
}

void OfficePCBuilder::buildPowerSupply() {
    computer->setPowerSupply("450W 80+ Bronze");
}

void OfficePCBuilder::buildCase() {
    computer->setCaseType("Fractal Design Define Mini");
}

// getResult() - Returns the constructed product
Computer* OfficePCBuilder::getComputer() {
    return computer;
}

// ServerBuilder Implementation
ServerBuilder::ServerBuilder() {
    computer = new Computer();
}

ServerBuilder::~ServerBuilder() {
    delete computer;
}

// buildPart() - Build individual parts with server-specific specifications
void ServerBuilder::buildCPU() {
    computer->setCPU("AMD EPYC 7763 (64 cores, 3.5GHz)");
}

void ServerBuilder::buildGPU() {
    computer->setGPU("None (Server grade)");
}

void ServerBuilder::buildRAM() {
    computer->setRAM("256GB ECC DDR4 3200MHz");
}

void ServerBuilder::buildStorage() {
    computer->setStorage("8x 4TB SSD in RAID 10");
}

void ServerBuilder::buildMotherboard() {
    computer->setMotherboard("Supermicro H12SSL-i");
}

void ServerBuilder::buildPowerSupply() {
    computer->setPowerSupply("Dual 1600W Redundant PSU");
}

void ServerBuilder::buildCase() {
    computer->setCaseType("4U Rackmount Server Chassis");
}

// getResult() - Returns the constructed product
Computer* ServerBuilder::getComputer() {
    return computer;
}