#ifndef GAME_H
#define GAME_H

#include "BOOL.H"
#include "GAMELVL.H"

class Ball;
class Paddle;
class Renderer;
class Game {
public:
    Game();
    
    ~Game();

    void run(void);
    
private:
    void processInput(void);

    void update(void);

    void render(void);

    void doCollision(void);

    Ball* ball;

    Paddle* paddle;

    Renderer* renderer;

    GameLevel levels[4];

    int isRunning;

    int currentLevel;

    int score;

    int life;
};

#endif