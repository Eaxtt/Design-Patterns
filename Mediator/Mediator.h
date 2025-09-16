#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

// Forward declaration
class User;

// Abstract Mediator interface
class Mediator {
public:
    virtual ~Mediator() {}
    virtual void notify(User* sender, const std::string& event, const std::string& message = "") = 0;
};

#endif