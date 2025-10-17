#include "RealOnlineBankAccount.h"
#include <iostream>
using namespace std;

// REALSUBJECT Implementation - This is the "expensive" or "sensitive" object
// that we want to protect/control access to via the Proxy

RealOnlineBankAccount::RealOnlineBankAccount() 
    : currentUser(""), balance(1000), loggedIn(false) {
    cout << "[RealSubject] RealOnlineBankAccount created (expensive operation)" << endl;
}

RealOnlineBankAccount::~RealOnlineBankAccount() {
    cout << "[RealSubject] RealOnlineBankAccount destroyed" << endl;
}

// The REAL login logic - validates credentials and establishes session
bool RealOnlineBankAccount::login(string username, string password) {
    cout << "[RealSubject] Performing actual login for: " << username << endl;
    
    // Simulate database validation
    if (username == "alice" && password == "secret123") {
        currentUser = username;
        loggedIn = true;
        cout << "[RealSubject] Login successful!" << endl;
        return true;
    }
    
    cout << "[RealSubject] Login failed - invalid credentials" << endl;
    return false;
}

// The REAL payment logic - performs actual transaction
bool RealOnlineBankAccount::pay(string to, string from, int amount) {
    cout << "[RealSubject] Processing payment: $" << amount 
         << " from " << from << " to " << to << endl;
    
    if (!loggedIn) {
        cout << "[RealSubject] Error: Not logged in" << endl;
        return false;
    }
    
    if (balance >= amount) {
        balance -= amount;
        cout << "[RealSubject] Payment successful! New balance: $" << balance << endl;
        return true;
    }
    
    cout << "[RealSubject] Payment failed - insufficient funds" << endl;
    return false;
}

// The REAL balance retrieval
int RealOnlineBankAccount::getBalance() {
    if (!loggedIn) {
        cout << "[RealSubject] Error: Not logged in" << endl;
        return -1;
    }
    
    cout << "[RealSubject] Returning balance: $" << balance << endl;
    return balance;
}