#ifndef CHECKERS_H
#define CHECKERS_H

#include "BoardGame.h"

// Concrete implementation for Checkers
class Checkers : public BoardGame {
private:
    std::string currentPlayer;
    int moveCount;
    int redPieces;
    int blackPieces;
    
public:
    Checkers();

protected:
    void initializeGame() override;
    void displayBoard() override;
    void showAvailableMoves() override;
    void makeMove() override;
    bool isGameOver() override;
    void announceWinner() override;
    std::string getCurrentPlayer() override;
    void switchPlayer() override;
};

#endif // CHECKERS_H