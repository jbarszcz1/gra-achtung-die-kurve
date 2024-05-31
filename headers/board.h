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
    bool countdownActive = false;
    int countdownValue = 5;
    double countdownStartTime = 0;

    Board(std::vector<Snake> Players);
    void display_window();

    // Collisions and restarting the game
    void check_collisions();
    void reset_game();

    // Countdown handling
    void start_countdown();
    void update_countdown();
};


bool operator==(const Color& lhs, const Color& rhs);
#endif //BOARD_H