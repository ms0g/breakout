#include "AABB.H"

bool checkCollision(GameObject* ball, GameObject* paddle) {
    return ((ball->pos.y + ball->height >= paddle->pos.y) && 
                (ball->pos.x > paddle->pos.x && ball->pos.x < (paddle->pos.x + paddle->width)));
}

bool checkAABBCollision(GameObject* one, GameObject* two) {
    // collision x-axis?
    bool collisionX = one->pos.x + one->width >= two->pos.x &&
        two->pos.x + two->width >= one->pos.x;
    // collision y-axis?
    bool collisionY = one->pos.y + one->height >= two->pos.y &&
        two->pos.y + two->height >= one->pos.y;
    // collision only if on both axes
    return collisionX && collisionY;
}
