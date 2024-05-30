#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake.h"
#include "board.h"



Snake::Snake(Color color, int turn_left_key, int turn_right_key)
    : color(color), turn_left_key(turn_left_key), turn_right_key(turn_right_key)
{
    srand(time(NULL));

    angle = static_cast<float>((std::rand() % 360) + 1);

    position = {static_cast<float>(std::rand() % 1300) + 100,
               static_cast<float>(std::rand() % 850) + 50};


    std::cout << "INITIALISATION" << turn_left_key << " " << char(turn_left_key) << std::endl;
    std::cout << "INITIALISATION" << turn_right_key << std::endl;
}


// GETTERS

Color Snake::get_color() {
   return color;
}

unsigned Snake::get_angle() {
    return angle;
}

Vector2 Snake::get_position() {
   return position;
}

unsigned Snake::get_turn_right_key() {
    return turn_right_key;
}

unsigned Snake::get_turn_left_key() {
    return turn_left_key;
}


// DRAW

void Snake::draw() {
    DrawCircleV(position, 10, color); // Draw the snake as a circle for simplicity
}


// MOVEMENT

void Snake::update() {

    if (IsKeyDown(turn_left_key)) {
        std::cout << "LEFT KEY" << turn_left_key << char(turn_left_key) << "  " << KEY_A << std::endl;
        angle -= 5.0f; // Turn left
    }
    if (IsKeyDown(turn_right_key)) {
        std::cout << "RIGHT KEY" << std::endl;
        angle += 5.0f; // Turn right
    }

    // Move the snake in the direction of the current angle
    position.x += cosf(DEG2RAD * angle) * speed;
    position.y += sinf(DEG2RAD * angle) * speed;

}