#ifndef PADDLE_H
#define PADDLE_H

#include "GAMEOBJ.H"

enum Direction {
    LEFT,
    RIGHT
};

typedef struct Paddle {
    GameObject base;
    Velocity velocity;

    void (*new)(struct Paddle*, float, float, char);
    void (*move)(struct Paddle*, int);
    void (*draw)(const struct Paddle*);
} Paddle;

void paddleInit(Paddle* this);

#endif