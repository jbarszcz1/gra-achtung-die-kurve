#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake.h"
#include "board.h"

//    unsigned size_x=1800;
//    unsigned size_y=1000;


Snake::Snake(Color color, char turn_left_key, char turn_right_key)
    : color(color), turn_left_key(turn_left_key), turn_right_key(turn_right_key) {
    srand(time(NULL));
    angle = (std::rand() % 360) + 1;
    position = {static_cast<float>(std::rand() % 1300) + 100,
               static_cast<float>(std::rand() % 850) + 50};
}

Color Snake::get_color() {
   return color;
}

unsigned Snake::get_angle() {
    return angle;
}

Vector2 Snake::get_position() {
   return position;
}

char Snake::get_turn_right_key() {
    return turn_right_key;
}

char Snake::get_turn_left_key() {
    return turn_left_key;
}

void Snake::draw() {
    DrawCircleV(position, 10, color); // Draw the snake as a circle for simplicity
}