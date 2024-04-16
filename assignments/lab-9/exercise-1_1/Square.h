#ifndef SQUARE_H
#define SQUARE_H

#include <GL/gl.h>
#include <cmath>

enum SquareState {EMPTY, PLAYER_X, PLAYER_O};

class Square {
    float x;
    float y;
    float size;
    SquareState state;

public:
    Square() : x(0.0f), y(0.0f), size(0.6f), state(EMPTY) {}

    Square(float x, float y, float size) : x(x), y(y), size(size), state(EMPTY) {}

    bool isEmpty() const {
        return state == EMPTY;
    }

    void playX() {
        state = PLAYER_X;
    }

    void playO() {
        state = PLAYER_O;
    }

    SquareState getState() const{
        return state;
    }

    void draw() {
        glColor3f(0.0f, 0.0f, 0.0f);
        // glLineWidth(2.0f);

        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + size, y);

            glVertex2f(x + size, y);
            glVertex2f(x + size, y - size);

            glVertex2f(x + size, y - size);
            glVertex2f(x, y - size);

            glVertex2f(x, y - size);
            glVertex2f(x, y);
        glEnd();

        if (state == PLAYER_X) {
            glColor3f(1.0f, 0.0f, 0.0f);
            glBegin(GL_LINES);
                glVertex2f(x + 0.1f * size, y - 0.1f * size);
                glVertex2f(x + 0.9f * size, y - 0.9f * size);
                glVertex2f(x + 0.9f * size, y - 0.1f * size);
                glVertex2f(x + 0.1f * size, y - 0.9f * size);
            glEnd();
        } else if (state == PLAYER_O) {
            glColor3f(0.0f, 0.0f, 1.0f);
            float centerX = x + size / 2;
            float centerY = y - size / 2;
            float radius = size * 0.4f;
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i <= 360; i++) {
                float angle = 2.0f * 3.14159f * i / 360;
                float dx = radius * cosf(angle);
                float dy = radius * sinf(angle);
                glVertex2f(centerX + dx, centerY - dy);
            }
            glEnd();
        }
    }

    bool contains(float mx, float my) {
        if (mx >= x && mx <= x + size && my <= y && my >= y - size) {
            return true;
        } else {
            return false;
        }
    }
};

#endif
