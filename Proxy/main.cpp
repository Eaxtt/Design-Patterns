#include <iostream>
#include <unistd.h>  // for sleep()
#include "ProxyOnlineBankAccount.h"
using namespace std;

void demonstrateProxyPattern() {
    cout << "========================================" << endl;
    cout << "PROXY DESIGN PATTERN DEMONSTRATION" << endl;
    cout << "========================================\n" << endl;
    
    // CLIENT uses the PROXY, not the RealSubject directly
    // The client doesn't know (and doesn't care) that it's using a proxy
    cout << "CLIENT: Creating bank account interface..." << endl;
    OnlineBankAccount* account = new ProxyOnlineBankAccount();
    
    cout << "\n--- Test 1: Failed Login (Wrong Credentials) ---" << endl;
    account->login("alice", "wrongpassword");
    
    cout << "\n--- Test 2: Successful Login ---" << endl;
    account->login("alice", "secret123");
    
    cout << "\n--- Test 3: Check Balance ---" << endl;
    int balance = account->getBalance();
    cout << "CLIENT received balance: $" << balance << endl;
    
    cout << "\n--- Test 4: Make Payment ---" << endl;
    account->pay("Bob", "alice", 100);
    
    cout << "\n--- Test 5: Check Balance Again ---" << endl;
    balance = account->getBalance();
    cout << "CLIENT received balance: $" << balance << endl;
    
    // Simulate time passing for session timeout
    cout << "\n--- Test 6: Session Timeout ---" << endl;
    cout << "CLIENT: Waiting 3 seconds to simulate timeout..." << endl;
    sleep(3);
    cout << "CLIENT: Trying to make payment after delay..." << endl;
    account->pay("Charlie", "alice", 50);
    
    cout << "\n--- Test 7: Multiple Failed Login Attempts ---" << endl;
    OnlineBankAccount* account2 = new ProxyOnlineBankAccount();
    account2->login("hacker", "wrong1");
    account2->login("hacker", "wrong2");
    account2->login("hacker", "wrong3");
    account2->login("hacker", "wrong4");  // Should be blocked
    
    cout << "\n========================================" << endl;
    cout << "PATTERN PARTICIPANTS SUMMARY:" << endl;
    cout << "========================================" << endl;
    cout << "SUBJECT (Interface): OnlineBankAccount" << endl;
    cout << "  - Defines common interface for Proxy and RealSubject" << endl;
    cout << "  - Methods: login(), pay(), getBalance()" << endl;
    cout << "\nREALSUBJECT: RealOnlineBankAccount" << endl;
    cout << "  - The actual object that does the real work" << endl;
    cout << "  - Performs actual banking operations" << endl;
    cout << "\nPROXY: ProxyOnlineBankAccount" << endl;
    cout << "  - Controls access to RealSubject" << endl;
    cout << "  - Adds: security checks, session management, logging" << endl;
    cout << "  - Maintains reference to RealSubject" << endl;
    cout << "  - Creates RealSubject lazily (on-demand)" << endl;
    cout << "  - Delegates to RealSubject after validation" << endl;
    cout << "\nCLIENT: main()" << endl;
    cout << "  - Uses Subject interface (OnlineBankAccount*)" << endl;
    cout << "  - Doesn't know it's using a Proxy" << endl;
    cout << "========================================\n" << endl;
    
    delete account;
    delete account2;
}

void demonstrateVirtualProxy() {
    cout << "\n========================================" << endl;
    cout << "BONUS: VIRTUAL PROXY EXAMPLE" << endl;
    cout << "========================================\n" << endl;
    
    cout << "Virtual Proxy delays creating expensive objects." << endl;
    cout << "In our example, RealSubject is only created on login," << endl;
    cout << "not when ProxyOnlineBankAccount is constructed!" << endl;
    
    cout << "\nStep 1: Create Proxy (cheap)" << endl;
    OnlineBankAccount* proxy = new ProxyOnlineBankAccount();
    
    cout << "\nStep 2: Try to use it without login" << endl;
    proxy->getBalance();  // RealSubject still not created
    
    cout << "\nStep 3: Login triggers RealSubject creation" << endl;
    proxy->login("alice", "secret123");  // NOW RealSubject is created
    
    cout << "\nStep 4: Now operations work" << endl;
    proxy->getBalance();
    
    delete proxy;
}

int main() {
    demonstrateProxyPattern();
    demonstrateVirtualProxy();
    
    cout << "\n========================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "========================================" << endl;
    cout << "1. Proxy provides same interface as RealSubject" << endl;
    cout << "2. Proxy adds extra functionality (protection/lazy loading)" << endl;
    cout << "3. Proxy delegates to RealSubject for actual work" << endl;
    cout << "4. Client is unaware it's using a Proxy" << endl;
    cout << "5. Types: Protection, Virtual, Remote, Smart Reference" << endl;
    cout << "========================================\n" << endl;
    
    return 0;
}