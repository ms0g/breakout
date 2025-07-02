#ifndef GAMELVL_H
#define GAMELVL_H

#include "GAMEOBJ.H"
#include "CONF.H"

typedef struct Brick {
    ObjectProperty property;

    int isActive;

    int hitCount;
} Brick;

class GameLevel {
public:
    void init(const int level[ROW][COL]);
    
    int isFinished(void);
    
    void update(void);

    void draw(void);

    Brick* getBrick(int index);

private:
    Brick bricks[BRICK_COUNT];

    int activeBrickCount;
};

#endif