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
    bool CheckCollisionWithWalls(int boardWidth, int boardHeight) const;
    void Draw() const;
    void SetDirection(Direction newDir);
    Vector2 GetHeadPosition() const;
private:
    static const int maxSnakeLength = 100; // To start with
    Vector2 body[maxSnakeLength];
    int length;
    Direction direction;
    int cellSize;
};


#endif //SNAKE_SNAKE_H
