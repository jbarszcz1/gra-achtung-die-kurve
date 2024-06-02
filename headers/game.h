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
};

#endif // GAME_H
