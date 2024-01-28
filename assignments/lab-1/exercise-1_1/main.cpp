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

    float shiftingX = 0.15;  
    float shiftingY = -0.4;

    // Choose color

    glColor3f(0, 0, 0);
    glLineWidth(2);

    // Bottom of box
    glBegin(GL_QUADS);
    glVertex2f(-0.7 + shiftingX, 0.1 + shiftingY);
    glVertex2f(0.5 + shiftingX, 0.1 + shiftingY);
    glVertex2f(0.5 + shiftingX, 0.0 + shiftingY);
    glVertex2f(-0.7 + shiftingX, 0.0 + shiftingY);
    glEnd();

    // Top of box
    glBegin(GL_QUADS);
    glVertex2f(-0.7 + shiftingX, 1.0 + shiftingY);
    glVertex2f(0.5 + shiftingX, 1.0 + shiftingY);
    glVertex2f(0.5 + shiftingX, 0.9 + shiftingY);
    glVertex2f(-0.7 + shiftingX, 0.9 + shiftingY);
    glEnd();

    // Left side of box
    glBegin(GL_QUADS);
    glVertex2f(-0.8 + shiftingX, 1.0 + shiftingY);
    glVertex2f(-0.7 + shiftingX, 1.0 + shiftingY);
    glVertex2f(-0.7 + shiftingX, 0.0 + shiftingY);
    glVertex2f(-0.8 + shiftingX, 0.0 + shiftingY);
    glEnd();

    // Right side of box
    glBegin(GL_QUADS);
    glVertex2f(0.5 + shiftingX, 1.0 + shiftingY);
    glVertex2f(0.4 + shiftingX, 1.0 + shiftingY);
    glVertex2f(0.4 + shiftingX, 0.0 + shiftingY);
    glVertex2f(0.5 + shiftingX, 0.0 + shiftingY);
    glEnd();

    // D
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-0.6 + shiftingX, 0.8 + shiftingY);
    glVertex2f(-0.5 + shiftingX, 0.8 + shiftingY);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.5 + shiftingX, 0.2 + shiftingY);
    glVertex2f(-0.6 + shiftingX, 0.2 + shiftingY);
    glEnd();

    // Top of D
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5 + shiftingX, 0.8 + shiftingY);
    glVertex2f(-0.4 + shiftingX, 0.8 + shiftingY);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.4 + shiftingX, 0.75 + shiftingY);
    glVertex2f(-0.5 + shiftingX, 0.75 + shiftingY);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.4 + shiftingX, 0.75 + shiftingY);
    glVertex2f(-0.3 + shiftingX, 0.75 + shiftingY);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.3 + shiftingX, 0.7 + shiftingY);
    glVertex2f(-0.4 + shiftingX, 0.7 + shiftingY);
    glEnd();

    // Bottom of D
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.5 + shiftingX, 0.25 + shiftingY);
    glVertex2f(-0.4 + shiftingX, 0.25 + shiftingY);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.4 + shiftingX, 0.2 + shiftingY);
    glVertex2f(-0.5 + shiftingX, 0.2 + shiftingY);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex2f(-0.4 + shiftingX, 0.25 + shiftingY);
    glVertex2f(-0.3 + shiftingX, 0.25 + shiftingY);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.3 + shiftingX, 0.3 + shiftingY);
    glVertex2f(-0.4 + shiftingX, 0.3 + shiftingY);
    glEnd();
    
    // Right side of D
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.3 + shiftingX, 0.7 + shiftingY);
    glVertex2f(-0.2 + shiftingX, 0.7 + shiftingY);
    glColor3f(0, 1, 0);
    glVertex2f(-0.2 + shiftingX, 0.3 + shiftingY);
    glVertex2f(-0.3 + shiftingX, 0.3 + shiftingY);
    glEnd();

    // Top of T
    // glColor3f(1.0f, 0.0f, 0.0f); // Red
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.1 + shiftingX, 0.8 + shiftingY);
    glVertex2f(0.2 + shiftingX, 0.8 + shiftingY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.2 + shiftingX, 0.2 + shiftingY);
    glVertex2f(0.1 + shiftingX, 0.2 + shiftingY);
    glEnd();

    // Bottom of T
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0 + shiftingX, 0.7 + shiftingY);
    glVertex2f(0.3 + shiftingX, 0.7 + shiftingY);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.3 + shiftingX, 0.8 + shiftingY);
    glVertex2f(0.0 + shiftingX, 0.8 + shiftingY);
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
    glutCreateWindow("GLUT App");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Run the program
    glutMainLoop();

    return(0);
}
