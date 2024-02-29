#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Rectangle.h"

enum COLOR {RED, GREEN, BLUE};

struct ColorSelector{
    Rectangle area;

    ColorSelector(){
        area = Rectangle(-0.8, -0.8, 1.8, 0.2, Color(1,0,0));
    }

    void draw(){
        area.draw();

    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }


    void handleMouseClick(float x, float y){

    }
};

#endif
