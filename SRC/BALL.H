#ifndef BALL_H
#define BALL_H

#include "OBJPRTY.H"

#define BALL_SPEED 2.0
#define BALL_WIDTH 3
#define BALL_HEIGHT 3
#define BALL_RESET_OFFSET_Y 3

typedef struct Ball {
    ObjectProperty property;
    
    struct {
        float x;
        float y;
    } velocity;

    void (*new)(struct Ball*, float, float, char);
    void (*move)(struct Ball*);
    void (*draw)(const struct Ball*);
    void (*reset)(struct Ball*, float, float);
} Ball;

void ballInit(Ball* self);
void ballCreate(Ball* self, float x, float y, char color);
void ballMove(Ball* self);
void ballDraw(const Ball* self);
void ballReset(Ball* self, float x, float y);
  
#endif