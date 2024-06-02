#include "game.h"
#include "raylib.h"

Game::Game() : board(state) {}  // Pass state to board

void Game::run() {
    InitWindow(board.get_screen_width(), board.get_screen_height(), "Achtung die Kurve!");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();

        switch (state.current_screen) {
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

        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (state.current_screen) {
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
