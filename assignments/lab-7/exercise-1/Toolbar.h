#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"

enum Tool {PENCIL, ERASER, SQUARE, MOUSE, CIRCLE, CLEAR, TRIANGLE, OCTAGON, UP, DOWN};

class Toolbar{
    Rectangle area;
    Tool selectedTool;

    Texture mouseButton;
    Texture pencilButton;
    Texture eraserButton;
    Texture squareButton;
    Texture circleButton;
    Texture trashButton;
    Texture triangleButton;
    Texture octagonButton;
    Texture upButton;
    Texture downButton;

    void delesectAll(){
        mouseButton.selected = false;
        pencilButton.selected = false;
        eraserButton.selected = false;
        squareButton.selected = false;
        circleButton.selected = false;
        trashButton.selected = false;
        triangleButton.selected = false;
        octagonButton.selected = false;
        upButton.selected = false;
        downButton.selected = false;
    }

public:
    Toolbar(){
        area = Rectangle(-1, 1, 0.4, 2, Color(0.8,0.8,0.8));
        mouseButton = Texture("assets/mouse.png", -1, 1, 0.2, 0.2);
        pencilButton = Texture("assets/pencil.png", -1, 0.8, 0.2, 0.2);
        trashButton = Texture("assets/trash.png", -0.8, 1, 0.2, 0.2);
        eraserButton = Texture("assets/eraser.png", -0.8, 0.8, 0.2, 0.2);
        circleButton = Texture("assets/Circle_png.png", -1, 0.6, 0.2, 0.2);
        squareButton = Texture("assets/square.png", -0.8, 0.6, 0.2, 0.2);
        triangleButton = Texture("assets/Triangle_png.png", -1, 0.4, 0.2, 0.2);
        octagonButton = Texture("assets/Octagon_png.png", -0.8, 0.4, 0.2, 0.2);
        upButton = Texture("assets/ArrowUp.png", -1, 0.2, 0.2, 0.2);
        downButton = Texture("assets/Down_arrow.png", -0.8, 0.2, 0.2, 0.2);
        selectedTool = PENCIL;
        pencilButton.selected = true;
    }

    void draw(){
        area.draw();
        mouseButton.draw();
        pencilButton.draw();
        eraserButton.draw();
        squareButton.draw();
        circleButton.draw();
        trashButton.draw();
        triangleButton.draw();
        octagonButton.draw();
        upButton.draw();
        downButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }

    void handleMouseClick(float x, float y){
        if (mouseButton.contains(x, y)){
            delesectAll();
            mouseButton.selected = true;
            selectedTool = MOUSE;
        }
        else if (pencilButton.contains(x, y)){
            delesectAll();
            pencilButton.selected = true;
            selectedTool = PENCIL;
        }
        else if (eraserButton.contains(x, y)){
            delesectAll();
            eraserButton.selected = true;
            selectedTool = ERASER;
        }
        else if (squareButton.contains(x, y)){
            delesectAll();
            squareButton.selected = true;
            selectedTool = SQUARE;
        }
        else if (circleButton.contains(x, y)){
            delesectAll();
            circleButton.selected = true;
            selectedTool = CIRCLE;
        }
        else if (trashButton.contains(x, y)) {
            delesectAll();
            trashButton.selected = true;
            selectedTool = CLEAR;
        }
        else if (triangleButton.contains(x, y)) {
            delesectAll();
            triangleButton.selected = true;
            selectedTool = TRIANGLE;
        }
        else if (octagonButton.contains(x, y)) {
            delesectAll();
            octagonButton.selected = true;
            selectedTool = OCTAGON;
        }
        else if (upButton.contains(x, y)) {
            delesectAll();
            upButton.selected = true;
            selectedTool = UP;
        }
        else if (downButton.contains(x, y)) {
            delesectAll();
            downButton.selected = true;
            selectedTool = DOWN;
        }
    }

    Tool getSelectedTool(){
        return selectedTool;
    }

    void setSelectedTool(Tool tool) {
        delesectAll();

        selectedTool = tool;

        switch (tool) {
            case PENCIL:
                pencilButton.selected = true;
                break;
            case ERASER:
                eraserButton.selected = true;
                break;
            case SQUARE:
                squareButton.selected = true;
                break;
            case CIRCLE:
                circleButton.selected = true;
                break;
            case CLEAR:
                trashButton.selected = true;
                break;
            case MOUSE:
                mouseButton.selected = true;
                break;
            case TRIANGLE:
                triangleButton.selected = true;
                break;
            case OCTAGON:
                octagonButton.selected = true;
                break;
            case UP:
                upButton.selected = true;
                break;
            case DOWN:
                downButton.selected = true;
                break;
            default:
                break;
        }
    }

    void selectEraser(){
        delesectAll();
        eraserButton.selected = true;
        selectedTool = ERASER;
    }
};

#endif
