#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "raylib.h"
#include <vector>
#include <tuple>
#include "snake.h"

enum GameScreen { TITLE = 0, GAMEPLAY, SCORE };

class GameState {
public:
    GameScreen current_screen = TITLE;
    std::vector<Snake> Players;
    bool gameInProgress = false;
    bool gameOver = false;
    double gameOverStartTime = 0;
    const int gameOverDuration = 2;
    bool countdownActive = false;
    int countdownValue = 3;
    double countdownStartTime = 0;
    double insufficientPlayersMessageTime = 0;
    bool insufficientPlayersMessageActive = false;

    std::tuple<Color, std::string> get_winner_color() const;
};

#endif // GAME_STATE_H

