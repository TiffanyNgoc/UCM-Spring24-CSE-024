#ifndef PAINT_APP_H
#define PAINT_APP_H

#include <GL/freeglut.h>
#include "Rectangle.h"
#include "Square.h"
#include "Button.h"
#include "Texture.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>

enum TOOL {PENCIL, ERASER, SQUARE, CIRCLE, TRIANGLE, MOUSE, RESIZE};
enum COLOR {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK, WHITE};

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
    Rectangle blackButton;
    Rectangle whiteButton;

    Texture mouseButton;
    Texture pencilButton;
    Texture eraserButton;
    Texture squareButton;
    Button circleButton;
    Button triangleButton;
    Button reSizeButton;

    Button clearButton;
    TOOL selectedTool;
    COLOR selectedColor;
    Color currentColor;

    Point points[100000];
    int pCounter;

    Point points2[100000];
    int pCounter2;

    Point points3[100000];
    int pCounter3;

    Square squares[1000];
    int sCounter;
    int selectedSquare;
    float offsetX;
    float offsetY;

    Circle circles[1000];
    int cCounter;
    int selectedCircle;
    float cOffsetX;
    float cOffsetY;

    Triangle triangles[1000];
    int tCounter;
    int selectedTriangle;
    float tOffsetX;
    float tOffsetY;

    Button smallStrokeBtn;
    Button mediumStrokeBtn;
    Button bigStrokeBtn;

    float pointSize;

    PaintApp() {
        verticalToolbar = Rectangle(-1.0f, 1.0f, 0.4f, 2.0f, Color(0.7f, 0.7f, 0.7f));
        horizontalToolbar = Rectangle(-0.6f, -0.6f, 1.8f, 0.4f, Color(0.7f, 0.7f, 0.7f));
        canvas = Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, Color(0.9f, 0.9f, 0.9f));

        redButton = Rectangle(-0.6f, -0.8f, 0.2f, 0.2f, Color(1.0f, 0.0f, 0.0f));
        orangeButton = Rectangle(-0.6f, -0.6f, 0.2f, 0.2f, Color(1.0f, 0.5f, 0.0f));
        yellowButton = Rectangle(-0.4f, -0.6f, 0.2f, 0.2f, Color(1.0f, 1.0f, 0.0f));
        greenButton = Rectangle(-0.4f, -0.8f, 0.2f, 0.2f, Color(0.0f, 1.0f, 0.0f));
        blueButton = Rectangle(-0.2f, -0.8f, 0.2f, 0.2f, Color(0.0f, 0.0f, 1.0f));
        purpleButton = Rectangle(-0.2f, -0.6f, 0.2f, 0.2f, Color(0.6f, 0.0f, 1.0f));
        blackButton = Rectangle(0.0f, -0.6f, 0.2f, 0.2f, Color(0.0f, 0.0f, 0.0f));
        whiteButton = Rectangle(0.0f, -0.8f, 0.2f, 0.2f, Color(1.0f, 1.0f, 1.0f));

        clearButton = Button("Clear", 0.7f, -0.8f);

        mouseButton = Texture("assets/mouse.png", -1.0f, 1.0f, 0.2f, 0.2f);
        pencilButton = Texture("assets/pencil.png", -1.0f, 0.8f, 0.2f, 0.2f);
        eraserButton = Texture("assets/eraser.png", -1.0f, 0.6f, 0.2f, 0.2f);
        squareButton = Texture("assets/square.png", -1.0f, 0.4f, 0.2f, 0.2f);
        circleButton = Button("Circle", -1.0f, 0.2f);
        triangleButton = Button("Tri", -1.0f, 0.0f);
        reSizeButton = Button("Resize", -1.0f, -0.2f);

        selectedTool = PENCIL;
        selectedColor = RED;
        currentColor.setRed();

        pCounter = 0; // 1st points counter
        pCounter2 = 0; // 2nd points counter
        pCounter3 = 0;

        sCounter = 0; // Square counter
        selectedSquare = -1;
        offsetX = 0;
        offsetY = 0;

        cCounter = 0; // Circle counter
        selectedCircle = -1;
        cOffsetX = 0;
        cOffsetY = 0;

        tCounter = 0; // Triangle counter
        selectedTriangle = -1;
        tOffsetX = 0;
        tOffsetY = 0;

        // Stroke size buttons
        pointSize = 1.0f;
        smallStrokeBtn = Button("S", -1.0f, -0.8f);
        mediumStrokeBtn = Button("M", -1.0f, -0.6f);
        bigStrokeBtn = Button("L", -1.0f, -0.4f);
    }

    // Set point size
    void setPointSize(float size) {
        pointSize = size;
    }

    // Get point size
    float getPointSize() const {
        return pointSize;
    }

    void init() {
        mouseButton.loadTexture();
        pencilButton.loadTexture();
        eraserButton.loadTexture();
        squareButton.loadTexture();
    }

    void leftMouseDown(float x, float y) {
        if (pencilButton.isClicked(x, y)) {
            selectedTool = PENCIL;
            reSizeButton.pressed = false;
        } else if (eraserButton.isClicked(x, y)) {
            selectedTool = ERASER;
            reSizeButton.pressed = false;
        } else if (squareButton.isClicked(x, y)) {
            selectedTool = SQUARE;
            reSizeButton.pressed = false;
        } else if (mouseButton.isClicked(x, y)) {
            selectedTool = MOUSE;
            reSizeButton.pressed = false;
        } else if (circleButton.isClicked(x, y)) {
            selectedTool = CIRCLE;
            reSizeButton.pressed = false;
        } else if (triangleButton.isClicked(x, y)) {
            selectedTool = TRIANGLE;
            reSizeButton.pressed = false;
        } else if (reSizeButton.isClicked(x, y)) {
            selectedTool = RESIZE;
        }

        if (redButton.isClicked(x, y)) {
            selectedColor = RED;
            currentColor.setRed();
        } else if (orangeButton.isClicked(x, y)) {
            selectedColor = ORANGE;
            currentColor.setOrange();
        } else if (yellowButton.isClicked(x, y)) {
            selectedColor = YELLOW;
            currentColor.setYellow();
        } else if (greenButton.isClicked(x, y)) {
            selectedColor = GREEN;
            currentColor.setGreen();
        } else if (blueButton.isClicked(x, y)) {
            selectedColor = BLUE;
            currentColor.setBlue();
        } else if (purpleButton.isClicked(x, y)) {
            selectedColor = PURPLE;
            currentColor.setPurple();
        } else if (blackButton.isClicked(x, y)) {
            selectedColor = BLACK;
            currentColor.setBlack();
        } else if (whiteButton.isClicked(x, y)) {
            selectedColor = WHITE;
            currentColor.setWhite();
        } else if (clearButton.isClicked(x, y)) {
            pCounter = 0;
            pCounter2 = 0;
            pCounter3 = 0;
            sCounter = 0;
            cCounter = 0;
            tCounter = 0;
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            clearButton.pressed = true;
            clearButton.pressed = false;
            reSizeButton.pressed = false;
        } else if (smallStrokeBtn.isClicked(x, y)) {
            pointSize = 1.0f; // Small stroke size
            std::cout << "small was clicked" << std::endl;
            smallStrokeBtn.pressed = true;
            mediumStrokeBtn.pressed = false;
            bigStrokeBtn.pressed = false;
            reSizeButton.pressed = false;
        } else if (mediumStrokeBtn.isClicked(x, y)) {
            pointSize = 5.0f; // Medium stroke size
            std::cout << "med was clicked" << std::endl;
            mediumStrokeBtn.pressed = true;
            smallStrokeBtn.pressed = false;
            bigStrokeBtn.pressed = false;
            reSizeButton.pressed = false;
        } else if (bigStrokeBtn.isClicked(x, y)) {
            pointSize = 10.0f; // Large stroke size
            std::cout << "big was clicked" << std::endl;
            bigStrokeBtn.pressed = true;
            smallStrokeBtn.pressed = false;
            mediumStrokeBtn.pressed = false;
            reSizeButton.pressed = false;
        } else if (reSizeButton.isClicked(x, y)) {
            reSizeButton.pressed = true;
            bigStrokeBtn.pressed = false;
            smallStrokeBtn.pressed = false;
            mediumStrokeBtn.pressed = false;
            
        }

        if (canvas.isClicked(x, y)){
            if (selectedTool == PENCIL){
                // Draw the point there
                if (pointSize == 1.0f && pCounter < 10000) {
                    points[pCounter] = Point(x, y, currentColor);
                    pCounter++;
                } else if (pointSize == 5.0f && pCounter2 < 10000) {
                    points2[pCounter2] = Point(x, y, currentColor);
                    pCounter2++;
                } else if (pointSize == 10.0f && pCounter3 < 10000) {
                    points3[pCounter3] = Point(x, y, currentColor);
                    pCounter3++;
                }
            }
            else if (selectedTool == ERASER){
                // Implement what should happen for ERASER
                erase(x, y);
            }
            else if (selectedTool == SQUARE){
                // Plase a square of the correct color
                // at the coordinates of the click

                squares[sCounter] = Square(x, y, 0.3f, 0.3f, currentColor);
                sCounter++;
            }
            else if (selectedTool == CIRCLE) {
                circles[cCounter] = Circle(x, y, 0.1f, currentColor);
                cCounter++;
            }
            else if (selectedTool == TRIANGLE) {
                float sizeT = 0.3;
                triangles[tCounter] = Triangle(x, y, x + sizeT, y - sizeT, x - sizeT, y - sizeT, currentColor);
                tCounter++;
            }
            else if (selectedTool == MOUSE || RESIZE){
                // Check if the mouse pointer falls
                // inside a rectangle, and if so,
                // select it
                for (int i = 0; i < sCounter; i++){
                    squares[i].selected = false;
                }

                selectedSquare = -1;

                for (int i = sCounter-1; i >= 0; i--){
                    if (squares[i].isClicked(x, y)){
                        squares[i].selected = true;
                        selectedSquare = i;
                        offsetX = x - squares[i].x;
                        offsetY = squares[i].y - y;
                        squares[i].color = currentColor;
                        break;
                    }
                }

                for (int i = 0; i < cCounter; i++) {
                    circles[i].selected = false;
                }

                selectedCircle = -1;

                for (int i = cCounter-1; i >= 0; i--) {
                    if (circles[i].isClicked(x, y)) {
                        circles[i].selected = true;
                        selectedCircle = i;
                        cOffsetX = x - circles[i].x;
                        cOffsetY = circles[i].y - y;
                        circles[i].color = currentColor;
                        break;
                    }
                }

                for (int i = 0; i < tCounter; i++) {
                    triangles[i].selected = false;
                }

                selectedTriangle = -1;

                for (int i = tCounter-1; i >= 0; i--) {
                    if (triangles[i].isClicked(x, y)) {
                        triangles[i].selected = true;
                        selectedTriangle = i;
                        tOffsetX = x - triangles[i].x1;
                        tOffsetY = triangles[i].y1 - y;
                        triangles[i].color = currentColor;
                        break;
                    }
                }
            }
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
        if (canvas.isClicked(x, y)){
            // Draw the point there
            if (selectedTool == PENCIL){
                if (pointSize == 1.0f && pCounter < 10000) {
                    points[pCounter] = Point(x, y, currentColor);
                    pCounter++;
                } else if (pointSize == 5.0f && pCounter2 < 10000) {
                    points2[pCounter2] = Point(x, y, currentColor);
                    pCounter2++;
                } else if (pointSize == 10.0f && pCounter3 < 10000) {
                    points3[pCounter3] = Point(x, y, currentColor);
                    pCounter3++;
                }
            }
            else if (selectedTool == MOUSE) {
                // Movement for square
                if (selectedSquare >= 0){
                    squares[selectedSquare].x = x - offsetX;
                    squares[selectedSquare].y = y + offsetY;
                }
                // Movement for circle
                else if (selectedCircle >= 0) {
                    circles[selectedCircle].x = x - cOffsetX;
                    circles[selectedCircle].y = y - cOffsetY;
                }
                // Movement for triangle
                else if (selectedTriangle >= 0) {
                    float dx = x - triangles[selectedTriangle].x1;
                    float dy = y - triangles[selectedTriangle].y1;

                    // Update all three vertices of triangle
                    triangles[selectedTriangle].x1 += dx;
                    triangles[selectedTriangle].y1 += dy;
                    triangles[selectedTriangle].x2 += dx;
                    triangles[selectedTriangle].y2 += dy;
                    triangles[selectedTriangle].x3 += dx;
                    triangles[selectedTriangle].y3 += dy;
                }
            }
            else if (selectedTool == RESIZE) {
                // Handle resizing for squares
                if (selectedTool == RESIZE && selectedSquare >= 0 && squares[selectedSquare].selected) {
                    float width = x - squares[selectedSquare].x;
                    float height = squares[selectedSquare].y - y;
                    squares[selectedSquare].w = width;
                    squares[selectedSquare].h = height;
                }
                // Handle resizing for circles
                else if (selectedTool == RESIZE && selectedCircle >= 0 && circles[selectedCircle].selected) {
                    float dx = x - circles[selectedCircle].x;
                    float dy = y - circles[selectedCircle].y;
                    circles[selectedCircle].radius = sqrt(dx*dx + dy*dy);
                }
                // Handle resizing for triangles
                else if (selectedTool == RESIZE && selectedTriangle >= 0 && triangles[selectedTriangle].selected) {
                    // Resize triangle while maintaining its shape
                    // Calculate scale factor based on initial and current mouse positions
                    float scaleFactor = sqrt(pow(x - triangles[selectedTriangle].x1, 2) + pow(y - triangles[selectedTriangle].y1, 2)) / sqrt(pow(triangles[selectedTriangle].x2 - triangles[selectedTriangle].x1, 2) + pow(triangles[selectedTriangle].y2 - triangles[selectedTriangle].y1, 2));
                    // Update coords of vertices accordingly
                    triangles[selectedTriangle].x2 = triangles[selectedTriangle].x1 + (triangles[selectedTriangle].x2 - triangles[selectedTriangle].x1) * scaleFactor;
                    triangles[selectedTriangle].y2 = triangles[selectedTriangle].y1 + (triangles[selectedTriangle].y2 - triangles[selectedTriangle].y1) * scaleFactor;
                    triangles[selectedTriangle].x3 = triangles[selectedTriangle].x1 + (triangles[selectedTriangle].x3 - triangles[selectedTriangle].x1) * scaleFactor;
                    triangles[selectedTriangle].y3 = triangles[selectedTriangle].y1 + (triangles[selectedTriangle].y3 - triangles[selectedTriangle].y1) * scaleFactor;
                }
            }
            else if (selectedTool == ERASER) {
                erase(x, y);
            }
        }
    }

    void keyboardDown(unsigned char key, float x, float y) {
        // 
    }

    void render() {
        if (selectedTool == PENCIL) {
            mouseButton.selected = false;
            pencilButton.selected = true;
            eraserButton.selected = false;
            squareButton.selected = false;
            circleButton.pressed = false;
            triangleButton.pressed = false;
        } else if (selectedTool == ERASER) {
            mouseButton.selected = false;
            pencilButton.selected = false;
            eraserButton.selected = true;
            squareButton.selected = false;
            circleButton.pressed = false;
            triangleButton.pressed = false;
        } else if (selectedTool == SQUARE) {
            mouseButton.selected = false;
            pencilButton.selected = false;
            eraserButton.selected = false;
            squareButton.selected = true;
            circleButton.pressed = false;
            triangleButton.pressed = false;
        } else if (selectedTool == MOUSE) {
            mouseButton.selected = true;
            pencilButton.selected = false;
            eraserButton.selected = false;
            squareButton.selected = false;
            circleButton.pressed = false;
            triangleButton.pressed = false;
        } else if (selectedTool == CIRCLE) {
            mouseButton.selected = false;
            pencilButton.selected = false;
            eraserButton.selected = false;
            squareButton.selected = false;
            circleButton.pressed = true;
            triangleButton.pressed = false;
        } else if (selectedTool == TRIANGLE) {
            mouseButton.selected = false;
            pencilButton.selected = false;
            eraserButton.selected = false;
            squareButton.selected = false;
            circleButton.pressed = false;
            triangleButton.pressed = true;
        }

        if (selectedColor == RED) {
            redButton.selected = true;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == ORANGE) {
            redButton.selected = false;
            orangeButton.selected = true;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == YELLOW) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = true;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == GREEN) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = true;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == BLUE) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = true;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == PURPLE) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = true;
            blackButton.selected = false;
            whiteButton.selected = false;
        } else if (selectedColor == BLACK) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = true;
            whiteButton.selected = false;
        } else if (selectedColor == WHITE) {
            redButton.selected = false;
            orangeButton.selected = false;
            yellowButton.selected = false;
            greenButton.selected = false;
            blueButton.selected = false;
            purpleButton.selected = false;
            blackButton.selected = false;
            whiteButton.selected = true;
        }

        canvas.draw();

        glPointSize(pointSize);

        for (int i = 0; i < pCounter; i++){
            points[i].draw();
        }

        for (int i = 0; i < pCounter2; i++){
            points2[i].draw();
        }

        for (int i = 0; i < pCounter3; i++){
            points3[i].draw();
        }

        for (int i = 0; i < sCounter; i++){
            squares[i].draw();
        }

        for (int i = 0; i < cCounter; i++) {
            circles[i].draw();
        }

        for (int i = 0; i < tCounter; i++) {
            triangles[i].draw();
        }


        verticalToolbar.draw();
        horizontalToolbar.draw();

        redButton.draw();
        orangeButton.draw();
        yellowButton.draw();
        greenButton.draw();
        blueButton.draw();
        purpleButton.draw();
        blackButton.draw();
        whiteButton.draw();
        clearButton.draw();

        mouseButton.draw();
        pencilButton.draw();
        eraserButton.draw();
        squareButton.draw();
        circleButton.draw();
        triangleButton.draw();

        smallStrokeBtn.draw();
        mediumStrokeBtn.draw();
        bigStrokeBtn.draw();
        reSizeButton.draw();

        if (pointSize == 0.1f) {
            smallStrokeBtn.pressed = true;
            mediumStrokeBtn.pressed = false;
            bigStrokeBtn.pressed = false;
        } else if (pointSize == 0.5f) {
            smallStrokeBtn.pressed = false;
            mediumStrokeBtn.pressed = true;
            bigStrokeBtn.pressed = false;
        } else if (pointSize == 2.0f) {
            smallStrokeBtn.pressed = false;
            mediumStrokeBtn.pressed = false;
            bigStrokeBtn.pressed = true;
        }
    }

    void erase(float x, float y) {
        // Iterate through points and squares to check if they need to be removed
        for (int i = 0; i < pCounter; i++) {
            // Calculate the distance between the point and the mouse pointer
            float distance = sqrt(pow(points[i].x - x, 2) + pow(points[i].y - y, 2));
            // If distance within certain threshold, then remove the point
            if (distance < 0.05) {
                // Shift all remaining points to fill in gap left by removed point
                for (int j = i; j < pCounter - 1; j++) {
                    points[j] = points[j + 1];
                }
                pCounter--;
            }
        }
        for (int i = 0; i < pCounter2; i++) {
            float distance = sqrt(pow(points2[i].x - x, 2) + pow(points2[i].y - y, 2));
            if (distance < 0.05) {
                for (int j = i; j < pCounter2 - 1; j++) {
                    points2[j] = points2[j + 1];
                }
                pCounter2--;
            }
        }
        for (int i = 0; i < pCounter3; i++) {
            float distance = sqrt(pow(points3[i].x - x, 2) + pow(points3[i].y - y, 2));
            if (distance < 0.05) {
                for (int j = i; j < pCounter3 - 1; j++) {
                    points3[j] = points3[j + 1];
                }
                pCounter3--;
            }
        }
        for (int i = 0; i < sCounter; i++) {
            float distance = sqrt(pow(squares[i].x - x, 2) + pow(squares[i].x - x, 2));
            if (distance < 0.05) {
                for (int j = i; j < sCounter - 1; j++) {
                    squares[j] = squares[j + 1];
                }
                sCounter--;
            }
        }
        for (int i = 0; i < cCounter; i++) {
            float distance = sqrt(pow(circles[i].x - x, 2) + pow(circles[i].x - x, 2));
            if (distance < 0.05) {
                for (int j = i; j < cCounter - 1; j++) {
                    circles[j] = circles[j + 1];
                }
                cCounter--;
            }
        }
        for (int i = 0; i < tCounter; i++) {
            float distance = sqrt(pow(triangles[i].x1 - x, 2) + pow(triangles[i].x1 - x, 2));
            if (distance < 0.05) {
                for (int j = i; j < tCounter - 1; j++) {
                    triangles[j] = triangles[j + 1];
                }
                tCounter--;
            }
        }
    }
};

#endif
