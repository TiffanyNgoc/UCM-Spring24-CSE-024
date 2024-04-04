#ifndef SQUARE_H
#define SQUARE_H

#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

class Square : public Shape{

    float w;
    float h;
    
public:
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
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();

        if (selected) {
            glColor3f(0.0f, 0.0f, 0.0f);
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x - 0.02f, y + 0.02f); // Outer rectangle
                glVertex2f(x + w + 0.02f, y + 0.02f);
                glVertex2f(x + w + 0.02f, y - h - 0.02f);
                glVertex2f(x - 0.02f, y - h - 0.02f);
            glEnd();
        }
    }

    bool contains(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }

    void setColor(Color color){
        this->color = color;
    }

    void setW(float w){
        this->w = w;
    }

    void setH(float h){
        this->h = h;
    }

    float getW(){
        return w;
    }

    float getH(){
        return h;
    }

};

#endif
