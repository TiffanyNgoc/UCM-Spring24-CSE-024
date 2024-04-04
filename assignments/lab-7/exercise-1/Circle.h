#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Shape.h"
#include "Color.h"

class Circle : public Shape {
    float r;

public:
    Circle() {
        x = 0.0f;
        y = 0.0f;
        r = 0.1f;
        selected = false;
    }

    Circle(float x, float y, float r, Color color) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
            for (float angle = 0.0f; angle < 2 * M_PI; angle += 0.01f) {
                glVertex2f(x + sin(angle) * r, y + cos(angle) * r);
            }
        glEnd();
    
        if (selected) {
            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                for (float angle = 0.0f; angle < 2* M_PI; angle += 0.01f) {
                    glVertex2f(x + sin(angle) * (r + 0.02f), y + cos(angle) * (r + 0.02f));
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
