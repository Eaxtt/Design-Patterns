// Product
// Represents the complex object under construction.
// Includes classes that define the constituent parts.

#include "Computer.h"
#include <iostream>

void Computer::setCPU(const std::string& cpu) {
    this->cpu = cpu;
}

void Computer::setGPU(const std::string& gpu) {
    this->gpu = gpu;
}

void Computer::setRAM(const std::string& ram) {
    this->ram = ram;
}

void Computer::setStorage(const std::string& storage) {
    this->storage = storage;
}

void Computer::setMotherboard(const std::string& motherboard) {
    this->motherboard = motherboard;
}

void Computer::setPowerSupply(const std::string& powerSupply) {
    this->powerSupply = powerSupply;
}

void Computer::setCaseType(const std::string& caseType) {
    this->caseType = caseType;
}

void Computer::display() const {
    std::cout << "\n=== Computer Specifications ===" << std::endl;
    std::cout << "CPU: " << cpu << std::endl;
    std::cout << "GPU: " << gpu << std::endl;
    std::cout << "RAM: " << ram << std::endl;
    std::cout << "Storage: " << storage << std::endl;
    std::cout << "Motherboard: " << motherboard << std::endl;
    std::cout << "Power Supply: " << powerSupply << std::endl;
    std::cout << "Case Type: " << caseType << std::endl;
    std::cout << "================================\n" << std::endl;
}