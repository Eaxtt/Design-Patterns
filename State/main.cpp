#include "PizzaOrder.h"
#include <iostream>

int main() {
    std::cout << "=== Pizza Place Order System ===" << std::endl;
    std::cout << std::endl;
    
    // Create a new pizza order
    PizzaOrder order("John Doe", 101);
    
    // Add some toppings (demonstrates canModifyOrder)
    std::cout << "Adding toppings to order:" << std::endl;
    order.addTopping("Pepperoni");
    order.addTopping("Mushrooms");
    order.addTopping("Extra Cheese");
    std::cout << std::endl;
    
    std::cout << "Initial order details:" << std::endl;
    order.displayOrderInfo();
    std::cout << std::endl;
    
    // Demonstrate different state functions
    std::cout << "Processing order through states:" << std::endl;
    std::cout << "===============================" << std::endl;
    
    // Step 1: Processing Payment
    std::cout << "\n=== STEP 1: Payment Processing ===" << std::endl;
    order.displayStatus();
    std::cout << "\nProcessing payment..." << std::endl;
    order.processOrder();
    
    // Step 2: Prepping Ingredients
    std::cout << "\n=== STEP 2: Ingredient Preparation ===" << std::endl;
    order.displayStatus();
    
    // Try to add topping (should fail now)
    std::cout << "\nTrying to add extra topping now:" << std::endl;
    order.addTopping("Olives");
    
    std::cout << "\nContinuing preparation..." << std::endl;
    order.processOrder();
    
    // Step 3: Assembling Pizza
    std::cout << "\n=== STEP 3: Pizza Assembly ===" << std::endl;
    order.displayStatus();
    std::cout << "\nAssembling pizza..." << std::endl;
    order.processOrder();
    
    // Step 4: Baking
    std::cout << "\n=== STEP 4: Baking ===" << std::endl;
    order.displayStatus();
    
    // Try to cancel (should fail)
    std::cout << "\nCustomer trying to cancel order:" << std::endl;
    order.cancelOrder();
    
    std::cout << "\nContinuing baking..." << std::endl;
    order.processOrder();
    
    // Step 5: Ready for Delivery
    std::cout << "\n=== STEP 5: Ready for Delivery ===" << std::endl;
    order.displayStatus();
    std::cout << "\nDispatching for delivery..." << std::endl;
    order.processOrder();
    
    // Step 6: Delivered
    std::cout << "\n=== STEP 6: Delivery Complete ===" << std::endl;
    order.displayStatus();
    
    std::cout << "\nFinal order summary:" << std::endl;
    order.displayOrderInfo();
    
    std::cout << "\n" << std::endl;
    std::cout << "=== Demonstration of Cancellation ===" << std::endl;
    
    // Create another order to demonstrate cancellation
    PizzaOrder cancelOrder("Jane Smith", 102);
    cancelOrder.addTopping("Sausage");
    cancelOrder.addTopping("Bell Peppers");
    
    std::cout << "\nNew order created:" << std::endl;
    cancelOrder.displayOrderInfo();
    
    std::cout << "\nCustomer decides to cancel early:" << std::endl;
    cancelOrder.cancelOrder();
    
    std::cout << "\nCancelled order status:" << std::endl;
    cancelOrder.displayOrderInfo();
    
    return 0;
}