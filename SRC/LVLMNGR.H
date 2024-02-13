#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"

class Renderer;
class LevelManager {
public:
    LevelManager();

    void drawCurrentLevel(Renderer* renderer);

    GameLevel* getCurrentLevel();

    void loadNextLevel();

private:
    GameLevel levels[4];
    
    int currentSceneIndex;

};

#endif