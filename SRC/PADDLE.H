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
    Paddle(float x, float y, char color);

    void move(int direction);

    void draw(const Renderer* renderer);
    
    struct {
        float x;
        float y;
    } velocity;
};

#endif