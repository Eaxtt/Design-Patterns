
#ifndef GAME_H
#define GAME_H

#include <iostream>

// Base class with template method
class Game {
public:
    // Template method - defines the algorithm skeleton
    void play() {
        startGame();
        playGame();    // Abstract - must be implemented
        endGame();
    }

protected:
    void startGame() {
        std::cout << "Game started!" << std::endl;
    }
    
    void endGame() {
        std::cout << "Game ended!" << std::endl;
    }
    
    // Abstract method - subclasses must implement
    virtual void playGame() = 0;
    
    virtual ~Game() = default;
};

// Concrete implementation 1
class Chess : public Game {
protected:
    void playGame() override {
        std::cout << "Playing chess - moving pieces strategically" << std::endl;
    }
};

// Concrete implementation 2
class Soccer : public Game {
protected:
    void playGame() override {
        std::cout << "Playing soccer - kicking the ball around" << std::endl;
    }
};

#endif