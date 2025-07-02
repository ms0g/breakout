#ifndef LVLMNGR_H
#define LVLMNGR_H

#include "GAMELVL.H"
#include "VECTOR.H"

class LevelManager {
public:
    LevelManager();

    void drawCurrentLevel(void);

    GameLevel* getCurrentLevel(void);

    void loadNextLevel(void);

private:
    vector<GameLevel> levels;
    
    int currentLevelIndex;
};

#endif