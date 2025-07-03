#ifndef PADDLE_H
#define PADDLE_H

#include "OBJPRTY.H"

enum Direction {
    LEFT,
    RIGHT
};

typedef struct Paddle {
    ObjectProperty property;
    Velocity velocity;

    void (*new)(struct Paddle*, float, float, char);
    void (*move)(struct Paddle*, int direction);
    void (*draw)(const struct Paddle*);
} Paddle;

void paddleInit(Paddle* self);

#endif