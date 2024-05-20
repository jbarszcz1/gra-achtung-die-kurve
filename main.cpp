
#include <iostream>
#include <vector>
#include "board.h"
#include "snake.h"

int main()
{
    Snake s1("RED",'a','d');
    std::vector<Snake> Players;
    Players.push_back(s1);
    Board board(Players);
    board.display_window();

    return 0;
}