#ifndef PIZZA_ORDER_H
#define PIZZA_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "OrderState.h"

class PizzaOrder {
private:
    OrderState* currentState;
    std::string customerName;
    std::vector<std::string> toppings;
    int orderId;
    double totalPrice;
    bool isCancelled;

public:
    PizzaOrder(const std::string& name, int id);
    ~PizzaOrder();
    
    // State management
    void setState(OrderState* state);
    void processOrder();
    void cancelOrder();
    void displayStatus();
    std::string getCurrentState() const;
    
    // Order operations (delegated to state)
    bool canModifyOrder() const;
    bool canCancel() const;
    int getEstimatedTime() const;
    
    // Getters
    std::string getCustomerName() const;
    std::vector<std::string> getToppings() const;
    int getOrderId() const;
    double getTotalPrice() const;
    bool getIsCancelled() const;
    
    // Setters
    void addTopping(const std::string& topping);
    void setTotalPrice(double price);
    void setCancelled(bool cancelled);
    void displayOrderInfo() const;
};

#endif