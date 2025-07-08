#ifndef GAMEOBJ_H
#define GAMEOBJ_H

typedef struct GameObject {
    struct {
        float x; 
        float y;
    } position;
    
    int width; 
    int height;
    char color;
} GameObject;

typedef struct {
    float x;
    float y;
} Velocity;

#endif