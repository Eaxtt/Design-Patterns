#ifndef ONLINE_BANK_ACCOUNT_H
#define ONLINE_BANK_ACCOUNT_H

#include <string>
using namespace std;

// SUBJECT - The common interface for RealSubject and Proxy
// This defines the interface that both RealOnlineBankAccount and ProxyOnlineBankAccount must implement
// Clients work with this interface, allowing Proxy to substitute for RealSubject
class OnlineBankAccount {
public:
    virtual ~OnlineBankAccount() {}
    
    // Interface methods that both Real and Proxy must implement
    virtual bool login(string username, string password) = 0;
    virtual bool pay(string to, string from, int amount) = 0;
    virtual int getBalance() = 0;
};

#endif