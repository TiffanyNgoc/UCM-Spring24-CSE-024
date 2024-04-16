#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include "AppController.h"
#include "Game.h"
#include "Rectangle.h"
#include "Button.h"

class Controller : public AppController {
    enum GameState {START, PLAYING, END};
    GameState gameState;
    Game game;
    int boardSize;
    bool isPLayingAgainstAI;
    std::string endMessage;

    Button button3x3;
    Button button4x4;
    Button button5x5;
    Button playButton;
    Button aiButton;
    Button humanButton;
    Button playAgainButton;
    Button quitButton;

public:

    Controller() : boardSize(3), isPLayingAgainstAI(true), gameState(START) {
        button3x3 = Button("3 x 3", -0.7, 0.85);
        button4x4 = Button("4 x 4", -0.7, 0.1);
        button5x5 = Button("5 x 5", -0.7, -0.7);
        aiButton = Button("Play vs AI", 0.3, 0.85);
        humanButton = Button("Play vs Human", 0.3, -0.7);
        playButton = Button("Play", -0.1, 0.1);
        playAgainButton = Button("Play Again?", -0.5, -0.3);
        quitButton = Button ("Quit", 0.5, -0.3);
    }

    void leftMouseDown(float x, float y) override {
        switch(gameState) {
            case START:
                if (button3x3.contains(x, y)) {
                    boardSize = 3;
                    button3x3.togglePressed();
                    button4x4.setPressed(false);
                    button5x5.setPressed(false);
                } else if (button4x4.contains(x, y)) {
                    boardSize = 4;
                    button4x4.togglePressed();
                    button3x3.setPressed(false);
                    button5x5.setPressed(false);
                } else if (button5x5.contains(x, y)) {
                    boardSize = 5;
                    button5x5.togglePressed();
                    button3x3.setPressed(false);
                    button4x4.setPressed(false);
                }

                // AI mode buttons
                if (aiButton.contains(x, y)) {
                    isPLayingAgainstAI = true;
                    aiButton.togglePressed();
                    humanButton.setPressed(false);
                } else if (humanButton.contains(x, y)) {
                    isPLayingAgainstAI = false;
                    humanButton.togglePressed();
                    aiButton.setPressed(false);
                }

                // Start game
                if (playButton.contains(x, y)) {
                    gameState = PLAYING;
                    game.initialize(boardSize, isPLayingAgainstAI);
                    playButton.setPressed(false);
                }
                break;
            case PLAYING:
                game.handleMouseClick(x, y);
                if (game.isGameOver()) {
                    gameState = END;
                    endMessage = game.getResult();
                }
                break;
            case END:
                if (playAgainButton.contains(x, y)) {
                    gameState = START;
                    game.initialize(boardSize, isPLayingAgainstAI);

                    resetButtonStates();
                }
                if (quitButton.contains(x, y)) {
                    exit(0);
                }
                break;
        }
    }

    void render() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        switch(gameState) {
            case START:
                button3x3.draw();
                button4x4.draw();
                button5x5.draw();
                aiButton.draw();
                humanButton.draw();
                playButton.draw();
                break;
            case PLAYING:
                game.draw();
                break;
            case END:
                playAgainButton.draw();
                quitButton.draw();
                std::cout << "End Message: " << endMessage << std::endl;
                renderText(-0.2, 0.0, endMessage);
                break;
        }
        glutSwapBuffers();
    }

private:
    void renderText(float x, float y, const std::string &text) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f(x, y);
        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }

    void resetButtonStates() {
        button3x3.setPressed(false);
        button4x4.setPressed(false);
        button5x5.setPressed(false);
        aiButton.setPressed(false);
        humanButton.setPressed(false);
        playButton.setPressed(false);
        playAgainButton.setPressed(false);
        quitButton.setPressed(false);
    }

    void checkButtonPress(float x, float y, Button& button, int newSize) {
        if (button.contains(x, y)) {
            boardSize = newSize;
            button.togglePressed();
        }
    }

    void togglePlayerMode(float x, float y, Button& button, bool mode) {
        if (button.contains(x, y)) {
            isPLayingAgainstAI = mode;
            button.togglePressed();
        }
    }
};

#endif
