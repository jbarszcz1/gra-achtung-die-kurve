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
    std::string get_color();
    char get_turn_left_key();
    char get_turn_right_key();
    int get_coord_x();
    int get_coord_y();
    unsigned get_angle();
    Snake(std::string color, char turn_left_key, char turn_right_key);
};