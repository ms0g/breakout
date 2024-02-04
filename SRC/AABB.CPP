#include "AABB.H"

int checkCollision(GameObject* ball, GameObject* paddle) {
    return ((ball->pos.y + ball->height >= paddle->pos.y) && 
                (ball->pos.x > paddle->pos.x && ball->pos.x < (paddle->pos.x + paddle->width)));
}
