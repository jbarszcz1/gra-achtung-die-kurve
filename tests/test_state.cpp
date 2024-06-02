#include "game_state.h"
#include "raylib.h"
#include "gtest/gtest.h"

// Test fixture for GameState
class GameStateTest : public ::testing::Test {
protected:
    GameState state;
};

TEST_F(GameStateTest, Initialization) {
    EXPECT_EQ(state.currentScreen, TITLE);
    EXPECT_FALSE(state.gameOver);
    EXPECT_FALSE(state.countdownActive);
    EXPECT_EQ(state.countdownValue, 3);
    EXPECT_EQ(state.Players.size(), 0);
}

TEST_F(GameStateTest, AddPlayer) {
    Snake snake(RED, KEY_A, KEY_D, "Red");
    state.Players.push_back(snake);
    EXPECT_EQ(state.Players.size(), 1);
}

TEST_F(GameStateTest, GameOver) {
    state.gameOver = true;
    EXPECT_TRUE(state.gameOver);
}

TEST_F(GameStateTest, Countdown) {
    state.countdownActive = true;
    state.countdownValue = 2;
    EXPECT_TRUE(state.countdownActive);
    EXPECT_EQ(state.countdownValue, 2);
}
