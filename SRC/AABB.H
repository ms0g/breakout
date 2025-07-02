#ifndef AABB_H
#define AABB_H

#include "GAMEOBJ.H"

#ifdef __cplusplus
extern "C" {
#endif

int checkAABBCollision(ObjectProperty* one, ObjectProperty* two);
#ifdef __cplusplus
}
#endif

#endif