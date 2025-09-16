#ifndef COMMAND_H
#define COMMAND_H

// Command Pattern Participant: Command (Abstract Base Class)
// This declares the interface for executing operations
// Following the GoF pattern structure from your lecture notes
class Command {
public:
    // Pure virtual function that all concrete commands must implement
    // This is the core of the Command pattern - encapsulating a request as an object
    virtual void execute() = 0;
    
    // Virtual destructor for proper cleanup of derived classes
    virtual ~Command() {}
    
    // Support for undoable operations (as mentioned in GoF intent)
    // Each command should know how to undo itself
    virtual void undo() = 0;
    
    // Get description of what this command does (useful for logging)
    virtual const char* getDescription() const = 0;
};

#endif