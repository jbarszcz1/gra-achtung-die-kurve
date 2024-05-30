#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include "raylib.h"
#include <unordered_map>


class Snake
{
private:
    Color color;
    int turn_left_key;
    int turn_right_key;
    //int coord_x, coord_y; // Polozenie poczatkowe to chyba bedziemy losowac ?
    Vector2 position;
    float angle;
    float speed = 2.0f;


public:
    Snake(Color color, int turn_left_key, int turn_right_key);

    // Getters
    Color get_color();

    unsigned get_turn_left_key();

    unsigned get_turn_right_key();

    Vector2 get_position();

    unsigned get_angle();

    // Draw methods
    void draw();

    // Movement mechanics
    void update();

};

#endif //SNAKE_H