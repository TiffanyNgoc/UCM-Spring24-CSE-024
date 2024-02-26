#ifndef Circle_H
#define Circle_H

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

struct Circle {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

    Circle (float x, float y, float radius, float r, float g, float b) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void draw() {
        glColor3f(r, g, b);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= 360; i++) {
            glVertex2f(x + (radius * cos(i * 3.1459 / 180)), y + (radius * sin(i * 3.14159 / 180)));
        }
        glEnd();
    }

    bool inside(float mx, float my) {
        return sqrt(pow(mx - x, 2) + pow(my - y, 2)) <= radius;
    }
};

#endif
