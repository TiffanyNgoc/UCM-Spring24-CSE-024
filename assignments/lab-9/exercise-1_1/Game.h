#ifndef GAME_H
#define GAME_H

#include "Square.h"
#include <vector>
#include <iostream>

class Game {
    std::vector<std::vector<Square>> board;
    bool playerX;
    bool AI;
    int boardSize; // Size of le board
    std::string gameOutcome;

public:
    Game() : playerX(true), AI(false), boardSize(3) {
        initialize(boardSize, AI); // Default initialization
    }

    void initialize(int size, bool vsAI) {
        boardSize = size;
        AI = vsAI;
        playerX = true; // X starts by default (bc its the best)
        gameOutcome = ""; // Resets outcome msg
        board.clear();
        board.resize(size, std::vector<Square>(size, Square()));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // Initialize each square position based on its index
                board[i][j] = Square(-0.9f + j * (1.8f / size), 0.9f - i * (1.8f / size), 0.6f / size);
            }
        }
    }

    bool isGameOver() {
        // Win condition by checking (horizontal, vertical, and diagonal)
        for (int i = 0; i < boardSize; i++) {
            if (checkRow(i) || checkColumn(i)) {
                return true;
            }
        }
        return checkDiagonals();


        // bool gameIsOver = false;
        // for (int i = 0; i < boardSize; i++) {
        //     if (checkRow(i) || checkColumn(i)) {
        //         gameIsOver = true;
        //         break;
        //     }
        // }
        // if (!gameIsOver) gameIsOver = checkDiagonals();

        // if (gameIsOver) {
        //     updateOutcome();
        // }
        // return gameIsOver;
    }

    std::string getResult() const {
        return gameOutcome;
    }

    void handleMouseClick(float x, float y) {
        if (AI && !playerX) return;

        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j].contains(x, y) && board[i][j].isEmpty()) {
                    if (playerX) {
                        board[i][j].playX();
                    } else {
                        board[i][j].playO();
                    }
                    bool gameOver = isGameOver();
                    updateOutcome(playerX);
                    if (!gameOver) {
                        playerX = !playerX;
                        if (AI && !playerX) {
                            AIMove();
                        }
                    }
                    return;
                }
            }
        }

        // if (AI && !playerX) return; // If it's AI turn and we're playing against AI, skip

        // for (int i = 0; i < boardSize; i++) {
        //     for (int j = 0; j < boardSize; j++) {
        //         if (board[i][j].contains(x, y) && board[i][j].isEmpty()) {
        //             if (playerX) {
        //                 board[i][j].playX();
        //             } else {
        //                 board[i][j].playO();
        //             }
        //             if (isGameOver()) { // Check for game over before toggling
        //                 updateOutcome();
        //             }
        //             playerX = !playerX;
        //             if (AI) AIMove();
        //             return;
        //         }
        //     }
        // }
    }

    void draw() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                board[i][j].draw();
            }
        }
    }

private:
    void AIMove() {
        // Placeholder AI logic (plays the first available spot)
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j].isEmpty()) {
                    board[i][j].playO(); 
                    playerX = !playerX;
                    return;
                    
                }
            }
        }
    }

    void updateOutcome(bool currentPlayerX) {
        bool hasEmpty = false;
        for (const auto& row : board) {
            for (const auto& square : row) {
                if (square.getState() == EMPTY) {
                    hasEmpty = true;
                    break;
                }
            }
            if (hasEmpty) break;
        }

        if (!hasEmpty) {
            gameOutcome = "Game is a tie!";
            return;
        }

        if (currentPlayerX) {
            gameOutcome = "Player X wins!";
        } else {
            gameOutcome = "Player O wins!";
        }
    }

    // void updateOutcome() {
    //     // This method updates the gameOutcome based on the board state
    //     bool hasEmpty = false;
    //     for (const auto& row : board) {
    //         for (const auto& square : row) {
    //             if (square.getState() == EMPTY) {
    //                 hasEmpty = true;
    //                 break;
    //             }
    //         }
    //         if (hasEmpty) break;
    //     }

    //     if (!hasEmpty) {
    //         gameOutcome = "Game is a Tie!";
    //         return;
    //     }

    //     if(playerX) {
    //         gameOutcome = "Player X wins!";
    //     } else {
    //         gameOutcome = "Player O wins!";
    //     }
    // }

    bool checkRow(int row) {
        SquareState first = board[row][0].getState();
        if (first == EMPTY) return false;
        for (int i = 1; i < boardSize; i++) {
            if (board[row][i].getState() != first) return false;
        }
        return true;
    }

    bool checkColumn(int col) {
        SquareState first = board[0][col].getState();
        if (first == EMPTY) return false;
        for (int i = 1; i < boardSize; i++) {
            if (board[i][col].getState() != first) return false;
        }
        return true;
    }

    bool checkDiagonals() {
        SquareState first = board[0][0].getState();
        bool diag1 = (first != EMPTY);
        for (int i = 1; i < boardSize; i++) {
            if (board[i][i].getState() != first) {
                diag1 = false;
                break;
            }
        }

        first = board[0][boardSize - 1].getState();
        bool diag2 = (first != EMPTY);
        for (int i = 1; i < boardSize; i++) {
            if (board[i][boardSize - 1 - i].getState() != first) {
                diag2 = false;
                break;
            }
        }
        return diag1 || diag2;
    }
};

#endif
