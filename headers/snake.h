#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>

class Snake {
private:
    // Colors for rendering and writing
    Color color;
    std::string snakeColor;

    // Snake control
    int turnLeftKey;
    int turnRightKey;

    // Movement
    Vector2 position;
    int margin = 50;
    float angle;
    float speed = 2.0f;

    // Trail with random gaps
    std::vector<Vector2> trail;
    int gapCounter;
    bool makingGap = false;

public:
    Snake(Color color, int turnLeftKey, int turnRightKey, std::string Color);
    void reset();

    bool is_active; // To define the winner

    // Getters
    Color get_color() const;
    std::string get_color_str() const;
    unsigned get_turn_left_key() const;
    unsigned get_turn_right_key() const;
    Vector2 get_position() const;
    unsigned get_angle() const;
    std::vector<Vector2> get_trail() const;

    // Snake rendering and movement
    void draw();
    void move();
    void update();

    // Checking different types of collisions
    bool check_self_collision() const;
    bool check_collision_with_walls(int screen_width, int screen_height) const;
    bool check_collision_with_others(const std::vector<Snake>& snakes) const;

    // Before the game itself starts
    void draw_initial_direction_arrow() const;
};

#endif // SNAKE_H
