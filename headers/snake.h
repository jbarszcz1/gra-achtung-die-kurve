#pragma once
#include <iostream>
#include "raylib.h"
#include <unordered_map>



class Snake
{
private:
    Color color;
    char turn_left_key;
    char turn_right_key;
    //int coord_x, coord_y; // Polozenie poczatkowe to chyba bedziemy losowac ?
    Vector2 position;
    unsigned angle;


public:
    Snake(Color color, char turn_left_key, char turn_right_key);

    // Getters
    Color get_color();

    char get_turn_left_key();

    char get_turn_right_key();

    Vector2 get_position();

    unsigned get_angle();

    // Draw methods
    void draw();

};