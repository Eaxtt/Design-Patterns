#ifndef CHATUSER_H
#define CHATUSER_H

#include "User.h"

// Concrete Colleague - Chat User
class ChatUser : public User {
public:
    ChatUser(Mediator* med, const std::string& userName);
    
    void sendMessage(const std::string& message) override;
    void receiveMessage(const std::string& from, const std::string& message) override;
    void userJoined(const std::string& userName) override;
    void userLeft(const std::string& userName) override;
};

#endif