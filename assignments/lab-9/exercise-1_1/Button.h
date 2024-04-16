#ifndef BUTTON_H
#define BUTTON_H

#include <GL/freeglut.h>
#include <string>

struct Button {
    std::string text;
    float x, y, w, h;
    bool pressed;

    Button() : x(0.0f), y(0.0f), w(0.4f), h(0.2f), text("Button"), pressed(false) {}

    Button(std::string text, float x, float y) : text(text), x(x), y(y), w(0.4f), h(0.2f), pressed(false) {}

    void draw() {
        float textWidth = 0.0f;
        for (char c : text) {
            textWidth += glutBitmapWidth(GLUT_BITMAP_9_BY_15, c);
        }
        float padding = 0.06;
        textWidth = 2.0f * (textWidth / 400.0);
        w = textWidth + padding;

        if (pressed) {
            glColor3f(0.8f, 0.8f, 0.8f);
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
            glVertex2f(x, y - h);
            glVertex2f(x, y);
        glEnd();

        glRasterPos2f(x + (padding / 2), y - (h / 2) - 0.025);
        for (char c : text) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }

    bool contains(float mx, float my) {
        return mx >= x && mx <= x + w && my <= y && my >= y - h;
    }

    void setPressed(bool state) {
        pressed = state;
    }

    void togglePressed() {
        pressed = !pressed;
    }
};

#endif
