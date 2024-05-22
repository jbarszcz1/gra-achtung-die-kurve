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

    while(!WindowShouldClose())
    {
        switch(current_screen)
        {
            case TITLE:
            {
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
                DrawText("Achtung die Kurve!",200, 200, 40, RED);
                DrawText("Add players...", 300, 300, 20, PINK);
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