#include "ChatUser.h"
#include "Mediator.h"
#include <iostream>

ChatUser::ChatUser(Mediator* med, const std::string& userName) 
    : User(med, userName) {
}

//changed()
void ChatUser::sendMessage(const std::string& message) {
    std::cout << name << " sends: " << message << std::endl;
    mediator->notify(this, "message", message);
}

void ChatUser::receiveMessage(const std::string& from, const std::string& message) {
    std::cout << name << " received from " << from << ": " << message << std::endl;
}

void ChatUser::userJoined(const std::string& userName) {
    std::cout << name << " notices: " << userName << " joined the room" << std::endl;
}

void ChatUser::userLeft(const std::string& userName) {
    std::cout << name << " notices: " << userName << " left the room" << std::endl;
}