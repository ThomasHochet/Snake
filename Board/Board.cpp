#include "Board.h"

#include <iostream>
#include "raylib.h"

Board::Board(int screenWidth, int screenHeight, int gridSize, int cellSize)
    : screenWidth(screenWidth), screenHeight(screenHeight), gridSize(gridSize), cellSize(cellSize) {}

void Board::Draw() const
{
    int gridWidth = gridSize * cellSize;
    int gridHeight = gridSize * cellSize;

    int offsetX = (screenWidth - gridWidth) / 2;
    int offsetY = (screenHeight - gridHeight) / 2;
    for (int y = 0; y < gridSize; y++)
    {
        for (int x = 0; x < gridSize; x++)
        {
            DrawRectangle(offsetX + x * cellSize, offsetY + y * cellSize, cellSize, cellSize, RAYWHITE);

            DrawLine(offsetX, offsetY, offsetX + gridWidth, offsetY, BLACK);
            DrawLine(offsetX, offsetY, offsetX, offsetY + gridHeight, BLACK);

            DrawLine(offsetX, offsetY + y * cellSize, offsetX + gridWidth, offsetY + y * cellSize, LIGHTGRAY);
            DrawLine(offsetX + x * cellSize, offsetY, offsetX + x * cellSize, offsetY + gridHeight, LIGHTGRAY);
        }
    }

    DrawLine(offsetX,  offsetY + gridHeight, offsetX + gridWidth, offsetY + gridHeight, BLACK);
    DrawLine(offsetX + gridWidth, offsetY, offsetX + gridWidth, offsetY + gridHeight, BLACK);
}

bool Board::IsInsideBoard(int x, int y) const
{
    return (x >= 0 && x < gridSize && y >= 0 && y < gridSize);
}