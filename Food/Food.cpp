#include "Food.h"

Food::Food(int boardWidth, int boardHeight, int cellSize, int gridSize) : boardWidth(boardWidth), boardHeight(boardHeight), cellSize(cellSize), gridSize(gridSize)
{
    GenerateNewPosition();
}

void Food::Draw() const
{
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
}

void Food::GenerateNewPosition()
{
    position.x = GetRandomValue(gridSize, boardWidth / gridSize - 1);
    position.y = GetRandomValue(gridSize, boardHeight / gridSize - 1);
}

Vector2 Food::GetPosition() const
{
    return position;
}