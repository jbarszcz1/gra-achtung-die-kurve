#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "raylib.h"
#include <vector>
#include <tuple>
#include "snake.h"

enum GameScreen { TITLE = 0, GAMEPLAY, SCORE };

// Class to create a state instance shared by Board and Game
class GameState {
public:
    // Game data
    GameScreen currentScreen = TITLE;
    std::vector<Snake> Players;

    // Game state
    bool gameInProgress = false;
    bool gameOver = false;

    // Frozen state before Score screen
    double gameOverStartTime = 0;
    const int gameOverDuration = 2;

    // Countdown before the game in Gameplay starts
    bool countdownActive = false;
    int countdownValue = 3;
    double countdownStartTime = 0;

    // Additional flags on Title screen
    double insufficientPlayersMessageTime = 0;
    bool insufficientPlayersMessageActive = false;

    // Getters
    std::tuple<Color, std::string> get_winner_color() const;
};

#endif // GAME_STATE_H

