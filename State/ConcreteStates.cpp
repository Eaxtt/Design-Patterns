#include "ConcreteStates.h"
#include "PizzaOrder.h"

// ProcessingPaymentState
void ProcessingPaymentState::processOrder(PizzaOrder* order) {
    std::cout << "Processing payment for order #" << order->getOrderId() << std::endl;
    double basePrice = 12.99; // Base pizza price
    double totalPrice = basePrice + (order->getToppings().size() * 2.50);
    order->setTotalPrice(totalPrice);
    std::cout << "Payment of $" << totalPrice << " processed successfully!" << std::endl;
    std::cout << "Moving to ingredient preparation..." << std::endl;
    order->setState(new PreppingIngredientsState());
}

void ProcessingPaymentState::cancelOrder(PizzaOrder* order) {
    std::cout << "Cancelling order #" << order->getOrderId() << " - refund processed" << std::endl;
    order->setCancelled(true);
    order->setState(new CancelledState());
}

void ProcessingPaymentState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Payment being processed..." << std::endl;
    std::cout << "Please wait while we verify your payment details." << std::endl;
}

std::string ProcessingPaymentState::getStateName() const {
    return "Processing Payment";
}

bool ProcessingPaymentState::canModifyOrder() const {
    return true; // Can still modify before payment is complete
}

bool ProcessingPaymentState::canCancel() const {
    return true;
}

int ProcessingPaymentState::getEstimatedTime() const {
    return 25; // 25 minutes total from payment
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PreppingIngredientsState
void PreppingIngredientsState::processOrder(PizzaOrder* order) {
    std::cout << "Kitchen staff preparing ingredients for " << order->getCustomerName() << "'s pizza..." << std::endl;
    std::cout << "Checking inventory and gathering fresh ingredients..." << std::endl;
    std::cout << "All ingredients ready! Moving to pizza assembly..." << std::endl;
    order->setState(new AssemblingPizzaState());
}

void PreppingIngredientsState::cancelOrder(PizzaOrder* order) {
    std::cout << "Cancelling order #" << order->getOrderId() << " - minimal ingredients used, partial refund" << std::endl;
    order->setCancelled(true);
    order->setState(new CancelledState());
}

void PreppingIngredientsState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Kitchen preparing your ingredients" << std::endl;
    std::cout << "Fresh ingredients are being gathered for your pizza." << std::endl;
}

std::string PreppingIngredientsState::getStateName() const {
    return "Prepping Ingredients";
}

bool PreppingIngredientsState::canModifyOrder() const {
    return false; // Too late to modify once prep started
}

bool PreppingIngredientsState::canCancel() const {
    return true;
}

int PreppingIngredientsState::getEstimatedTime() const {
    return 20; // 20 minutes remaining
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// AssemblingPizzaState
void AssemblingPizzaState::processOrder(PizzaOrder* order) {
    std::cout << "Chef assembling pizza with toppings: ";
    std::vector<std::string> toppings = order->getToppings();
    if (toppings.empty()) {
        std::cout << "Plain cheese pizza";
    } else {
        for (size_t i = 0; i < toppings.size(); ++i) {
            std::cout << toppings[i];
            if (i < toppings.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Spreading sauce, adding cheese, and carefully placing toppings..." << std::endl;
    std::cout << "Pizza assembled perfectly! Moving to oven..." << std::endl;
    order->setState(new BakingState());
}

void AssemblingPizzaState::cancelOrder(PizzaOrder* order) {
    std::cout << "Cancelling order #" << order->getOrderId() << " - pizza partially assembled, limited refund" << std::endl;
    order->setCancelled(true);
    order->setState(new CancelledState());
}

void AssemblingPizzaState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Pizza being assembled by our chef" << std::endl;
    std::cout << "Your pizza is being carefully crafted with your selected toppings." << std::endl;
}

std::string AssemblingPizzaState::getStateName() const {
    return "Assembling Pizza";
}

bool AssemblingPizzaState::canModifyOrder() const {
    return false;
}

bool AssemblingPizzaState::canCancel() const {
    return true;
}

int AssemblingPizzaState::getEstimatedTime() const {
    return 15; // 15 minutes remaining
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// BakingState
void BakingState::processOrder(PizzaOrder* order) {
    std::cout << "Pizza in the oven - baking at 450°F..." << std::endl;
    std::cout << "Monitoring for perfect golden crust and melted cheese..." << std::endl;
    std::cout << "Pizza baked to perfection! Cooling and ready for delivery..." << std::endl;
    order->setState(new ReadyForDeliveryState());
}

void BakingState::cancelOrder(PizzaOrder* order) {
    std::cout << "Cannot cancel order #" << order->getOrderId() << " - pizza is already in the oven!" << std::endl;
    std::cout << "Order will proceed to completion." << std::endl;
}

void BakingState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Pizza baking in our wood-fired oven" << std::endl;
    std::cout << "Your pizza is cooking to golden perfection!" << std::endl;
}

std::string BakingState::getStateName() const {
    return "Baking";
}

bool BakingState::canModifyOrder() const {
    return false;
}

bool BakingState::canCancel() const {
    return false; // Cannot cancel while baking
}

int BakingState::getEstimatedTime() const {
    return 8; // 8 minutes remaining
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ReadyForDeliveryState
void ReadyForDeliveryState::processOrder(PizzaOrder* order) {
    std::cout << "Pizza packaged and ready for delivery to " << order->getCustomerName() << std::endl;
    std::cout << "Delivery driver assigned and en route!" << std::endl;
    std::cout << "Estimated delivery time: 5-10 minutes" << std::endl;
    order->setState(new DeliveredState());
}

void ReadyForDeliveryState::cancelOrder(PizzaOrder* order) {
    std::cout << "Cannot cancel order #" << order->getOrderId() << " - pizza is ready and being delivered!" << std::endl;
}

void ReadyForDeliveryState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Fresh, hot pizza ready for delivery" << std::endl;
    std::cout << "Your pizza is boxed and our driver will be there soon!" << std::endl;
}

std::string ReadyForDeliveryState::getStateName() const {
    return "Ready for Delivery";
}

bool ReadyForDeliveryState::canModifyOrder() const {
    return false;
}

bool ReadyForDeliveryState::canCancel() const {
    return false;
}

int ReadyForDeliveryState::getEstimatedTime() const {
    return 5; // 5 minutes remaining
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// DeliveredState
void DeliveredState::processOrder(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " has been successfully delivered!" << std::endl;
    std::cout << "Thank you " << order->getCustomerName() << " for choosing our pizza place!" << std::endl;
    std::cout << "We hope you enjoy your delicious pizza!" << std::endl;
}

void DeliveredState::cancelOrder(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " has already been delivered." << std::endl;
    std::cout << "Please call customer service if you have any issues." << std::endl;
}

void DeliveredState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - Successfully delivered to " 
              << order->getCustomerName() << std::endl;
    std::cout << "Order completed! We hope you enjoyed your pizza!" << std::endl;
}

std::string DeliveredState::getStateName() const {
    return "Delivered";
}

bool DeliveredState::canModifyOrder() const {
    return false;
}

bool DeliveredState::canCancel() const {
    return false;
}

int DeliveredState::getEstimatedTime() const {
    return 0; // Order complete
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// CancelledState
void CancelledState::processOrder(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " is cancelled and cannot be processed." << std::endl;
}

void CancelledState::cancelOrder(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " is already cancelled." << std::endl;
}

void CancelledState::displayStatus(PizzaOrder* order) {
    std::cout << "Order #" << order->getOrderId() << " - CANCELLED" << std::endl;
    std::cout << "This order has been cancelled. Refund processed if applicable." << std::endl;
}

std::string CancelledState::getStateName() const {
    return "Cancelled";
}

bool CancelledState::canModifyOrder() const {
    return false;
}

bool CancelledState::canCancel() const {
    return false;
}

int CancelledState::getEstimatedTime() const {
    return 0;
}