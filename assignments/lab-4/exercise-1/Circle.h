#ifndef CIRCLE_H
#define CIRCLE_H

#include <GL/freeglut.h>
#include "Color.h"
#include <cmath>

struct Circle {
    float x;
    float y;
    float radius;
    Color color;
    bool selected;

    Circle () {
        x = 0.0f;
        y = 0.0f;
        radius = 0.2f;
        selected = false;
    }

    Circle (float x, float y, float radius, Color color) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->color = color;
        selected = false;
    }

    void draw() {
        const int numSegments = 100;
        glColor3f(color.r, color.g, color.b);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y); // Center of the circle
        for (int i = 0; i <= numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Get the current angle
            float dx = radius * cosf(theta); // Calculate the x component
            float dy = radius * sinf(theta); // Calculate the y component
            glVertex2f(x + dx, y + dy); // Output the vertex
        }
        glEnd();

        if (selected) {
            glLineWidth(2.0f); // Set outline width
            glColor3f(0.0f, 0.0f, 0.0f); // Black color for outline
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i <= numSegments; i++) {
                float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); // Get the current angle
                float dx = radius * cosf(theta); // Calculate the x component
                float dy = radius * sinf(theta); // Calculate the y component
                glVertex2f(x + dx, y + dy); // Output the vertex
            }
            glEnd();
        }
    }

    bool isClicked(float mx, float my) {
        float distance = sqrt((mx - x) * (mx - x) + (my - y) * (my - y));
        return distance <= radius;
    }
};

#endif
