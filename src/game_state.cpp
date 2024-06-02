#include "game_state.h"


// Getters
std::tuple<Color, std::string> GameState::get_winner_color() const {
    for (const Snake& snake : Players) {
        if (snake.is_active) {
            return std::make_tuple(snake.get_color(), snake.get_color_str());
        }
    }
    return std::make_tuple(BLACK, "BLACK");
}
