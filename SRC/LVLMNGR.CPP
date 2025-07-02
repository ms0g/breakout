#include "LVLMNGR.H"
#include "RENDERER.H"
#include "LEVELS.H"

LevelManager::LevelManager() {
    levels.reserve(4);

    GameLevel one;
    one.init(levelOne);
    levels.push_back(one);

    GameLevel two;
    two.init(levelTwo);
    levels.push_back(two);

    GameLevel three;
    three.init(levelThree);
    levels.push_back(three);

    GameLevel four;
    four.init(levelFour);
    levels.push_back(four);
    
    currentLevelIndex = 0;
}

void LevelManager::drawCurrentLevel(void) {
    levels[currentLevelIndex].draw();
}

GameLevel* LevelManager::getCurrentLevel(void) {
    return &levels[currentLevelIndex];
}

void LevelManager::loadNextLevel(void) {
    ++currentLevelIndex;

    if (currentLevelIndex > 3) {
        currentLevelIndex = 0;
    }
}