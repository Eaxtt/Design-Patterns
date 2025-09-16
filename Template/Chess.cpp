#include "Chess.h"

Chess::Chess() {
    currentPlayer = "White";
    moveCount = 0;
}

void Chess::initializeGame() {
    std::cout << "Setting up Chess board...\n";
    std::cout << "Placing pieces: King, Queen, Rooks, Bishops, Knights, Pawns\n";
    currentPlayer = "White";
    moveCount = 0;
    std::cout << "Chess game initialized! White moves first.\n";
}

void Chess::displayBoard() {
    std::cout << "\n  a b c d e f g h\n";
    std::cout << "8 r n b q k b n r\n";
    std::cout << "7 p p p p p p p p\n";
    std::cout << "6 . . . . . . . .\n";
    std::cout << "5 . . . . . . . .\n";
    std::cout << "4 . . . . . . . .\n";
    std::cout << "3 . . . . . . . .\n";
    std::cout << "2 P P P P P P P P\n";
    std::cout << "1 R N B Q K B N R\n";
    std::cout << "(Simplified chess board display)\n";
}

void Chess::showAvailableMoves() {
    std::cout << "Available Chess moves:\n";
    if (currentPlayer == "White") {
        std::cout << "- Pawn moves: e2-e4, d2-d4, Nf3, etc.\n";
        std::cout << "- Opening moves available\n";
    } else {
        std::cout << "- Pawn moves: e7-e5, d7-d5, Nf6, etc.\n";
        std::cout << "- Defensive/attacking moves available\n";
    }
}

void Chess::makeMove() {
    moveCount++;
    if (currentPlayer == "White") {
        std::cout << "White player makes move: e2-e4 (simulated)\n";
    } else {
        std::cout << "Black player makes move: e7-e5 (simulated)\n";
    }
    std::cout << "Move " << moveCount << " completed.\n";
}

bool Chess::isGameOver() {
    // Simulate game ending after 6 moves for demo
    if (moveCount >= 2) {
        std::cout << "Game ending condition reached (checkmate/stalemate)\n";
        return true;
    }
    return false;
}

void Chess::announceWinner() {
    std::cout << "\n*** CHESS GAME OVER ***\n";
    if (moveCount % 2 == 0) {
        std::cout << "Black wins by checkmate!\n";
    } else {
        std::cout << "White wins by checkmate!\n";
    }
    std::cout << "Total moves played: " << moveCount << "\n";
}

std::string Chess::getCurrentPlayer() {
    return currentPlayer;
}

void Chess::switchPlayer() {
    if (currentPlayer == "White") {
        currentPlayer = "Black";
    } else {
        currentPlayer = "White";
    }
}