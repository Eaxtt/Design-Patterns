#include "SumCalculator.h"
#include "Spreadsheet.h"
#include <iostream>

SumCalculator::SumCalculator() : Observer() {
    totalSum = 0;
    cellCount = 0;
}

SumCalculator::~SumCalculator() {
    // Base class destructor handles subject cleanup
}

void SumCalculator::update() {
    std::cout << "SumCalculator: Recalculating..." << std::endl;
    
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
    
    displaySummary();
}

int SumCalculator::getTotalSum() {
    return totalSum;
}

int SumCalculator::getCellCount() {
    return cellCount;
}

void SumCalculator::displaySummary() {
    std::cout << "SUM CALCULATOR: Total = " << totalSum 
              << ", Cells with values = " << cellCount << std::endl;
}