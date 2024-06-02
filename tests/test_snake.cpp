#include <gtest/gtest.h>
#include "snake.h"

class SnakeTest : public ::testing::Test {
protected:
    Snake snake;

    SnakeTest() : snake(RED, KEY_LEFT, KEY_RIGHT, "red") {} // Inicjalizacja w konstruktorze
};

TEST_F(SnakeTest, ResetTest) {
    snake.reset();
    EXPECT_EQ(snake.get_trail().size(), 22); // Początkowa wielkość śladu powinna wynosić 22
}

TEST_F(SnakeTest, MoveTest) {
    Vector2 initial_position = snake.get_position();
    snake.move();
    Vector2 new_position = snake.get_position();
    EXPECT_NE(initial_position.x, new_position.x);
    EXPECT_NE(initial_position.y, new_position.y);
}

TEST_F(SnakeTest, UpdateTest) {
    Vector2 initial_position = snake.get_position();
    snake.update();
    Vector2 new_position = snake.get_position();
    EXPECT_NE(initial_position.x, new_position.x);
    EXPECT_NE(initial_position.y, new_position.y);
}

TEST_F(SnakeTest, GettersTest) {
    EXPECT_EQ(snake.get_color_str(), "red");
    EXPECT_EQ(snake.get_turn_left_key(), KEY_LEFT);
    EXPECT_EQ(snake.get_turn_right_key(), KEY_RIGHT);
}

TEST_F(SnakeTest, CheckSelfCollisionTest) {
    EXPECT_FALSE(snake.check_self_collision()); // Nie powinno być kolizji na początku
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
