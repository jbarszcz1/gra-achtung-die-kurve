#include "board.h"
#include <iostream>
#include "raylib.h"

Board::Board(std::vector<Snake> Players): Players(Players) {}

void Board::display_window()
{
    typedef enum GameScreen { TITLE=0, GAMEPLAY, SCORE } GameScreen;
    const int screen_width = size_x;
    const int screen_height = size_y;
    int frames_counter = 0;

    InitWindow(screen_width, screen_height, "Achtung die Kurve!");

    GameScreen current_screen = TITLE;
    SetTargetFPS(60);

    Rectangle buttonRedBounds = { size_x / 2 - 450, 300, 100, 50 };
    bool buttonRedClicked = false;
    Rectangle buttonGreenBounds = { size_x / 2 - 450, 400, 150, 50 };
    bool buttonGreenClicked = false;
    Rectangle buttonPurpleBounds = { size_x / 2 - 450, 500, 170, 50 };
    bool buttonPurpleClicked = false;
    Rectangle buttonOrangeBounds = { size_x / 2 - 450, 600, 170, 50 };
    bool buttonOrangeClicked = false;

    bool textBoxRedLeftActive = false;
    bool textBoxRedRightActive = false;
    bool drawKeyRedLeft = false;
    bool drawKeyRedRight = false;
    char inputKeyRedLeft[2] = "\0";
    char inputKeyRedRight[2] = "\0";

    bool textBoxGreenLeftActive = false;
    bool textBoxGreenRightActive = false;
    bool drawKeyGreenLeft = false;
    bool drawKeyGreenRight = false;
    char inputKeyGreenLeft[2] = "\0";
    char inputKeyGreenRight[2] = "\0";

    bool textBoxPurpleLeftActive = false;
    bool textBoxPurpleRightActive = false;
    bool drawKeyPurpleLeft = false;
    bool drawKeyPurpleRight = false;
    char inputKeyPurpleLeft[2] = "\0";
    char inputKeyPurpleRight[2] = "\0";

    bool textBoxOrangeLeftActive = false;
    bool textBoxOrangeRightActive = false;
    bool drawKeyOrangeLeft = false;
    bool drawKeyOrangeRight = false;
    char inputKeyOrangeLeft[2] = "\0";
    char inputKeyOrangeRight[2] = "\0";

    while (!WindowShouldClose())
    {
        switch (current_screen)
        {
            case TITLE:
            {
                Vector2 mousePoint = GetMousePosition();

                if (CheckCollisionPointRec(mousePoint, buttonRedBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonRedClicked = true;
                    textBoxRedLeftActive = true;
                }
                if (textBoxRedLeftActive)
                {
                    int keyRedLeft = GetCharPressed();
                    if (keyRedLeft >= 32 && keyRedLeft <= 126)
                    {
                        inputKeyRedLeft[0] = (char)keyRedLeft;
                        inputKeyRedLeft[1] = '\0';
                        drawKeyRedLeft = true;
                        textBoxRedLeftActive = false;
                    }
                }
                if (buttonRedClicked && !textBoxRedLeftActive)
                {
                    textBoxRedRightActive = true;
                    buttonRedClicked = false;
                }
                if (textBoxRedRightActive)
                {
                    int keyRedRight = GetCharPressed();
                    if (keyRedRight >= 32 && keyRedRight <= 126)
                    {
                        inputKeyRedRight[0] = (char)keyRedRight;
                        inputKeyRedRight[1] = '\0';
                        drawKeyRedRight = true;
                        textBoxRedRightActive = false;
                    }
                }

                if (CheckCollisionPointRec(mousePoint, buttonGreenBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonGreenClicked = true;
                    textBoxGreenLeftActive = true;
                }
                if (textBoxGreenLeftActive)
                {
                    int keyGreenLeft = GetCharPressed();
                    if (keyGreenLeft >= 32 && keyGreenLeft <= 126)
                    {
                        inputKeyGreenLeft[0] = (char)keyGreenLeft;
                        inputKeyGreenLeft[1] = '\0';
                        drawKeyGreenLeft = true;
                        textBoxGreenLeftActive = false;
                    }
                }
                if (buttonGreenClicked && !textBoxGreenLeftActive)
                {
                    textBoxGreenRightActive = true;
                    buttonGreenClicked = false;
                }
                if (textBoxGreenRightActive)
                {
                    int keyGreenRight = GetCharPressed();
                    if (keyGreenRight >= 32 && keyGreenRight <= 126)
                    {
                        inputKeyGreenRight[0] = (char)keyGreenRight;
                        inputKeyGreenRight[1] = '\0';
                        drawKeyGreenRight = true;
                        textBoxGreenRightActive = false;
                    }
                }

                if (CheckCollisionPointRec(mousePoint, buttonPurpleBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonPurpleClicked = true;
                    textBoxPurpleLeftActive = true;
                }
                if (textBoxPurpleLeftActive)
                {
                    int keyPurpleLeft = GetCharPressed();
                    if (keyPurpleLeft >= 32 && keyPurpleLeft <= 126)
                    {
                        inputKeyPurpleLeft[0] = (char)keyPurpleLeft;
                        inputKeyPurpleLeft[1] = '\0';
                        drawKeyPurpleLeft = true;
                        textBoxPurpleLeftActive = false;
                    }
                }
                if (buttonPurpleClicked && !textBoxPurpleLeftActive)
                {
                    textBoxPurpleRightActive = true;
                    buttonPurpleClicked = false;
                }
                if (textBoxPurpleRightActive)
                {
                    int keyPurpleRight = GetCharPressed();
                    if (keyPurpleRight >= 32 && keyPurpleRight <= 126)
                    {
                        inputKeyPurpleRight[0] = (char)keyPurpleRight;
                        inputKeyPurpleRight[1] = '\0';
                        drawKeyPurpleRight = true;
                        textBoxPurpleRightActive = false;
                    }
                }

                if (CheckCollisionPointRec(mousePoint, buttonOrangeBounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    buttonOrangeClicked = true;
                    textBoxOrangeLeftActive = true;
                }
                if (textBoxOrangeLeftActive)
                {
                    int keyOrangeLeft = GetCharPressed();
                    if (keyOrangeLeft >= 32 && keyOrangeLeft <= 126)
                    {
                        inputKeyOrangeLeft[0] = (char)keyOrangeLeft;
                        inputKeyOrangeLeft[1] = '\0';
                        drawKeyOrangeLeft = true;
                        textBoxOrangeLeftActive = false;
                    }
                }
                if (buttonOrangeClicked && !textBoxOrangeLeftActive)
                {
                    textBoxOrangeRightActive = true;
                    buttonOrangeClicked = false;
                }
                if (textBoxOrangeRightActive)
                {
                    int keyOrangeRight = GetCharPressed();
                    if (keyOrangeRight >= 32 && keyOrangeRight <= 126)
                    {
                        inputKeyOrangeRight[0] = (char)keyOrangeRight;
                        inputKeyOrangeRight[1] = '\0';
                        drawKeyOrangeRight = true;
                        textBoxOrangeRightActive = false;
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
                DrawText("Press color button to add player and then press 2 keys to control your player",size_x/2 - 400, 160, 20, DARKGRAY);

                DrawText("RED", buttonRedBounds.x, buttonRedBounds.y, 50, buttonRedClicked ? RED : WHITE);
                DrawText("GREEN", buttonGreenBounds.x, buttonGreenBounds.y, 50, buttonGreenClicked ? GREEN : WHITE);
                DrawText("PURPLE", buttonPurpleBounds.x, buttonPurpleBounds.y, 50, buttonPurpleClicked ? PURPLE : WHITE);
                DrawText("ORANGE", buttonOrangeBounds.x, buttonOrangeBounds.y, 50, buttonOrangeClicked ? ORANGE : WHITE);
                DrawText(inputKeyRedLeft, size_x / 2 - 100, buttonRedBounds.y, 50, drawKeyRedLeft ? WHITE : BLACK);
                DrawText(inputKeyRedRight, size_x / 2 + 350, buttonRedBounds.y, 50, drawKeyRedRight ? WHITE : BLACK);
                DrawText(inputKeyGreenLeft, size_x / 2 - 100, buttonGreenBounds.y, 50, drawKeyGreenLeft ? WHITE : BLACK);
                DrawText(inputKeyGreenRight, size_x / 2 + 350, buttonGreenBounds.y, 50, drawKeyGreenRight ? WHITE : BLACK);
                DrawText(inputKeyPurpleLeft, size_x / 2 - 100, buttonPurpleBounds.y, 50, drawKeyPurpleLeft ? WHITE : BLACK);
                DrawText(inputKeyPurpleRight, size_x / 2 + 350, buttonPurpleBounds.y, 50, drawKeyPurpleRight ? WHITE : BLACK);
                DrawText(inputKeyOrangeLeft, size_x / 2 - 100, buttonOrangeBounds.y, 50, drawKeyOrangeLeft ? WHITE : BLACK);
                DrawText(inputKeyOrangeRight, size_x / 2 + 350, buttonOrangeBounds.y, 50, drawKeyOrangeRight ? WHITE : BLACK);
            } break;

            case GAMEPLAY:
            {
                DrawRectangle(0, 0, screen_width, screen_height, LIGHTGRAY);
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
