#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/freeglut.h>
#include "Color.h"

struct Triangle {
    float x1, y1, x2, y2, x3, y3; // Three points defining the triangle
    Color color;
    bool selected;

    Triangle() {
        x1 = 0.0f;
        y1 = 0.0f;
        x2 = 0.4f;
        y2 = 0.0f;
        x3 = 0.2f;
        y3 = 0.4f;
        selected = false;
    }

    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_TRIANGLES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glVertex2f(x3, y3);
        glEnd();

        if (selected) {
            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x1, y1);
                glVertex2f(x2, y2);
                glVertex2f(x3, y3);
            glEnd();
        }
    }

    bool isClicked(float mx, float my) {
        // Calculate the area of the triangle formed by point (mx, my) and two vertices of the triangle
        float area1 = (x1*(y2 - my) + x2*(my - y1) + mx*(y1 - y2)) / 2.0f;
        float area2 = (x1*(my - y3) + mx*(y3 - y1) + x3*(y1 - my)) / 2.0f;
        float area3 = (mx*(y2 - y3) + x2*(y3 - my) + x3*(my - y2)) / 2.0f;

        // Calculate the total area of the triangle
        float totalArea = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0f;

        // If the sum of the areas equals the area of the triangle, the point is inside
        return (area1 + area2 + area3) == totalArea;
    }
};

#endif
