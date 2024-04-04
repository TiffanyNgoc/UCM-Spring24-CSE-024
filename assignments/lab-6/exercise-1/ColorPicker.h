#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"
#include <algorithm> // for std::clamp

// Define a custom clamp function
template<typename T>
T clamp(const T& value, const T& low, const T& high) {
    return (value < low) ? low : (value > high) ? high : value;
}

struct ColorPicker {
private:
    Rectangle area; // Area covering the whole color picker
    Rectangle sliderAreaRed, sliderAreaGreen, sliderAreaBlue; // Area for RGB sliders
    Rectangle indicatorRed, indicatorGreen, indicatorBlue; // Indicators for RGB values
    Color currentColor;
    float redValue, greenValue, blueValue;

    void updateCurrentColor() {
        currentColor = Color(redValue, greenValue, blueValue);
    }

public:
    ColorPicker() {
        // Initial area setup
        area = Rectangle(-0.95f, -0.95f, 1.9f, 0.3f, Color(0.8f, 0.8f, 0.8f));
        // Setup sliders and indicators for RGB
        float sliderWidth = 1.8f, sliderHeight = 0.05f;
        sliderAreaRed = Rectangle(-0.95f, -0.9f, sliderWidth, sliderHeight, Color(0.5f, 0.0f, 0.0f));
        sliderAreaGreen = Rectangle(-0.95f, -0.8f, sliderWidth, sliderHeight, Color(0.0f, 0.5f, 0.0f));
        sliderAreaBlue = Rectangle(-0.95f, -0.7f, sliderWidth, sliderHeight, Color(0.0f, 0.0f, 0.5f));
        indicatorRed = Rectangle(-0.95f, -0.9f, 0.05f, sliderHeight, Color(1.0f, 0.0f, 0.0f));
        indicatorGreen = Rectangle(-0.95f, -0.8f, 0.05f, sliderHeight, Color(0.0f, 1.0f, 0.0f));
        indicatorBlue = Rectangle(-0.95f, -0.7f, 0.05f, sliderHeight, Color(0.0f, 0.0f, 1.0f));
        // Initial color values
        redValue = greenValue = blueValue = 0.0f; // Default to black
        updateCurrentColor();
    }

    Color getCurrentColor() {
        return currentColor;
    }

    void handleMouseClick(float x, float y) {
        // Check if click is within any slider area and set the respective color value
        if (sliderAreaRed.contains(x, y)) {
            redValue = clamp((x + 0.95f) / 1.8f, 0.0f, 1.0f);
            indicatorRed.setX(x - (indicatorRed.getW() / 2)); // Center the indicator on the click
        } else if (sliderAreaGreen.contains(x, y)) {
            greenValue = clamp((x + 0.95f) / 1.8f, 0.0f, 1.0f);
            indicatorGreen.setX(x - (indicatorGreen.getW() / 2));
        } else if (sliderAreaBlue.contains(x, y)) {
            blueValue = clamp((x + 0.95f) / 1.8f, 0.0f, 1.0f);
            indicatorBlue.setX(x - (indicatorBlue.getW() / 2));
        }
        updateCurrentColor(); // Update current color based on the new RGB values
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

    bool contains(float x, float y) {
        return area.contains(x, y);
    }

};

#endif
