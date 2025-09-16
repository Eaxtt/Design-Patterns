#include "ChatRoom.h"
#include "User.h"
#include <algorithm>
#include <iostream>

void ChatRoom::addUser(User* user) {
    users.push_back(user);
    std::cout << "[SYSTEM] " << user->getName() << " joined the chat room." << std::endl;
    
    // Notify all existing users about the new user
    for (User* existingUser : users) {
        if (existingUser != user) {
            existingUser->userJoined(user->getName());
        }
    }
}

void ChatRoom::removeUser(User* user) {
    auto it = std::find(users.begin(), users.end(), user);
    if (it != users.end()) {
        users.erase(it);
        std::cout << "[SYSTEM] " << user->getName() << " left the chat room." << std::endl;
        
        // Notify remaining users
        for (User* remainingUser : users) {
            remainingUser->userLeft(user->getName());
        }
    }
}

void ChatRoom::notify(User* sender, const std::string& event, const std::string& message) {
    if (event == "message") {
        // Broadcast message to all users except sender
        for (User* user : users) {
            if (user != sender) {
                user->receiveMessage(sender->getName(), message);
            }
        }
    }
}