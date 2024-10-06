#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

class Board {
public:
    Board(int screenWidth, int screenHeight, int gridSize, int cellSize);
    void Draw() const;
    [[nodiscard]] bool IsInsideBoard(int x, int y) const;
private:
    int screenWidth, screenHeight, gridSize, cellSize;
};

#endif //SNAKE_BOARD_H