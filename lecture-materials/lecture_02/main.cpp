#include <GL/freeglut_std.h>
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>


using namespace std;

void drawScene(){
    // Clear the screen and set it to current color (black)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Objects to be drawn go here

    glEnable(GL_POINT_SMOOTH);

    // Choose color
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(15);
    

    glBegin(GL_POINTS);

    glVertex2f(0, 0);

    glVertex2f(0.5, 0.5);

    glEnd();


    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(-1, 0);
    glVertex2f(1, 0);

    glVertex2f(0, 1);
    glVertex2f(0, -1);

    glEnd();


    glPointSize(3);
    glColor3f(1,0,0);

    glBegin(GL_POINTS);
    for (float theta = 0; theta < 2*M_PI; theta +=0.01){
        glVertex2f(0.3*cos(theta)+0.5, 0.3*sin(theta)+0.5);
    }
    glEnd();

    glColor3f(0, 1, 0);

    glBegin(GL_POLYGON);

        glVertex2f(-0.5, 0.5);

        glVertex2f(-0.5, 0.8);

        glVertex2f(-0.1, 0.5);

    glEnd();

    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();
}



int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("UCM GLUT App");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Run the program
    glutMainLoop();

    return 0;
}
