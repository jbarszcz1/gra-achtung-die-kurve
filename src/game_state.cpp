#include "game_state.h"


// Constructors

GameState::GameState(const GameState& other)
    : currentScreen(other.currentScreen),
      Players(other.Players),
      gameInProgress(other.gameInProgress),
      gameOver(other.gameOver),
      gameOverStartTime(other.gameOverStartTime),
      gameOverDuration(other.gameOverDuration),
      countdownActive(other.countdownActive),
      countdownValue(other.countdownValue),
      countdownStartTime(other.countdownStartTime),
      insufficientPlayersMessageTime(other.insufficientPlayersMessageTime),
      insufficientPlayersMessageActive(other.insufficientPlayersMessageActive) {}

GameState& GameState::operator=(const GameState& other) {
    if (this == &other) {
        return *this;
    }
    currentScreen = other.currentScreen;
    Players = other.Players;
    gameInProgress = other.gameInProgress;
    gameOver = other.gameOver;
    gameOverStartTime = other.gameOverStartTime;
    countdownActive = other.countdownActive;
    countdownValue = other.countdownValue;
    countdownStartTime = other.countdownStartTime;
    insufficientPlayersMessageTime = other.insufficientPlayersMessageTime;
    insufficientPlayersMessageActive = other.insufficientPlayersMessageActive;
    return *this;
}


// Getters
std::tuple<Color, std::string> GameState::get_winner_color() const {
    for (const Snake& snake : Players) {
        if (snake.is_active) {
            return std::make_tuple(snake.get_color(), snake.get_color_str());
        }
    }
    return std::make_tuple(BLACK, "BLACK");
}
