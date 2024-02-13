#include "SCENMNGR.H"
#include "RENDERER.H"
#include "LEVELS.H"

SceneManager::SceneManager() {
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

void SceneManager::drawCurrentScene(Renderer* renderer) {
    levels[currentSceneIndex].draw(renderer);
}

GameLevel* SceneManager::getCurrentLevel() {
    return &levels[currentSceneIndex];
}

void SceneManager::loadNextScene() {
    ++currentSceneIndex;
}