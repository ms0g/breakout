#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

typedef struct {
    struct {
        float x; 
        float y;
    } position;
    
    int width; 
    int height;
    char color;
} ObjectProperty;

#endif