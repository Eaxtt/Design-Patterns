#include "Subject.h"
#include "Observer.h"

Subject::Subject() {
    // Vector is automatically initialized
}

Subject::~Subject() {
    // Don't delete observers - they manage their own lifecycle
}

bool Subject::attach(Observer* observer) {
    if (observer == nullptr) {
        return false;
    }
    
    observers.push_back(observer);
    observer->setSubject(this);
    return true;
}

bool Subject::detach(Observer* observer) {
    if (observer == nullptr) {
        return false;
    }
    
    bool found = false;
    std::vector<Observer*>::iterator it = observers.begin();
    
    while ((it != observers.end()) && (!found)) {
        if (*it == observer) {
            found = true;
            observers.erase(it);
        } else {
            ++it;
        }
    }
    
    return found;
}

void Subject::notify() {
    std::vector<Observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update();
    }
}