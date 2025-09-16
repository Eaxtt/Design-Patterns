#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include "Command.h"
#include <vector>

// Command Pattern Participant: Invoker
// This class asks commands to carry out requests
// It can also queue/log requests and support undoable operations
class TransactionManager {
private:
    std::vector<Command*> commandHistory;  // For undo functionality
    std::vector<Command*> currentBatch;    // For transaction batching
    bool inTransaction;                    // Track if we're in a transaction
    
public:
    TransactionManager();
    ~TransactionManager();
    
    // Core invoker functionality
    void executeCommand(Command* command);     // Execute a single command
    void undoLastCommand();                    // Undo the last executed command
    
    // Transaction support (batch operations)
    void beginTransaction();                   // Start collecting commands
    void commitTransaction();                  // Execute all batched commands
    void rollbackTransaction();                // Discard batched commands
    
    // Utility functions
    void showHistory() const;                  // Display command history
    void clearHistory();                       // Clear undo history
    int getHistorySize() const;
    bool isInTransaction() const;
};

#endif