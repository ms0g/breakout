#include "AABB.H"

int checkAABBCollision(ObjectProperty* one, ObjectProperty* two) {
    // collision x-axis?
    int collisionX = one->position.x + one->width >= two->position.x &&
        two->position.x + two->width >= one->position.x;
    // collision y-axis?
    int collisionY = one->position.y + one->height >= two->position.y &&
        two->position.y + two->height >= one->position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}
