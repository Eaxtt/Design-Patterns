// main.cpp
#include "Pizza.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include <iostream>
using namespace std;



int main() {
    std::cout << "=== Pizza Decorator Pattern Demo ===" << std::endl << std::endl;
    
    // Create a simple base pizza
    std::cout << "1. Basic Pizza:" << std::endl;
    Pizza* margherita = new BasePizza("Margherita");
    margherita->printPizza();
    std::cout << std::endl;
    
    // Decorate with extra cheese
    std::cout << "2. Pizza with Extra Cheese:" << std::endl;
    Pizza* cheezyMargherita = new ExtraCheese(new BasePizza("Margherita"));
    cheezyMargherita->printPizza();
    std::cout << std::endl;
    
    // Decorate with stuffed crust
    std::cout << "3. Pizza with Stuffed Crust:" << std::endl;
    Pizza* stuffedPepperoni = new StuffedCrust(new BasePizza("Pepperoni"));
    stuffedPepperoni->printPizza();
    std::cout << std::endl;
    
    // Multiple decorations - Extra cheese AND stuffed crust
    std::cout << "4. Pizza with Multiple Decorations:" << std::endl;
    Pizza* deluxePizza = new ExtraCheese(
        new StuffedCrust(
            new BasePizza("Supreme")
        )
    );
    deluxePizza->printPizza();
    std::cout << std::endl;
    
    // Another combination - Stuffed crust with extra cheese
    std::cout << "5. Different Order of Decorations:" << std::endl;
    Pizza* anotherDeluxe = new StuffedCrust(
        new ExtraCheese(
            new BasePizza("Hawaiian")
        )
    );
    anotherDeluxe->printPizza();
    std::cout << std::endl;

    cout << "6. Extra Extra Extra cheese pizza:" << endl;
    Pizza* eeeCheese = new ExtraCheese(
        new ExtraCheese(
            new ExtraCheese(
                new BasePizza("plain")
            )
        )
    );
    eeeCheese->printPizza();
    cout << endl;
    
    std::cout << "=== Demonstration of Dynamic Behavior ===" << std::endl;
    std::cout << "Base Margherita: $" << margherita->getPrice() << std::endl;
    std::cout << "With Extra Cheese: $" << cheezyMargherita->getPrice() << std::endl;
    std::cout << "With Stuffed Crust: $" << stuffedPepperoni->getPrice() << std::endl;
    std::cout << "With Both Decorations: $" << deluxePizza->getPrice() << std::endl;
    cout << "pizza with extra extra extra cheese: $" << eeeCheese->getPrice() << endl;
    
    // Clean up
    delete margherita;
    delete cheezyMargherita;
    delete stuffedPepperoni;
    delete deluxePizza;
    delete anotherDeluxe;
    delete eeeCheese;
    
    return 0;
}