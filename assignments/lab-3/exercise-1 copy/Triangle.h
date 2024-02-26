#ifndef Triangle_H
#define Triangle_H

#include <GL/freeglut.h>
#include <GL/gl.h>

struct Triangle {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float r;
    float g;
    float b;

    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void draw() {
        glColor3f(r, g, b);
        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
    }

    bool inside(float mx, float my) {
        float sign1 = (mx - x1) * (y2 - y1) - (my - y1) * (x2 - x1);
        float sign2 = (mx - x2) * (y3 - y2) - (my - y2) * (x3 - x2);
        float sign3 = (mx - x3) * (y1 - y3) - (my - y3) * (x1 - x3);

        return (sign1 >= 0 && sign2 >= 0 && sign3 >=0) || (sign1 <= 0 && sign2 <= 0 && sign3 <=0);
    }
};

#endif
