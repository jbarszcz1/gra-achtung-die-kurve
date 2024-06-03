#include "board.h"
#include "gtest/gtest.h"

// Test fixture for Board
class BoardTest : public ::testing::Test {
protected:
    GameState state;
    Board board;

    BoardTest() : board(state) {}

    void SetUp() override {
        state.currentScreen = TITLE;
        state.gameOver = false;
        state.countdownActive = false;
    }
};

TEST_F(BoardTest, HandleTitleScreen) {
    Vector2 mousePoint = {0, 0};

    board.handle_title_screen(mousePoint);

    EXPECT_TRUE(state.Players.empty());
}

TEST_F(BoardTest, HandleGameplayScreenCountdown) {
    state.currentScreen = GAMEPLAY;
    state.countdownActive = true;
    state.countdownValue = 3;
    state.countdownStartTime = GetTime() - 1.1;  // Simulate countdown timer

    board.handle_gameplay_screen();

    EXPECT_EQ(state.countdownValue, 2);
}

TEST_F(BoardTest, HandleGameplayScreenUpdate) {
    state.currentScreen = GAMEPLAY;
    state.countdownActive = false;
    state.Players.emplace_back(RED, KEY_A, KEY_D, "RED");

    board.handle_gameplay_screen();

    EXPECT_TRUE(state.Players[0].get_position().x != 0);
    EXPECT_TRUE(state.Players[0].get_position().y != 0);
}

