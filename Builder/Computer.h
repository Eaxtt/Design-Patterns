// Product
// Represents the complex object under construction.
// Includes classes that define the constituent parts.

#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class Computer {
private:
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string storage;
    std::string motherboard;
    std::string powerSupply;
    std::string caseType;

public:
    void setCPU(const std::string& cpu);
    void setGPU(const std::string& gpu);
    void setRAM(const std::string& ram);
    void setStorage(const std::string& storage);
    void setMotherboard(const std::string& motherboard);
    void setPowerSupply(const std::string& powerSupply);
    void setCaseType(const std::string& caseType);
    
    void display() const;
};

#endif