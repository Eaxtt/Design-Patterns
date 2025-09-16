#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include "Observer.h"

class Spreadsheet;

class StatisticsDisplay : public Observer {
private:
    int minValue;
    int maxValue;
    int totalCells;
    bool hasData;

public:
    StatisticsDisplay();
    virtual ~StatisticsDisplay();
    
    virtual void update();
    void displayStatistics();
    int getMinValue();
    int getMaxValue();
    int getTotalCells();
};

#endif