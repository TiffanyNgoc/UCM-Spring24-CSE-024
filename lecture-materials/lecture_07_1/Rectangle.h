#ifndef Rectangle_H
#define Rectangle_H

#include <GL/freeglut.h>
#include <GL/gl.h>

struct Rectangle{
    float w;
    float h;
    float x;
    float y;

    float r;
    float g;
    float b;

    bool selected;

    Rectangle(){
        x = 0;
        y = 0;
        w = 0.4;
        h = 0.2;
        r = 0;
        g = 0;
        b = 1;

        selected = false;
    }

    Rectangle(float x, float y, float w, float h, float r, float g, float b){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->r = r;
        this->g = g;
        this->b = b;

        selected = false;
    }

    void draw(){
        if (selected) {
            glColor3f(r * 0.5, g * 0.5, b * 0.5);
        }
        else {
            glColor3f(r, g, b);
        }

        glBegin(GL_POLYGON);

        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y - h);
        glVertex2f(x, y - h);
        glEnd();

    }

    bool inside(float mx, float my){
        if (mx >= x && mx <= x + w && my <= y && my >= y-h){
            return true;
        }
        else {
            return false;
        }
    }
};

#endif
