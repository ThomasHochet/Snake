#include "Snake.h"

Snake::Snake(int startX, int startY, int cellSize) : length(3), cellSize(cellSize), direction(RIGHT)
{
    body[0] = { static_cast<float>(startX), static_cast<float>(startY) };
}

void Snake::Draw(int offsetX, int offsetY) const
{
    for (int i = 0; i < length; i++)
    {
        DrawRectangle(offsetX + body[i].x * cellSize, offsetY + body[i].y * cellSize, cellSize, cellSize, BLACK);
    }
}

bool Snake::CheckCollisionWithSelf() const
{
    for (int i = 1; i < length; i++)
    {
        if (body[0].x == body[i].x && body[0].y == body[i].y)
            return true;
    }
    return false;
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

void Snake::Reset(int maxX, int maxY)
{
    length = 3;
    body[0] = { static_cast<float>(GetRandomValue(0, maxX)), static_cast<float>(GetRandomValue(0, maxY)) };
}

int Snake::GetLength() {
    return length;
}


void Snake::SetDirection(Direction newDir)
{
    direction = newDir;
}

Vector2 Snake::GetHeadPosition() const
{
    return body[0];
}
