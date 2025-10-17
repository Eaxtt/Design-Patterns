#ifndef PROXY_ONLINE_BANK_ACCOUNT_H
#define PROXY_ONLINE_BANK_ACCOUNT_H

#include "OnlineBankAccount.h"
#include "RealOnlineBankAccount.h"
#include <string>
#include <ctime>
using namespace std;

// PROXY - The surrogate that controls access to the RealSubject
// Key responsibilities:
// 1. Maintains a reference to RealSubject (realSubject pointer)
// 2. Controls access via security checks, timeouts, etc.
// 3. May create/delete the RealSubject (lazy initialization)
// 4. Forwards requests to RealSubject after performing checks
class ProxyOnlineBankAccount : public OnlineBankAccount {
private:
    // Reference to the RealSubject - the Proxy delegates to this
    RealOnlineBankAccount* realSubject;
    
    // Proxy-specific state for access control
    long maxSessionTime;    // Maximum session duration in seconds
    time_t startTime;        // When session started
    bool loggedIn;           // Track login state
    int failedAttempts;      // Security: count failed login attempts

public:
    ProxyOnlineBankAccount();
    ~ProxyOnlineBankAccount();
    
    // Same interface as Subject - but adds protection logic
    bool login(string username, string password) override;
    bool pay(string to, string from, int amount) override;
    int getBalance() override;

private:
    // Proxy helper methods for access control
    bool isSessionValid();
    void logSecurityEvent(string event);
};

#endif