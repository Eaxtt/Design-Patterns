#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <vector>

enum class SortOrder {
    ASCENDING,
    DESCENDING
};

// Base class with template method
class Sorter {
public:
    // Template method - defines the sorting process
    void sort(std::vector<int>& data, SortOrder order = SortOrder::ASCENDING) {
        if (data.empty()) {
            std::cout << "No data to sort!" << std::endl;
            return;
        }
        
        std::cout << "Starting sort..." << std::endl;
        printArray(data, "Before");
        
        // The actual sorting algorithm (implemented by subclasses)
        doSort(data, order);
        
        std::cout << "Sort completed!" << std::endl;
        printArray(data, "After");
    }

protected:
    // Helper method to print array
    void printArray(const std::vector<int>& data, const std::string& label) {
        std::cout << label << ": ";
        for (int val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    // Helper method to compare based on sort order
    bool shouldSwap(int a, int b, SortOrder order) {
        if (order == SortOrder::ASCENDING) {
            return a > b;
        } else {
            return a < b;
        }
    }
    
    // Abstract method - each sorter implements its own algorithm
    virtual void doSort(std::vector<int>& data, SortOrder order) = 0;
    
    virtual ~Sorter() = default;
};

// Bubble Sort implementation
class BubbleSorter : public Sorter {
protected:
    void doSort(std::vector<int>& data, SortOrder order) override {
        std::cout << "Using Bubble Sort algorithm" << std::endl;
        
        int n = data.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (shouldSwap(data[j], data[j + 1], order)) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Selection Sort implementation
class SelectionSorter : public Sorter {
protected:
    void doSort(std::vector<int>& data, SortOrder order) override {
        std::cout << "Using Selection Sort algorithm" << std::endl;
        
        int n = data.size();
        for (int i = 0; i < n - 1; i++) {
            int targetIndex = i;
            
            for (int j = i + 1; j < n; j++) {
                if (shouldSwap(data[targetIndex], data[j], order)) {
                    targetIndex = j;
                }
            }
            
            if (targetIndex != i) {
                std::swap(data[i], data[targetIndex]);
            }
        }
    }
};

// Insertion Sort implementation
class InsertionSorter : public Sorter {
protected:
    void doSort(std::vector<int>& data, SortOrder order) override {
        std::cout << "Using Insertion Sort algorithm" << std::endl;
        
        int n = data.size();
        for (int i = 1; i < n; i++) {
            int key = data[i];
            int j = i - 1;
            
            while (j >= 0 && shouldSwap(data[j], key, order)) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }
};

#endif