#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake.h"

//    unsigned size_x=1800;
//    unsigned size_y=1000;

Snake::Snake(std::string color, char turn_left_key, char turn_right_key): color(color), turn_left_key(turn_left_key), turn_right_key(turn_right_key)
 {
    srand( time( NULL ) );
    angle = (std::rand() % 360) + 1;
    coord_x = (std::rand() % 1300) + 100;
    coord_y = (std::rand() % 850) + 50;
 }
