#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>

class Snake {
private:
    Color color;
    std::string snakeColor;
    int turn_left_key;
    int turn_right_key;
    Vector2 position;
    int margin = 50;
    float angle;
    float speed = 2.0f;
    std::vector<Vector2> trail;
    int gapCounter;
    bool makingGap = false;

public:
    Snake(Color color, int turn_left_key, int turn_right_key, std::string Color);
    void reset();

    bool is_active;

    Color get_color() const;
    std::string get_color_str() const;
    unsigned get_turn_left_key() const;
    unsigned get_turn_right_key() const;
    Vector2 get_position() const;
    unsigned get_angle() const;
    std::vector<Vector2> get_trail() const;

    void draw();
    void move();
    void update();
    bool check_self_collision() const;
    bool check_collision_with_walls(int screen_width, int screen_height) const;
    bool check_collision_with_others(const std::vector<Snake>& snakes) const;
    void draw_initial_direction_arrow() const;
};

#endif // SNAKE_H
