#include "Database.h"
#include "ConcreteCommands.h"
#include "TransactionManager.h"
#include <iostream>

void printMenu() {
    std::cout << "\n========== DATABASE COMMAND SYSTEM ==========\n";
    std::cout << "1. Insert Record (INSERT INTO table)\n";
    std::cout << "2. Update Record (UPDATE table SET)\n";
    std::cout << "3. Delete Record (DELETE FROM table)\n";
    std::cout << "4. Select Record by ID (SELECT * FROM table WHERE id = ?)\n";
    std::cout << "5. Select All Records (SELECT * FROM table)\n";
    std::cout << "6. Undo Last Command\n";
    std::cout << "7. Begin Transaction\n";
    std::cout << "8. Commit Transaction\n";
    std::cout << "9. Rollback Transaction\n";
    std::cout << "10. Show Command History\n";
    std::cout << "11. Clear History\n";
    std::cout << "0. Exit\n";
    std::cout << "=============================================\n";
    std::cout << "Enter choice: ";
}

void demonstratePattern() {
    std::cout << "=== COMMAND PATTERN DEMONSTRATION ===\n";
    std::cout << "This demonstrates the Command Pattern with:\n";
    std::cout << "• Command: Abstract base class with execute() and undo()\n";
    std::cout << "• ConcreteCommands: InsertCommand, UpdateCommand, DeleteCommand, SelectCommand\n";
    std::cout << "• Receiver: Database class that performs the actual work\n";
    std::cout << "• Invoker: TransactionManager that executes commands and manages history\n";
    std::cout << "• Client: This main() function that creates and configures commands\n\n";
}

int main() {
    // Command Pattern Participant: Client (Application)
    // The client creates ConcreteCommand objects and sets their Receiver
    
    demonstratePattern();
    
    // Create the Receiver
    Database* db = new Database();
    
    // Create the Invoker
    TransactionManager* txManager = new TransactionManager();
    
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        Command* command = nullptr;  // Will hold our command objects
        
        switch (choice) {
            case 1: {  // Insert Record
                char* name = new char[100];
                int age;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter age: ";
                std::cin >> age;
                
                // Client creates ConcreteCommand and sets its Receiver
                command = new InsertCommand(db, name, age);
                txManager->executeCommand(command);
                break;
            }
            
            case 2: {  // Update Record
                int id, age;
                char* name = new char[100];
                std::cout << "Enter record ID to update: ";
                std::cin >> id;
                std::cout << "Enter new name: ";
                std::cin >> name;
                std::cout << "Enter new age: ";
                std::cin >> age;
                
                // Client creates ConcreteCommand and sets its Receiver
                command = new UpdateCommand(db, id, name, age);
                txManager->executeCommand(command);
                break;
            }
            
            case 3: {  // Delete Record
                int id;
                std::cout << "Enter record ID to delete: ";
                std::cin >> id;
                
                // Client creates ConcreteCommand and sets its Receiver
                command = new DeleteCommand(db, id);
                txManager->executeCommand(command);
                break;
            }
            
            case 4: {  // Select Record
                int id;
                std::cout << "Enter record ID to select: ";
                std::cin >> id;
                
                // Client creates ConcreteCommand and sets its Receiver
                command = new SelectCommand(db, id);
                txManager->executeCommand(command);
                break;
            }
            
            case 5: {  // Select All
                // Client creates ConcreteCommand and sets its Receiver
                command = new SelectCommand(db);  // Default parameter selects all
                txManager->executeCommand(command);
                break;
            }
            
            case 6: {  // Undo Last Command
                txManager->undoLastCommand();
                break;
            }
            
            case 7: {  // Begin Transaction
                txManager->beginTransaction();
                break;
            }
            
            case 8: {  // Commit Transaction
                txManager->commitTransaction();
                break;
            }
            
            case 9: {  // Rollback Transaction
                txManager->rollbackTransaction();
                break;
            }
            
            case 10: {  // Show History
                txManager->showHistory();
                break;
            }
            
            case 11: {  // Clear History
                txManager->clearHistory();
                break;
            }
            
            case 0: {  // Exit
                std::cout << "Goodbye!\n";
                delete db;
                delete txManager;
                return 0;
            }
            
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    
    return 0;
}