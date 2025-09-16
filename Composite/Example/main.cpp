// main.cpp
#include "PizzaComponent.h"
#include "Topping.h"
#include "ToppingGroup.h"
#include <iostream>

int main() {
    std::cout << "=== Romeo's Pizza Menu ===" << std::endl << std::endl;
    
    // Create individual toppings
    Topping* pepperoni = new Topping("Pepperoni", 2.50);
    Topping* cheese = new Topping("Extra Cheese", 1.75);
    
    // Create topping groups (composite objects)
    ToppingGroup* vegetarian = new ToppingGroup("Vegetarian Special");
    vegetarian->add(new Topping("Mushrooms", 1.50));
    vegetarian->add(new Topping("Green Peppers", 1.25));
    vegetarian->add(new Topping("Onions", 1.00));
    
    ToppingGroup* meatLovers = new ToppingGroup("Meat Lovers Special");
    //meatLovers->add(new Topping("Pepperoni", 2.50));
    meatLovers->add(pepperoni);
    meatLovers->add(new Topping("Beef Sausage", 3.00));
    meatLovers->add(new Topping("Salami", 2.75));
    
    ToppingGroup* vegetarianDeluxe = new ToppingGroup("Vegetarian Deluxe");
    vegetarianDeluxe->add(new Topping("Mushrooms", 1.50));
    vegetarianDeluxe->add(new Topping("Green Peppers", 1.25));
    vegetarianDeluxe->add(new Topping("Onions", 1.00));
    vegetarianDeluxe->add(new Topping("Feta Cheese", 2.25));
    vegetarianDeluxe->add(new Topping("Olives", 1.50));
    
    // Display individual toppings
    std::cout << "Individual Toppings:" << std::endl;
    pepperoni->display();
    cheese->display();
    
    std::cout << std::endl;
    
    // Display topping groups
    std::cout << "Topping Combinations:" << std::endl;
    vegetarian->display();
    std::cout << std::endl;
    
    meatLovers->display();
    std::cout << std::endl;
    
    vegetarianDeluxe->display();
    std::cout << std::endl;
    
    // Demonstrate uniform treatment
    std::cout << "Price Comparison:" << std::endl;
    std::cout << "Single Pepperoni: $" << pepperoni->getPrice() << std::endl;
    std::cout << "Vegetarian Special: $" << vegetarian->getPrice() << std::endl;
    std::cout << "Meat Lovers Special: $" << meatLovers->getPrice() << std::endl;
    std::cout << "Vegetarian Deluxe: $" << vegetarianDeluxe->getPrice() << std::endl;
    
    // Clean up
    delete pepperoni;
    delete cheese;
    delete vegetarian;
    delete meatLovers;
    delete vegetarianDeluxe;
    
    return 0;
}