#include "game.h"
#include "gtest/gtest.h"

// Test fixture for Game
class GameTest : public ::testing::Test {
protected:
    Game game;
};

TEST_F(GameTest, Initialization) {
    GameState state = game.get_state();  // Get a copy of the state
    EXPECT_EQ(state.currentScreen, TITLE);
    EXPECT_FALSE(state.gameOver);
    EXPECT_FALSE(state.countdownActive);
}

TEST_F(GameTest, RunTitleScreen) {
    GameState state = game.get_state();
    state.currentScreen = TITLE;
    game.set_state(state);

    state = game.get_state();
    EXPECT_EQ(state.currentScreen, TITLE);  // Ensure it stays in the title screen if no input
}

TEST_F(GameTest, RunGameplayScreen) {
    GameState state = game.get_state();
    state.currentScreen = GAMEPLAY;
    game.set_state(state);

    state = game.get_state();
    EXPECT_EQ(state.currentScreen, GAMEPLAY);  // Ensure it stays in gameplay screen if no game over
}
