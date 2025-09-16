#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "Subject.h"
#include <iostream>

class Spreadsheet : public Subject {
private:
    int size;
    int** grid;
    bool** hasValue;

public:
    Spreadsheet(int gridSize);
    virtual ~Spreadsheet();
    
    bool setValue(int row, int col, int value);
    bool clearValue(int row, int col);
    int getValue(int row, int col);
    bool hasValueAt(int row, int col);
    void displayGrid();
    int getSize();
    
private:
    bool isValidPosition(int row, int col);
};

#endif