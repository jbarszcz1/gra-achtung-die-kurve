#include "board.h"
#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>



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
                        bool unique;
                        int keyLeft = GetCharPressed();
                        for (auto& button : buttons)
                        {
                            unique = false;
                            if (char(keyLeft)==button.inputKeyLeft || char(keyLeft)==button.inputKeyRight)
                            {
                                break;
                            }
                            unique = true;
                        }

                        if (keyLeft >= 32 && keyLeft <= 126 && unique==true)
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
                        bool unique;
                        int keyRight = GetCharPressed();
                        for (auto& button : buttons)
                        {
                            unique = false;
                            if (char(keyRight)==button.inputKeyLeft || char(keyRight)==button.inputKeyRight)
                            {
                                break;
                            }
                            unique = true;
                        }
                        if (keyRight >= 32 && keyRight <= 126 && unique==true)
                        {
                            button.inputKeyRight = (char)keyRight;
                            button.drawKeyRight = true;
                            button.textBoxRightActive = false;
                        }



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

                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = GAMEPLAY;
                    start_countdown();
                }
            } break;

            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = SCORE;
                }

                if (countdownActive) {
                    update_countdown();
                } else {
                    for (Snake& player : Players)
                    {
                        if (player.is_active) {
                            player.update();
                        }
                    }
                    check_collisions();
                    if (check_game_over()) {
                        current_screen = SCORE;
                    }
                }
            } break;

            case SCORE:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                for (auto& button : buttons)
                {
                    button.inputKeyLeft = '\n';
                    button.inputKeyRight = '\n';
                }

                    current_screen = TITLE;

            }
            }break;

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
                        if (player.is_active) {
                            player.update();
                        }
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
