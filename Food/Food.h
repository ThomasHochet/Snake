#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include "../Snake/Snake.h"

class Food {
public:
    Food(int boardWidth, int boardHeight, int cellSize, int gridSize);
    void GenerateNewPosition();
    [[nodiscard]] Vector2 GetPosition() const;
    void Draw() const;
private:
    Vector2 position;
    int boardWidth, boardHeight, cellSize, gridSize;
};


#endif //SNAKE_FOOD_H
