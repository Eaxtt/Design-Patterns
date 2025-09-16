#ifndef CONCRETE_COMMANDS_H
#define CONCRETE_COMMANDS_H

#include "Command.h"
#include "Database.h"

// Command Pattern Participant: ConcreteCommand classes
// These define bindings between Receiver objects and actions
// They implement execute() by invoking corresponding operations on Receiver

// INSERT Command - Adds a new record to the database
class InsertCommand : public Command {
private:
    Database* database;      // Reference to receiver
    const char* name;        // Command parameters
    int age;
    int insertedId;          // Store ID for undo purposes
    bool executed;           // Track if command was executed
    
public:
    InsertCommand(Database* db, const char* name, int age);
    void execute() override;
    void undo() override;
    const char* getDescription() const override;
};

// UPDATE Command - Modifies an existing record
class UpdateCommand : public Command {
private:
    Database* database;      // Reference to receiver
    int recordId;           // Which record to update
    const char* newName;    // New values
    int newAge;
    Record* originalRecord; // Store original for undo
    bool executed;
    
public:
    UpdateCommand(Database* db, int id, const char* newName, int newAge);
    ~UpdateCommand();       // Clean up stored record
    void execute() override;
    void undo() override;
    const char* getDescription() const override;
};

// DELETE Command - Removes a record from the database
class DeleteCommand : public Command {
private:
    Database* database;      // Reference to receiver
    int recordId;           // Which record to delete
    Record* deletedRecord;  // Store deleted record for undo
    bool executed;
    
public:
    DeleteCommand(Database* db, int id);
    ~DeleteCommand();       // Clean up stored record
    void execute() override;
    void undo() override;
    const char* getDescription() const override;
};

// SELECT Command - Displays a record (read-only, no undo needed)
class SelectCommand : public Command {
private:
    Database* database;      // Reference to receiver
    int recordId;           // Which record to select (-1 for all)
    
public:
    SelectCommand(Database* db, int id = -1);  // -1 means select all
    void execute() override;
    void undo() override;   // No-op for read operations
    const char* getDescription() const override;
};

#endif