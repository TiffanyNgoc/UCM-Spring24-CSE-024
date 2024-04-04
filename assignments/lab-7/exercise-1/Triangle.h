#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
    float height;

public:
    Triangle() {
        x = 0.0f;
        y = 0.0f;
        height = 0.4f;
        selected = false;
    }

    Triangle(float x, float y, float height, Color color) {
        this->x = x;
        this->y = y;
        this->height = height;
        this->color = color;
        selected = false;
    }

    void draw() {
        float side = height * sqrt(3) / 2;
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
            glVertex2f(x, y + (2.0f / 3.0f) * height);
            glVertex2f(x - side / 2, y - (1.0f / 3.0f) * height);
            glVertex2f(x + side / 2, y - (1.0f / 3.0f) * height);
        glEnd();
        
        if (selected) {
            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x, y + (2.0f / 3.0f) * height);
                glVertex2f(x - side / 2, y - (1.0f / 3.0f) * height);
                glVertex2f(x + side / 2, y - (1.0f / 3.0f) * height);
            glEnd();
        }
    }

    bool contains(float mx, float my) {
        float side = height * sqrt(3) / 2;
        return mx >= (x - side / 2) && mx <= (x + side / 2) &&
            my >= (y - (1.0f / 3.0f) * height) && my <= (y + (2.0f / 3.0f) * height);
    }

    void setColor(Color color) {
        this->color = color;
    }

    void setHeight(float height) {
        this->height = height;
    }

    float getHeight() {
        return height;
    }
};

#endif
