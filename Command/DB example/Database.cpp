#include "Database.h"

Database::Database() : nextId(1) {
    std::cout << "Database initialized.\n";
}

Database::~Database() {
    std::cout << "Database shutting down.\n";
}

// Insert a new record and return its ID
int Database::insertRecord(const char* name, int age) {
    int id = nextId++;
    records.push_back(Record(id, name, age));
    std::cout << "Inserted record: ID=" << id << ", Name=" << name << ", Age=" << age << "\n";
    return id;
}

// Update an existing record
bool Database::updateRecord(int id, const char* name, int age) {
    for (auto& record : records) {
        if (record.id == id) {
            std::cout << "Updated record ID=" << id << " from (Name=" << record.name 
                      << ", Age=" << record.age << ") to (Name=" << name << ", Age=" << age << ")\n";
            record.name = name;
            record.age = age;
            return true;
        }
    }
    std::cout << "Update failed: Record ID=" << id << " not found.\n";
    return false;
}

// Delete a record
bool Database::deleteRecord(int id) {
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->id == id) {
            std::cout << "Deleted record: ID=" << id << ", Name=" << it->name << ", Age=" << it->age << "\n";
            records.erase(it);
            return true;
        }
    }
    std::cout << "Delete failed: Record ID=" << id << " not found.\n";
    return false;
}

// Find a record by ID
Record* Database::findRecord(int id) {
    for (auto& record : records) {
        if (record.id == id) {
            return &record;
        }
    }
    return nullptr;
}

// Display all records
void Database::displayAll() const {
    std::cout << "\n=== DATABASE CONTENTS ===\n";
    if (records.empty()) {
        std::cout << "Database is empty.\n";
    } else {
        for (const auto& record : records) {
            std::cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << "\n";
        }
    }
    std::cout << "========================\n\n";
}

// Display a specific record
void Database::displayRecord(int id) const {
    for (const auto& record : records) {
        if (record.id == id) {
            std::cout << "Record found - ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << "\n";
            return;
        }
    }
    std::cout << "Record ID=" << id << " not found.\n";
}

// Get number of records
int Database::getRecordCount() const {
    return records.size();
}

// Get a copy of a record for undo purposes
Record* Database::getRecordCopy(int id) const {
    for (const auto& record : records) {
        if (record.id == id) {
            return new Record(record.id, record.name, record.age);
        }
    }
    return nullptr;
}