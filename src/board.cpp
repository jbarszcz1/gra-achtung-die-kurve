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
    const int screen_width = size_x;
    const int screen_height = size_y;
    int frames_counter = 0;

    InitWindow(screen_width, screen_height, "Achtung die Kurve!");

    GameScreen current_screen = TITLE;
    SetTargetFPS(60);

    std::vector<ButtonData> buttons = {
        {{size_x / 2 - 450, 300, 100, 50}, false, false, false, false, false, '\0', '\0', RED, "RED"},
        {{size_x / 2 - 450, 400, 150, 50}, false, false, false, false, false, '\0', '\0', GREEN, "GREEN"},
        {{size_x / 2 - 450, 500, 170, 50}, false, false, false, false, false, '\0', '\0', PURPLE, "PURPLE"},
        {{size_x / 2 - 450, 600, 170, 50}, false, false, false, false, false, '\0', '\0', ORANGE, "ORANGE"}
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
                                Players.emplace_back(button.color, button.inputKeyLeft, button.inputKeyRight);
                            }
                        }
                    }
                }

                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = GAMEPLAY;
                }
            } break;

            case GAMEPLAY:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = SCORE;
                }
            } break;

            case SCORE:
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    current_screen = TITLE;
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
                DrawText("Achtung die Kurve!", size_x / 2 - 200, 75, 40, PINK);
                DrawText("Add players...", size_x / 2 - 100, 125, 30, DARKPURPLE);
                DrawText("Player:", size_x / 2 - 450, 200, 30, LIGHTGRAY);
                DrawText("Left key", size_x / 2 - 100, 200, 30, LIGHTGRAY);
                DrawText("Right key", size_x / 2 + 350, 200, 30, LIGHTGRAY);
                DrawText("Press color button to add player and then press 2 keys to control your player", size_x / 2 - 400, 160, 20, DARKGRAY);

                for (const auto& button : buttons)
                {
                    DrawText(button.colorName.c_str(), button.bounds.x, button.bounds.y, 50, button.clicked ? button.color : WHITE);
                    if (button.drawKeyLeft)
                        DrawText(std::string(1, button.inputKeyLeft).c_str(), size_x / 2 - 100, button.bounds.y, 50, WHITE);
                    if (button.drawKeyRight)
                        DrawText(std::string(1, button.inputKeyRight).c_str(), size_x / 2 + 350, button.bounds.y, 50, WHITE);
                }
            } break;

            case GAMEPLAY:
            {
                DrawRectangle(0, 0, screen_width, screen_height, LIGHTGRAY);
                DrawText("PLAY...", 300, 300, 40, RED);
                for (Snake& player : Players)
                {
                    player.draw();
                }
            } break;

            case SCORE:
            {
                DrawText("and the winner is", 300, 300, 20, RED);
            } break;

            default: break;
        }

        EndDrawing();
    }

    CloseWindow();
}
