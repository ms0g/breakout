#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    struct {
        float x; 
        float y;
    } position;

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