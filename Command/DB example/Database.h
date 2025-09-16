#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>

// Simple record structure to simulate database entries
struct Record {
    int id;
    const char* name;
    int age;
    
    Record(int id, const char* name, int age) : id(id), name(name), age(age) {}
};

// Command Pattern Participant: Receiver
// This class knows how to perform the operations associated with carrying out requests
// As noted in your lecture: "Any class may serve as a Receiver"
class Database {
private:
    std::vector<Record> records;  // Our "database" storage
    int nextId;                   // Auto-increment ID counter
    
public:
    Database();
    ~Database();
    
    // Database operations that commands will invoke
    // These are the actual operations that do the work
    int insertRecord(const char* name, int age);    // Returns the ID of inserted record
    bool updateRecord(int id, const char* name, int age);  // Returns success/failure
    bool deleteRecord(int id);                      // Returns success/failure
    Record* findRecord(int id);                     // Returns pointer to record or nullptr
    
    // Utility functions
    void displayAll() const;
    void displayRecord(int id) const;
    int getRecordCount() const;
    
    // Functions to help with undo operations
    Record* getRecordCopy(int id) const;  // Get a copy for undo purposes
};

#endif