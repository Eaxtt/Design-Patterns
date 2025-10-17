#ifndef REAL_ONLINE_BANK_ACCOUNT_H
#define REAL_ONLINE_BANK_ACCOUNT_H

#include "OnlineBankAccount.h"
#include <string>
using namespace std;

// REALSUBJECT - The real object that the Proxy represents
// This does the actual work - real banking operations
// The Proxy will delegate to this object after performing its own checks
class RealOnlineBankAccount : public OnlineBankAccount {
private:
    string currentUser;
    int balance;
    bool loggedIn;

public:
    RealOnlineBankAccount();
    ~RealOnlineBankAccount();
    
    // Implementation of Subject interface - actual banking logic
    bool login(string username, string password) override;
    bool pay(string to, string from, int amount) override;
    int getBalance() override;
};

#endif