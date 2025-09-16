#ifndef AVERAGECALCULATOR_H
#define AVERAGECALCULATOR_H

#include "Observer.h"

class Spreadsheet;

class AverageCalculator : public Observer {
private:
    double currentAverage;
    int totalSum;
    int cellCount;

public:
    AverageCalculator();
    virtual ~AverageCalculator();
    
    virtual void update();
    double getAverage();
    void displayAverage();
};

#endif