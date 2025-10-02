// Client
// Demonstrates the Builder pattern by creating different computer configurations
// using the same construction process.

#include <iostream>
#include "Computer.h"
#include "ComputerBuilder.h"
#include "ConcreteBuilders.h"
#include "TechnicianAssembler.h"

int main() {
    std::cout << "=== Computer Builder Pattern Demo ===\n" << std::endl;
    
    // Build a Gaming PC
    std::cout << "Building a Gaming PC..." << std::endl;
    GamingPCBuilder* gamingBuilder = new GamingPCBuilder();
    TechnicianAssembler technicianGaming(gamingBuilder);
    // construct() - Director orchestrates the building process
    technicianGaming.constructComputer();
    // getResult() - Retrieve the constructed product
    Computer* gamingPC = gamingBuilder->getComputer();
    gamingPC->display();
    
    // Build an Office PC
    std::cout << "\nBuilding an Office PC..." << std::endl;
    OfficePCBuilder* officeBuilder = new OfficePCBuilder();
    TechnicianAssembler technicianOffice(officeBuilder);
    technicianOffice.constructComputer();
    Computer* officePC = officeBuilder->getComputer();
    officePC->display();
    
    // Build a Server
    std::cout << "\nBuilding a Server..." << std::endl;
    ServerBuilder* serverBuilder = new ServerBuilder();
    TechnicianAssembler technicianServer(serverBuilder);
    technicianServer.constructComputer();
    Computer* server = serverBuilder->getComputer();
    server->display();
    
    // Demonstrate reusing director with different builder
    std::cout << "\n=== Demonstrating Director Reuse ===" << std::endl;
    std::cout << "Using same technician to build another Gaming PC..." << std::endl;
    GamingPCBuilder* gamingBuilder2 = new GamingPCBuilder();
    technicianGaming.setBuilder(gamingBuilder2);
    technicianGaming.constructComputer();
    Computer* gamingPC2 = gamingBuilder2->getComputer();
    gamingPC2->display();
    
    // Cleanup
    delete gamingBuilder;
    delete officeBuilder;
    delete serverBuilder;
    delete gamingBuilder2;
    
    return 0;
}