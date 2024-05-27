#include "board.h"
#include <iostream>
#include "raylib.h"

Board::Board(std::vector<Snake> Players): Players(Players) {}

void Board::display_window()
{
    typedef enum GameScreen {TITLE=0, GAMEPLAY, SCORE} GameScreen;
    const int screen_width = size_x;
    const int screen_height = size_y;
    int frames_counter = 0;

    InitWindow(screen_width, screen_height," Achtung die Kurve!");

    GameScreen current_screen = TITLE;
    SetTargetFPS(60);

    Rectangle buttonRedBounds = { size_x/2 - 450, 300, 100, 50 };
    bool buttonRedClicked = false;
    Rectangle buttonGreenBounds = { size_x/2 - 450, 400, 150, 50 };
    bool buttonGreenClicked = false;
    Rectangle buttonPurpleBounds = { size_x/2 - 450, 500, 170, 50 };
    bool buttonPurpleClicked = false;
    Rectangle buttonOrangeBounds = { size_x/2 - 450, 600, 170, 50 };
    bool buttonOrangeClicked = false;







    while(!WindowShouldClose())
    {
        switch(current_screen)
        {
            case TITLE:
            {
                Vector2 mousePoint = GetMousePosition();
                if (CheckCollisionPointRec(mousePoint, buttonRedBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonRedClicked = true;
                }
                if (CheckCollisionPointRec(mousePoint, buttonGreenBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonGreenClicked = true;
                }
                if (CheckCollisionPointRec(mousePoint, buttonPurpleBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonPurpleClicked = true;
                }
                if (CheckCollisionPointRec(mousePoint, buttonOrangeBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonOrangeClicked = true;
                }

                if(IsKeyPressed(KEY_ENTER))
                {
                    current_screen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    current_screen = SCORE;
                }

            }break;
            case SCORE:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    current_screen = TITLE;
                }
            }break;
            default: break;
        }

        // drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch(current_screen)
        {
            case TITLE:
            {
                DrawRectangle(0, 0, screen_width, screen_height, BLACK);
                DrawText("Achtung die Kurve!",size_x/2 - 200, 75, 40, PINK);
                DrawText("Add players...", size_x/2 - 100, 125, 30, DARKPURPLE);
                DrawText("Player:", size_x/2 - 450, 200, 30, LIGHTGRAY);
                DrawText("Left key", size_x/2 - 100, 200, 30, LIGHTGRAY);
                DrawText("Right key", size_x/2 + 350, 200, 30, LIGHTGRAY);

                DrawText("RED", buttonRedBounds.x, buttonRedBounds.y, 50, buttonRedClicked ? RED : WHITE);
                DrawText("GREEN", buttonGreenBounds.x, buttonGreenBounds.y, 50, buttonGreenClicked ? GREEN : WHITE);
                DrawText("PURPLE", buttonPurpleBounds.x, buttonPurpleBounds.y, 50, buttonPurpleClicked ? PURPLE : WHITE);
                DrawText("ORANGE", buttonOrangeBounds.x, buttonOrangeBounds.y, 50, buttonOrangeClicked ? ORANGE : WHITE);
            if (buttonRedClicked)
            {

            }

            } break;

            case GAMEPLAY:
            {
                DrawRectangle(0,0,screen_width,screen_height,LIGHTGRAY);
                DrawText("PLAY...", 300, 300, 40, RED);
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