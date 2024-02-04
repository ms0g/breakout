#ifndef PADDLE_H
#define PADDLE_H

#include "GAMEOBJ.H"

enum Direction {
    LEFT,
    RIGHT
};

class Renderer;
class Paddle: public GameObject {
public:
    Paddle(int x, int y, char color);

    void move(int direction);

    void draw(Renderer* renderer);
};

#endif