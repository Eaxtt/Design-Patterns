#ifndef SUMCALCULATOR_H
#define SUMCALCULATOR_H

#include "Observer.h"

class Spreadsheet;

class SumCalculator : public Observer {
private:
    int totalSum;
    int cellCount;

public:
    SumCalculator();
    virtual ~SumCalculator();
    
    virtual void update();
    int getTotalSum();
    int getCellCount();
    void displaySummary();
};

#endif