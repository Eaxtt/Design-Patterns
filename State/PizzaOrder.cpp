#include "PizzaOrder.h"
#include "ConcreteStates.h"

PizzaOrder::PizzaOrder(const std::string& name, int id) 
    : customerName(name), orderId(id), totalPrice(0.0), isCancelled(false) {
    currentState = new ProcessingPaymentState();
}

PizzaOrder::~PizzaOrder() {
    delete currentState;
}

void PizzaOrder::setState(OrderState* state) {
    delete currentState;
    currentState = state;
}

void PizzaOrder::processOrder() {
    currentState->processOrder(this);
}

void PizzaOrder::cancelOrder() {
    currentState->cancelOrder(this);
}

void PizzaOrder::displayStatus() {
    currentState->displayStatus(this);
}

std::string PizzaOrder::getCurrentState() const {
    return currentState->getStateName();
}

bool PizzaOrder::canModifyOrder() const {
    return currentState->canModifyOrder();
}

bool PizzaOrder::canCancel() const {
    return currentState->canCancel();
}

int PizzaOrder::getEstimatedTime() const {
    return currentState->getEstimatedTime();
}

std::string PizzaOrder::getCustomerName() const {
    return customerName;
}

std::vector<std::string> PizzaOrder::getToppings() const {
    return toppings;
}

int PizzaOrder::getOrderId() const {
    return orderId;
}

double PizzaOrder::getTotalPrice() const {
    return totalPrice;
}

bool PizzaOrder::getIsCancelled() const {
    return isCancelled;
}

void PizzaOrder::addTopping(const std::string& topping) {
    if (canModifyOrder()) {
        toppings.push_back(topping);
        totalPrice += 2.50; // Each topping costs $2.50
        std::cout << "Added " << topping << " to order. New total: $" << totalPrice << std::endl;
    } else {
        std::cout << "Cannot modify order in current state: " << getCurrentState() << std::endl;
    }
}

void PizzaOrder::setTotalPrice(double price) {
    totalPrice = price;
}

void PizzaOrder::setCancelled(bool cancelled) {
    isCancelled = cancelled;
}

void PizzaOrder::displayOrderInfo() const {
    std::cout << "Order #" << orderId << " for " << customerName << std::endl;
    std::cout << "Current State: " << getCurrentState() << std::endl;
    std::cout << "Total Price: $" << totalPrice << std::endl;
    std::cout << "Estimated Time: " << getEstimatedTime() << " minutes" << std::endl;
    std::cout << "Can Modify: " << (canModifyOrder() ? "Yes" : "No") << std::endl;
    std::cout << "Can Cancel: " << (canCancel() ? "Yes" : "No") << std::endl;
    std::cout << "Toppings: ";
    if (toppings.empty()) {
        std::cout << "None";
    } else {
        for (size_t i = 0; i < toppings.size(); ++i) {
            std::cout << toppings[i];
            if (i < toppings.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
}