#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include "AppController.h"
#include "Rectangle.h"
#include "Button.h"

class Controller : public AppController {
    enum GameState {START, PLAYING, END};
    GameState gameState;
    Game game;
    int boardSize;
    bool isPLayingAgainstAI;

public:
    Controller() : gameState(START), boardSize(3), isPLayingAgainstAI(true) {
        // Default to 3x3 board playing against AI
    }

    void leftMouseDown(float x, float y) override {
        switch(gameState) {
            case START:
                gameState = PLAYING;
                if(isPLayingAgainstAI) {
                    game.AIOn();
                } else {
                    game.AIOff();
                }
                break;
            case PLAYING:
                game.handleMouseClick(x, y);
                if(game.isGameOver()) {
                    gameState = END;
                }
                break;
            case END:
                gameState = START;
                break;
    }
    }

    void render() override {
        switch(gameState) {
            case START:
                // Draw Startup screen
                break;
            case PLAYING:
                game.draw();
                break;
            case END:
                // Draw end screen
                break;
        }
    }
};

#endif
