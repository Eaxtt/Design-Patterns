#ifndef STAFF_HANDLER_H
#define STAFF_HANDLER_H

#include <string>

// Handler (Chain of Responsibility Pattern participant)
class StaffHandler {
protected:
    StaffHandler* successor;
    std::string department;
    
public:
    StaffHandler(std::string dept);
    virtual ~StaffHandler();
    
    void setSuccessor(StaffHandler* next);
    virtual void handleRequest(std::string requestType, std::string details);
    
protected:
    virtual void processRequest(std::string details);
};

#endif