#ifndef GAME_H
#define GAME_H

#include "BOOL.H"
#include "GAMELVL.H"

class Ball;
class Paddle;
class Renderer;
class UI;
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

    UI* ui;

    GameLevel levels[4];

    int isRunning;

    int currentLevel;

    int score;

    int life;
};

#endif