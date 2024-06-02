#include "game.h"
#include "raylib.h"


Game::Game() : board(state) {}  // Pass state to board

void Game::run() {
    // Set the game window
    InitWindow(board.get_screen_width(), board.get_screen_height(), "Achtung die Kurve!");

    SetTargetFPS(60);


    // Main game loop
    while (!WindowShouldClose()) {
        // Current mouse position
        Vector2 mousePoint = GetMousePosition();

        // Handle different game states
        switch (state.currentScreen) {
            case TITLE:
                board.handle_title_screen(mousePoint);
                break;
            case GAMEPLAY:
                board.handle_gameplay_screen();
                break;
            case SCORE:
                board.handle_score_screen();
                break;
        }


        // Rendering
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Current screen rendering
        switch (state.currentScreen) {
            case TITLE:
                board.draw_title_screen();
                break;
            case GAMEPLAY:
                board.draw_gameplay_screen();
                break;
            case SCORE:
                board.draw_score_screen();
                break;
        }

        EndDrawing();
    }

    CloseWindow();
}
