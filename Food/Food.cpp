#include "Food.h"

Food::Food(int boardWidth, int boardHeight, int cellSize, int gridSize) : boardWidth(boardWidth), boardHeight(boardHeight), cellSize(cellSize), gridSize(gridSize)
{
    GenerateNewPosition();
}

void Food::Draw(int offsetX, int offsetY) const
{
    DrawRectangle(offsetX + position.x * cellSize, offsetY + position.y * cellSize, cellSize, cellSize, RED);
}

void Food::GenerateNewPosition()
{
    position.x = GetRandomValue(gridSize -1, boardWidth / gridSize);
    position.y = GetRandomValue(gridSize -1, boardHeight / gridSize);
}

Vector2 Food::GetPosition() const
{
    return position;
}