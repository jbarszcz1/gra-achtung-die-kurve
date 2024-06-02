#ifndef GAME_H
#define GAME_H

#include "game_state.h"
#include "board.h"

class Game {
private:
    GameState state;  // Instance of GameState
    Board board;

public:
    Game();
    void run();

    // Getters
    GameState get_state() const;

    // Setters (for testing purposes)
    void set_state(const GameState& new_state);
};

#endif // GAME_H
