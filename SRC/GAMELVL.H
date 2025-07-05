#ifndef GAMELVL_H
#define GAMELVL_H

#include "OBJPRTY.H"
#include "CONF.H"

typedef struct Brick {
    ObjectProperty property;
    int isActive;
    int hitCount;
} Brick;

typedef struct GameLevel {
    Brick bricks[BRICK_COUNT];
    int activeBrickCount;

    void (*new)(struct GameLevel*, const int (*level)[COL]);
    void (*update)(struct GameLevel*);
    void (*draw)(const struct GameLevel*);
    int (*isFinished)(const struct GameLevel*);
    Brick* (*getBrick)(struct GameLevel*, int);
} GameLevel;

void glInit(GameLevel* this);

#endif