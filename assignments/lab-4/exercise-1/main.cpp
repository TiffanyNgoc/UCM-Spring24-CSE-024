#include <GL/freeglut.h>
#include "PaintApp.h"

using namespace std;

// Window width and height
int width = 400;
int height = 400;

PaintApp paintApp;

// Convert window coordinates to Cartesian coordinates
void windowToScene(float& x, float& y) {
    x = (2.0f * (x / float(width))) - 1.0f;
    y = 1.0f - (2.0f * (y / float(height)));
}

void drawScene(){
    // Clear the screen and set it to current color (black)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Objects to be drawn go here
    glEnable(GL_POINT_SMOOTH);
    
    // Set the point size
    float pointSize = paintApp.getPointSize();
    glPointSize(pointSize);

    // Render Paint App
    paintApp.render();

    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    /*
        button: 0 -> left mouse button
                2 -> right mouse button
        
        state:  0 -> mouse click
                1 -> mouse release
        
        x, y:   mouse location in window relative coordinates
    */

    float mx = x;
    float my = y;
    windowToScene(mx, my);

    if (button == 0 && state == 0) {
        paintApp.leftMouseDown(mx, my);
    } else if (button == 0 && state == 1) {
        paintApp.leftMouseUp(mx, my);
    } else if (button == 2 && state == 0) {
        paintApp.rightMouseDown(mx, my);
    } else if (button == 2 && state == 1) {
        paintApp.rightMouseUp(mx, my);
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

    paintApp.mouseMotion(mx, my);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    /*
        key:    ASCII character of the keyboard key that was pressed
        x, y:   mouse location in window relative coordinates
    */

    float mx = x;
    float my = y;

    windowToScene(mx, my);

    paintApp.keyboardDown(key, mx, my);

    glutPostRedisplay();
}

int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ur mom");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Set the Mouse Function
    glutMouseFunc(mouse);

    // Set the Motion Function
    glutMotionFunc(motion);

    // Set the Keyboard Funcion
    glutKeyboardFunc(keyboard);

    // Load textures
    paintApp.init();

    // Run the program
    glutMainLoop();


    return 0;
}
