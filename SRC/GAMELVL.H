#ifndef GAMELVL_H
#define GAMELVL_H

#include "OBJPRTY.H"
#include "CONF.H"

typedef struct Brick {
    ObjectProperty property;
    int isActive;
    int hitCount;
} Brick;

typedef struct GameLevel{
    Brick bricks[BRICK_COUNT];
    int activeBrickCount;

    void (*new)(struct GameLevel* self, const int level[ROW][COL]);
    int (*isFinished)(const struct GameLevel* self);
    void (*update)(struct GameLevel* self);
    void (*draw)(const struct GameLevel* self);
    Brick* (*getBrick)(const struct GameLevel* self, int index);
} GameLevel;

void glInit(GameLevel* self);
void glCreate(GameLevel* self, const int level[ROW][COL]);
int glIsFinished(const GameLevel* self);
void glUpdate(GameLevel* self);
void glDraw(const GameLevel* self);
Brick* glGetBrick(const GameLevel* self, int index);

#endif