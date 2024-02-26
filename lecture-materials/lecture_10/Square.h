#ifndef SQUARE_H
#define SQUARE_H

#include <GL/freeglut.h>
#include "Color.h"

struct Square {
    float x;
    float y;
    float w;
    float h;
    Color color;
    bool selected;

    Square() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.2f;
        selected = false;
    }

    Square(float x, float y, float w, float h, Color color) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();

        if (selected) {
            glColor3f(1.0f, 1.0f, 1.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x - 0.02f, y + 0.02f); // Outer rectangle
                glVertex2f(x + w + 0.02f, y + 0.02f);
                glVertex2f(x + w + 0.02f, y - h - 0.02f);
                glVertex2f(x - 0.02f, y - h - 0.02f);
            glEnd();
        }
    }

    bool isClicked(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }
};

#endif
