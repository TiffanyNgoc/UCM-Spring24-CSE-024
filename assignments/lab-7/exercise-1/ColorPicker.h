#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"
#include "Color.h"
#include <string>
#include <GL/freeglut.h>
#include <iostream>

struct ColorPicker {
private:
    Rectangle area;
    Color currentColor;
    Rectangle rPlusButton, gPlusButton, bPlusButton;
    Rectangle rMinusButton, gMinusButton, bMinusButton;
    Rectangle colorDisplay;

public:
    ColorPicker(){
        area = Rectangle(-0.6f, -0.8f, 1.8f, 0.2f, Color(0.8f, 0.8f, 0.8f));
        currentColor = Color(0.5f, 0.5f, 0.5f); // Start with a neutral color

        rPlusButton = Rectangle(-0.5f, -0.925f, 0.1f, 0.05f, Color(0.9f, 0.2f, 0.2f));
        gPlusButton = Rectangle(-0.3f, -0.925f, 0.1f, 0.05f, Color(0.2f, 0.9f, 0.2f));
        bPlusButton = Rectangle(-0.1f, -0.925f, 0.1f, 0.05f, Color(0.2f, 0.2f, 0.9f));

        rMinusButton = Rectangle(-0.5f, -0.825f, 0.1f, 0.05f, Color(0.7f, 0.1f, 0.1f));
        gMinusButton = Rectangle(-0.3f, -0.825f, 0.1f, 0.05f, Color(0.1f, 0.7f, 0.1f));
        bMinusButton = Rectangle(-0.1f, -0.825f, 0.1f, 0.05f, Color(0.1f, 0.1f, 0.7f));

        colorDisplay = Rectangle(0.1f, -0.825f, 0.2f, 0.15f, currentColor);
    } //

    void adjustColor(float rDelta, float gDelta, float bDelta) {
        float newR = std::max(0.0f, std::min(1.0f, currentColor.getR() + rDelta));
        float newG = std::max(0.0f, std::min(1.0f, currentColor.getG() + gDelta));
        float newB = std::max(0.0f, std::min(1.0f, currentColor.getB() + bDelta));
        currentColor = Color(newR, newG, newB);
        colorDisplay.setColor(currentColor);

        std::cout << "NewColor: " << newR << ", " << newG << ", " << newB << std::endl;
    }

    void handleMouseClick(float x, float y) {
        if (rPlusButton.contains(x, y)) {
            adjustColor(0.1f, 0.0f, 0.0f);
            std::cout << "R+ button clicked" << std::endl;
        } else if (gPlusButton.contains(x, y)) {
            adjustColor(0.0f, 0.1f, 0.0f);
            std::cout << "G+ button clicked" << std::endl;
        } else if (bPlusButton.contains(x, y)) {
            adjustColor(0.0f, 0.0f, 0.1f);
            std::cout << "B+ button clicked" << std::endl;
        } else if (rMinusButton.contains(x, y)) {
            adjustColor(-0.1f, 0.0f, 0.0f);
            std::cout << "R- button clicked" << std::endl;
        } else if (gMinusButton.contains(x, y)) {
            adjustColor(0.0f, -0.1f, 0.0f);
            std::cout << "G- button clicked" << std::endl;
        } else if (bMinusButton.contains(x, y)) {
            adjustColor(0.0f, 0.0f, -0.1f);
            std::cout << "B- button clicked" << std::endl;
        }
    }

    Color getCurrentColor() {
        return currentColor;
    }

    void draw() {
        area.draw();
        rPlusButton.draw();
        gPlusButton.draw();
        bPlusButton.draw();
        rMinusButton.draw();
        gMinusButton.draw();
        bMinusButton.draw();
        colorDisplay.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y) || rPlusButton.contains(x, y) || gPlusButton.contains(x, y) ||
            bPlusButton.contains(x, y) || rMinusButton.contains(x, y) || gMinusButton.contains(x, y) ||
            bMinusButton.contains(x, y);
    }

    Color getCurrentColor() const {
        return currentColor;
    }
};

#endif
