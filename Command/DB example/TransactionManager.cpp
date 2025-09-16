#include "TransactionManager.h"
#include <iostream>

TransactionManager::TransactionManager() : inTransaction(false) {
    std::cout << "Transaction Manager initialized.\n";
}

TransactionManager::~TransactionManager() {
    // Clean up any remaining commands
    for (Command* cmd : commandHistory) {
        delete cmd;
    }
    for (Command* cmd : currentBatch) {
        delete cmd;
    }
    std::cout << "Transaction Manager shutting down.\n";
}

// Execute a single command immediately (or add to batch if in transaction)
void TransactionManager::executeCommand(Command* command) {
    if (inTransaction) {
        // Add to batch instead of executing immediately
        currentBatch.push_back(command);
        std::cout << "Added " << command->getDescription() << " to current transaction.\n";
    } else {
        // Execute immediately and add to history
        std::cout << "Executing " << command->getDescription() << "...\n";
        command->execute();
        commandHistory.push_back(command);
        std::cout << "Command executed and added to history.\n";
    }
}

// Undo the last executed command
void TransactionManager::undoLastCommand() {
    if (commandHistory.empty()) {
        std::cout << "No commands to undo.\n";
        return;
    }
    
    Command* lastCommand = commandHistory.back();
    std::cout << "Undoing last command: " << lastCommand->getDescription() << "\n";
    lastCommand->undo();
    
    // Remove from history and clean up
    commandHistory.pop_back();
    delete lastCommand;
    std::cout << "Command undone and removed from history.\n";
}

// Start a transaction (batch mode)
void TransactionManager::beginTransaction() {
    if (inTransaction) {
        std::cout << "Already in a transaction. Commit or rollback first.\n";
        return;
    }
    
    inTransaction = true;
    std::cout << "Transaction started. Commands will be batched until commit/rollback.\n";
}

// Execute all commands in the current batch
void TransactionManager::commitTransaction() {
    if (!inTransaction) {
        std::cout << "No active transaction to commit.\n";
        return;
    }
    
    std::cout << "Committing transaction with " << currentBatch.size() << " commands...\n";
    
    // Execute all batched commands
    for (Command* cmd : currentBatch) {
        std::cout << "  Executing " << cmd->getDescription() << "...\n";
        cmd->execute();
        commandHistory.push_back(cmd);  // Add to history for undo
    }
    
    currentBatch.clear();  // Clear the batch (commands now in history)
    inTransaction = false;
    std::cout << "Transaction committed successfully.\n";
}

// Discard all commands in the current batch
void TransactionManager::rollbackTransaction() {
    if (!inTransaction) {
        std::cout << "No active transaction to rollback.\n";
        return;
    }
    
    std::cout << "Rolling back transaction. Discarding " << currentBatch.size() << " commands...\n";
    
    // Clean up all batched commands without executing them
    for (Command* cmd : currentBatch) {
        delete cmd;
    }
    
    currentBatch.clear();
    inTransaction = false;
    std::cout << "Transaction rolled back successfully.\n";
}

// Display command history
void TransactionManager::showHistory() const {
    std::cout << "\n=== COMMAND HISTORY ===\n";
    if (commandHistory.empty()) {
        std::cout << "No commands in history.\n";
    } else {
        for (size_t i = 0; i < commandHistory.size(); ++i) {
            std::cout << (i + 1) << ". " << commandHistory[i]->getDescription() << "\n";
        }
    }
    
    if (inTransaction && !currentBatch.empty()) {
        std::cout << "\nCurrent Transaction (not yet committed):\n";
        for (size_t i = 0; i < currentBatch.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << currentBatch[i]->getDescription() << "\n";
        }
    }
    std::cout << "=====================\n\n";
}

// Clear all command history
void TransactionManager::clearHistory() {
    for (Command* cmd : commandHistory) {
        delete cmd;
    }
    commandHistory.clear();
    std::cout << "Command history cleared.\n";
}

// Get size of command history
int TransactionManager::getHistorySize() const {
    return commandHistory.size();
}

// Check if currently in a transaction
bool TransactionManager::isInTransaction() const {
    return inTransaction;
}