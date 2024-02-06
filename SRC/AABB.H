#ifndef AABB_H
#define AABB_H

#include "GAMEOBJ.H"
#include "BOOL.H"

int checkCollision(GameObject* ball, GameObject* paddle);

int checkAABBCollision(GameObject* one, GameObject* two);

#endif