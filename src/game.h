#ifndef GAME_H
#define GAME_H

#include "bool.h"

class Game {
public:
    void init(void);

    void run(void);

    void processInput(void);

    void update(void);

    void render(void);

private:
    typedef struct Ball {
        int x; 
        int y;
        int width; 
        int height;
    } Ball;

    Ball m_ball;

    typedef struct Paddle {
        int x; 
        int y;
        int width; 
        int height;
    } Paddle;

    Paddle m_paddle;
    
    bool isRunning;

};

#endif