#include "raylib.h"
#include "Game/Game.h"

const int screenWidth = 1280;
const int screenHeight = 720;
const int cellSize = 20;
const int gridSize = 30;

int main() {
    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(10);

    Game game(screenWidth, screenHeight, gridSize, cellSize);
    game.Run();

    CloseWindow();

    return 0;
}
