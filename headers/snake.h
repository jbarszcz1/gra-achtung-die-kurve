#pragma once
#include <iostream>

class Snake
{
    std::string color;
    char turn_left_key;
    char turn_right_key;
    int coord_x, coord_y; // Polozenie poczatkowe to chyba bedziemy losowac ?
    unsigned angle;
    public:
    Snake(std::string color, char turn_left_key, char turn_right_key);
};