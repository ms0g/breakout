#ifndef AABB_H
#define AABB_H

struct GameObject;
int checkAABBCollision(const struct GameObject* one, const struct GameObject* two);

#endif