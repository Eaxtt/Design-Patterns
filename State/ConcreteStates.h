#ifndef CONCRETE_STATES_H
#define CONCRETE_STATES_H

#include "OrderState.h"

class ProcessingPaymentState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class PreppingIngredientsState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class AssemblingPizzaState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class BakingState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class ReadyForDeliveryState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class DeliveredState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

class CancelledState : public OrderState {
public:
    void processOrder(PizzaOrder* order) override;
    void cancelOrder(PizzaOrder* order) override;
    void displayStatus(PizzaOrder* order) override;
    std::string getStateName() const override;
    bool canModifyOrder() const override;
    bool canCancel() const override;
    int getEstimatedTime() const override;
};

#endif