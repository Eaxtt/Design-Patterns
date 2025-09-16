#include "Sorter.h"
#include <memory>

void demonstrateSorter(Sorter* sorter, const std::string& sorterName) {
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << sorterName << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    
    // Test data
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    // Test ascending sort
    std::cout << "\nAscending sort:" << std::endl;
    std::vector<int> ascData = data;
    sorter->sort(ascData, SortOrder::ASCENDING);
    
    // Test descending sort
    std::cout << "\nDescending sort:" << std::endl;
    std::vector<int> descData = data;
    sorter->sort(descData, SortOrder::DESCENDING);
}

int main() {
    std::cout << "Template Pattern - Sorting Algorithms Demo" << std::endl;
    std::cout << "==========================================" << std::endl;
    
    // Create different sorters
    std::unique_ptr<Sorter> bubbleSorter = std::make_unique<BubbleSorter>();
    std::unique_ptr<Sorter> selectionSorter = std::make_unique<SelectionSorter>();
    std::unique_ptr<Sorter> insertionSorter = std::make_unique<InsertionSorter>();
    
    // Demonstrate each sorting algorithm
    demonstrateSorter(bubbleSorter.get(), "Bubble Sorter");
    demonstrateSorter(selectionSorter.get(), "Selection Sorter");
    demonstrateSorter(insertionSorter.get(), "Insertion Sorter");
    
    std::cout << "\n" << std::string(40, '=') << std::endl;
    std::cout << "Template Pattern Benefits:" << std::endl;
    std::cout << "- Same sorting process for all algorithms" << std::endl;
    std::cout << "- Easy to add new sorting algorithms" << std::endl;
    std::cout << "- Consistent output formatting" << std::endl;
    std::cout << "- Shared helper methods (shouldSwap, printArray)" << std::endl;
    std::cout << std::string(40, '=') << std::endl;
    
    return 0;
}