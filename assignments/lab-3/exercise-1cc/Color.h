#ifndef COLOR_H
#define COLOR_H


struct Color{
    float r;
    float g;
    float b;
    float strokeSize;
    float currentMouseX;
    float currentMouseY;

    Color() {
        r = 1;
        g = 0;
        b = 0;
        strokeSize = 10;
        currentMouseX = 0;
        currentMouseY = 0;
    }

    Color (float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
        strokeSize = 10;
    }

    void setRed() {
        r = 1;
        g = 0;
        b = 0;
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

    void set(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void increaseStrokeSize() {
        strokeSize += 1;
    }

    void decreaseStrokeSize() {
        strokeSize -=1;
        if (strokeSize < 1) {
            strokeSize = 1;
        }
    }
};

#endif
