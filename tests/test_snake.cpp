#include <gtest/gtest.h>
#include "snake.h"


// TEST(SnakeTest, ConstructorInitializesFields) {
//     Snake snake(GREEN, 'a', 'd');

//     EXPECT_EQ(snake.get_color(), GREEN);
//     EXPECT_EQ(snake.get_turn_left_key(), 'a');
//     EXPECT_EQ(snake.get_turn_right_key(), 'd');


//     EXPECT_GE(snake.get_angle(), 1);
//     EXPECT_LE(snake.get_angle(), 360);
//     EXPECT_GE(snake.get_angle(), 1);
//     EXPECT_LE(snake.get_angle(), 360);

//     EXPECT_GE(snake.get_position().x, 100);
//     EXPECT_LE(snake.get_position().x, 1400);

//     EXPECT_GE(snake.get_coord_y(), 50);
//     EXPECT_LE(snake.get_coord_y(), 900);
// }
//     EXPECT_GE(snake.get_coord_y(), 50);
//     EXPECT_LE(snake.get_coord_y(), 900);
// }


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
