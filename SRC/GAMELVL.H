#ifndef GAMELVL_H
#define GAMELVL_H

#include "VECTOR.H"
#include "GAMEOBJ.H"

class Renderer;
class GameLevel {
public:
    void init(int level[9][13]);

    void draw(Renderer* renderer);

    vector<GameObject> bricks; 
};

#endif