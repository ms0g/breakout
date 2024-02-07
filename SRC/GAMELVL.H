#ifndef GAMELVL_H
#define GAMELVL_H

#include "VECTOR.H"
#include "GAMEOBJ.H"
#include "CONF.H"

class Renderer;
class GameLevel {
public:
    void init(const int level[ROW][COL]);

    void draw(Renderer* renderer);

    GameObject bricks[BRICK_COUNT];

    int activeBrickCount;
};

#endif