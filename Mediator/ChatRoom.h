#ifndef CHATROOM_H
#define CHATROOM_H

#include "Mediator.h"
#include <vector>
#include <string>

class User;

// Concrete Mediator - Chat Room
class ChatRoom : public Mediator {
private:
    std::vector<User*> users;
    
public:
    void addUser(User* user);
    void removeUser(User* user);
    void notify(User* sender, const std::string& event, const std::string& message = "") override;
};

#endif