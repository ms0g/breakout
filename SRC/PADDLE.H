#ifndef PADDLE_H
#define PADDLE_H

#include "GAMEOBJ.H"

enum Direction {
    LEFT,
    RIGHT
};

typedef struct Paddle {
    ObjectProperty property;
    
    struct {
        float x;
        float y;
    } velocity;

    void (*create)(struct Paddle*, float, float, char);
    void (*move)(struct Paddle*, int direction);
    void (*draw)(struct Paddle*);
} Paddle;

#ifdef __cplusplus
extern "C" {
#endif
void paddleInit(Paddle* self);
void paddleCreate(Paddle* self, float x, float y, char color);
void paddleMove(Paddle* self, int direction);
void paddleDraw(Paddle* self);

#endif