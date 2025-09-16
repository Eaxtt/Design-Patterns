#ifndef OBSERVER_H
#define OBSERVER_H

// Forward declaration
class Subject;

class Observer {
protected:
    Subject* subject;

public:
    Observer();
    virtual ~Observer();
    
    virtual void update() = 0;
    virtual void setSubject(Subject* s);
};

#endif