#ifndef BALL_H
#define BALL_H

#include "GAMEOBJ.H"

class Renderer;
class Ball: public GameObject {
public:
    Ball(float x, float y, char color);

    void move(void);

    void draw(Renderer* renderer);

    void reset(float x, float y);
};

#endif