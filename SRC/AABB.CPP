#include "AABB.H"

int checkAABBCollision(GameObject* one, GameObject* two) {
    // collision x-axis?
    int collisionX = one->property.position.x + one->property.width >= two->property.position.x &&
        two->property.position.x + two->property.width >= one->property.position.x;
    // collision y-axis?
    int collisionY = one->property.position.y + one->property.height >= two->property.position.y &&
        two->property.position.y + two->property.height >= one->property.position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}
