#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <iostream>
#include <string>

// Abstract base class defining the template method for board games
class BoardGame {
public:
    // This is the TEMPLATE METHOD - defines the skeleton of playing any board game
    void playGame();
    
    // Virtual destructor for proper cleanup
    virtual ~BoardGame() {}

protected:
    // These are the steps that subclasses must implement
    virtual void initializeGame() = 0;
    virtual void displayBoard() = 0;
    virtual void showAvailableMoves() = 0;
    virtual void makeMove() = 0;
    virtual bool isGameOver() = 0;
    virtual void announceWinner() = 0;
    virtual std::string getCurrentPlayer() = 0;
    virtual void switchPlayer() = 0;
};

#endif // BOARDGAME_H