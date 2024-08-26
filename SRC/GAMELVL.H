#ifndef GAMELVL_H
#define GAMELVL_H

#include "GAMEOBJ.H"
#include "CONF.H"

class Renderer;
class Brick: public GameObject {
public:
    int isActive;

    int hitCount;
};

class GameLevel {
public:
    void init(const int level[ROW][COL]);
    
    int isFinished(void);
    
    void update(void);

    void draw(Renderer* renderer);

    Brick* getBrick(int index);

private:
    Brick bricks[BRICK_COUNT];

    int activeBrickCount;
};

#endif