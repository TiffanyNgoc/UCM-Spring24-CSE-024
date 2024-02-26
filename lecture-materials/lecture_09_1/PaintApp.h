#ifndef PAINT_APP_H
#define PAINT_APP_H

#include <GL/freeglut.h>
#include "Rectangle.h"
#include "Button.h"
#include "Texture.h"
#include <iostream>

enum TOOL {PENCIL, ERASER};
enum COLOR {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

struct PaintApp {
    Rectangle verticalToolbar;
    Rectangle horizontalToolbar;
    Rectangle canvas;

    Rectangle redButton;
    Rectangle orangeButton;
    Rectangle yellowButton;
    Rectangle greenButton;
    Rectangle blueButton;
    Rectangle purpleButton;

    Texture pencilButton;
    Texture eraserButton;

    Button eraseButton;
    Button clearButton;
    Button incStrokeBtn;
    Button decStrokeBtn;
    TOOL selectedTool;
    COLOR selectedColor;

    PaintApp() {
        verticalToolbar = Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, Color(0.7f, 0.7f, 0.7f));
        horizontalToolbar = Rectangle(-0.8f, -0.8f, 1.8f, 0.2f, Color(0.7f, 0.7f, 0.7f));
        canvas = Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, Color(0.9f, 0.9f, 0.9f));

        redButton = Rectangle(-0.8, -0.8, 0.2, 0.2, Color(1.0f, 0.0f, 0.0f));
        orangeButton = Rectangle(-0.6, -0.8, 0.2, 0.2, Color(1, 0.5, 0));
        yellowButton = Rectangle(-0.4, -0.8, 0.2, 0.2, Color(1, 1, 0));
        greenButton = Rectangle(-0.2, -0.8, 0.2, 0.2, Color(0.0f, 1.0f, 0.0f));
        blueButton = Rectangle(0.0, -0.8, 0.2, 0.2, Color(0.0f, 0.0f, 1.0f));
        purpleButton = Rectangle(0.2, -0.8, 0.2, 0.2, Color (0.6, 0, 1));

        eraseButton = Button("Erase", 0.41, -0.8);
        clearButton = Button("Clear", 0.71, -0.8f);
        incStrokeBtn = Button(" + ", -1, 0.2);
        decStrokeBtn = Button(" - ", -1, 0.0);

        pencilButton = Texture("assets/pencil.png", -1.0f, 1.0f, 0.2f, 0.2f);
        eraserButton = Texture("assets/eraser.png", -1.0f, 0.8f, 0.2f, 0.2f);

        selectedTool = PENCIL;
        selectedColor = RED;
    }

    void init() {
        pencilButton.loadTexture();
        eraserButton.loadTexture();
    }

    void leftMouseDown(float x, float y) {
        if (pencilButton.isClicked(x, y)) {
            selectedTool = PENCIL;
        } else if (eraserButton.isClicked(x, y)) {
            selectedTool = ERASER;
        }

        if (redButton.isClicked(x, y)) {
            selectedColor = RED;
        } else if (orangeButton.isClicked(x, y)) {
            selectedColor = ORANGE;
        } else if (yellowButton.isClicked(x, y)) {
            selectedColor = YELLOW;
        } else if (greenButton.isClicked(x, y)) {
            selectedColor = GREEN;
        } else if (blueButton.isClicked(x, y)) {
            selectedColor = BLUE;
        } else if (purpleButton.isClicked(x, y)) {
            selectedColor = PURPLE;
        }
    }

    void leftMouseUp(float x, float y) {
        // 
    }

    void rightMouseDown(float x, float y) {
        // 
    }

    void rightMouseUp(float x, float y) {
        // 
    }

    void mouseMotion(float x, float y) {
        // 
    }

    void keyboardDown(unsigned char key, float x, float y) {
        // 
    }

    void render() {
        if (selectedTool == PENCIL) {
            pencilButton.selected = true;
            eraserButton.selected = false;
        } else if (selectedTool == ERASER) {
            pencilButton.selected = false;
            eraserButton.selected = true;
        }

        if (selectedColor == RED) {
            redButton.selected = true;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
        } else if (selectedColor == ORANGE) {
            redButton.selected = false;
            orangeButton.selected = true;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
        } else if (selectedColor == YELLOW) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = true;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
        }
        else if (selectedColor == GREEN) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = true;
            blueButton.selected = false;
            purpleButton.selected = false;
        } else if (selectedColor == BLUE) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = true;
            purpleButton.selected = false;
        } else if (selectedColor == PURPLE) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = true;
        }

        canvas.draw();
        verticalToolbar.draw();
        horizontalToolbar.draw();

        redButton.draw();
        orangeButton.draw();
        yellowButton.draw();
        greenButton.draw();
        blueButton.draw();
        purpleButton.draw();

        eraseButton.draw();
        clearButton.draw();
        incStrokeBtn.draw();
        decStrokeBtn.draw();

        pencilButton.draw();
        eraserButton.draw();
    }
};

#endif
