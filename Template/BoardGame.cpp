#include "BoardGame.h"

void BoardGame::playGame() {
    std::cout << "=== Starting Game Session ===\n";
    
    // Step 1: Initialize the game (different for each game)
    initializeGame();
    
    // Step 2: Display initial board state
    displayBoard();
    
    // Step 3: Main game loop
    while (!isGameOver()) {
        // Get current player
        std::string currentPlayer = getCurrentPlayer();
        std::cout << "\n" << currentPlayer << "'s turn:\n";
        
        // Display available moves
        showAvailableMoves();
        
        // Make a move (specific to each game)
        makeMove();
        
        // Display updated board
        displayBoard();
        
        // Switch to next player
        switchPlayer();
    }
    
    // Step 4: Game is over, announce winner
    announceWinner();
    
    std::cout << "\n=== Game Session Ended ===\n";
}