#ifndef BUTTON_DATA_H
#define BUTTON_DATA_H

#include "raylib.h"
#include <string>

// Structure to process buttons on the Title screen
struct ButtonData {
    Rectangle bounds;
    bool clicked;
    bool textBoxLeftActive;
    bool textBoxRightActive;
    bool drawKeyLeft;
    bool drawKeyRight;
    char inputKeyLeft;
    char inputKeyRight;
    Color color;
    std::string colorName;
};

#endif // BUTTON_DATA_H

