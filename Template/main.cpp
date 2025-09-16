#include "Chess.h"
#include "Checkers.h"

// Usage example
int main() {
    std::cout << "TEMPLATE METHOD PATTERN - BOARD GAMES DEMO\n";
    std::cout << "==========================================\n\n";
    
    // Play a game of Chess
    std::cout << ">>> PLAYING CHESS <<<\n";
    Chess chessGame;
    chessGame.playGame();  // Uses the template method
    
    std::cout << "\n\n>>> PLAYING CHECKERS <<<\n";
    Checkers checkersGame;
    checkersGame.playGame();  // Uses the same template method
    
    // Demonstrate polymorphic usage with raw pointers
    std::cout << "\n\n>>> POLYMORPHIC GAME NIGHT <<<\n";
    BoardGame* games[2];
    games[0] = new Chess();
    games[1] = new Checkers();
    
    std::cout << "Playing multiple games in sequence...\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "\n--- Game " << (i + 1) << " ---\n";
        games[i]->playGame();
    }
    
    // Clean up memory
    delete games[0];
    delete games[1];
    
    return 0;
}