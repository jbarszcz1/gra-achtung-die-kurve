#pragma once
#include "snake.h"
#include <vector>

class Board
{
    private:
    unsigned size_x=1800;
    unsigned size_y=1000;
    std::vector<Snake> Players;
    public:
    Board(std::vector<Snake> Players);
    void display_window();
};