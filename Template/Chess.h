#ifndef CHESS_H
#define CHESS_H

#include "BoardGame.h"

// Concrete implementation for Chess
class Chess : public BoardGame {
private:
    std::string currentPlayer;
    int moveCount;
    
public:
    Chess();

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

#endif // CHESS_H