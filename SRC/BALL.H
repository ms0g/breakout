#ifndef BALL_H
#define BALL_H

#include "GAMEOBJ.H"

#define BALL_SPEED 2.0
#define BALL_WIDTH 3
#define BALL_HEIGHT 3
#define BALL_RESET_OFFSET_Y 3

class Ball: public GameObject {
public:
    Ball(float x, float y, char color);

    void move(void);

    void draw(void);

    void reset(float x, float y);

    struct {
        float x;
        float y;
    } velocity;
};

#endif