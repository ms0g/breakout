#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"

typedef struct LevelManager{
    GameLevel levels[4];
    int currentLevelIndex;

    void (*create)(struct LevelManager* self);
    void (*drawCurrentLevel)(struct LevelManager* self);
    GameLevel* (*getCurrentLevel)(struct LevelManager* self);
    void (*loadNextLevel)(struct LevelManager* self);
} LevelManager;

#ifdef __cplusplus
extern "C" {
#endif

void lmInit(LevelManager* self);
void lmCreate(LevelManager* self);
void lmDrawCurrentLevel(LevelManager* self);
GameLevel* lmGetCurrentLevel(LevelManager* self);
void lmLoadNextLevel(LevelManager* self);

#ifdef __cplusplus
}
#endif

#endif