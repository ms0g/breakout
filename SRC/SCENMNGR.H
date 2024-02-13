#ifndef SCENMNGR_H
#define SCENMNGR_H

#include "GAMELVL.H"

class Renderer;
class SceneManager {
public:
    SceneManager();

    void drawCurrentScene(Renderer* renderer);

    GameLevel* getCurrentLevel();

    void loadNextScene();

private:
    GameLevel levels[4];
    
    int currentSceneIndex;

};

#endif