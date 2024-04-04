#ifndef OCTAGON_H
#define OCTAGON_H

#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"
#include <cmath>

class Octagon : public Shape {
    float r;

public:
    Octagon() {
        x = 0.0f;
        y = 0.0f;
        r = 0.1f;
        selected = false;
    }

    Octagon(float x, float y, float r, Color color) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
            for (int i = 0; i < 8; i++) {
                float angle = 2 * M_PI * i / 8;
                glVertex2f(x + cos(angle) * r, y + sin(angle) * r);
            }
        glEnd();

        if (selected) {
            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 8; i++) {
                    float angle = 2 * M_PI * i / 8;
                    glVertex2f(x + cos(angle) * (r + 0.02f), y + sin(angle) * (r + 0.02f));
                }
            glEnd();
        }
    }

    bool contains(float mx, float my) {
        float distSquared = (x - mx) * (x - mx) + (y - my) * (y - my);
        return distSquared <= r * r;
    }

    void setColor(Color color) {
        this->color = color;
    }

    void setR(float r) {
        this->r = r;
    }

    float getR() {
        return r;
    }
};

#endif
