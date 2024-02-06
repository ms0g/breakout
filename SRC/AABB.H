#ifndef AABB_H
#define AABB_H

#include "GAMEOBJ.H"
#include "BOOL.H"

bool checkCollision(GameObject* ball, GameObject* paddle);

bool checkAABBCollision(GameObject* one, GameObject* two);

#endif