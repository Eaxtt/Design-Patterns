#ifndef EDITORINVOKER_H
#define EDITORINVOKER_H

#include "Command.h"
#include <vector>

// Invoker class - manages and executes commands
// This class doesn't know what the commands do, just how to execute them
class EditorInvoker {
private:
    std::vector<Command*> history;    // Command history for undo
    std::vector<Command*> undoStack;  // Stack for redo functionality
    int currentPos;                   // Current position in history
    
public:
    EditorInvoker();
    ~EditorInvoker();
    
    // Execute a command and add it to history
    void executeCommand(Command* command);
    
    // Undo the last command
    bool undo();
    
    // Redo a previously undone command  
    bool redo();
    
    // Show command history
    void showHistory() const;
    
    // Clear all history (cleanup)
    void clearHistory();
    
    // Check if undo/redo is available
    bool canUndo() const;
    bool canRedo() const;
};

#endif