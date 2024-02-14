#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    struct {
        float x; 
        float y;
    } pos;

    int width; 
    int height;
        
    struct {
        float x;
        float y;
    } velocity;

    char _color;

    int isActive;

    int hitCount;
};

#endif