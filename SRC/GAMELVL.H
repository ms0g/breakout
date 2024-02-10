#ifndef GAMELVL_H
#define GAMELVL_H

#include "GAMEOBJ.H"
#include "CONF.H"

class Renderer;
class GameLevel {
public:
    void init(const int level[ROW][COL]);

    void update(void);

    void draw(Renderer* renderer);

    int isFinished(void);

    GameObject bricks[BRICK_COUNT];

private:
    int activeBrickCount;
};

#endif