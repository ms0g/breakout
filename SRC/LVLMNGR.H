#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"

typedef struct LevelManager{
    GameLevel levels[4];
    int currentLevelIndex;

    void (*new)(struct LevelManager* self);
    void (*drawCurrentLevel)(const struct LevelManager* self);
    GameLevel* (*getCurrentLevel)(struct LevelManager* self);
    void (*loadNextLevel)(struct LevelManager* self);
} LevelManager;

void lmInit(LevelManager* self);
void lmCreate(LevelManager* self);
void lmDrawCurrentLevel(const LevelManager* self);
GameLevel* lmGetCurrentLevel(LevelManager* self);
void lmLoadNextLevel(LevelManager* self);

#endif