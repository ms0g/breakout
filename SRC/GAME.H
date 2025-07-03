#ifndef GAME_H
#define GAME_H

#include "PADDLE.h"
#include "BALL.h"
#include "LVLMNGR.h"
class Game {
public:
    Game();
    
    ~Game();

    void loop(void);
    
private:
    void processInput(void);

    void update(void);

    void render(void);

    void doCollision(void);

    void resetBall(void);

    Ball ball;

    Paddle paddle;

    LevelManager levelManager;

    int isRunning;

    int done;

    int score;

    int life;
};

#endif