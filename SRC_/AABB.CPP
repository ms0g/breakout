#include "AABB.H"

int checkCollision(GameObject* ball, GameObject* paddle) {
    return ((ball->posY() + ball->height() >= paddle->posY()) && 
                (ball->posX() > paddle->posX() && ball->posX() < (paddle->posX() + paddle->width())));
}
