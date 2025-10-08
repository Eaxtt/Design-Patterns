#include "StaffHandler.h"
#include <iostream>

StaffHandler::StaffHandler(std::string dept) 
    : successor(0), department(dept) {}

StaffHandler::~StaffHandler() {
    // Note: successor is not deleted here to avoid double deletion
    // The chain owner is responsible for cleanup
}

void StaffHandler::setSuccessor(StaffHandler* next) {
    successor = next;
}

void StaffHandler::handleRequest(std::string requestType, std::string details) {
    // Extract department from requestType (format: "department:action")
    std::string requestDept = requestType.substr(0, requestType.find(':'));
    
    if (requestDept == department) {
        // This handler can process the request
        processRequest(details);
    } else if (successor != 0) {
        // Pass to successor
        std::cout << department << " staff: Not my department, passing along...\n";
        successor->handleRequest(requestType, details);
    } else {
        // No one can handle it
        std::cout << "Sorry, no staff member available to help with: " 
                  << requestType << "\n";
    }
}

void StaffHandler::processRequest(std::string details) {
    std::cout << department << " staff: I can help with that!\n";
}