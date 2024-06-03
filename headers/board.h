#ifndef BOARD_H
#define BOARD_H

#include "snake.h"
#include "button_data.h"
#include "game_state.h"
#include <vector>
#include <tuple>

class Board {
private:
    GameState& state;  // Shared GameState instance
    const float screen_width = 1450;
    const float screen_height = 800;
    std::vector<ButtonData> buttons;

public:
    Board(GameState& state);

    // Screens
    void handle_title_screen(Vector2 mousePoint);
    void handle_gameplay_screen();
    void handle_score_screen();

    // Draw methods
    void draw_title_screen();
    void draw_gameplay_screen();
    void draw_score_screen();

    // Gameplay
    void check_collisions(std::vector<Snake>& Players);

    // Getters
    float get_screen_width() const;
    float get_screen_height() const;
};

#endif // BOARD_H
