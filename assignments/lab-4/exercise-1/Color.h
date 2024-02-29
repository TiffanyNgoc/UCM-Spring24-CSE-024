#ifndef COLOR_H
#define COLOR_H

#include <GL/freeglut.h>

struct Color {
    float r;
    float g;
    float b;

    Color() {
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
    }

    Color(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void setColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void setRed() {
        r = 1.0f;
        g = 0.0f;
        b = 0.0f;
    }

    void setOrange() {
        r = 1;
        g = 0.5;
        b = 0;
    }

    void setYellow() {
        r = 1;
        g = 1;
        b = 0;
    }

    void setGreen(){
        r = 0;
        g = 1;
        b = 0;
    }

    void setBlue() {
        r = 0;
        g = 0;
        b = 1;
    }

    void setPurple() {
        r = 0.6;
        g = 0;
        b = 1;
    }

    void setErase() {
        r = 0.8;
        g = 0.8;
        b = 0.8;
    }

    void setBlack() {
        r = 0.0;
        g = 0.0;
        b = 0.0;
    }

    void setWhite() {
        r = 1.0;
        g = 1.0;
        b = 1.0;
    }
};


#endif
