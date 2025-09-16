#include "User.h"
#include "Mediator.h"

User::User(Mediator* med, const std::string& userName) 
    : mediator(med), name(userName) {
}