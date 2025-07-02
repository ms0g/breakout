#ifndef BALL_H
#define BALL_H

#include "GAMEOBJ.H"

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

    void (*create)(struct Ball*, float, float, char);
    void (*move)(struct Ball*);
    void (*draw)(struct Ball*);
    void (*reset)(struct Ball*, float, float);
} Ball;

#ifdef __cplusplus
extern "C" {
#endif


void ballInit(Ball* self);
void ballCreate(Ball* self, float x, float y, char color);
void ballMove(Ball* self);
void ballDraw(Ball* self);
void ballReset(Ball* self, float x, float y);
  


#ifdef __cplusplus
}
#endif

#endif