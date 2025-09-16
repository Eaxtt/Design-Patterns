#include "ChatRoom.h"
#include "ChatUser.h"
#include <iostream>

int main() {
    std::cout << "=== Mediator Pattern Demo - Chat Room ===" << std::endl << std::endl;
    
    // Create the mediator (chat room)
    ChatRoom chatRoom;
    
    // Create users
    ChatUser alice(&chatRoom, "Alice");
    ChatUser bob(&chatRoom, "Bob");
    ChatUser charlie(&chatRoom, "Charlie");
    
    std::cout << std::endl << "--- Adding users to chat room ---" << std::endl;
    
    // Add users to chat room
    chatRoom.addUser(&alice);
    chatRoom.addUser(&bob);
    
    std::cout << std::endl << "--- Users sending messages ---" << std::endl;
    
    // Users communicate through the mediator
    alice.sendMessage("Hello everyone!");
    bob.sendMessage("Hi Alice, how are you?");
    
    std::cout << std::endl << "--- Another user joins ---" << std::endl;
    
    // Add another user
    chatRoom.addUser(&charlie);
    
    std::cout << std::endl << "--- More messages ---" << std::endl;
    
    charlie.sendMessage("Hey guys, what's up?");
    alice.sendMessage("Welcome Charlie!");
    
    std::cout << std::endl << "--- User leaves ---" << std::endl;
    
    // Remove a user
    chatRoom.removeUser(&bob);
    
    std::cout << std::endl << "--- Final messages ---" << std::endl;
    
    alice.sendMessage("Goodbye Bob!");
    charlie.sendMessage("See you later!");
    
    std::cout << std::endl << "=== Demo completed ===" << std::endl;
    
    return 0;
}