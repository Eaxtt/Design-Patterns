#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class Mediator;

// Abstract Colleague (User) class
class User {
protected:
    Mediator* mediator;
    std::string name;

public:
    User(Mediator* med, const std::string& userName);
    virtual ~User() {}
    
    virtual void sendMessage(const std::string& message) = 0;
    virtual void receiveMessage(const std::string& from, const std::string& message) = 0;
    virtual void userJoined(const std::string& userName) = 0;
    virtual void userLeft(const std::string& userName) = 0;
    
    std::string getName() const { return name; }
};

#endif