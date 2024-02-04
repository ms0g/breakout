#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class Renderer;
class GameObject {
public:
    void draw(Renderer* renderer);

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
};


#endif