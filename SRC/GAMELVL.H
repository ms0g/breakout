#ifndef GAMELVL_H
#define GAMELVL_H

#include "VECTOR.H"
#include "GAMEOBJ.H"
#include "CONF.H"

class Renderer;
class GameLevel {
public:
    void init(int level[ROW][COL]);

    void draw(Renderer* renderer);

    vector<GameObject> bricks;
};

#endif