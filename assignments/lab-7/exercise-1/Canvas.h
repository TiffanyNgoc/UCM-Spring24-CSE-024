#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Square.h"
#include "Toolbar.h"
#include "Scribble.h"
#include "Circle.h"
#include "Triangle.h"
#include "Octagon.h"
#include "ColorPicker.h"

struct Canvas{
private:
    Rectangle area;
    ColorPicker colorPicker;

    Square squares[1000];
    int sCounter;
    int selectedSquare;

    float offsetX;
    float offsetY;

    Scribble scribbles[100];
    int scribbleCounter;
    int selectedScribble;

    Shape* shapes[1000];
    int shapeCounter;
    int selectedShape;

    Circle circles[1000];
    int cCounter;
    int selectedCircle;

    Triangle triangles[1000];
    int tCounter;
    int selectedTriangle;

    Octagon octagons[1000];
    int oCounter;
    int selectedOctagon;

public:
    Canvas(){
        area = Rectangle(-0.8, 1, 1.8, 1.8, Color(1,1,1));
        scribbleCounter = 0;
        selectedScribble = -1;

        sCounter = 0;
        selectedSquare = -1;

        cCounter = 0;
        selectedCircle = -1;

        tCounter = 0;
        selectedTriangle = -1;

        oCounter = 0;
        selectedOctagon = -1;

        shapeCounter = 0;
        selectedShape = -1;

        offsetX = 0;
        offsetY = 0;
    }

    void eraseShape(float x, float y) {
        int indexToDelete = -1;

        for (int i = 0; i < shapeCounter; i++) {
            if (shapes[i]->contains(x, y)) {
                indexToDelete = i;
                break;
            }
        }
        
        if (indexToDelete != -1) {                
            delete shapes[indexToDelete];
            for (int i = indexToDelete; i < shapeCounter - 1; i++) {
                shapes[i] = shapes[i + 1];
            }

            shapeCounter--;
        }
    }

    void draw(){
        area.draw();

        for (int i = 0; i < shapeCounter; i++){
            shapes[i]->draw();
        }

        for (int i = 0; i < sCounter; i++){
            squares[i].draw();
        }

        for (int i = 0; i < scribbleCounter; i++){
            scribbles[i].draw();
        }
        for (int i = 0; i < cCounter; i++) {
            circles[i].draw();
        }
        for (int i = 0; i < tCounter; i++) {
            triangles[i].draw();
        }
        for (int i = 0; i < oCounter; i++) {
            octagons[i].draw();
        }
    }

    void handleMouseClick(float x, float y, Tool selectedTool, Color color){
        if (selectedTool == PENCIL){
            // shapes[shapeCounter] = new Scribble();
            // shapeCounter++;
            // ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, color);
            Scribble* newScribble = new Scribble();
            newScribble->addPoint(x, y, color);
            shapes[shapeCounter++] = newScribble;
        }
        else if (selectedTool == ERASER){
            // shapes[shapeCounter] = new Scribble();
            // shapeCounter++;
            // ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, Color(1, 1, 1));
            eraseShape(x, y);
        }
        else if (selectedTool == SQUARE){
            shapes[shapeCounter] = new Square(x, y, 0.2, 0.2, color);
            shapeCounter++;
        }
        else if (selectedTool == CIRCLE) {
            shapes[shapeCounter] = new Circle(x, y, 0.1f, color);
            shapeCounter++;
        }
        else if (selectedTool == TRIANGLE) {
            shapes[shapeCounter] = new Triangle(x, y, 0.2f, color);
            shapeCounter++;
        }
        else if (selectedTool == OCTAGON) {
            shapes[shapeCounter] = new Octagon(x, y, 0.1f, color);
            shapeCounter++;
        }
        else if (selectedTool == CLEAR) {
            clearScreen();
        }
        else if (selectedTool == UP) {
            moveToFront(selectedShape);
        }
        else if (selectedTool == DOWN) {
            moveToBack(selectedShape);
        }
        else if (selectedTool == MOUSE){
            bool shapeSelected = false;

            // Deselect prviously selected shape
            if (selectedShape != -1) {
                shapes[selectedShape]->deselect();
                selectedShape = -1;
            }

            // Iterate in reverse order to prioritize selecting the topmost shape
            for (int i = shapeCounter - 1; i >= 0 && !shapeSelected; i--) {
                if (shapes[i]->contains(x, y)) {
                    shapes[i]->select();
                    selectedShape = i;
                    shapeSelected = true;
                    // Calculate the offset
                    offsetX = x - shapes[i]->getX();
                    offsetY = y - shapes[i]->getY();
                    break;
                }
            }

            if (selectedShape != -1) {
                shapes[selectedShape]->setColor(color);
            }
        }
    }

    void handleMouseDrag(float x, float y, Tool selectedTool, Color color){
        if (selectedTool == PENCIL && shapeCounter > 0){
            // ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, color);
            Scribble* currentScribble = dynamic_cast<Scribble*>(shapes[shapeCounter - 1]);
            if (currentScribble) {
                currentScribble->addPoint(x, y, color);
            }
        }
        // else if (selectedTool == ERASER){
        //     // ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, Color(1, 1, 1));
            
        // }
        else if (selectedTool == MOUSE && selectedShape != -1){
            // if (selectedShape != -1) {
                shapes[selectedShape]->setX(x - offsetX);
                shapes[selectedShape]->setY(y - offsetY);
            // }
        }
        else if (selectedTool == ERASER) {
            eraseShape(x, y);
        }
    }    

    void moveToFront(int index) {
        if (index < 0 || index >= shapeCounter) return; // Invalid index
        Shape* temp = shapes[index];
        for (int i = index; i < shapeCounter - 1; i++) {
            shapes[i] = shapes[i + 1];
        }
        shapes[shapeCounter - 1] = temp;
    }

    void moveToBack(int index) {
        if (index < 0 || index >= shapeCounter) return;
        Shape* temp = shapes[index];
        for (int i = index; i > 0; i--) {
            shapes[i] = shapes[i - 1];
        }
        shapes[0] = temp;
    }

    void clearScreen() {
        // Reset all counters to 0;
        scribbleCounter = 0;
        sCounter = 0;
        cCounter = 0;
        shapeCounter = 0;
        tCounter = 0;
        oCounter = 0;

        for (int i = 0; i < shapeCounter; i++) {
            delete shapes[i];
            shapes[i] = nullptr;
        }

        selectedSquare = -1;
        selectedScribble = -1;
        selectedCircle = -1;
        selectedShape = -1;
        selectedTriangle = -1;
        selectedOctagon = -1;

        offsetX = 0;
        offsetY = 0;
    }
    

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif
