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
    
    currentSceneIndex = 0;
}

void LevelManager::drawCurrentLevel(Renderer* renderer) {
    levels[currentSceneIndex].draw(renderer);
}

GameLevel* LevelManager::getCurrentLevel() {
    return &levels[currentSceneIndex];
}

void LevelManager::loadNextLevel() {
    ++currentSceneIndex;
}