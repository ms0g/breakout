#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"
#include "VECTOR.H"

class Renderer;
class LevelManager {
public:
    LevelManager();

    void drawCurrentLevel(const Renderer* renderer);

    GameLevel* getCurrentLevel();

    void loadNextLevel();

private:
    vector<GameLevel> levels;
    
    int currentLevelIndex;
};

#endif