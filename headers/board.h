#ifndef BOARD_H
#define BOARD_H
#include "snake.h"
#include <vector>
#include <tuple>


class Board
{
    private:
    // float size_x=1800;
    // float size_y=1000;
    // TEMPORARY for my screen
    const float screen_width=1450;
    const float screen_height=800;
    std::vector<Snake> Players;

    public:
    bool countdownActive = false;
    int countdownValue = 3;
    double countdownStartTime = 0;

    Board(std::vector<Snake> Players);
    void display_window();

    // Collisions and restarting the game
    void check_collisions();
    void reset_game();

    // Countdown handling
    void start_countdown();
    void update_countdown();

    // Game ending
    bool check_game_over() const;
    std::tuple<Color, std::string> get_winner_color() const;
};


bool operator==(const Color& lhs, const Color& rhs);
#endif //BOARD_H