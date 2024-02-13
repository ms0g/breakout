#ifndef GAMELVL_H
#define GAMELVL_H

#include "GAMEOBJ.H"
#include "CONF.H"

class Renderer;
class GameLevel {
public:
    void init(const int level[ROW][COL]);
    
    int isFinished(void);
    
    void update(void);

    void draw(Renderer* renderer);

    GameObject* getBrick(int index);

private:
    GameObject bricks[BRICK_COUNT];

    int activeBrickCount;
};

#endif