#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

void drawScene(){
    // Clear the screen and set it to current color (black)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Objects to be drawn go here

    glEnable(GL_POINT_SMOOTH);

    float shiftAmountX = -0.6;  
    float shiftAmountY = -0.4;

    // Choose color

    glColor3f(0, 0, 0);
    glLineWidth(2);

    // T
    // glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(0.1 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(0.2 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(1, 0.5, 0);
    glVertex2f(0.2 + shiftAmountX, 0.2 + shiftAmountY);
    glVertex2f(0.1 + shiftAmountX, 0.2 + shiftAmountY);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0); // Red
    glVertex2f(0.0 + shiftAmountX, 0.7 + shiftAmountY);
    glVertex2f(0.3 + shiftAmountX, 0.7 + shiftAmountY);
    glColor3f(1, 0.5, 0);
    glVertex2f(0.3 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(0.0 + shiftAmountX, 0.8 + shiftAmountY);
    glEnd();

    // N
    // glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.4 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(0.5 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(0, 1, 0);
    glVertex2f(0.5 + shiftAmountX, 0.2 + shiftAmountY);
    glVertex2f(0.4 + shiftAmountX, 0.2 + shiftAmountY);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.4 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(0.7 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(0, 1, 0);
    glVertex2f(0.7 + shiftAmountX, 0.7 + shiftAmountY);
    glVertex2f(0.4 + shiftAmountX, 0.7 + shiftAmountY);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.7 + shiftAmountX, 0.7 + shiftAmountY);
    glVertex2f(0.7 + shiftAmountX, 0.2 + shiftAmountY);
    glColor3f(0, 1, 0);
    glVertex2f(0.6 + shiftAmountX, 0.2 + shiftAmountY);
    glVertex2f(0.6 + shiftAmountX, 0.7 + shiftAmountY);
    glEnd();

    // P
    // glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.9 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(1.0 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.0 + shiftAmountX, 0.2 + shiftAmountY);
    glVertex2f(0.9 + shiftAmountX, 0.2 + shiftAmountY);
    glEnd();

    // glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.9 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(1.0 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.0 + shiftAmountX, 0.7 + shiftAmountY);
    glVertex2f(0.9 + shiftAmountX, 0.7 + shiftAmountY);
    glEnd();

    // glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.9 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(1.2 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.2 + shiftAmountX, 0.7 + shiftAmountY);
    glVertex2f(0.9 + shiftAmountX, 0.7 + shiftAmountY);
    glEnd();

    // glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1.1 + shiftAmountX, 0.8 + shiftAmountY);
    glVertex2f(1.2 + shiftAmountX, 0.8 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.2 + shiftAmountX, 0.55 + shiftAmountY);
    glVertex2f(1.1 + shiftAmountX, 0.55 + shiftAmountY);
    glEnd();

    // glColor3f(0.2f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(1.1 + shiftAmountX, 0.6 + shiftAmountY);
    glVertex2f(1.2 + shiftAmountX, 0.6 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.2 + shiftAmountX, 0.53 + shiftAmountY);
    glVertex2f(1.1 + shiftAmountX, 0.53 + shiftAmountY);
    glEnd();

    // glColor3f(0.7f, 0.0f, 0.2f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.9 + shiftAmountX, 0.6 + shiftAmountY);
    glVertex2f(1.2 + shiftAmountX, 0.6 + shiftAmountY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.2 + shiftAmountX, 0.53 + shiftAmountY);
    glVertex2f(0.9 + shiftAmountX, 0.53 + shiftAmountY);
    glEnd();

    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();
}


int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL TNP");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Run the program
    glutMainLoop();

    return(0);
}
