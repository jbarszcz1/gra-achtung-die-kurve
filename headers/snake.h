#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include "raylib.h"
#include <unordered_map>
#include <vector>


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
    std::vector<Vector2> trail;


public:
    Snake(Color color, int turn_left_key, int turn_right_key);

    // Getters
    Color get_color() const;

    unsigned get_turn_left_key() const;

    unsigned get_turn_right_key() const;

    Vector2 get_position() const;

    unsigned get_angle() const;

    std::vector<Vector2> get_trail() const;

    // Draw methods
    void draw();

    // Movement mechanics
    void update();

};

#endif //SNAKE_H