#include <iostream>
#include <vector>
#include "Spreadsheet.h"
#include "SumCalculator.h"
#include "AverageCalculator.h"
#include "StatisticsDisplay.h"
#include "CellLinker.h"

void displayMenu() {
    std::cout << "\n=== SPREADSHEET OBSERVER DEMO ===" << std::endl;
    std::cout << "1. Set cell value" << std::endl;
    std::cout << "2. Clear cell value" << std::endl;
    std::cout << "3. Display grid" << std::endl;
    std::cout << "4. Display all statistics" << std::endl;
    std::cout << "5. Add pre-defined test data" << std::endl;
    std::cout << "6. Create cell link (A=B)" << std::endl;
    std::cout << "7. Remove cell link" << std::endl;
    std::cout << "8. Display all cell links" << std::endl;
    std::cout << "9. Toggle cell link active/inactive" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choice: ";
}

void displayAllStatistics(SumCalculator* sum, AverageCalculator* avg, StatisticsDisplay* stats) {
    std::cout << "\n=== ALL STATISTICS ===" << std::endl;
    sum->displaySummary();
    avg->displayAverage();
    stats->displayStatistics();
    std::cout << "======================" << std::endl;
}

void addTestData(Spreadsheet* spreadsheet) {
    std::cout << "\nAdding test data..." << std::endl;
    spreadsheet->setValue(0, 0, 10);
    spreadsheet->setValue(0, 1, 20);
    spreadsheet->setValue(1, 0, 5);
    spreadsheet->setValue(1, 1, 15);
    spreadsheet->setValue(2, 2, 100);
    std::cout << "Test data added!" << std::endl;
}

void displayAllLinks(const std::vector<CellLinker*>& cellLinkers) {
    std::cout << "\n=== CELL LINKS ===" << std::endl;
    if (cellLinkers.empty()) {
        std::cout << "No cell links created." << std::endl;
    } else {
        for (size_t i = 0; i < cellLinkers.size(); i++) {
            std::cout << i << ": ";
            cellLinkers[i]->displayLink();
        }
    }
    std::cout << "==================" << std::endl;
}

int main() {
    const int GRID_SIZE = 5;
    
    // Create the subject (spreadsheet)
    Spreadsheet* spreadsheet = new Spreadsheet(GRID_SIZE);
    
    // Create observers
    SumCalculator* sumCalc = new SumCalculator();
    AverageCalculator* avgCalc = new AverageCalculator();
    StatisticsDisplay* statsDisplay = new StatisticsDisplay();
    
    // Vector to store cell linkers
    std::vector<CellLinker*> cellLinkers;
    
    // Attach observers to the subject
    spreadsheet->attach(sumCalc);
    spreadsheet->attach(avgCalc);
    spreadsheet->attach(statsDisplay);
    
    std::cout << "Spreadsheet Observer Pattern Demo" << std::endl;
    std::cout << "Grid size: " << GRID_SIZE << "x" << GRID_SIZE << std::endl;
    std::cout << "Observers attached: SumCalculator, AverageCalculator, StatisticsDisplay" << std::endl;
    
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                int row, col, value;
                std::cout << "Enter row (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> row;
                std::cout << "Enter column (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> col;
                std::cout << "Enter value: ";
                std::cin >> value;
                
                if (!spreadsheet->setValue(row, col, value)) {
                    std::cout << "Invalid position!" << std::endl;
                }
                break;
            }
            case 2: {
                int row, col;
                std::cout << "Enter row (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> row;
                std::cout << "Enter column (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> col;
                
                if (!spreadsheet->clearValue(row, col)) {
                    std::cout << "Invalid position!" << std::endl;
                }
                break;
            }
            case 3: {
                spreadsheet->displayGrid();
                break;
            }
            case 4: {
                displayAllStatistics(sumCalc, avgCalc, statsDisplay);
                break;
            }
            case 5: {
                addTestData(spreadsheet);
                break;
            }
            case 6: {
                int srcRow, srcCol, tgtRow, tgtCol;
                std::cout << "Enter source cell row (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> srcRow;
                std::cout << "Enter source cell column (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> srcCol;
                std::cout << "Enter target cell row (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> tgtRow;
                std::cout << "Enter target cell column (0-" << (GRID_SIZE-1) << "): ";
                std::cin >> tgtCol;
                
                if (srcRow >= 0 && srcRow < GRID_SIZE && srcCol >= 0 && srcCol < GRID_SIZE &&
                    tgtRow >= 0 && tgtRow < GRID_SIZE && tgtCol >= 0 && tgtCol < GRID_SIZE) {
                    
                    CellLinker* linker = new CellLinker(srcRow, srcCol, tgtRow, tgtCol);
                    spreadsheet->attach(linker);
                    cellLinkers.push_back(linker);
                    
                    std::cout << "Cell link created: (" << tgtRow << "," << tgtCol 
                              << ") = (" << srcRow << "," << srcCol << ")" << std::endl;
                    
                    // Trigger initial update if source has value
                    if (spreadsheet->hasValueAt(srcRow, srcCol)) {
                        linker->update();
                    }
                } else {
                    std::cout << "Invalid cell positions!" << std::endl;
                }
                break;
            }
            case 7: {
                if (cellLinkers.empty()) {
                    std::cout << "No cell links to remove." << std::endl;
                    break;
                }
                
                displayAllLinks(cellLinkers);
                int linkIndex;
                std::cout << "Enter link index to remove: ";
                std::cin >> linkIndex;
                
                if (linkIndex >= 0 && linkIndex < static_cast<int>(cellLinkers.size())) {
                    CellLinker* linker = cellLinkers[linkIndex];
                    spreadsheet->detach(linker);
                    delete linker;
                    cellLinkers.erase(cellLinkers.begin() + linkIndex);
                    std::cout << "Cell link removed." << std::endl;
                } else {
                    std::cout << "Invalid link index!" << std::endl;
                }
                break;
            }
            case 8: {
                displayAllLinks(cellLinkers);
                break;
            }
            case 9: {
                if (cellLinkers.empty()) {
                    std::cout << "No cell links available." << std::endl;
                    break;
                }
                
                displayAllLinks(cellLinkers);
                int linkIndex;
                std::cout << "Enter link index to toggle: ";
                std::cin >> linkIndex;
                
                if (linkIndex >= 0 && linkIndex < static_cast<int>(cellLinkers.size())) {
                    CellLinker* linker = cellLinkers[linkIndex];
                    bool currentState = linker->getIsActive();
                    linker->setActive(!currentState);
                    std::cout << "Link " << (!currentState ? "activated" : "deactivated") << "." << std::endl;
                } else {
                    std::cout << "Invalid link index!" << std::endl;
                }
                break;
            }
            case 0: {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
        
    } while (choice != 0);
    
    // Clean up memory
    for (CellLinker* linker : cellLinkers) {
        delete linker;
    }
    delete sumCalc;
    delete avgCalc;
    delete statsDisplay;
    delete spreadsheet;
    
    return 0;
}