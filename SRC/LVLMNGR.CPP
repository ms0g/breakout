#include "LVLMNGR.H"
#include "RENDERER.H"
#include "LEVELS.H"

LevelManager::LevelManager() {
    GameLevel one;
    one.init(levelOne);
    levels[0] = one;

    GameLevel two;
    two.init(levelTwo);
    levels[1] = two;

    GameLevel three;
    three.init(levelThree);
    levels[2] = three;

    GameLevel four;
    four.init(levelFour);
    levels[3] = four;
    
    currentLevelIndex = 0;
}

void LevelManager::drawCurrentLevel(Renderer* renderer) {
    levels[currentLevelIndex].draw(renderer);
}

GameLevel* LevelManager::getCurrentLevel() {
    return &levels[currentLevelIndex];
}

void LevelManager::loadNextLevel() {
    ++currentLevelIndex;

    if (currentLevelIndex > 3) {
        currentLevelIndex = 0;
    }
}