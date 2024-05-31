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
    int margin = 50;  // set margin to prevent spawn at the window borders
    float angle;
    float speed = 2.0f;
    std::vector<Vector2> trail;

    //Gap randomising
    int gapCounter;
    bool makingGap = false;


public:
    // Initialisation and reset
    Snake(Color color, int turn_left_key, int turn_right_key);
    void reset();

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
    void move();
    void update();

    // Collision check
    bool check_self_collision () const;
    bool check_collision_with_walls(int screen_width, int screen_height) const;
    bool check_collision_with_others(const std::vector<Snake>& snakes) const;

    // Countdown screen
    void draw_initial_direction_arrow() const;

};

#endif //SNAKE_H