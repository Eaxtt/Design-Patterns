#include "Checkers.h"

Checkers::Checkers() {
    currentPlayer = "Red";
    moveCount = 0;
    redPieces = 12;
    blackPieces = 12;
}

void Checkers::initializeGame() {
    std::cout << "Setting up Checkers board...\n";
    std::cout << "Placing 12 red pieces and 12 black pieces on alternating squares\n";
    currentPlayer = "Red";
    moveCount = 0;
    redPieces = 12;
    blackPieces = 12;
    std::cout << "Checkers game initialized! Red moves first.\n";
}

void Checkers::displayBoard() {
    std::cout << "\n  1 2 3 4 5 6 7 8\n";
    std::cout << "A . b . b . b . b\n";
    std::cout << "B b . b . b . b .\n";
    std::cout << "C . b . b . b . b\n";
    std::cout << "D . . . . . . . .\n";
    std::cout << "E . . . . . . . .\n";
    std::cout << "F r . r . r . r .\n";
    std::cout << "G . r . r . r . r\n";
    std::cout << "H r . r . r . r .\n";
    std::cout << "(r=Red pieces, b=Black pieces)\n";
    std::cout << "Red pieces: " << redPieces << ", Black pieces: " << blackPieces << "\n";
}

void Checkers::showAvailableMoves() {
    std::cout << "Available Checkers moves:\n";
    if (currentPlayer == "Red") {
        std::cout << "- Forward diagonal moves available\n";
        std::cout << "- Jump moves if enemy pieces are adjacent\n";
    } else {
        std::cout << "- Forward diagonal moves available\n";
        std::cout << "- Jump moves if enemy pieces are adjacent\n";
    }
}

void Checkers::makeMove() {
    moveCount++;
    // Simulate capturing pieces occasionally
    if (moveCount % 3 == 0) {
        if (currentPlayer == "Red") {
            blackPieces--;
            std::cout << "Red player jumps and captures a black piece!\n";
        } else {
            redPieces--;
            std::cout << "Black player jumps and captures a red piece!\n";
        }
    } else {
        if (currentPlayer == "Red") {
            std::cout << "Red player moves diagonally forward\n";
        } else {
            std::cout << "Black player moves diagonally forward\n";
        }
    }
    std::cout << "Move " << moveCount << " completed.\n";
}

bool Checkers::isGameOver() {
    // Game ends when one player has no pieces left or after 8 moves for demo
    if (redPieces == 0 || blackPieces == 0 || moveCount >= 8) {
        std::cout << "Game ending condition reached!\n";
        return true;
    }
    return false;
}

void Checkers::announceWinner() {
    std::cout << "\n*** CHECKERS GAME OVER ***\n";
    if (redPieces == 0) {
        std::cout << "Black wins! All red pieces captured.\n";
    } else if (blackPieces == 0) {
        std::cout << "Red wins! All black pieces captured.\n";
    } else {
        // Determine winner by remaining pieces
        if (redPieces > blackPieces) {
            std::cout << "Red wins with more pieces remaining!\n";
        } else if (blackPieces > redPieces) {
            std::cout << "Black wins with more pieces remaining!\n";
        } else {
            std::cout << "It's a tie!\n";
        }
    }
    std::cout << "Final count - Red: " << redPieces << ", Black: " << blackPieces << "\n";
    std::cout << "Total moves played: " << moveCount << "\n";
}

std::string Checkers::getCurrentPlayer() {
    return currentPlayer;
}

void Checkers::switchPlayer() {
    if (currentPlayer == "Red") {
        currentPlayer = "Black";
    } else {
        currentPlayer = "Red";
    }
}