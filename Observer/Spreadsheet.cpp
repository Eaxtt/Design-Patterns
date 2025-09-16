#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int gridSize) : Subject(), size(gridSize) {
    // Allocate memory for grid
    grid = new int*[size];
    hasValue = new bool*[size];
    
    for (int i = 0; i < size; i++) {
        grid[i] = new int[size];
        hasValue[i] = new bool[size];
        
        // Initialize all cells as empty
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
            hasValue[i][j] = false;
        }
    }
}

Spreadsheet::~Spreadsheet() {
    // Clean up memory
    for (int i = 0; i < size; i++) {
        delete[] grid[i];
        delete[] hasValue[i];
    }
    delete[] grid;
    delete[] hasValue;
}

bool Spreadsheet::isValidPosition(int row, int col) {
    return (row >= 0 && row < size && col >= 0 && col < size);
}

bool Spreadsheet::setValue(int row, int col, int value) {
    if (!isValidPosition(row, col)) {
        return false;
    }
    
    grid[row][col] = value;
    hasValue[row][col] = true;
    
    std::cout << "Cell (" << row << "," << col << ") set to " << value << std::endl;
    notify();  // Notify all observers
    
    return true;
}

bool Spreadsheet::clearValue(int row, int col) {
    if (!isValidPosition(row, col)) {
        return false;
    }
    
    grid[row][col] = 0;
    hasValue[row][col] = false;
    
    std::cout << "Cell (" << row << "," << col << ") cleared" << std::endl;
    notify();  // Notify all observers
    
    return true;
}

int Spreadsheet::getValue(int row, int col) {
    if (!isValidPosition(row, col)) {
        return 0;
    }
    
    return grid[row][col];
}

bool Spreadsheet::hasValueAt(int row, int col) {
    if (!isValidPosition(row, col)) {
        return false;
    }
    
    return hasValue[row][col];
}

void Spreadsheet::displayGrid() {
    std::cout << "\n=== SPREADSHEET GRID ===" << std::endl;
    std::cout << "   ";
    for (int j = 0; j < size; j++) {
        std::cout << "  " << j << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i < size; i++) {
        std::cout << i << ": ";
        for (int j = 0; j < size; j++) {
            if (hasValue[i][j]) {
                std::cout << "[" << grid[i][j] << "]";
                if (grid[i][j] < 10) std::cout << " ";
            } else {
                std::cout << "[ ] ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "========================" << std::endl;
}

int Spreadsheet::getSize() {
    return size;
}