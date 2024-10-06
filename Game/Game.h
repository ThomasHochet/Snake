#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H


#include "../Board/Board.h"
#include "../Snake/Snake.h"
#include "../Food/Food.h"

typedef enum GameScreen { TITLE = 0, GAMEPLAY, ENDING } GameScreen;

class Game {
public:
    Game(int screenWidth, int screenHeight, int gridSize, int cellSize);
    void Run();
private:
    int screenWidth, screenHeight;
    Board board;
    Snake snake;
    Food food;
    GameScreen currentScreen;
    void UpdateTitleScreen();
    void UpdateGameplayScreen();
    void UpdateEndingScreen();
    void DrawTitleScreen();
    void DrawGameplayScreen();
    void DrawEndingScreen();
    [[nodiscard]] bool CheckCollisionWithFood() const;
};

#endif //SNAKE_GAME_H
