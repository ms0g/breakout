#include "AABB.H"

int checkAABBCollision(GameObject* one, GameObject* two) {
    // collision x-axis?
    int collisionX = one->pos.x + one->width >= two->pos.x &&
        two->pos.x + two->width >= one->pos.x;
    // collision y-axis?
    int collisionY = one->pos.y + one->height >= two->pos.y &&
        two->pos.y + two->height >= one->pos.y;
    // collision only if on both axes
    return collisionX && collisionY;
}
