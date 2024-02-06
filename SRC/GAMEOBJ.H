#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "BOOL.H"

class GameObject {
public:
    struct {
        int x; 
        int y;
    } pos;

    int width; 
    int height;
        
    struct {
        int x;
        int y;
    } velocity;

    char m_color;

    bool isActive;

    int hitCount;
};


#endif