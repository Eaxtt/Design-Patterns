#include "EditorInvoker.h"
#include <iostream>

EditorInvoker::EditorInvoker() : currentPos(-1) {}

EditorInvoker::~EditorInvoker() {
    clearHistory();
}

// Execute a command and add it to history
void EditorInvoker::executeCommand(Command* command) {
    if (command == nullptr) return;
    
    // Execute the command
    command->execute();
    
    // Clear any redo history since we're making a new change
    // Don't delete commands in undoStack - they're still in history
    undoStack.clear();
    
    // Remove any commands after current position (if we're in middle of history)
    while ((int)history.size() > currentPos + 1) {
        delete history.back();
        history.pop_back();
    }
    
    // Add command to history
    history.push_back(command);
    currentPos++;
    
    std::cout << "Executed: " << command->getDescription() << std::endl;
}

// Undo the last command
bool EditorInvoker::undo() {
    if (!canUndo()) {
        std::cout << "Nothing to undo!" << std::endl;
        return false;
    }
    
    Command* command = history[currentPos];
    command->undo();
    
    // Move the command to undo stack (don't delete it, it's still in history)
    undoStack.push_back(command);
    currentPos--;
    
    std::cout << "Undone: " << command->getDescription() << std::endl;
    return true;
}

// Redo a previously undone command
bool EditorInvoker::redo() {
    if (!canRedo()) {
        std::cout << "Nothing to redo!" << std::endl;
        return false;
    }
    
    Command* command = undoStack.back();
    undoStack.pop_back();
    command->execute();
    currentPos++;
    
    std::cout << "Redone: " << command->getDescription() << std::endl;
    return true;
}

// Show command history
void EditorInvoker::showHistory() const {
    std::cout << "\n=== Command History ===" << std::endl;
    if (history.empty()) {
        std::cout << "No commands executed yet." << std::endl;
        return;
    }
    
    for (int i = 0; i < (int)history.size(); ++i) {
        std::cout << i << ": " << history[i]->getDescription();
        if (i == currentPos) {
            std::cout << " <-- Current";
        }
        std::cout << std::endl;
    }
    
    if (!undoStack.empty()) {
        std::cout << "Redo stack has " << undoStack.size() << " commands." << std::endl;
    }
    std::cout << "=====================\n" << std::endl;
}

// Clear all history
void EditorInvoker::clearHistory() {
    // Delete all commands in history
    for (Command* cmd : history) {
        delete cmd;
    }
    history.clear();
    
    // Clear undo stack (commands were already deleted above)
    undoStack.clear();
    
    currentPos = -1;
}

// Check if undo is available
bool EditorInvoker::canUndo() const {
    return currentPos >= 0;
}

// Check if redo is available
bool EditorInvoker::canRedo() const {
    return !undoStack.empty();
}