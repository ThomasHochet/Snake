#include "Snake.h"

Snake::Snake(int startX, int startY, int cellSize) : length(2), cellSize(cellSize), direction(RIGHT)
{
    body[0] = { static_cast<float>(startX), static_cast<float>(startY) };
}

void Snake::Draw() const
{
    for (int i = 0; i < length; i++)
    {
        DrawRectangle(body[i].x * cellSize, body[i].y * cellSize, cellSize, cellSize, BLACK);
    }
}

void Snake::Move()
{
    for (int i = length - 1; i > 0; i--)
    {
        body[i] = body[i - 1];
    }

    switch (direction) {
        case UP:    body[0].y -= 1; break;
        case DOWN:  body[0].y += 1; break;
        case LEFT:  body[0].x -= 1; break;
        case RIGHT: body[0].x += 1; break;
    }
}

void Snake::Grow()
{
    if (length < maxSnakeLength)
    {
        body[length] = body[length - 1];
        length++;
    }
}

void Snake::SetDirection(Direction newDir)
{
    direction = newDir;
}

Vector2 Snake::GetHeadPosition() const
{
    return body[0];
}
