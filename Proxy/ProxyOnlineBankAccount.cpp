#include "ProxyOnlineBankAccount.h"
#include <iostream>
using namespace std;

// PROXY Implementation - Controls access to RealSubject

ProxyOnlineBankAccount::ProxyOnlineBankAccount() 
    : realSubject(nullptr), maxSessionTime(30), startTime(0), 
      loggedIn(false), failedAttempts(0) {
    cout << "[Proxy] ProxyOnlineBankAccount created (lightweight)" << endl;
    cout << "[Proxy] RealSubject NOT created yet (lazy initialization)" << endl;
}

ProxyOnlineBankAccount::~ProxyOnlineBankAccount() {
    cout << "[Proxy] Cleaning up..." << endl;
    // Proxy is responsible for managing RealSubject lifecycle
    if (realSubject != nullptr) {
        delete realSubject;
    }
}

// PROXY login - Adds security checks BEFORE delegating to RealSubject
bool ProxyOnlineBankAccount::login(string username, string password) {
    cout << "\n[Proxy] Login request received for: " << username << endl;
    
    // PROTECTION: Check for too many failed attempts
    if (failedAttempts >= 3) {
        logSecurityEvent("Account locked due to failed attempts");
        cout << "[Proxy] BLOCKED - Too many failed login attempts!" << endl;
        return false;
    }
    
    // PROTECTION: Validate input (example: prevent empty credentials)
    if (username.empty() || password.empty()) {
        logSecurityEvent("Login attempt with empty credentials");
        cout << "[Proxy] BLOCKED - Invalid credentials format" << endl;
        failedAttempts++;
        return false;
    }
    
    // If already logged in, clean up old session
    if (loggedIn && realSubject != nullptr) {
        cout << "[Proxy] Ending previous session..." << endl;
        delete realSubject;
        realSubject = nullptr;
    }
    
    // LAZY INITIALIZATION: Create RealSubject only when needed
    if (realSubject == nullptr) {
        cout << "[Proxy] Creating RealSubject (on-demand)..." << endl;
        realSubject = new RealOnlineBankAccount();
    }
    
    // DELEGATE to RealSubject for actual login
    cout << "[Proxy] Delegating to RealSubject..." << endl;
    bool success = realSubject->login(username, password);
    
    if (success) {
        // Start tracking session
        startTime = time(nullptr);
        loggedIn = true;
        failedAttempts = 0;  // Reset on successful login
        logSecurityEvent("Successful login: " + username);
        cout << "[Proxy] Session started - valid for " << maxSessionTime << " seconds" << endl;
    } else {
        failedAttempts++;
        logSecurityEvent("Failed login attempt for: " + username);
    }
    
    return success;
}

// PROXY pay - Adds session validation BEFORE delegating to RealSubject
bool ProxyOnlineBankAccount::pay(string to, string from, int amount) {
    cout << "\n[Proxy] Payment request: $" << amount << " to " << to << endl;
    
    // PROTECTION: Check if logged in
    if (!loggedIn || realSubject == nullptr) {
        logSecurityEvent("Unauthorized payment attempt");
        cout << "[Proxy] BLOCKED - Not logged in!" << endl;
        return false;
    }
    
    // PROTECTION: Check session timeout
    if (!isSessionValid()) {
        logSecurityEvent("Session expired during payment attempt");
        cout << "[Proxy] BLOCKED - Session expired!" << endl;
        loggedIn = false;
        delete realSubject;
        realSubject = nullptr;
        return false;
    }
    
    // PROTECTION: Validate payment amount
    if (amount <= 0) {
        logSecurityEvent("Invalid payment amount: " + to_string(amount));
        cout << "[Proxy] BLOCKED - Invalid amount!" << endl;
        return false;
    }
    
    // DELEGATE to RealSubject
    cout << "[Proxy] Delegating payment to RealSubject..." << endl;
    bool success = realSubject->pay(to, from, amount);
    
    if (success) {
        logSecurityEvent("Payment successful: $" + to_string(amount) + " to " + to);
    }
    
    return success;
}

// PROXY getBalance - Adds session validation BEFORE delegating
int ProxyOnlineBankAccount::getBalance() {
    cout << "\n[Proxy] Balance request received" << endl;
    
    // PROTECTION: Check if logged in
    if (!loggedIn || realSubject == nullptr) {
        cout << "[Proxy] BLOCKED - Not logged in!" << endl;
        return -1;
    }
    
    // PROTECTION: Check session timeout
    if (!isSessionValid()) {
        cout << "[Proxy] BLOCKED - Session expired!" << endl;
        loggedIn = false;
        delete realSubject;
        realSubject = nullptr;
        return -1;
    }
    
    // DELEGATE to RealSubject
    cout << "[Proxy] Delegating to RealSubject..." << endl;
    return realSubject->getBalance();
}

// PROXY helper: Check if session is still valid
bool ProxyOnlineBankAccount::isSessionValid() {
    if (!loggedIn) return false;
    
    time_t currentTime = time(nullptr);
    long duration = currentTime - startTime;
    
    cout << "[Proxy] Session duration: " << duration << "s / " 
         << maxSessionTime << "s" << endl;
    
    return duration < maxSessionTime;
}

// PROXY helper: Log security events
void ProxyOnlineBankAccount::logSecurityEvent(string event) {
    cout << "[Proxy Security Log] " << event << endl;
}