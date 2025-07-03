#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"

typedef struct LevelManager {
    GameLevel levels[4];
    int currentLevelIndex;

    void (*new)(struct LevelManager*);
    void (*drawCurrentLevel)(const struct LevelManager*);
    GameLevel* (*getCurrentLevel)(struct LevelManager*);
    void (*loadNextLevel)(struct LevelManager*);
} LevelManager;

void lmInit(LevelManager* this);

#endif