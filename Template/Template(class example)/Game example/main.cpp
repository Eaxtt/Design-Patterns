#include "Game.h"

int main() {
    std::cout << "=== Template Pattern Demo ===" << std::endl;
    
    Chess chess;
    Soccer soccer;
    
    std::cout << "\nChess game:" << std::endl;
    chess.play();
    
    std::cout << "\nSoccer game:" << std::endl;
    soccer.play();
    
    return 0;
}