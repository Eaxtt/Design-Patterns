#include "ConcreteCommands.h"
#include <iostream>

// ============ INSERT COMMAND ============
InsertCommand::InsertCommand(Database* db, const char* name, int age) 
    : database(db), name(name), age(age), insertedId(-1), executed(false) {}

void InsertCommand::execute() {
    if (!executed) {
        insertedId = database->insertRecord(name, age);
        executed = true;
    } else {
        std::cout << "Insert command already executed.\n";
    }
}

void InsertCommand::undo() {
    if (executed && insertedId != -1) {
        database->deleteRecord(insertedId);
        std::cout << "Undid insert: removed record ID=" << insertedId << "\n";
        executed = false;
    } else {
        std::cout << "Cannot undo: Insert command not executed or failed.\n";
    }
}

const char* InsertCommand::getDescription() const {
    return "INSERT command";
}

// ============ UPDATE COMMAND ============
UpdateCommand::UpdateCommand(Database* db, int id, const char* newName, int newAge)
    : database(db), recordId(id), newName(newName), newAge(newAge), 
      originalRecord(nullptr), executed(false) {}

UpdateCommand::~UpdateCommand() {
    delete originalRecord;  // Clean up stored record
}

void UpdateCommand::execute() {
    if (!executed) {
        // Store original record for undo
        originalRecord = database->getRecordCopy(recordId);
        if (originalRecord && database->updateRecord(recordId, newName, newAge)) {
            executed = true;
        } else {
            std::cout << "Update command failed to execute.\n";
            delete originalRecord;
            originalRecord = nullptr;
        }
    } else {
        std::cout << "Update command already executed.\n";
    }
}

void UpdateCommand::undo() {
    if (executed && originalRecord) {
        database->updateRecord(recordId, originalRecord->name, originalRecord->age);
        std::cout << "Undid update: restored record ID=" << recordId << "\n";
        executed = false;
    } else {
        std::cout << "Cannot undo: Update command not executed or failed.\n";
    }
}

const char* UpdateCommand::getDescription() const {
    return "UPDATE command";
}

// ============ DELETE COMMAND ============
DeleteCommand::DeleteCommand(Database* db, int id)
    : database(db), recordId(id), deletedRecord(nullptr), executed(false) {}

DeleteCommand::~DeleteCommand() {
    delete deletedRecord;  // Clean up stored record
}

void DeleteCommand::execute() {
    if (!executed) {
        // Store record before deleting for undo
        deletedRecord = database->getRecordCopy(recordId);
        if (deletedRecord && database->deleteRecord(recordId)) {
            executed = true;
        } else {
            std::cout << "Delete command failed to execute.\n";
            delete deletedRecord;
            deletedRecord = nullptr;
        }
    } else {
        std::cout << "Delete command already executed.\n";
    }
}

void DeleteCommand::undo() {
    if (executed && deletedRecord) {
        database->insertRecord(deletedRecord->name, deletedRecord->age);
        std::cout << "Undid delete: restored record ID=" << recordId << "\n";
        executed = false;
    } else {
        std::cout << "Cannot undo: Delete command not executed or failed.\n";
    }
}

const char* DeleteCommand::getDescription() const {
    return "DELETE command";
}

// ============ SELECT COMMAND ============
SelectCommand::SelectCommand(Database* db, int id) : database(db), recordId(id) {}

void SelectCommand::execute() {
    if (recordId == -1) {
        // Select all records
        database->displayAll();
    } else {
        // Select specific record
        database->displayRecord(recordId);
    }
}

void SelectCommand::undo() {
    // Select operations don't need undo - they're read-only
    std::cout << "Select operations cannot be undone (read-only).\n";
}

const char* SelectCommand::getDescription() const {
    return "SELECT command";
}