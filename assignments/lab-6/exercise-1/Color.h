#ifndef COLOR_H
#define COLOR_H

#include <GL/freeglut.h>

struct Color {
private:
    float r;
    float g;
    float b;

public:
    Color() : r(0.0f), g(0.0f), b(0.0f) {}

    Color(float r, float g, float b) : r(r), g(g), b(b) {}

    void setColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    float getR() const { return r; }
    float getG() const { return g; }
    float getB() const { return b; }
    // Color() {
    //     r = 0.0f;
    //     g = 0.0f;
    //     b = 0.0f;
    // }

    // Color(float r, float g, float b) {
    //     this->r = r;
    //     this->g = g;
    //     this->b = b;
    // }

    // void setColor(float r, float g, float b) {
    //     this->r = r;
    //     this->g = g;
    //     this->b = b;
    // }

    // float getR() {
    //     return r;
    // }

    // float getG() {
    //     return g;
    // }

    // float getB() {
    //     return b;
    // }
};


#endif
