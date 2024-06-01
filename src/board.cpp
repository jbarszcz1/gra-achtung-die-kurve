#include "board.h"
#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>

struct ButtonData {
    Rectangle bounds;
    bool clicked;
    bool textBoxLeftActive;
    bool textBoxRightActive;
    bool drawKeyLeft;
    bool drawKeyRight;
    char inputKeyLeft;
    char inputKeyRight;
    Color color;
    std::string colorName;
};

Board::Board(std::vector<Snake> Players): Players(Players) {}

bool operator==(const Color& lhs, const Color& rhs) {
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b && lhs.a == rhs.a);
}

void Board::display_window()
{
    typedef enum GameScreen { TITLE=0, GAMEPLAY, SCORE } GameScreen;
    int frames_counter = 0;

    InitWindow(screen_width, screen_height, "Achtung die Kurve!");

    GameScreen current_screen = TITLE;
    SetTargetFPS(60);

    std::vector<ButtonData> buttons = {
        {{screen_width / 2 - 450, 300, 100, 50}, false, false, false, false, false, '\0', '\0', RED, "RED"},
        {{screen_width / 2 - 450, 400, 150, 50}, false, false, false, false, false, '\0', '\0', GREEN, "GREEN"},
        {{screen_width / 2 - 450, 500, 170, 50}, false, false, false, false, false, '\0', '\0', PURPLE, "PURPLE"},
        {{screen_width / 2 - 450, 600, 170, 50}, false, false, false, false, false, '\0', '\0', ORANGE, "ORANGE"}
    };

    while (!WindowShouldClose())
    {
        Vector2 mousePoint = GetMousePosition();

        switch (current_screen)
        {
            case TITLE:
            {
                for (auto& button : buttons)
                {
                    if (CheckCollisionPointRec(mousePoint, button.bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                            button.clicked = true;
                            button.textBoxLeftActive = true;
                    }

                    if (button.textBoxLeftActive)
                    {
                        int keyLeft = GetCharPressed();
                        if (keyLeft >= 32 && keyLeft <= 126)
                        {
                            button.inputKeyLeft = (char)keyLeft;
                            button.drawKeyLeft = true;
                            button.textBoxLeftActive = false;
                        }
                    }


                    if (button.clicked && !button.textBoxLeftActive)
                    {
                        button.textBoxRightActive = true;
                        button.clicked = false;
                    }


                    if (button.textBoxRightActive)
                    {
                        int keyRight = GetCharPressed();
                        if (keyRight >= 32 && keyRight <= 126)
                        {
                            button.inputKeyRight = (char)keyRight;
                            button.drawKeyRight = true;
                            button.textBoxRightActive = false;


                            if (button.drawKeyLeft && button.drawKeyRight)
                            {
                                // Remove existing snake of this color if it exists
                                Players.erase(std::remove_if(Players.begin(), Players.end(),
                                    [&button](Snake& snake) { return snake.get_color() == button.color; }),
                                    Players.end());
                                // Add the new snake
                                Players.emplace_back(button.color, (int)std::toupper(button.inputKeyLeft), (int)std::toupper(button.inputKeyRight), button.colorName);
                            }
                        }
                    }
                }

                if (IsKeyPressed(KEY_ENTER))
                {
                    // Count the number of players with both left and right keys assigned
                    int activePlayers = 0;
                    for (const auto& button : buttons)
                    {
                        if (button.drawKeyLeft && button.drawKeyRight)
                        {
                            activePlayers++;
                        }
                    }

                    if (activePlayers >= 2)
                    {
                        current_screen = GAMEPLAY;
                        start_countdown();
                    }
                    else
                    {
                        insufficientPlayersMessageTime = GetTime();
                        insufficientPlayersMessageActive = true;
                    }
                }



            } break;

            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER) && gameOver)
                {
                    current_screen = SCORE;
                    gameInProgress = false; // Game is no longer in progress
                }

                if (countdownActive) {
                    update_countdown();
                } else if (gameOver) {
                    // Display the trails and "GAME OVER" text for some time before switching to the SCORE screen
                    if (GetTime() - gameOverStartTime >= gameOverDuration) {
                        current_screen = SCORE;
                        gameInProgress = false; // Game is no longer in progress
                    }
                } else {
                    for (Snake& player : Players)
                    {
                        if (player.is_active) {
                            player.update();
                        }
                    }
                    check_collisions();
                    if (check_game_over()) {
                        gameOver = true;
                        gameOverStartTime = GetTime();
                    }
                }
            } break;

            case SCORE:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = TITLE;
                    reset_game();
                }
            } break;

            default: break;
        }

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (current_screen)
        {
            case TITLE:
            {
                DrawRectangle(0, 0, screen_width, screen_height, BLACK);
                DrawText("Achtung die Kurve!", screen_width / 2 - 200, 75, 40, PINK);
                DrawText("Add players...", screen_width / 2 - 100, 125, 30, DARKPURPLE);
                DrawText("Player:", screen_width / 2 - 450, 200, 30, LIGHTGRAY);
                DrawText("Left key", screen_width / 2 - 100, 200, 30, LIGHTGRAY);
                DrawText("Right key", screen_width / 2 + 350, 200, 30, LIGHTGRAY);
                DrawText("Press color button to add player and then press 2 keys to control your player", screen_width / 2 - 400, 160, 20, DARKGRAY);

                for (const auto& button : buttons)
                {
                    DrawText(button.colorName.c_str(), button.bounds.x, button.bounds.y, 50, button.clicked ? button.color : WHITE);
                    if (button.drawKeyLeft)
                        DrawText(std::string(1, button.inputKeyLeft).c_str(), screen_width / 2 - 100, button.bounds.y, 50, WHITE);
                    if (button.drawKeyRight)
                        DrawText(std::string(1, button.inputKeyRight).c_str(), screen_width / 2 + 350, button.bounds.y, 50, WHITE);
                }

                if (insufficientPlayersMessageActive && (GetTime() - insufficientPlayersMessageTime < 2.0))
                {
                    DrawText("Choose at least 2 players", screen_width / 2 - MeasureText("Choose at least 2 players", 20) / 2, screen_height - 50, 20, RED);
                }
                else
                {
                    insufficientPlayersMessageActive = false;
                }
            } break;

            case GAMEPLAY:
            {
                DrawRectangle(0, 0, screen_width, screen_height, LIGHTGRAY);

                if (countdownActive) {
                    if (countdownValue > 0) {
                        DrawText(("GAME STARTS IN " + std::to_string(countdownValue)).c_str(), screen_width / 2 - 150, screen_height / 2, 40, RED);
                    } else {
                        DrawText("GO!", screen_width / 2 - 50, screen_height / 2, 40, RED);
                    }
                    for (const Snake& player : Players) {
                        player.draw_initial_direction_arrow();
                    }

                } else {
                    for (Snake& player : Players)
                    {
                        player.draw();
                    }
                    if (gameOver) {
                        DrawText("GAME OVER", screen_width / 2 - MeasureText("GAME OVER", 60) / 2, screen_height / 2 - 30, 60, RED);
                    }
                }
            } break;

            case SCORE:
            {
                Color winnerColor;
                std::string winnerColorStr;
                std::tie(winnerColor, winnerColorStr) = get_winner_color();
                std::string winnerText = "The winner is: " + winnerColorStr;
                int textWidth = MeasureText(winnerText.c_str(), 40);
                DrawText(winnerText.c_str(), screen_width / 2 - textWidth / 2, screen_height / 2 - 20, 40, winnerColor);
                std::string promptText = "Press Enter to return to Title Screen";
                int promptWidth = MeasureText(promptText.c_str(), 20);
                DrawText(promptText.c_str(), screen_width / 2 - promptWidth / 2, screen_height / 2 + 20, 20, winnerColor);
            } break;

            default: break;
        }

        EndDrawing();
    }

    CloseWindow();
}



void Board::check_collisions() {
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

void Board::reset_game() {
    // Reset all snakes to initial positions
    for (Snake& snake : Players) {
        snake.reset();
    }
    start_countdown();
    //TODO: refactor!!!!! (can the object be reinitialised to stick to dry?)
    gameOver = false;
    gameOverStartTime = 0;
}

void Board::start_countdown() {
    countdownActive = true;
    countdownValue = 3; // For multiple restarts to work correctly
    countdownStartTime = GetTime();
}


void Board::update_countdown() {
    double currentTime = GetTime();
    if (currentTime - countdownStartTime >= 1.0) {
        countdownValue--;
        countdownStartTime = currentTime;
    }

    if (countdownValue <= 0) {
        countdownActive = false;
    }
}

bool Board::check_game_over() const {
    int activeCount = 0;
    for (const Snake& snake : Players) {
        if (snake.is_active) {
            activeCount++;
        }
    }
    return activeCount <= 1;
}

std::tuple<Color, std::string> Board::get_winner_color() const {
    for (const Snake& snake : Players) {
        if (snake.is_active) {
            return std::make_tuple(snake.get_color(), snake.get_color_str());
        }
    }
    return std::make_tuple(BLACK, "BLACK");
}
