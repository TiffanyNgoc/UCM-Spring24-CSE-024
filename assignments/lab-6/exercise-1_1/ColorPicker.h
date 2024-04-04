#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"
#include "Circle.h"
#include <algorithm>

struct RGBSlider {
private:
    Rectangle area;
    float value; // Value between 0 and 1
    Circle sliderButton;

public:
    RGBSlider(float x, float y, float w, float h, float initialValue)
        : area(x, y, w, h, Color(0.8f, 0.8f, 0.8f)), value(initialValue) {
        float buttonX = x + value * (w - h);
        sliderButton = Circle(buttonX, y + h / 2.0f, h / 2.0f, Color(0.5f, 0.5f, 0.5f));
    }

    void setValue(float newValue) {
        value = newValue;
        float buttonX = area.getX() + value * (area.getW() - area.getH());
        sliderButton.setX(buttonX);
    }

    float getValue() const {
        return value;
    }

    void draw() {
        area.draw();
        sliderButton.draw();
    }

    bool contains(float x, float y) const {
        return area.contains(x, y);
    }

    void updateSliderPosition(float mx) {
        float newX = std::max(area.getX(), std::min(area.getX() + area.getW(), mx - area.getH() / 2.0f));
        sliderButton.setX(newX);
        value = (newX - area.getX()) / (area.getW() - area.getH());
    }
};

#endif
