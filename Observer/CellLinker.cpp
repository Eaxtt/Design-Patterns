#include "CellLinker.h"
#include "Spreadsheet.h"
#include <iostream>

CellLinker::CellLinker(int srcRow, int srcCol, int tgtRow, int tgtCol) : Observer() {
    sourceRow = srcRow;
    sourceCol = srcCol;
    targetRow = tgtRow;
    targetCol = tgtCol;
    isActive = true;
}

CellLinker::~CellLinker() {
    // Base class destructor handles subject cleanup
}

void CellLinker::update() {
    if (!isActive || subject == nullptr) {
        return;
    }
    
    // Cast subject to Spreadsheet to access specific methods
    Spreadsheet* spreadsheet = dynamic_cast<Spreadsheet*>(subject);
    if (spreadsheet == nullptr) {
        return;
    }
    
    // Check if source cell has a value
    if (spreadsheet->hasValueAt(sourceRow, sourceCol)) {
        int sourceValue = spreadsheet->getValue(sourceRow, sourceCol);
        
        std::cout << "CellLinker: Linking cell (" << targetRow << "," << targetCol 
                  << ") to value " << sourceValue << " from cell (" 
                  << sourceRow << "," << sourceCol << ")" << std::endl;
        
        // Temporarily disable this observer to prevent infinite recursion
        isActive = false;
        
        // Update the target cell with the source value
        spreadsheet->setValue(targetRow, targetCol, sourceValue);
        
        // Re-enable this observer
        isActive = true;
    } else {
        // If source cell is cleared, clear the target cell too
        std::cout << "CellLinker: Clearing linked cell (" << targetRow << "," << targetCol 
                  << ") because source cell (" << sourceRow << "," << sourceCol 
                  << ") was cleared" << std::endl;
        
        // Temporarily disable this observer to prevent infinite recursion
        isActive = false;
        
        // Clear the target cell
        spreadsheet->clearValue(targetRow, targetCol);
        
        // Re-enable this observer
        isActive = true;
    }
}

void CellLinker::displayLink() {
    std::cout << "CELL LINK: (" << targetRow << "," << targetCol 
              << ") = (" << sourceRow << "," << sourceCol << ")";
    if (isActive) {
        std::cout << " [ACTIVE]" << std::endl;
    } else {
        std::cout << " [INACTIVE]" << std::endl;
    }
}

// Getters
int CellLinker::getSourceRow() const {
    return sourceRow;
}

int CellLinker::getSourceCol() const {
    return sourceCol;
}

int CellLinker::getTargetRow() const {
    return targetRow;
}

int CellLinker::getTargetCol() const {
    return targetCol;
}

bool CellLinker::getIsActive() const {
    return isActive;
}

// Setters
void CellLinker::setSourceCell(int row, int col) {
    sourceRow = row;
    sourceCol = col;
}

void CellLinker::setTargetCell(int row, int col) {
    targetRow = row;
    targetCol = col;
}

void CellLinker::setActive(bool active) {
    isActive = active;
}