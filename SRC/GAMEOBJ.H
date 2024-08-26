#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
    struct {
        struct {
            float x; 
            float y;
        } position;
    
        int width; 
        int height;
        char color;
    } property;
};

#endif