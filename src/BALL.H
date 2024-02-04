#ifndef BALL_H
#define BALL_H

#include "GAMEOBJ.H"

class Renderer;
class Ball: public GameObject {
public:
    Ball(int x, int y, char color);

    void move(void);

    void draw(Renderer* renderer);

    void reset(int x, int y);
};

#endif