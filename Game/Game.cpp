#include "Game.h"
#include "raylib.h"
#include "../Snake/Snake.h"
#include "../Board/Board.h"
#include "../Food/Food.h"

Game::Game(int screenWidth, int screenHeight, int gridSize, int cellSize)
    : screenWidth(screenWidth), screenHeight(screenHeight), gridSize(gridSize), cellSize(cellSize),
      board(screenWidth, screenHeight, gridSize, cellSize),
      snake(GetRandomValue(0 ,gridSize / 2), GetRandomValue(0, gridSize / 2), cellSize),
      food(gridSize / 2, gridSize / 2, cellSize, gridSize


      )
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
            case GAMEPLAY: {
                DrawLeftSideGameplay();
                DrawGameplayScreen();
                DrawRightSideGameplay();
                break;
            }
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
    int offsetX = (screenWidth - gridSize * cellSize) / 2;
    int offsetY = (screenHeight - gridSize * cellSize) / 2;
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
        score++;
        snake.Grow();
        food.GenerateNewPosition();
    }

    if (snake.CheckCollisionWithSelf())
        currentScreen = ENDING;

    if (!board.IsInsideBoard(snake.GetHeadPosition().x, snake.GetHeadPosition().y))
    {
        currentScreen = ENDING;
    }

}

void Game::UpdateEndingScreen() {
    snake.Reset(gridSize / 2, gridSize / 2);
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
    int offsetX = (screenWidth - gridSize * cellSize) / 2;
    int offsetY = (screenHeight - gridSize * cellSize) / 2;
    board.Draw();
    snake.Draw(offsetX, offsetY);
    food.Draw(offsetX, offsetY);

    DrawScore();
    DrawLength();
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

void Game::DrawLeftSideGameplay()
{
    std::string scoreText = "Score : ";
    std::string length = "Snake Size : ";

    DrawText(scoreText.c_str(), 30, screenHeight / 2 - 50, 30, BLACK);
    DrawText(length.c_str(), 30, screenHeight / 2 + 50, 30, BLACK);
}

void Game::DrawRightSideGameplay()
{}

void Game::DrawScore()
{
    DrawText(std::to_string(score).c_str(), 150, screenHeight / 2 - 50, 30, BLACK);
}

void Game::DrawLength()
{
    DrawText(std::to_string(snake.GetLength()).c_str(), 230, screenHeight / 2 + 50, 30, BLACK);
}