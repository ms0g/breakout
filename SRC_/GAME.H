#ifndef GAME_H
#define GAME_H

#include "BOOL.H"

class Ball;
class Paddle;
class Renderer;
class Game {
public:
    void init(void);

    void run(void);

    void processInput(void);

    void update(void);

    void render(void);

    void doCollision(void);

private:

    Ball* m_ball;

    Paddle* m_paddle;

    Renderer* m_renderer;
    
    bool isRunning;
};

#endif