
#include <iostream>
#include <vector>
#include "board.h"
#include "snake.h"

int main()
{
    std::vector<Snake> Players;
    Board board(Players);
    board.display_window();

    return 0;
}

