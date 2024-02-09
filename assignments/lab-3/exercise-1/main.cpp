#include <GL/freeglut.h>
#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Button.h"
#include "Color.h"

using namespace std;


// Window width and height
int width = 400;
int height = 400;



Point points[10000];
int pCounter = 0;

Rectangle redBtn(-0.8, -0.8, 0.2, 0.2, 1, 0, 0);
Rectangle orangeBtn(-0.6, -0.8, 0.2, 0.2, 1, 0.5, 0);
Rectangle yellowBtn(-0.4, -0.8, 0.2, 0.2, 1, 1, 0);
Rectangle greenBtn(-0.2, -0.8, 0.2, 0.2, 0, 1, 0);
Rectangle blueBtn(0.0, -0.8, 0.2, 0.2, 0, 0, 1);
Rectangle purpleBtn(0.2, -0.8, 0.2, 0.2, 0.6, 0, 1);

Color brushColor;

Rectangle canvas(-0.8, 1, 1.8, 1.8, 0.8, 0.8, 0.8);
Rectangle vertical(-1, 1, 0.2, 2, 0.7, 0.7, 0.7);
Rectangle horizontal(-0.8, -0.8, 1.8, 0.2, 0.6, 0.6, 0.6);

Button eraseBtn("Erase", 0.41, -0.8);
Button clearBtn("Clear", 0.71, -0.8);
Button incStrokeBtn(" + ", -0.999, 1);
Button decStrokeBtn(" - ", -0.999, 0.8);

// Convert window coordinates to Cartesian coordinates
void windowToScene(float& x, float& y) {
    x = (2.0f * (x / float(width))) - 1.0f;
    y = 1.0f - (2.0f * (y / float(height)));
}

void drawScene(){
    // Clear the screen and set it to current color (black)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Objects to be drawn go here
    glEnable(GL_POINT_SMOOTH);
    glPointSize(brushColor.strokeSize);

    canvas.draw();

    for (int i = 0; i < pCounter; i++){
        points[i].draw();
    }

    vertical.draw();
    horizontal.draw();

    redBtn.draw();
    orangeBtn.draw();
    yellowBtn.draw();
    greenBtn.draw();
    blueBtn.draw();
    purpleBtn.draw();

    eraseBtn.render();
    clearBtn.render();
    incStrokeBtn.render();
    decStrokeBtn.render();
    
    

    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    /*
        button: 0 -> left mouse button
                1 -> right mouse button
        
        state:  0 -> mouse click
                2 -> mouse release
        
        x, y:   mouse location in window relative coordinates
    */
    float mx = x;
    float my = y;
    windowToScene(mx, my); 


    // if (state == 0) {
    //     redBtn.selected = false;
    //     orangeBtn.selected = false;
    //     yellowBtn.selected = false;
    //     greenBtn.selected = false;
    //     blueBtn.selected = false;
    //     purpleBtn.selected = false;
    //     eraseBtn.down = false;
    // }

    // if (state == 1) {
    //     incStrokeBtn.down = false;
    //     decStrokeBtn.down = false;
    // }

    if (button == 0 && state == 1){
        clearBtn.down = false;
        incStrokeBtn.down = false;
        decStrokeBtn.down = false;
    }

    if (button == 0 && state == 0){
        if (canvas.inside(mx, my)){
            if (pCounter < 10000){
                points[pCounter] = Point(mx, my, brushColor);
                pCounter++;
            }
        }
        else if (horizontal.inside(mx, my)){
                if (redBtn.inside(mx, my)) {
                    cout << "Red was clicked" << endl;
                    brushColor.setRed();
                    redBtn.selected = true;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (orangeBtn.inside(mx, my)) {
                    cout << "Orange was clicked" << endl;
                    brushColor.setOrange();
                    redBtn.selected = false;
                    orangeBtn.selected = true;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (yellowBtn.inside(mx, my)) {
                    cout << "Yellow was clicked" << endl;
                    brushColor.setYellow();
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = true;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (greenBtn.inside(mx, my)) {
                    cout << "Green was clicked" << endl;
                    brushColor.setGreen();
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = true;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (blueBtn.inside(mx, my)) {
                    cout << "Blue was clicked" << endl;
                    // r = 0; g = 0; b = 1;
                    brushColor.setBlue();
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = true;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (purpleBtn.inside(mx, my)) {
                    cout << "Purple was clicked" << endl;
                    brushColor.setPurple();
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = true;
                    eraseBtn.down = false;
                }
                else if (eraseBtn.inside(mx, my)) {
                    cout << "Erase was clicked" << endl;
                    brushColor.setErase();
                    eraseBtn.down = true;
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                }
                else if (clearBtn.inside(mx, my)) {
                    cout << "Clear was clicked" << endl;
                    pCounter = 0;
                    clearBtn.down = true;
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                }
        }
        else if (vertical.inside(mx, my)){
                if (!(incStrokeBtn.inside(mx, my) || decStrokeBtn.inside(mx, my))) {
                    cout << "Clicked on Vertical" << endl;
                }
                else if (incStrokeBtn.inside(mx, my)) {
                    cout << "Increase stroke was clicked" << endl;
                    brushColor.increaseStrokeSize();
                    incStrokeBtn.down = true;
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
                }
                else if (decStrokeBtn.inside(mx, my)) {
                    cout << "Decrease stroke was clicked" << endl;
                    brushColor.decreaseStrokeSize();
                    decStrokeBtn.down = true;
                    redBtn.selected = false;
                    orangeBtn.selected = false;
                    yellowBtn.selected = false;
                    greenBtn.selected = false;
                    blueBtn.selected = false;
                    purpleBtn.selected = false;
                    eraseBtn.down = false;
        }
    }
    glutPostRedisplay();
}

void motion(int x, int y) {
    /*
        x, y:   mouse location in window relative coordinates
    */
    float mx = x;
    float my = y;
    windowToScene(mx, my); 

    if (pCounter < 10000){
        if (canvas.inside(mx, my)){
            points[pCounter] = Point(mx, my, brushColor);
            pCounter++;
        }
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    /*
        key:    ASCII character of the keyboard key that was pressed
        x, y:   mouse location in window relative coordinates
    */
}

int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Drawwww");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Set the Mouse Function
    glutMouseFunc(mouse);

    // Set the Motion Function
    glutMotionFunc(motion);

    // Set the Keyboard Funcion
    glutKeyboardFunc(keyboard);

    // Run the program
    glutMainLoop();

    return 0;
}
