#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

// Forward declaration
class Observer;

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    Subject();
    virtual ~Subject();
    
    virtual bool attach(Observer* observer);
    virtual bool detach(Observer* observer);
    virtual void notify();
};

#endif