#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"

// Define a custom clamp function
template<typename T>
T clamp(const T& value, const T& low, const T& high) {
    return (value < low) ? low : (value > high) ? high : value;
}

struct ColorPicker {
private:
    Rectangle area;
    Rectangle sliderAreaRed, sliderAreaGreen, sliderAreaBlue; // Area for RGB sliders
    Rectangle indicatorRed, indicatorGreen, indicatorBlue; // Indicators for RGB values
    Color currentColor;
    float redValue, greenValue, blueValue;

    void updateCurrentColor() {
        currentColor = Color(clamp(redValue, 0.0f, 1.0f), clamp(greenValue, 0.0f, 1.0f), clamp(blueValue, 0.0f, 1.0f));
    }

    void updateIndicatorPosition() {
        float sliderStartX = sliderAreaRed.getX();
        float sliderWidth = sliderAreaRed.getW();

        indicatorRed.setX(sliderStartX + redValue * sliderWidth - 0.025f); // Adjusting by half the indicator's width for centering
        indicatorGreen.setX(sliderStartX + greenValue * sliderWidth - 0.025f);
        indicatorBlue.setX(sliderStartX + blueValue * sliderWidth - 0.025f);
    }

public:
    ColorPicker(){
        area = Rectangle(-0.8f, -0.7f, 1.8f, 0.4f, Color(0.8f, 0.8f, 0.8f));
        // Setup sliders and indicators for RGB
        float sliderWidth = 1.5f, sliderHeight = 0.04f;
        sliderAreaRed = Rectangle(-0.7f, -0.9f, sliderWidth, sliderHeight, Color(0.5f, 0.0f, 0.0f));
        sliderAreaGreen = Rectangle(-0.7f, -0.8f, sliderWidth, sliderHeight, Color(0.0f, 0.5f, 0.0f));
        sliderAreaBlue = Rectangle(-0.7f, -0.7f, sliderWidth, sliderHeight, Color(0.0f, 0.0f, 0.5f));
        indicatorRed = Rectangle(-0.7f, -0.9f, 0.05f, sliderHeight, Color(1.0f, 0.0f, 0.0f));
        indicatorGreen = Rectangle(-0.7f, -0.8f, 0.05f, sliderHeight, Color(0.0f, 1.0f, 0.0f));
        indicatorBlue = Rectangle(-0.7f, -0.7f, 0.05f, sliderHeight, Color(0.0f, 0.0f, 1.0f));
        // Initial color values
        redValue = greenValue = blueValue = 0.0f; // Default to black
        updateCurrentColor();
    }

    Color getCurrentColor() {
        return currentColor;
    }

    void handleMouseClick(float x, float y){
        if (sliderAreaRed.contains(x, y)) {
            // Assume sliderWidth is the actual width you can work with
            float sliderWidth = sliderAreaRed.getW();
            redValue = (x - sliderAreaRed.getX()) / sliderWidth;
            redValue = clamp(redValue, 0.0f, 1.0f);
        } else if (sliderAreaGreen.contains(x, y)) {
            float sliderWidth = sliderAreaGreen.getW();
            greenValue = (x - sliderAreaGreen.getX()) / sliderWidth;
            greenValue = clamp(greenValue, 0.0f, 1.0f);
        } else if (sliderAreaBlue.contains(x, y)) {
            float sliderWidth = sliderAreaBlue.getW();
            blueValue = (x - sliderAreaBlue.getX()) / sliderWidth;
            blueValue = clamp(blueValue, 0.0f, 1.0f);
        }
    }

    void draw() {
        area.draw();
        sliderAreaRed.draw();
        sliderAreaGreen.draw();
        sliderAreaBlue.draw();
        indicatorRed.draw();
        indicatorGreen.draw();
        indicatorBlue.draw();
        // Optionally, draw the current color as a visual feedback
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif
