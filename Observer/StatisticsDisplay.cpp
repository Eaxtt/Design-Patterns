#include "StatisticsDisplay.h"
#include "Spreadsheet.h"
#include <iostream>
#include <limits>

StatisticsDisplay::StatisticsDisplay() : Observer() {
    minValue = 0;
    maxValue = 0;
    totalCells = 0;
    hasData = false;
}

StatisticsDisplay::~StatisticsDisplay() {
    // Base class destructor handles subject cleanup
}

void StatisticsDisplay::update() {
    std::cout << "StatisticsDisplay: Updating statistics..." << std::endl;
    
    if (subject == nullptr) {
        return;
    }
    
    // Cast subject to Spreadsheet to access specific methods
    Spreadsheet* spreadsheet = dynamic_cast<Spreadsheet*>(subject);
    if (spreadsheet == nullptr) {
        return;
    }
    
    totalCells = 0;
    hasData = false;
    minValue = std::numeric_limits<int>::max();
    maxValue = std::numeric_limits<int>::min();
    
    int size = spreadsheet->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (spreadsheet->hasValueAt(i, j)) {
                int value = spreadsheet->getValue(i, j);
                totalCells++;
                
                if (!hasData) {
                    minValue = value;
                    maxValue = value;
                    hasData = true;
                } else {
                    if (value < minValue) {
                        minValue = value;
                    }
                    if (value > maxValue) {
                        maxValue = value;
                    }
                }
            }
        }
    }
    
    displayStatistics();
}

void StatisticsDisplay::displayStatistics() {
    if (hasData) {
        std::cout << "STATISTICS: Min = " << minValue 
                  << ", Max = " << maxValue 
                  << ", Total cells = " << totalCells << std::endl;
    } else {
        std::cout << "STATISTICS: No data available" << std::endl;
    }
}

int StatisticsDisplay::getMinValue() {
    return hasData ? minValue : 0;
}

int StatisticsDisplay::getMaxValue() {
    return hasData ? maxValue : 0;
}

int StatisticsDisplay::getTotalCells() {
    return totalCells;
}