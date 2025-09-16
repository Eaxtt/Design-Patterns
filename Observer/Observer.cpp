#include "Observer.h"
#include "Subject.h"

Observer::Observer() {
    subject = nullptr;
}

Observer::~Observer() {
    if (subject != nullptr) {
        subject->detach(this);
    }
}

void Observer::setSubject(Subject* s) {
    subject = s;
}