#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "RequestParser.h"
#include "StaffHandler.h"

// Client class - initiates requests
class Customer {
private:
    std::string name;
    RequestParser parser;
    
public:
    Customer(std::string customerName);
    
    void askForHelp(std::string request, StaffHandler* firstStaff);
};

#endif