#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "AppController.h"
#include <GL/gl.h>
#include "Toolbar.h"
#include "Canvas.h"
#include "ColorSelector.h"


struct Controller : public AppController {

    Toolbar toolbar;
    Canvas canvas;
    ColorSelector colorSelector;

    Controller(){
        // colorSelector.currentColor.setColor(0, 0, 0);
    }

    void leftMouseDown( float x, float y ){
        if (toolbar.contains(x, y)){
            toolbar.handleMouseClick(x, y);
        }
        else if (canvas.contains(x, y)){
            canvas.handleMouseClick(x, y, toolbar.selectedTool, colorSelector.getCurrentColor());
        }
        else if (colorSelector.contains(x, y)){
            colorSelector.handleMouseClick(x, y);
            if (canvas.selectedSquare != -1){
                canvas.squares[canvas.selectedSquare].color = colorSelector.getCurrentColor();
            }
        }
    }

    void mouseMotion( float x, float y ){
        if (canvas.contains(x, y)){
            if (toolbar.selectedTool == PENCIL || toolbar.selectedTool == ERASER){
                canvas.handleMouseClick(x, y, toolbar.selectedTool, colorSelector.getCurrentColor());
            }
        }
    }

    void render() {
        canvas.draw();
        toolbar.draw();
        colorSelector.draw();
    }

};

#endif
