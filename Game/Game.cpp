#include "Game.h"
#include "raylib.h"
#include "../Snake/Snake.h"
#include "../Board/Board.h"
#include "../Food/Food.h"

Game::Game(int screenWidth, int screenHeight, int gridSize, int cellSize)
    : screenWidth(screenWidth), screenHeight(screenHeight),
      board(screenWidth, screenHeight, gridSize, cellSize),
      snake(screenWidth / (2 * cellSize), screenHeight / (2 * cellSize), cellSize),
      food(screenWidth / (2 * cellSize) + 1, screenHeight / (2 * cellSize) + 1, cellSize, gridSize)
{

    currentScreen = TITLE;
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
            case TITLE: UpdateTitleScreen(); break;
            case GAMEPLAY: UpdateGameplayScreen(); break;
            case ENDING: UpdateEndingScreen(); break;
        }
        BeginDrawing();

        ClearBackground(RAYWHITE);
        switch (currentScreen)
        {
            case TITLE: DrawTitleScreen(); break;
            case GAMEPLAY: DrawGameplayScreen(); break;
            case ENDING: DrawEndingScreen();
        }

        EndDrawing();
    }
}

void Game::UpdateTitleScreen()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentScreen = GAMEPLAY;
    }
}

void Game::UpdateGameplayScreen() {
    if (IsKeyPressed(KEY_UP))
        snake.SetDirection(UP);
    if (IsKeyPressed(KEY_DOWN))
        snake.SetDirection(DOWN);
    if (IsKeyPressed(KEY_LEFT))
        snake.SetDirection(LEFT);
    if (IsKeyPressed(KEY_RIGHT))
        snake.SetDirection(RIGHT);

    snake.Move();

    if (CheckCollisionWithFood())
    {
        snake.Grow();
        food.GenerateNewPosition();
    }

    if (!board.IsInsideBoard(snake.GetHeadPosition().x, snake.GetHeadPosition().y))
    {
        currentScreen = ENDING;
    }

}

void Game::UpdateEndingScreen() {
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        currentScreen = TITLE;
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        currentScreen = GAMEPLAY;
    }
}

void Game::DrawTitleScreen() {
    std::string title = "Snake";
    int titleWidth = MeasureText(title.c_str(), 40);
    int x = (screenWidth - titleWidth) / 2;
    DrawText(title.c_str(), x, 20, 40, BLACK);

    std::string text = "Press ENTER to START";
    int textWidth = MeasureText(text.c_str(), 30);
    int xText = (screenWidth - textWidth) / 2;
    DrawText(text.c_str(), xText, screenHeight / 2 - 20, 30, GRAY);
}

void Game::DrawGameplayScreen() {
    board.Draw();
    snake.Draw();
    food.Draw();
}

void Game::DrawEndingScreen() {
    std::string goText = "Game Over!";
    std::string bToT = "BACKSPACE to TITLE!";
    std::string startAgain = "ENTER to START again!";

    int goTextWidth = MeasureText(goText.c_str(), 30);
    int bToTWidth = MeasureText(bToT.c_str(), 30);
    int startAgainWidth = MeasureText(startAgain.c_str(), 30);

    int goTextX = (screenWidth - goTextWidth) / 2;
    int bToTX = (screenWidth - bToTWidth) / 2;
    int startAgainX = (screenWidth - startAgainWidth) / 2;

    DrawText(goText.c_str(), goTextX, screenHeight / 2 - 80, 30, GRAY);
    DrawText(bToT.c_str(), bToTX, screenHeight / 2 - 40, 30, GRAY);
    DrawText(startAgain.c_str(), startAgainX, screenHeight / 2, 30, GRAY);
}

bool Game::CheckCollisionWithFood() const
{
    return (snake.GetHeadPosition().x == food.GetPosition().x && snake.GetHeadPosition().y == food.GetPosition().y);
}