#ifndef BOARD_H
#define BOARD_H
#include "snake.h"
#include <vector>


class Board
{
    private:
    float size_x=1800;
    float size_y=1000;
    std::vector<Snake> Players;

    public:
    Board(std::vector<Snake> Players);
    void display_window();
};

bool operator==(const Color& lhs, const Color& rhs);
#endif //BOARD_H