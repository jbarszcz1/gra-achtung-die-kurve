#include "board.h"
#include "raylib.h"
#include <iostream>
#include <algorithm>


// Overload to further initialize snakes correctly
bool operator==(const Color& lhs, const Color& rhs) {
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a);
}


Board::Board(GameState& gameState) : state(gameState) {
    // Initialize buttons for player to choose his color
    buttons.push_back({{screen_width / 2 - 450, 300, 100, 50}, false, false, false, false, false, '\0', '\0', RED, "RED"});
    buttons.push_back({{screen_width / 2 - 450, 400, 150, 50}, false, false, false, false, false, '\0', '\0', GREEN, "GREEN"});
    buttons.push_back({{screen_width / 2 - 450, 500, 170, 50}, false, false, false, false, false, '\0', '\0', PURPLE, "PURPLE"});
    buttons.push_back({{screen_width / 2 - 450, 600, 170, 50}, false, false, false, false, false, '\0', '\0', ORANGE, "ORANGE"});
}


// Screens handling

// Title screen where players are added
void Board::handle_title_screen(Vector2 mousePoint) {
    for (auto& button : buttons) {
        // Check if the button is clicked
        if (CheckCollisionPointRec(mousePoint, button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            button.clicked = true;
            button.textBoxLeftActive = true;
        }

        // Handle left key input for player control and check if keys aren't repeated
        if (button.textBoxLeftActive) {
            bool unique = true;
            int keyLeft = GetCharPressed();
            for (auto& otherButton : buttons) {
                if (char(keyLeft) == otherButton.inputKeyLeft || char(keyLeft) == otherButton.inputKeyRight) {
                    unique = false;
                    break;
                }
            }

            if (keyLeft >= 32 && keyLeft <= 126 && unique) {
                button.inputKeyLeft = (char)keyLeft;
                button.drawKeyLeft = true;
                button.textBoxLeftActive = false;
            }
        }

        // Handle right key input for player control
        if (button.clicked && !button.textBoxLeftActive) {
            button.textBoxRightActive = true;
            button.clicked = false;
        }

        if (button.textBoxRightActive) {
            bool unique = true;
            int keyRight = GetCharPressed();
            for (auto& otherButton : buttons) {
                if (char(keyRight) == otherButton.inputKeyLeft || char(keyRight) == otherButton.inputKeyRight) {
                    unique = false;
                    break;
                }
            }

            if (keyRight >= 32 && keyRight <= 126 && unique) {
                button.inputKeyRight = (char)keyRight;
                button.drawKeyRight = true;
                button.textBoxRightActive = false;
            }

            // Add the snake with specified control keys if both keys are set
            if (button.drawKeyLeft && button.drawKeyRight) {
                state.Players.erase(std::remove_if(state.Players.begin(), state.Players.end(), [&button](Snake& snake) {
                    return snake.get_color() == button.color;
                }), state.Players.end());

                state.Players.emplace_back(button.color, (int)std::toupper(button.inputKeyLeft), (int)std::toupper(button.inputKeyRight), button.colorName);
            }
        }
    }


    // If at least 2 players are set, the game starts
    if (IsKeyPressed(KEY_ENTER)) {
        int activePlayers = 0;
        for (const auto& button : buttons) {
            if (button.drawKeyLeft && button.drawKeyRight) {
                activePlayers++;
            }
        }

        if (activePlayers >= 2) {
            state.currentScreen = GAMEPLAY;
            state.countdownActive = true;
            state.countdownStartTime = GetTime();
        } else {
            state.insufficientPlayersMessageTime = GetTime();
            state.insufficientPlayersMessageActive = true;
        }
    }
}

// Gameplay screen
void Board::handle_gameplay_screen() {
    if (IsKeyPressed(KEY_ENTER) && state.gameOver) {
        state.currentScreen = SCORE;
    }

    double currentTime = GetTime();
    // Handle countdown before the snakes start moving
    if (state.countdownActive) {
        if (currentTime - state.countdownStartTime >= 1.0) {
            state.countdownValue--;
            state.countdownStartTime = currentTime;
        }

        if (state.countdownValue <= 0) {
            state.countdownActive = false;
        }
    } else if (state.gameOver) {
        if (currentTime - state.gameOverStartTime >= state.gameOverDuration) {
            state.currentScreen = SCORE;
        }
    } else {
        // Update player positions and check for collisions
        for (Snake& player : state.Players) {
            if (player.is_active) {
                player.update();
            }
        }
        check_collisions(state.Players);
        if (std::count_if(state.Players.begin(), state.Players.end(), [](const Snake& player) { return player.is_active; }) <= 1) {
            state.gameOver = true;
            state.gameOverStartTime = currentTime;
        }
    }
}

// Score screen
void Board::handle_score_screen() {
    if (IsKeyPressed(KEY_ENTER)) {
        for (auto& button : buttons) {
            button.inputKeyLeft = '\0';
            button.inputKeyRight = '\0';
            button.drawKeyLeft = false;
            button.drawKeyRight = false;
        }
        state.currentScreen = TITLE;
        state.Players.clear();
        state.gameOver = false;
        state.countdownValue = 3;
    }
}


// Drawing methods

// Title screen
void Board::draw_title_screen() {
    DrawRectangle(0, 0, screen_width, screen_height, BLACK);
    DrawText("Achtung die Kurve!", screen_width / 2 - 200, 75, 40, PINK);
    DrawText("Add players...", screen_width / 2 - 100, 125, 30, DARKPURPLE);
    DrawText("Player:", screen_width / 2 - 450, 200, 30, LIGHTGRAY);
    DrawText("Left key", screen_width / 2 - 100, 200, 30, LIGHTGRAY);
    DrawText("Right key", screen_width / 2 + 350, 200, 30, LIGHTGRAY);
    DrawText("Press color button to add player and then press 2 keys to control your player", screen_width / 2 - 400, 160, 20, DARKGRAY);

    for (const auto& button : buttons) {
        DrawText(button.colorName.c_str(), button.bounds.x, button.bounds.y, 50, button.clicked ? button.color : WHITE);
        if (button.drawKeyLeft)
            DrawText(std::string(1, button.inputKeyLeft).c_str(), screen_width / 2 - 100, button.bounds.y, 50, WHITE);
        if (button.drawKeyRight)
            DrawText(std::string(1, button.inputKeyRight).c_str(), screen_width / 2 + 350, button.bounds.y, 50, WHITE);
    }

    if (state.insufficientPlayersMessageActive && (GetTime() - state.insufficientPlayersMessageTime < 2.0)) {
        DrawText("Choose at least 2 players", screen_width / 2 - MeasureText("Choose at least 2 players", 20) / 2, screen_height - 50, 20, RED);
    } else {
        state.insufficientPlayersMessageActive = false;
    }
}

// Gameplay screen
void Board::draw_gameplay_screen() {
    DrawRectangle(0, 0, screen_width, screen_height, LIGHTGRAY);

    if (state.countdownActive) {
        for (const Snake& player : state.Players) {
            player.draw_initial_direction_arrow();
        }
        if (state.countdownValue > 0) {
            DrawText(("GAME STARTS IN " + std::to_string(state.countdownValue)).c_str(), screen_width / 2 - 150, screen_height / 2, 40, RED);
        } else {
            DrawText("GO!", screen_width / 2 - 50, screen_height / 2, 40, RED);
        }
    } else {
        for (Snake& player : state.Players) {
            player.draw();
        }
        if (state.gameOver) {
            DrawText("GAME OVER", screen_width / 2 - MeasureText("GAME OVER", 60) / 2, screen_height / 2 - 30, 60, RED);
        }
    }
}

// Score screen
void Board::draw_score_screen() {
    Color winnerColor;
    std::string winnerColorStr;
    std::tie(winnerColor, winnerColorStr) = state.get_winner_color();
    std::string winnerText = "The winner is: " + winnerColorStr;
    int textWidth = MeasureText(winnerText.c_str(), 40);
    DrawText(winnerText.c_str(), screen_width / 2 - textWidth / 2, screen_height / 2 - 20, 40, winnerColor);
    std::string promptText = "Press Enter to return to Title Screen";
    int promptWidth = MeasureText(promptText.c_str(), 20);
    DrawText(promptText.c_str(), screen_width / 2 - promptWidth / 2, screen_height / 2 + 20, 20, winnerColor);
}


// Check for all possible collisions
void Board::check_collisions(std::vector<Snake>& Players) {
    for (Snake& snake : Players) {
        if (!snake.is_active) continue;

        if (snake.check_collision_with_walls(screen_width, screen_height)) {
            snake.is_active = false;
        } else if (snake.check_self_collision()) {
            snake.is_active = false;
        } else if (snake.check_collision_with_others(Players)) {
            snake.is_active = false;
        }
    }
}


// Getters
float Board::get_screen_width() const {
    return screen_width;
}

float Board::get_screen_height() const {
    return screen_height;
}
