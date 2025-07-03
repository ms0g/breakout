#ifndef OBJPRTY_H
#define OBJPRTY_H

typedef struct {
    struct {
        float x; 
        float y;
    } position;
    
    int width; 
    int height;
    char color;
} ObjectProperty;

typedef struct {
    float x;
    float y;
} Velocity;

#endif