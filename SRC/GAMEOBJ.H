#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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

    char _color;

    int isActive;

    int hitCount;
};


#endif