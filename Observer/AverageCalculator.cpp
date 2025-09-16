#include "AverageCalculator.h"
#include "Spreadsheet.h"
#include <iostream>

AverageCalculator::AverageCalculator() : Observer() {
    currentAverage = 0.0;
    totalSum = 0;
    cellCount = 0;
}

AverageCalculator::~AverageCalculator() {
    // Base class destructor handles subject cleanup
}

void AverageCalculator::update() {
    std::cout << "AverageCalculator: Recalculating..." << std::endl;
    
    if (subject == nullptr) {
        return;
    }
    
    // Cast subject to Spreadsheet to access specific methods
    Spreadsheet* spreadsheet = dynamic_cast<Spreadsheet*>(subject);
    if (spreadsheet == nullptr) {
        return;
    }
    
    totalSum = 0;
    cellCount = 0;
    
    int size = spreadsheet->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (spreadsheet->hasValueAt(i, j)) {
                totalSum += spreadsheet->getValue(i, j);
                cellCount++;
            }
        }
    }
    
    if (cellCount > 0) {
        currentAverage = static_cast<double>(totalSum) / cellCount;
    } else {
        currentAverage = 0.0;
    }
    
    displayAverage();
}

double AverageCalculator::getAverage() {
    return currentAverage;
}

void AverageCalculator::displayAverage() {
    if (cellCount > 0) {
        std::cout << "AVERAGE CALCULATOR: Average = " << currentAverage 
                  << " (from " << cellCount << " cells)" << std::endl;
    } else {
        std::cout << "AVERAGE CALCULATOR: No data available" << std::endl;
    }
}