#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Rectangle.h"

enum COLOR {RED, GREEN, BLUE};

struct ColorSelector{
    Rectangle area;

    Rectangle redButton;
    Rectangle greenButton;
    Rectangle blueButton;

    Color currentColor;

    ColorSelector(){
        area = Rectangle(-0.8, -0.8, 1.8, 0.2, Color(0.8,0.8,0.8));
        redButton = Rectangle(-0.8, -0.8, 0.2, 0.2, Color(1,0,0));
        greenButton = Rectangle(-0.6, -0.8, 0.2, 0.2, Color(0,1,0));
        blueButton = Rectangle(-0.4, -0.8, 0.2, 0.2, Color(0,0,1));

        currentColor.setRed();
        redButton.select();
    }

    void draw(){
        area.draw();
        redButton.draw();
        greenButton.draw();
        blueButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

    void deselectAll(){
        redButton.deselect();
        greenButton.deselect();
        blueButton.deselect();
    }

    void handleMouseClick(float x, float y){
        if (redButton.contains(x, y)){
            deselectAll();
            redButton.select();
            currentColor.setRed();
        }
        else if (greenButton.contains(x, y)){
            deselectAll();
            greenButton.select();
            currentColor.setGreen();
        }
        else if (blueButton.contains(x, y)){
            deselectAll();
            blueButton.select();
            currentColor.setBlue();
        }
    }
};

#endif
