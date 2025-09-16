#ifndef ORDER_STATE_H
#define ORDER_STATE_H

#include <iostream>
#include <string>

class PizzaOrder; // Forward declaration

class OrderState {
public:
    virtual ~OrderState() {}
    
    // Core state functions
    virtual void processOrder(PizzaOrder* order) = 0;
    virtual void cancelOrder(PizzaOrder* order) = 0;
    virtual void displayStatus(PizzaOrder* order) = 0;
    virtual std::string getStateName() const = 0;
    
    // State-specific functions
    virtual bool canModifyOrder() const = 0;
    virtual bool canCancel() const = 0;
    virtual int getEstimatedTime() const = 0;
};

#endif