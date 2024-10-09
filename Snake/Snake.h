#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "raylib.h"
#include <iostream>

typedef enum Direction { UP, DOWN, LEFT, RIGHT } Direction;

class Snake {
public:
    Snake(int startX, int startY, int cellSize);
    void Move();
    void Grow();
    bool CheckCollisionWithSelf() const;
    void Draw(int offsetX, int offsetY) const;
    void SetDirection(Direction newDir);
    void Reset(int maxX, int maxY);
    int GetLength();
    Vector2 GetHeadPosition() const;
private:
    int length;
    static const int maxSnakeLength = 100; // To start with
    Vector2 body[maxSnakeLength];
    Direction direction;
    int cellSize;
};


#endif //SNAKE_SNAKE_H
