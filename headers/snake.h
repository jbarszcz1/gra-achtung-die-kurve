#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include "raylib.h"
#include <unordered_map>
#include <vector>


class Snake
{
private:
    // Control keys and color
    Color color;
    int turn_left_key;
    int turn_right_key;

    // Position and movement control
    Vector2 position;
    float angle;
    float speed = 2.5f;
    std::vector<Vector2> trail;

    //Gap randomising
    int gapCounter;
    bool makingGap = false;


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