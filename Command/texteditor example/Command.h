#ifndef COMMAND_H
#define COMMAND_H

// Command interface - declares execute() and undo() operations
// This is the main participant that defines the contract for all commands
class Command {
public:
    virtual ~Command() {}
    
    // Execute the command - required by Command pattern
    virtual void execute() = 0;
    
    // Undo the command - useful for practical applications
    virtual void undo() = 0;
    
    // Get description of what this command does
    virtual const char* getDescription() const = 0;
};

#endif