#ifndef CELLLINKER_H
#define CELLLINKER_H

#include "Observer.h"

class Spreadsheet;

class CellLinker : public Observer {
private:
    int sourceRow;
    int sourceCol;
    int targetRow;
    int targetCol;
    bool isActive;

public:
    CellLinker(int srcRow, int srcCol, int tgtRow, int tgtCol);
    virtual ~CellLinker();
    
    virtual void update();
    void displayLink();
    
    // Getters
    int getSourceRow() const;
    int getSourceCol() const;
    int getTargetRow() const;
    int getTargetCol() const;
    bool getIsActive() const;
    
    // Setters
    void setSourceCell(int row, int col);
    void setTargetCell(int row, int col);
    void setActive(bool active);
};

#endif